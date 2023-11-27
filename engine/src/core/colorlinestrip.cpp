#include "colorlinestrip.h"






ColorLineStrip::ColorLineStrip(QQuickItem *p)
    :QQuickFramebufferObject{p}
{
    QObject::connect(this,&ColorLineStrip::widthChanged, this, [this]{
            this->update();
    });
    QObject::connect(this,&ColorLineStrip::heightChanged, this, [this]{
        this->update();
    });
}

QQuickFramebufferObject::Renderer *ColorLineStrip::createRenderer() const
{
    return new ColorLineStripRenderer();
}

ColorLineStripRenderer::ColorLineStripRenderer()
{
    m_func.initializeOpenGLFunctions();

    m_program.addCacheableShaderFromSourceCode(QOpenGLShader::Vertex,R"(
    #version 330 core
    attribute  vec2 vertexCoord;
    attribute  vec4 vertexColor;
    attribute  vec2 offset;
    flat out  vec4 color;
    uniform int flag;
    uniform float scale;
    uniform vec2 whscale;
    uniform vec2 xyoffset;
    void main()
    {
        if(flag==1){ // line strip
            gl_Position = vec4(2.0*scale*(vertexCoord.xy+xyoffset)*whscale-scale*whscale, 0, 1);
            color = vec4(vertexColor.rgb,1);
        }else if(flag==2){ // inst rect
            gl_Position = vec4(2.0*(vertexCoord.xy+(xyoffset+offset)*scale*whscale)-scale*whscale, 0, 1);
            color = vec4(1,1,1,1);
        }else if(flag==3){ // inst filled poly
            gl_Position = vec4(2.0*(vertexCoord.xy+(xyoffset+offset)*scale*whscale)-scale*whscale, 0, 1);
            color = vec4(vertexColor.r,(1-vertexColor.r), (1-vertexColor.r), 1);
        }

    }
    )");
    m_program.addCacheableShaderFromSourceCode(QOpenGLShader::Fragment,R"(
    #version 330 core
    flat in  vec4 color;
    void main()
    {
        gl_FragColor = color;
    }
    )");

    m_program.bindAttributeLocation("vertexCoord", 0);
    m_program.bindAttributeLocation("vertexColor", 1);
    m_program.bindAttributeLocation("offset", 2);
    m_program.link();
    m_needUpdate = true;
}


