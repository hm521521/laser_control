#ifndef QSGCOLORLINESTRIPMATERIAL_H
#define QSGCOLORLINESTRIPMATERIAL_H

#include <QObject>
#include <QSGMaterial>
#include <QColor>

class QSGColorLineStripMaterial : public QSGMaterial
{
public:
    QSGColorLineStripMaterial();
    //该函数由场景图调用以返回每个子类的唯一实例
    QSGMaterialType *type() const override;
    //对于场景图中存在的每种材质类型，createShader只会被调用一次，并将在内部缓存
    QSGMaterialShader *createShader() const override;
    int compare(const QSGMaterial *other) const override;

};

#endif // QSGCOLORLINESTRIPMATERIAL_H
