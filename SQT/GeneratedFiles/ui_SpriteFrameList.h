/********************************************************************************
** Form generated from reading UI file 'SpriteFrameList.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPRITEFRAMELIST_H
#define UI_SPRITEFRAMELIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SpriteFrameList
{
public:
    QFrame *frame;
    QFrame *frame_view;
    QPushButton *SpriteFrameList_rect;

    void setupUi(QWidget *SpriteFrameList)
    {
        if (SpriteFrameList->objectName().isEmpty())
            SpriteFrameList->setObjectName(QStringLiteral("SpriteFrameList"));
        SpriteFrameList->resize(198, 198);
        frame = new QFrame(SpriteFrameList);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 110, 131));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame_view = new QFrame(frame);
        frame_view->setObjectName(QStringLiteral("frame_view"));
        frame_view->setGeometry(QRect(5, 5, 100, 100));
        frame_view->setFrameShape(QFrame::StyledPanel);
        frame_view->setFrameShadow(QFrame::Raised);
        SpriteFrameList_rect = new QPushButton(frame);
        SpriteFrameList_rect->setObjectName(QStringLiteral("SpriteFrameList_rect"));
        SpriteFrameList_rect->setGeometry(QRect(27, 105, 25, 25));
        SpriteFrameList_rect->setFocusPolicy(Qt::NoFocus);
        SpriteFrameList_rect->setText(QStringLiteral(""));
        QIcon icon;
        icon.addFile(QStringLiteral("Resources/Icon/sprite_frame_list_rect.png"), QSize(), QIcon::Normal, QIcon::Off);
        SpriteFrameList_rect->setIcon(icon);
        SpriteFrameList_rect->setIconSize(QSize(23, 23));
        SpriteFrameList_rect->setAutoDefault(false);
        SpriteFrameList_rect->setFlat(true);

        retranslateUi(SpriteFrameList);

        SpriteFrameList_rect->setDefault(false);


        QMetaObject::connectSlotsByName(SpriteFrameList);
    } // setupUi

    void retranslateUi(QWidget *SpriteFrameList)
    {
        SpriteFrameList->setWindowTitle(QApplication::translate("SpriteFrameList", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class SpriteFrameList: public Ui_SpriteFrameList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPRITEFRAMELIST_H
