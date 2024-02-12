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

//时间换算函数将media_track和scene_track上的X坐标换算成时间（秒）
float timeConversion(int x, float invertal_prop);

//将时间点换算成开始的像素点
int XConversion(float time, float invertal_prop);

//将帧长度换算成时间长度
float timeLength(int frame_length, float frame_rate);

//将时间长度换算成帧长度
int frameLength(float time_length, float frame_rate);

enum class MOUSE_MOVE_MODE//鼠标移动模式
{
    MMM_NONE,
    MMM_DRAG,
};
class track_panel;
//class  project_panel:public QGraphicsView
//{
//    Q_OBJECT
//public:
//    project_panel(QWidget *parent = nullptr);
//    ~project_panel();
//    void update_panel(QRectF rec);
//    void set_scene(QGraphicsScene *scene);
//    void play();
//    void stop();
//    void update_show(CJSection * out_picture);
//private:
//    QGraphicsScene *m_graphicsScene;
//    track_panel *m_track_panel;
//protected:
//    void mousePressEvent(QMouseEvent *event) override;
//};
//class track_list_widget;
#include <QMimeData>
 

class scene_info
{
public:
    scene_info(single_scene* scene);
    bool operator==(scene_info& other);
    single_scene *m_scene;
    void load_scene(float start_time,int frame_length,float relative_rate);
    float m_start_time; //开始的时间
    float m_time_length;
    //int m_frame_length = 0;//scene的总帧数
    int m_current_index = 0;//当前播放的帧编号
    //void play(bool flag,float current_time);
private:
};

class media_info:public QObject//媒体信息类
{
    Q_OBJECT
public:
    media_info(QWidget *parent=nullptr);
    ~media_info();
    bool load_file(float start_time,const QString &name);
    int get_frame_length();
    void draw_level(QPainter *painter, int x, int y, int width, int height);
    QString m_filename;
    QMediaPlayer* m_mp3_player;
    std::vector<double> m_sample;
    float m_start_time; //media开始的时间
    //int m_track_index;
    bool m_play_flag;
    int m_buffer_length = 0;//注意单位是微秒
    int m_temp_buffer = 0;
    int m_sample_rate = 44100;
    float m_time_length;
private:
    QAudioDecoder *m_decoder;
    QAudioBuffer m_buffer;
    QMediaPlaylist  *m_playlist;//播放列表
    QCPGraph *m_wavePlot;
public slots:
    void onStateChanged(QMediaPlayer::State);
    void onPositionChanged(qint64);
    void onDurationChanged(qint64);
    void onPlaylistChanged(int);
private slots:
    qreal getPeakValue(const QAudioFormat &format);
    void setBuffer();
    void plot();
};

//class track_panel:public QObject,public QGraphicsItem
//{
//Q_OBJECT
//public:
//    track_panel(project_panel *parent=0);
//    ~track_panel();
//    QRectF boundingRect() const override;
//    void paint(QPainter *painter,
//                              const QStyleOptionGraphicsItem *option,
//                              QWidget *widget=nullptr) override;
//
//    void update_width();
//    void update_width(int x);
//    void play();
//    void stop();
//    void update_show(CJSection* out_picture);
//    void add_scene(int x, int y, single_scene *scene);
//
//    CJSection *item_section;
//    int m_play_start;
//protected:
//    void Init();
//    //void dropEvent(QGraphicsSceneDragDropEvent *event) override;
//    void dragEnterEvent(QGraphicsSceneDragDropEvent *event) override;
//    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
//    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
//    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
//    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) override;
//private:
//    int get_media_start_y(int idx);
//    int get_laser_start_y(int idx);
//    media_info* get_media(int x, int y);
//    QPoint right_click_pos;
//private:
//    project_panel *m_parent;
//    show_model m_show_model;
//    int m_header_width;
//    int m_media_track_count;
//    int m_scene_track_count;
//    float m_play_pos;
//    int m_last_x;//保存鼠标左键按下的最后位置
//    MOUSE_MOVE_MODE m_mouse_move_mode = MOUSE_MOVE_MODE::MMM_NONE;
//    int m_current_index;//当前正在移动的media或scene的index
//    int m_frame_index;
//    QVector<media_info*> m_medias;
//    QVector<scene_info> m_scenes;
//    int m_laser_x;//保存鼠标左键按下的最后位置
//    int m_width=900;
//    int m_height=900;
//    QMenu *m_menu;
//    QAction *del;
//private:
//    int on_media_track(int y);
//    bool on_tick_panel(int y);
//    void set_selected_scene(int track_index);
//    int on_scene_track(int y);
//    float get_stop_postion();
//private slots:
//    void slotRemoveItem(bool flag);
//
//};

