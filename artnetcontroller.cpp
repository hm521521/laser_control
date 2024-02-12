/*
  Q Light Controller
  artnetnode.cpp

  Copyright (c) Massimo Callegari

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  Version 2 as published by the Free Software Foundation.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details. The license is
  in the file "COPYING".

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

#include "artnetcontroller.h"

#include <QDebug>

ArtNetController::ArtNetController(QString ipaddr, QList<QNetworkAddressEntry> interfaces,
                                   QList<QString> macAddrList, Type type, QObject *parent)
    : QObject(parent)
    ,m_interfaces(interfaces)
{
    QSettings* settings=new QSettings("./artnetconfig.ini",QSettings::IniFormat);
    m_ipAddr = QHostAddress(ipaddr);
    int i = 0;
    foreach(QNetworkAddressEntry iface, interfaces)
    {
        if (iface.ip() == m_ipAddr)
        {
            //手动设置组播地址****************************8
//            int n=settings->value("ArtNetPlugin/outputs").toInt();
//            for(int iset=0; iset<n;iset++)
//            {
//                QString key = QString("ArtNetPlugin/Output%1").arg(iset);
//                QString str=settings->value(key).toString();
//                QString str1=iface.ip().toString();
//                if(str.contains(str1))
//                {
//                    QString port=settings->value(key).toString().split('#').last();
//                    key=QString("Broadcast/Universe%1").arg(port.toInt());
//                    m_broadcastAddr = QHostAddress(settings->value(key).toString());
//                    break;
//                }
//            }
            //*************************************
            //自动组播地址
            m_broadcastAddr=iface.broadcast();
            //*******************************************
            m_MACAddress = macAddrList.at(i);
            break;
        }
        i++;
    }

    /*
    // calculate the broadcast address
    quint32 ip = m_ipAddr.toIPv4Address();
    quint32 mask = QHostAddress("255.255.255.0").toIPv4Address(); // will it work in all cases ?
    quint32 broadcast = (ip & mask) | (0xFFFFFFFFU & ~mask);
    m_broadcastAddr = QHostAddress(broadcast);
    */

    qDebug() << "[ArtNetController] Broadcast address:" << m_broadcastAddr.toString() << "(MAC:" << m_MACAddress << ")";
    qDebug() << "[ArtNetController] type: " << type;
    m_packetizer = new ArtNetPacketizer();
    m_UdpSocket = new QUdpSocket(this);
//组播模式*****************************
//    if (m_UdpSocket->bind(QHostAddress::AnyIPv4, ARTNET_DEFAULT_PORT, QUdpSocket::ShareAddress))
//    {
//        m_UdpSocket->joinMulticastGroup(m_broadcastAddr);
//    }
//    else
//    {
//        return;
//    }
//**********************************
    //自动组播
    if (!m_UdpSocket->bind(ARTNET_DEFAULT_PORT,QUdpSocket::ShareAddress))
        return;
//****************************************************************88
    //手动组播绑定端口******************************************
//    if(!m_UdpSocket->bind(ARTNET_DEFAULT_PORT,QUdpSocket::ShareAddress| QUdpSocket::ReuseAddressHint))return;
    //******************************************************8
    connect(m_UdpSocket, SIGNAL(readyRead()),
            this, SLOT(processPendingPackets()));

    // don't send a Poll if we're an input
    if (type == Output)
    {
        //自动发送poll*************************
        QByteArray pollPacket;
        m_packetizer->setupArtNetPoll(pollPacket);
        m_UdpSocket->writeDatagram(pollPacket.data(), pollPacket.size(),
                                   m_broadcastAddr, ARTNET_DEFAULT_PORT);
        //******************************************
//手动发送poll************************************
//        qDebug()<<QHostAddress(getLocalIP()).toString();
//        if(m_ipAddr.toString()!=QHostAddress(getLocalIP()).toString()) return;
//        foreach(QNetworkAddressEntry iface, interfaces)
//        {
//            if (iface.ip() == m_ipAddr)
//            {
//                int n=settings->value("ArtNetPlugin/outputs").toInt();
//                for(int iset=0; iset<n;iset++)
//                {
//                    QString key = QString("ArtNetPlugin/Output%1").arg(iset);
//                    QString str=settings->value(key).toString();
//                    QString str1=iface.ip().toString();
//                    if(str.contains(str1))
//                    {
//                        QString port=settings->value(key).toString().split('#').last();
//                        manualOutput(port.toInt());
//                    }
//                }
//                break;
//            }

//        }
//***************************************************

    }
    else
    {
        for (int i = 0; i < 2048; i++)
            m_dmxValues.append((char)0x00);
    }

    m_type = type;
}

