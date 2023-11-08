#include "qsgcolorlinestrip.h"
#include "qsgcolorlinestripmaterial.h"

#include <QSGGeometryNode>

QSGColorLineStrip::QSGColorLineStrip(QQuickItem *parent)
    : QQuickItem(parent)

{
    setFlag(ItemHasContents, true);
}

QSGNode *QSGColorLineStrip::updatePaintNode(QSGNode *oldNode, UpdatePaintNodeData *updatePaintNodeData)
{
    Q_UNUSED(updatePaintNodeData);
    QSGGeometryNode *node = nullptr;
    QSGGeometry *geometry = nullptr;
    if (!oldNode) {
        node = new QSGGeometryNode;
        geometry = new QSGGeometry(QSGGeometry::defaultAttributes_ColoredPoint2D(), 3);
        //线宽
        geometry->setLineWidth(1);
        geometry->setDrawingMode(QSGGeometry::DrawLineStrip);
        node->setGeometry(geometry);
        node->setFlag(QSGNode::OwnsGeometry);

        QSGColorLineStripMaterial *material = new QSGColorLineStripMaterial;
        node->setMaterial(material);
        node->setFlag(QSGNode::OwnsMaterial);
    } else {
        //初始化完成后，后面的刷新会进入到这个逻辑里
        //这里我们可以更新geometry
        node = static_cast<QSGGeometryNode *>(oldNode);
        geometry = node->geometry();
        //可以重置坐标点个数，比如刷新了数据，调用update，就可以在此处重新设置
        //geometry->allocate(2);
    }
    QSGGeometry::ColoredPoint2D *vertices = geometry->vertexDataAsColoredPoint2D();
    vertices[0].set(0,-width()*0.4, 255,0, 0, 255); //点1左上角
    vertices[1].set(width()*0.5,height()*0.5, 0,255,0,255); //点2右下角
    vertices[2].set(width()*0.6,height()*0.7, 0,0,255,255);

    node->markDirty(QSGNode::DirtyGeometry);
    return node;
}
