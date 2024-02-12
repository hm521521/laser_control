#ifndef DND_SCENE_DATA_OBJECT_H
#define DND_SCENE_DATA_OBJECT_H

#include <QMimeData>
#include"main_panel.h"

class dnd_scene_data_object : public QMimeData
{
public:
    //dnd_scene_data_object();
    dnd_scene_data_object(single_scene *scene);

    single_scene *m_scene;
};

#endif // DND_SCENE_DATA_OBJECT_H
