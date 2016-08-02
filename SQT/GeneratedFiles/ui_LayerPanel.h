/********************************************************************************
** Form generated from reading UI file 'LayerPanel.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAYERPANEL_H
#define UI_LAYERPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LayerPanel
{
public:
    QFrame *Frame;
    QPushButton *Layer_del;
    QPushButton *Selection_del;
    QPushButton *Layer_fuse;
    QPushButton *Layer_new;
    QFrame *Layer_frame;

    void setupUi(QWidget *LayerPanel)
    {
        if (LayerPanel->objectName().isEmpty())
            LayerPanel->setObjectName(QStringLiteral("LayerPanel"));
        LayerPanel->resize(129, 809);
        Frame = new QFrame(LayerPanel);
        Frame->setObjectName(QStringLiteral("Frame"));
        Frame->setGeometry(QRect(0, 0, 129, 809));
        Frame->setFrameShape(QFrame::StyledPanel);
        Frame->setFrameShadow(QFrame::Raised);
        Layer_del = new QPushButton(Frame);
        Layer_del->setObjectName(QStringLiteral("Layer_del"));
        Layer_del->setGeometry(QRect(28, 4, 25, 25));
        QIcon icon;
        icon.addFile(QStringLiteral("Resources/Layers/layer_del.png"), QSize(), QIcon::Normal, QIcon::Off);
        Layer_del->setIcon(icon);
        Layer_del->setIconSize(QSize(23, 23));
        Layer_del->setAutoDefault(false);
        Layer_del->setFlat(true);
        Selection_del = new QPushButton(Frame);
        Selection_del->setObjectName(QStringLiteral("Selection_del"));
        Selection_del->setGeometry(QRect(100, 4, 25, 25));
        QIcon icon1;
        icon1.addFile(QStringLiteral("Resources/Selections/selec_del.png"), QSize(), QIcon::Normal, QIcon::Off);
        Selection_del->setIcon(icon1);
        Selection_del->setIconSize(QSize(23, 23));
        Selection_del->setAutoDefault(false);
        Selection_del->setFlat(true);
        Layer_fuse = new QPushButton(Frame);
        Layer_fuse->setObjectName(QStringLiteral("Layer_fuse"));
        Layer_fuse->setGeometry(QRect(52, 4, 25, 25));
        QIcon icon2;
        icon2.addFile(QStringLiteral("Resources/Layers/layer_fuse.png"), QSize(), QIcon::Normal, QIcon::Off);
        Layer_fuse->setIcon(icon2);
        Layer_fuse->setIconSize(QSize(23, 23));
        Layer_fuse->setAutoDefault(false);
        Layer_fuse->setFlat(true);
        Layer_new = new QPushButton(Frame);
        Layer_new->setObjectName(QStringLiteral("Layer_new"));
        Layer_new->setGeometry(QRect(4, 4, 25, 25));
        Layer_new->setText(QStringLiteral(""));
        QIcon icon3;
        icon3.addFile(QStringLiteral("Resources/Layers/layer_new.png"), QSize(), QIcon::Normal, QIcon::Off);
        Layer_new->setIcon(icon3);
        Layer_new->setIconSize(QSize(23, 23));
        Layer_new->setAutoDefault(false);
        Layer_new->setFlat(true);
        Layer_frame = new QFrame(Frame);
        Layer_frame->setObjectName(QStringLiteral("Layer_frame"));
        Layer_frame->setGeometry(QRect(0, 32, 129, 777));
        Layer_frame->setFrameShape(QFrame::StyledPanel);
        Layer_frame->setFrameShadow(QFrame::Raised);

        retranslateUi(LayerPanel);

        Layer_del->setDefault(false);
        Selection_del->setDefault(false);
        Layer_fuse->setDefault(false);
        Layer_new->setDefault(false);


        QMetaObject::connectSlotsByName(LayerPanel);
    } // setupUi

    void retranslateUi(QWidget *LayerPanel)
    {
        LayerPanel->setWindowTitle(QApplication::translate("LayerPanel", "Form", 0));
        Layer_del->setText(QString());
        Selection_del->setText(QString());
        Layer_fuse->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LayerPanel: public Ui_LayerPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAYERPANEL_H
