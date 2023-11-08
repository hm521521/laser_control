#ifndef QSGCOLORLINESTRIP_H
#define QSGCOLORLINESTRIP_H

#include <QQuickItem>

class QSGColorLineStrip : public QQuickItem
{
    Q_OBJECT
    QML_ELEMENT
public:
    QSGColorLineStrip(QQuickItem *parent = nullptr);

    QSGNode *updatePaintNode(QSGNode *oldNode, UpdatePaintNodeData *updatePaintNodeData) override;

};

#endif // QSGCOLORLINESTRIP_H
