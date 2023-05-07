#ifndef PROJECT_PANEL0_H
#define PROJECT_PANEL0_H
#include"cjsection.h"
#include<QGraphicsItem>
#include"show_model.h"
//#include"mp3_player.h"
#include<QMediaPlayer>
#include "scene_pool.h"
#include<QAudioProbe>
#include<QObject>
#include<QMediaPlaylist>
#include<QAudioBuffer>
#include<qcustomplot.h>
#include<QAudioDecoder>



enum class MOUSE_MOVE_MODE//鼠标移动模式
{
    MMM_NONE,
    MMM_MEDIA_DRAG,
    MMM_SCENE_DRAG,
    MMM_SCENE_LEFT_MOVE,
    MMM_SCENE_RIGHT_MOVE,
};
class track_panel;
class  project_panel:public QGraphicsView
{
    Q_OBJECT
public:
    project_panel(QWidget *parent = nullptr);
    ~project_panel();
    void update_panel(QRectF rec);
    void set_scene(QGraphicsScene *scene);
    void play();
    void stop();
    void update_show(CJSection * out_picture);
private:
    QGraphicsScene *m_graphicsScene;
    track_panel *m_track_panel;

};

class scene_info
{
public:
    scene_info(single_scene* scene,int start_x, int end_x, int track_index);
    ~scene_info();
    bool operator==(scene_info& other);
    single_scene *m_scene;
    int m_start_x;
    int m_end_x;
    int m_track_index;//track被删除的话，除了laser_scene要被删除，以下的track index也要被更新
    bool is_moving(int x);
    bool on_start_pos(int x);
    bool on_end_pos(int x);
};

class media_info:public QCustomPlot//媒体信息类
{
    Q_OBJECT
public:
//    media_info(project_panel *parent=0);
    media_info(int x, int idx, track_panel *panel,QWidget *parent=nullptr);
    ~media_info();
    bool load_file(const QString &name);
    int get_frame_length();
    void draw_level(QPainter *painter, int x, int y, int width, int height);
    QString m_filename;
    QMediaPlayer* m_mp3_player;
    QVector<double> m_sample;
    int m_start_x; //media开始位置
    //int m_media_length; //media长度
    //int m_last_x;
    int m_track_index;
    bool m_play_flag;
private:
    QAudioDecoder *m_decoder;
//    QAudioProbe *m_probe;
    QAudioBuffer m_buffer;
//    track_panel *m_parent;
    QMediaPlaylist  *m_playlist;//播放列表
    QCPGraph *m_wavePlot;
    track_panel *m_track_panel;


public slots:
    void onStateChanged(QMediaPlayer::State);
    void onPositionChanged(qint64);
    void onDurationChanged(qint64);
    void onPlaylistChanged(int);
private slots:
//    void processBuffer(const QAudioBuffer &buffer);
    qreal getPeakValue(const QAudioFormat &format);
    void setBuffer();
    void plot();


};

class track_panel:public QGraphicsItem
{
public:
    track_panel(project_panel *parent=0);
    ~track_panel();
    QRectF boundingRect() const override;
    void paint(QPainter *painter,
                              const QStyleOptionGraphicsItem *option,
                              QWidget *widget=nullptr) override;

    void update_width();
    void update_width(int x);
    void play();
    void stop();
    void update_show(CJSection* out_picture);
    void add_scene(int x, int y, single_scene *scene);

    CJSection *item_section;
    int m_play_start;
protected:
    void Init();
    void dropEvent(QGraphicsSceneDragDropEvent *event) override;
    void dragEnterEvent(QGraphicsSceneDragDropEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
private:
    int get_media_start_y(int idx);
    int get_laser_start_y(int idx);
    media_info* get_media(int x, int y);
private:
    project_panel *m_parent;
    show_model m_show_model;
    int m_header_width;
    int m_media_track_count;
    int m_laser_track_count;
    float m_play_pos;
    int m_last_x;//保存鼠标左键按下的最后位置
    MOUSE_MOVE_MODE m_mouse_move_mode = MOUSE_MOVE_MODE::MMM_NONE;
    int m_current_index;//当前正在移动的media或scene的index
    int m_frame_index;
    QVector<media_info*> m_medias;
    QVector<scene_info> m_scenes;
    int m_laser_x;//保存鼠标左键按下的最后位置
    int m_width;
    int m_height;
private:
    int on_media_track(int y);
    bool on_tick_panel(int y);
    void set_selected_scene(int track_index);
    int on_laser_track(int y);
    float get_stop_postion();

};


#endif // PROJECT_PANEL0_H
