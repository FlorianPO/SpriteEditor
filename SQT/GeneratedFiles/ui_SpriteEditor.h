/********************************************************************************
** Form generated from reading UI file 'SpriteEditor.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPRITEEDITOR_H
#define UI_SPRITEEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SpriteEditor
{
public:
    QPushButton *Sprite_del;
    QPushButton *Sprite_new;
    QFrame *frame;
    QPushButton *Sprite_new_grid;

    void setupUi(QWidget *SpriteEditor)
    {
        if (SpriteEditor->objectName().isEmpty())
            SpriteEditor->setObjectName(QStringLiteral("SpriteEditor"));
        SpriteEditor->resize(400, 477);
        Sprite_del = new QPushButton(SpriteEditor);
        Sprite_del->setObjectName(QStringLiteral("Sprite_del"));
        Sprite_del->setGeometry(QRect(52, 4, 25, 25));
        Sprite_del->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QStringLiteral("Resources/Layers/layer_del.png"), QSize(), QIcon::Normal, QIcon::Off);
        Sprite_del->setIcon(icon);
        Sprite_del->setIconSize(QSize(23, 23));
        Sprite_del->setAutoDefault(false);
        Sprite_del->setFlat(true);
        Sprite_new = new QPushButton(SpriteEditor);
        Sprite_new->setObjectName(QStringLiteral("Sprite_new"));
        Sprite_new->setGeometry(QRect(4, 4, 25, 25));
        Sprite_new->setFocusPolicy(Qt::NoFocus);
        Sprite_new->setText(QStringLiteral(""));
        QIcon icon1;
        icon1.addFile(QStringLiteral("Resources/Layers/layer_new.png"), QSize(), QIcon::Normal, QIcon::Off);
        Sprite_new->setIcon(icon1);
        Sprite_new->setIconSize(QSize(23, 23));
        Sprite_new->setAutoDefault(false);
        Sprite_new->setFlat(true);
        frame = new QFrame(SpriteEditor);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(4, 32, 217, 441));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        Sprite_new_grid = new QPushButton(SpriteEditor);
        Sprite_new_grid->setObjectName(QStringLiteral("Sprite_new_grid"));
        Sprite_new_grid->setGeometry(QRect(28, 4, 25, 25));
        Sprite_new_grid->setFocusPolicy(Qt::NoFocus);
        QIcon icon2;
        icon2.addFile(QStringLiteral("Resources/Icon/sprite_new_grid.png"), QSize(), QIcon::Normal, QIcon::Off);
        Sprite_new_grid->setIcon(icon2);
        Sprite_new_grid->setIconSize(QSize(23, 23));
        Sprite_new_grid->setAutoDefault(false);
        Sprite_new_grid->setFlat(true);

        retranslateUi(SpriteEditor);

        Sprite_del->setDefault(false);
        Sprite_new->setDefault(false);
        Sprite_new_grid->setDefault(false);


        QMetaObject::connectSlotsByName(SpriteEditor);
    } // setupUi

    void retranslateUi(QWidget *SpriteEditor)
    {
        SpriteEditor->setWindowTitle(QApplication::translate("SpriteEditor", "Form", 0));
        Sprite_del->setText(QString());
        Sprite_new_grid->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SpriteEditor: public Ui_SpriteEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPRITEEDITOR_H
