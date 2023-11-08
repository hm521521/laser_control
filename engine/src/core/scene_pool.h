#ifndef SCENE_POOL_H
#define SCENE_POOL_H

#include <QMainWindow>
#include<QUrl>

#include"effect.h"

class single_scene: public QVector<effect*>//一组动画的所有信息
{
public:
    explicit single_scene();
    ~single_scene();
    void setname(QString name);
    void render(CJSection * section,int time);
    int max_frame_length();
    single_scene& operator=(single_scene& other);
    QString get_name();
private:
    QString m_name;
    void clearup();
};

class scene_pool : public QVector<single_scene*>//所有动画的信息
{
public:
    scene_pool(QWidget *parent=0);
    ~scene_pool();
    void read(QUrl url);
    void readSinglePage(QUrl url,int page=0);
    void clearup();
    int total_page=0;
    int current_page=0;
    QString m_name="defaut";
    QUrl m_url;
private:
    single_scene *m_scene;
    effect *m_effect;

};






#endif // SCENE_POOL_H
