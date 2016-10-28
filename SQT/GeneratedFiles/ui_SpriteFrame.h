/********************************************************************************
** Form generated from reading UI file 'SpriteFrame.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPRITEFRAME_H
#define UI_SPRITEFRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SpriteFrame
{
public:
    QPushButton *SpriteFrameList_new;
    QPushButton *SpriteFrameList_del;
    QPushButton *SpriteFrame_transf;

    void setupUi(QWidget *SpriteFrame)
    {
        if (SpriteFrame->objectName().isEmpty())
            SpriteFrame->setObjectName(QStringLiteral("SpriteFrame"));
        SpriteFrame->resize(675, 549);
        SpriteFrameList_new = new QPushButton(SpriteFrame);
        SpriteFrameList_new->setObjectName(QStringLiteral("SpriteFrameList_new"));
        SpriteFrameList_new->setGeometry(QRect(4, 4, 25, 25));
        SpriteFrameList_new->setFocusPolicy(Qt::NoFocus);
        SpriteFrameList_new->setText(QStringLiteral(""));
        QIcon icon;
        icon.addFile(QStringLiteral("Resources/Layers/layer_new.png"), QSize(), QIcon::Normal, QIcon::Off);
        SpriteFrameList_new->setIcon(icon);
        SpriteFrameList_new->setIconSize(QSize(23, 23));
        SpriteFrameList_new->setAutoDefault(false);
        SpriteFrameList_new->setFlat(true);
        SpriteFrameList_del = new QPushButton(SpriteFrame);
        SpriteFrameList_del->setObjectName(QStringLiteral("SpriteFrameList_del"));
        SpriteFrameList_del->setGeometry(QRect(28, 4, 25, 25));
        SpriteFrameList_del->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QStringLiteral("Resources/Layers/layer_del.png"), QSize(), QIcon::Normal, QIcon::Off);
        SpriteFrameList_del->setIcon(icon1);
        SpriteFrameList_del->setIconSize(QSize(23, 23));
        SpriteFrameList_del->setAutoDefault(false);
        SpriteFrameList_del->setFlat(true);
        SpriteFrame_transf = new QPushButton(SpriteFrame);
        SpriteFrame_transf->setObjectName(QStringLiteral("SpriteFrame_transf"));
        SpriteFrame_transf->setGeometry(QRect(52, 4, 25, 25));
        SpriteFrame_transf->setFocusPolicy(Qt::NoFocus);
        QIcon icon2;
        icon2.addFile(QStringLiteral("Resources/Tools/tool_move.png"), QSize(), QIcon::Normal, QIcon::Off);
        SpriteFrame_transf->setIcon(icon2);
        SpriteFrame_transf->setIconSize(QSize(23, 23));
        SpriteFrame_transf->setAutoDefault(false);
        SpriteFrame_transf->setFlat(true);

        retranslateUi(SpriteFrame);

        SpriteFrameList_new->setDefault(false);
        SpriteFrameList_del->setDefault(false);
        SpriteFrame_transf->setDefault(false);


        QMetaObject::connectSlotsByName(SpriteFrame);
    } // setupUi

    void retranslateUi(QWidget *SpriteFrame)
    {
        SpriteFrame->setWindowTitle(QApplication::translate("SpriteFrame", "Form", 0));
        SpriteFrameList_del->setText(QString());
        SpriteFrame_transf->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SpriteFrame: public Ui_SpriteFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPRITEFRAME_H