void ColorLineStripRenderer::render()
{
    if(!m_needUpdate) return;
    m_needUpdate = false;

    QOpenGLExtraFunctions *f = QOpenGLContext::currentContext()->extraFunctions();

    m_program.bind();

    m_program.enableAttributeArray(0);
    m_program.enableAttributeArray(1);
    m_program.enableAttributeArray(2);

//    m_points=QVector<qreal>({
//        0.1,0.1,1,1,1,1,
//        0.5,0.5,1,0,1,1
//    });
    int pcnt = m_points.size()/6;
    float* coords = new float[pcnt<<1];
    float* cols = new float[pcnt<<2];
    for(int i=0;i<pcnt;i++){
        int b = i*6;
        coords[i*2] = (float)m_points.at(b);
        coords[i*2+1] = (float)m_points.at(b+1);
        cols[i*4] = (float)m_points.at(b+2);
        cols[i*4+1] = (float)m_points.at(b+3);
        cols[i*4+2] = (float)m_points.at(b+4);
        cols[i*4+3] = (float)m_points.at(b+5);
    }
    float rectSizeW = 6/m_width;
    float rectSizeH = 6/m_height;
    float tinySizeW = rectSizeW*0.77;
    float tinySizeH = rectSizeW*0.77;
    float smallRect[] = {
        -rectSizeW, -rectSizeH,
        +rectSizeW, -rectSizeH,
        +rectSizeW, +rectSizeH,
        -rectSizeW, +rectSizeH
    };
    float tinyRect[] = {
        -tinySizeW, -tinySizeH,
        +tinySizeW, -tinySizeH,
        +tinySizeW, +tinySizeH,
        -tinySizeW, +tinySizeH
    };
    float colss[] = {
        1, 1, 1, 1,
        1, 0, 0, 1,
        0, 1, 0, 1,
        0, 0, 1, 1
    };


    float values[] = {
        0.97, 0.97,
        0.5, 0.9,
        0.9, 0.5,
        0.1, 0.1
    };

    float off[] = {
        0.0, 0.0,
        0.5, 0.5,
        0.9, 0.9,
        0.3, 0.3
    };
    float rectCols[] = {
                        1, 1, 1, 1,
                        1, 0, 1, 1,
                        1, 1, 0, 1,
                        0, 0, 1, 1
    };

    // This example relies on (deprecated) client-side pointers for the vertex
    // input. Therefore, we have to make sure no vertex buffer is bound.
    f->glBindBuffer(GL_ARRAY_BUFFER, 0);

    m_program.setAttributeArray(0, GL_FLOAT, coords, 2, 2*sizeof(GL_FLOAT));
    m_program.setAttributeArray(1, GL_FLOAT, cols, 4, 4*sizeof(GL_FLOAT));
    m_program.setAttributeArray(2, GL_FLOAT, coords, 2, 2*sizeof(GL_FLOAT));

    //f->glViewport(60, 70,720, 640);

    //f->glVertexAttribPointer(2, 2,GL_FLOAT, GL_FALSE,4,  0);
    //f->glVertexAttribDivisor(2, 1);

    //f->glDepthMask(true);

    f->glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    f->glClear(GL_COLOR_BUFFER_BIT);
    //f->glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //f->glEnable(GL_DEPTH_TEST);

    f->glEnable(GL_BLEND);
    f->glBlendFunc(GL_SRC_ALPHA, GL_ONE);

    m_program.setUniformValue("whscale", (float)m_wscale, (float)m_hscale);
    m_program.setUniformValue("xyoffset", (float)m_offsetX, (float)m_offsetY);
    m_program.setUniformValue("scale", (float)m_scale);
    m_program.setUniformValue("flag", 1);
    f->glDrawArrays(GL_LINE_STRIP, 0, pcnt);
    if(!m_linesOnly){
        m_program.setAttributeArray(0, GL_FLOAT, smallRect, 2, 2*sizeof(GL_FLOAT));
        //m_program.setAttributeArray(1, GL_FLOAT, rectCols, 4, 4*sizeof(GL_FLOAT));
        f->glVertexAttribDivisor(1, 1);
        f->glVertexAttribDivisor(2, 1);
        m_program.setUniformValue("flag", 2);
        f->glDrawArraysInstanced(GL_LINE_LOOP, 0, 4, pcnt);

        m_program.setAttributeArray(0, GL_FLOAT, tinyRect, 2, 2*sizeof(GL_FLOAT));
        m_program.setUniformValue("flag", 3);
        f->glDrawArraysInstanced(GL_POLYGON, 0, 4, pcnt);
    }


    m_program.disableAttributeArray(0);
    m_program.disableAttributeArray(1);
    m_program.disableAttributeArray(2);
    f->glVertexAttribDivisor(1, 0);
    f->glVertexAttribDivisor(2, 0);

    m_program.release();

    delete [] coords;
    delete [] cols;

    // Not strictly needed for this example, but generally useful for when
    // mixing with raw OpenGL.
    //QQuickWindow::resetOpenGLState(); // will be white screen

    //qDebug()<<"..";
    update();
}

void ColorLineStripRenderer::synchronize(QQuickFramebufferObject *item)
{
    auto qItem = ((ColorLineStrip*)item);
    if(qItem==NULL) {
        qDebug()<<" ColorLineStrip Item == NULL! ";
        return;
    }
    m_linesOnly = qItem->linesOnly();
    m_points = qItem->pointsData();
    m_width = qItem->width();
    m_height = qItem->height();
    m_scale = qItem->scale();
    m_offsetX = qItem->offsetX();
    m_offsetY = qItem->offsetY();
    if(m_width<m_height){
        m_wscale = 1;
        m_hscale = m_width/m_height;
    }else{
        m_hscale = 1;
        m_wscale = m_height/m_width;
    }
    m_needUpdate = true;
}

QOpenGLFramebufferObject *ColorLineStripRenderer::createFramebufferObject(const QSize &size)
{
    //QOpenGLFramebufferObjectFormat format;
    //format.setAttachment(QOpenGLFramebufferObject::CombinedDepthStencil);
    return new QOpenGLFramebufferObject(size);
}