ArtNetController::~ArtNetController()
{
    qDebug() << Q_FUNC_INFO;
//    m_UdpSocket->leaveMulticastGroup(m_broadcastAddr);
    disconnect(m_UdpSocket, SIGNAL(readyRead()),
            this, SLOT(processPendingPackets()));
    m_UdpSocket->abort();
    m_UdpSocket->close();
}

void ArtNetController::addUniverse(quint32 line, int uni)
{
    if (m_universes.contains(uni) == false)
    {
        m_universes[uni] = line;
        qDebug() << "[ArtNetController::addUniverse] Added new universe: " << uni;
    }
}

int ArtNetController::getUniversesNumber()
{
    return m_universes.size();
}

bool ArtNetController::removeUniverse(int uni)
{
    if (m_universes.contains(uni))
    {

        qDebug() << Q_FUNC_INFO << "Removing universe " << uni;
        return m_universes.remove(uni);
    }
    return false;
}

int ArtNetController::getType()
{
    return m_type;
}

QString ArtNetController::getNetworkIP()
{
    return m_ipAddr.toString();
}

QHash<QHostAddress, ArtNetNodeInfo> ArtNetController::getNodesList()
{
    return m_nodesList;
}

void ArtNetController::sendDmx(const int &universe, const QByteArray &data)
{
    QByteArray dmxPacket;
    m_packetizer->setupArtNetDmx(dmxPacket, universe, data);
    m_UdpSocket->writeDatagram(dmxPacket.data(), dmxPacket.size(),
                               m_broadcastAddr, ARTNET_DEFAULT_PORT);
}

void ArtNetController::sendDmxManual(QByteArray data)
{
//    if(m_ipAddr.toString()!=getLocalIP())
//        return;
    m_dmxValues=data;
    QSettings* settings=new QSettings("./artnetconfig.ini",QSettings::IniFormat);
    int universe=settings->value("output_universe").toInt();
    QByteArray dmxPacket;
    m_packetizer->setupArtNetDmx(dmxPacket, universe, m_dmxValues);
    m_UdpSocket->writeDatagram(dmxPacket.data(),dmxPacket.size(),m_broadcastAddr,ARTNET_DEFAULT_PORT);

//手动组播***************************************************************
//    int n=settings->value("ArtNetPlugin/outputs").toInt();
//    for(int iset=0; iset<n;iset++)
//    {
//        QString key = QString("ArtNetPlugin/Output%1").arg(iset);
//        QString port=settings->value(key).toString().split('#').last();
//        if(port.toInt()==universe)
//        {
//            auto m_interf=QHostAddress(settings->value(key).toString().split('#').first());
//            if(m_interf.toString()!=m_ipAddr.toString()&&m_interf.toString()!=getLocalIP())
//            {
//                qDebug()<<"multicast interface:"<<m_interf.toString();
//                m_UdpSocket->writeDatagram(dmxPacket.data(), dmxPacket.size(),
//                                           m_interf, ARTNET_DEFAULT_PORT);
//            }
//        }
//    }
//***********************************************************************
}



