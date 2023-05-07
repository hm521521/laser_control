#ifndef MP3_PLAYER_H
#define MP3_PLAYER_H
#include<QString>

#include <QMediaPlayer>
#include <QAudioProbe>

class mp3_player : public QMediaPlayer
{
public:
    mp3_player();
    bool open_file(QString file);
    int get_frame_length() {return m_frame_length;};
    void get_music_data(QVector<unsigned int>& data);
private:
    QString m_name;
    unsigned long m_handle;
    int m_start_frame;//起始帧，相对于整个节目的位置
    int m_frame_length;//帧长度=时间（秒）*25
    QAudioProbe *m_probe;
    QByteArray *m_byteArr;
public slots:
    void processBuffer(QAudioBuffer &buffer);
};

#endif // MP3_PLAYER_H
