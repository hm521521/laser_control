#include "mp3_player.h"
#include<QDir>

mp3_player::mp3_player()
    :m_handle(0)
    ,m_start_frame(0)
    ,m_frame_length(0)
    ,m_probe(new QAudioProbe)
{
    connect(m_probe, SIGNAL(audioBufferProbed(QAudioBuffer)), this, SLOT(processBuffer(QAudioBuffer)));
    m_probe->setSource(this);
}

bool mp3_player::open_file(QString file)
{
    QDir dir(file);
    if(!dir.exists()) return false;
    m_handle=0;
    m_name=file;
    return true;
}

void mp3_player::get_music_data(std::vector<unsigned int> &data)
{
    for(int i=0;i<m_byteArr->size();++i)
    {
        data.push_back(m_byteArr->at(i));
    }
}

void mp3_player::processBuffer(QAudioBuffer &buffer)
{
    m_byteArr->append(buffer.constData<char>(),buffer.byteCount());
}

