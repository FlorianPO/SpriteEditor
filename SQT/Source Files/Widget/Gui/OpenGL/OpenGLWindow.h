#pragma once

#include "OpenGLWidget.h"

class OpenGLWindow : public OpenGLWidget
{
    Q_OBJECT
public:
    explicit OpenGLWindow(QWidget* parent = 0);
    void initializeGL() override;
    void resizeGL(int width, int height) override;
    void paintGL() override;
};