void ArtNetController::processPendingPackets()
{
    while (m_UdpSocket->hasPendingDatagrams())
    {
        QByteArray datagram;
        QHostAddress senderAddress;
        datagram.resize(m_UdpSocket->pendingDatagramSize());
        m_UdpSocket->readDatagram(datagram.data(), datagram.size(), &senderAddress);
        auto senderstr=senderAddress.toString().split(":").last();
        if (senderstr != m_ipAddr.toString())
        {
            foreach (QNetworkAddressEntry iface, m_interfaces) {
                qDebug()<<"ifaceAddress:"<<iface.ip().toString();
                qDebug()<<"senderAddress:"<<senderstr;
                if(iface.ip().toString() == senderstr) return;
            }
            qDebug() << "Received packet with size: " << datagram.size() << ", host: " << senderAddress.toString();
            int opCode = -1;
            if (m_packetizer->checkPacketAndCode(datagram, opCode) == true)
            {
                switch (opCode)
                {
                    case ARTNET_POLLREPLY:
                    {
                        qDebug() << "ArtPollReply received";
                        ArtNetNodeInfo newNode;
                        if (m_packetizer->fillArtPollReplyInfo(datagram, newNode) == true)
                        {
                            if (m_nodesList.contains(senderAddress) == false)
                                m_nodesList[senderAddress] = newNode;
                        }
                        QByteArray pollReplyPacket;
                        m_packetizer->setupArtNetPollReply(pollReplyPacket, m_ipAddr, m_MACAddress);
                        m_UdpSocket->writeDatagram(pollReplyPacket.data(), pollReplyPacket.size(),
                                                   senderAddress, ARTNET_DEFAULT_PORT);
                    }
                    break;
                    case ARTNET_POLL:
                    {
                        qDebug() << "ArtPoll received";
                        QByteArray pollReplyPacket;
                        m_packetizer->setupArtNetPollReply(pollReplyPacket, m_ipAddr, m_MACAddress);
                        m_UdpSocket->writeDatagram(pollReplyPacket.data(), pollReplyPacket.size(),
                                                   senderAddress, ARTNET_DEFAULT_PORT);
                    }
                    break;
                    case ARTNET_DMX:
                    {
                        qDebug() << "DMX data received";
                        QByteArray dmxData;
                        int universe;
                        if (m_packetizer->fillDMXdata(datagram, dmxData, universe) == true)
                        {
                            if ((universe * 512) > m_dmxValues.length() || m_universes.contains(universe) == false)
                            {
                                qDebug() << "Universe " << universe << "not supported !";
                                break;
                            }
                            for (int i = 0; i < dmxData.length(); i++)
                            {
                                if (m_dmxValues.at(i + (universe * 512)) != dmxData.at(i))
                                    emit valueChanged(m_universes[universe], i, (uchar)dmxData.at(i));
                            }
                        }
                    }
                    break;
                    default:
                        qDebug() << "opCode not supported yet (" << opCode << ")";
                    break;
                }
            }
            else
                qDebug() << "Malformed packet received";
        }
    }
}
//手动组播
void ArtNetController::manualOutput(int universe)
{
    if(m_ipAddr.toString()!=artgetLocalIP())
    {
        return;
    }
    QSettings* settings=new QSettings("./artnetconfig.ini",QSettings::IniFormat);
    int n=settings->value("ArtNetPlugin/outputs").toInt();
    for(int iset=0; iset<n;iset++)
    {
        QString key = QString("ArtNetPlugin/Output%1").arg(iset);
        QString port=settings->value(key).toString().split('#').last();
        if(port.toInt()==universe)
        {
            auto m_interf=QHostAddress(settings->value(key).toString().split('#').first());
            if(m_interf.toString()!=m_ipAddr.toString()&&m_interf.toString()!=artgetLocalIP())
            {
                qDebug()<<"multicast interface:"<<m_interf.toString();
                QByteArray pollPacket;
                m_packetizer->setupArtNetPoll(pollPacket);
                m_UdpSocket->writeDatagram(pollPacket.data(), pollPacket.size(),
                                           m_interf, ARTNET_DEFAULT_PORT);
            }
        }
    }

}
QString artgetLocalIP()
{

    foreach (QHostAddress ptr , QNetworkInterface::allAddresses())
    {
        if(ptr.protocol() == QAbstractSocket::IPv4Protocol){// 获取ipv4地址
            if(!ptr.isLoopback()){  // 过滤本地回环127.0.0.1
                return ptr.toString();
            }
        }
    }

}