//class media_panel :public QGraphicsRectItem
//{
//public:
//    media_panel(project_panel *parent = 0);
//    QRectF boundingRect() const override;
//    void paint(QPainter* painter,
//        const QStyleOptionGraphicsItem* option,
//        QWidget* widget = nullptr) override;
//protected:
//
//};

class common_track :public QWidget
{
    Q_OBJECT

public:
    common_track(QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
    QPoint current_pos;
    QPoint context_pos;
    QMenu* m_menu;
    float m_interval_prop=1;
    MOUSE_MOVE_MODE m_MMM = MOUSE_MOVE_MODE(0);
    float m_current_time = 0;//当前时间线进度
    int m_index = 0;
signals:
    void setCurrentTime(float ct);
};


class scene_track :public common_track
{
    Q_OBJECT
public:
    scene_track(QString name, QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
    void paintEvent(QPaintEvent* event) override;
    QString getName();
    void setIndex(int idx);
    bool hasInfo(scene_info* mi);
    void play(bool flag);
    std::vector<scene_info*> info_list;
    CJSection *outputSection;
    void udateOutputScene(CJSection *picture);
    int getIndex();
protected:
    void mousePressEvent(QMouseEvent* event) override;
private:
    QString m_name;
    float relative_frame_rate = 1;//相对帧率
    float m_interval_prop = 1;//时间和像素转换
    
protected:
    void dragEnterEvent(QDragEnterEvent* event) override;
    void dropEvent(QDropEvent* event) override;
    void dragMoveEvent(QDragMoveEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
signals:
    void set_Width(int width);
    void deleteInfo(int index);//删除info发送-1
public slots:
    void delete_info(bool);
};

class media_track :public common_track
{
    Q_OBJECT
public:
    media_track(QString name,float interval_prop,QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
    void paintEvent(QPaintEvent* event) override;
    void setIndex(int idx);
    bool hasInfo(media_info *mi);
    std::vector<media_info*> info_list;
    void play(bool flag);
    int getIndex();
private:
    QString m_name;   
    float m_interval_prop=1;
    float temp_buffer_length = -100;
    
protected:
    void dragEnterEvent(QDragEnterEvent* event) override;
    void dropEvent(QDropEvent* event) override;
    void dragMoveEvent(QDragMoveEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
protected:
    void mousePressEvent(QMouseEvent* event) override;
signals:
    void set_Width(int width);//resize完大小，手动发出信号
    void deleteInfo(int index);//删除info发送-1
public slots:
    void delete_info(bool);
};

class track_list_widget:public QWidget
{
    Q_OBJECT
public:
    track_list_widget(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
    void paintEvent(QPaintEvent *event) override;
    std::vector<scene_track*> scene_track_list;
    std::vector<media_track*> media_track_list;
    void setMarginWidth(const int&);           //设置鼠标可以在界面边缘多大范围内拖动改变界面大小
    void seResizable(bool);                    //设置是否可以拖动改变大小
    float m_interval_prop = 1;//取0-1连续值
    float relative_frame_rate = 1;
    float m_current_time = 0;//当前时间线进度
    void setCurrentTime(int time_interval);
    void play(bool flag); 
    void updateOutputScene(CJSection *m_picture);
    bool hasinfo();//判断track上是否有info
    QMenu * m_context_menu;
protected:
    void mousePressEvent(QMouseEvent* event) override;
public slots:
    void resetWidth(int width);
    void setCurrent(float);
    void infoDeleted(int index);
    void addMediaTrack(bool);
    void addSceneTrack(bool);
signals:
    void set_Width(int width);
    void set_Height(int height);
    void setCurrentTime(float ct);
    void addTrack(bool type);//添加的轨道类型 type=0是媒体型，=1是scene_track
};

class tick_panel :public QWidget
{
    Q_OBJECT
public:
    tick_panel(QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
    void paintEvent(QPaintEvent* event) override;
private:
    float m_interval_prop=1;
public slots:
    void resizeWidth(int width);    
};

class track_project_panel :public QWidget
{
    Q_OBJECT
public:
    track_project_panel(QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
    void paintEvent(QPaintEvent* event) override;
    void setTrackList(track_list_widget *tlw);
    float m_current_time = 0;//当前时间线进度
    void updateTracks();
    void deleteItem(int index);
protected:
    void mousePressEvent(QMouseEvent* event) override;
private:
    float m_interval_prop=1;//取0-1连续值
    track_list_widget* m_track_list;   
    //QVBoxLayout* m_verticallayout;
public slots:
    void set_Width(int width);
    void set_Height(int height);
    void setCurrent(float ct);
    void acceptAddTrack(bool);
};

class list_tick :public QWidget
{
    Q_OBJECT
public:
    list_tick(QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
    void paintEvent(QPaintEvent* event) override;
};



#endif // PROJECT_PANEL0_H
