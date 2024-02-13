#include "sendtodevice.h"



sendToDevice::sendToDevice(StagesList &sl, QObject *parent):
    QObject(parent)
{
    m_stageslist=sl;
    m_config=new Configuration(this);
    m_config->Load();

}

void sendToDevice::dataSend(LaserFrame &lf)//把在输出面板上显示的数据发给下位机出去
{
    if(lf.size()>0)
    {
        for(int i=0;i<m_stageslist.size();++i)
        {
            auto s=m_stageslist.at(i);
            std::vector<ishow_data> out=s->globalprocessing(lf);
            s->add_send_data(out);
        }
    }
}


