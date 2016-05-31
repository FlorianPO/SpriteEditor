#pragma once

#include <QtOpenGL>
#include <QGLWidget>

class OpenGLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit OpenGLWidget(QWidget *parent=NULL, char *name=NULL, int framesPerSecond=0);
    virtual void initializeGL() override = 0;
    virtual void resizeGL(int width, int height) override = 0;
    virtual void paintGL() override = 0;

    virtual void keyPressEvent(QKeyEvent *keyEvent) override;
        
public slots:
    virtual void timeOutSlot();

private:
    QTimer *t_Timer;
};
