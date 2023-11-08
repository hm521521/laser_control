#include "qsgcolorlinestripmaterial.h"
#include "qopenglcontext.h"
#include "qopenglextrafunctions.h"
#include "qopenglfunctions.h"

#include <QSGMaterialShader>
class MyMaterialShader : public QSGMaterialShader
{
public:
    MyMaterialShader(){}

    const char *vertexShader() const override
    {
        return R"(
#version 330 core
attribute highp vec4 vertexCoord;
attribute highp vec4 vertexColor;
uniform highp mat4 matrix;
uniform highp float opacity;
flat out lowp vec4 color;
void main()
{
    gl_Position = matrix * vertexCoord;
    color = vec4(vertexColor.rgb*vertexColor.a,vertexColor.a) * opacity;
}
)";
    }

    const char *fragmentShader() const override
    {
        return R"(
#version 330 core
flat in lowp vec4 color;
void main()
{
    gl_FragColor = color;
}
)";
    }

    //刷新的时候会调用此函数，通过判断状态来决定哪些需要更新
    void updateState(const RenderState &state, QSGMaterial *newEffect, QSGMaterial *oldEffect) override
    {
        Q_UNUSED(newEffect)
        Q_UNUSED(oldEffect)
        //QSG混合模式为glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA)，提供了预乘混合
        //FlatColorMaterialShader::updateState中预乘了透明度，但现在我把颜色作为顶点属性
        //所glsl改为：color = vec4(vertexColor.rgb*vertexColor.a,vertexColor.a) * opacity;
//            if(state.context()&&state.context()->functions()){

//            }
            //启用LINE_SMOOTH或者MSAA都会导致横向/竖向直线变胖
            //if(state.context()&&state.context()->functions()){
            //    //state.context()->functions()->glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            //    state.context()->functions()->glEnable(GL_BLEND);
            //    state.context()->functions()->glEnable(GL_LINE_SMOOTH);
            //    state.context()->functions()->glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
            //}
        //state.context()->extraFunctions()->glDrawElementsInstanced();
        if (state.isOpacityDirty()){
            qDebug()<<"-------------isOpacityDirty";
            program()->setUniformValue(opacityId, state.opacity());
        }
        if (state.isMatrixDirty()){
            qDebug()<<"-------------isMatrixDirty";
            program()->setUniformValue(matrixId, state.combinedMatrix());
        }
        if(state.isCachedMaterialDataDirty()){
            qDebug()<<"-------------isCachedMaterialDataDirty";
        }
    }

    //顶点属性名，数组最后一个填nullptr
    //对应geometry的vertexData数据结构
    char const *const *attributeNames() const override
    {
        static const char *const attr[] = { "vertexCoord", "vertexColor", nullptr };
        return attr;
    }

private:
    void initialize() override
    {
        QSGMaterialShader::initialize();
        opacityId = program()->uniformLocation("opacity");
        matrixId = program()->uniformLocation("matrix");
    }

private:
    int opacityId;
    int matrixId;
};


QSGColorLineStripMaterial::QSGColorLineStripMaterial()
{
    setFlag(Blending, true);
}

QSGMaterialType *QSGColorLineStripMaterial::type() const
{
    static QSGMaterialType type;
    return &type;
}

QSGMaterialShader *QSGColorLineStripMaterial::createShader() const
{
    return new MyMaterialShader;
}

int QSGColorLineStripMaterial::compare(const QSGMaterial *other) const
{
    return 0;
}
