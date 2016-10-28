#include "SpriteList.h"

#include "Source Files/Widget/Various/FLineEdit/FLineEdit.h"
#include "Source Files/Widget/Various/Layout/List.h"
#include "SpriteFrame.h"
#include "Source Files/Application/Animation/Animation.h"

QHash<Animation*, SpriteList*> SpriteList::hash;

SpriteList::SpriteList(QWidget* parent, List& list, SignalListObject& binded_object) : ListObject(parent, &binded_object) {
	ui.setupUi(this);
	show();

	anim = static_cast<Animation*>(&binded_object);
	hash[anim] = this;

	line_edit = new FLineEdit(this);
	line_edit->setGeometry(QRect(28, 4, 80, 25));
	line_edit->setText(anim->getName());
	line_edit->show();

	sprite_frame = new SpriteFrame(parent, *anim, *this);
	sprite_frame->move(width(), 0);
	sprite_frame->hide();

	QObject::connect(anim, &Animation::animationChanged, [&](){ list.selectOne(*this); });
	QObject::connect(&list, SIGNAL(noMoreOneObjectSelected()), sprite_frame, SLOT(hide()));
	QObject::connect(this, SIGNAL(unselected()), sprite_frame, SLOT(hide()));
	QObject::connect(this, SIGNAL(dropped()), sprite_frame, SLOT(hide()));
	QObject::connect(anim, &Animation::nameChanged, [this](const QString& name){ line_edit->setText(name); });
	QObject::connect(line_edit, &QLineEdit::textChanged, [this](const QString& text){ anim->setName(text); });

	QObject::connect(anim, &Animation::animationVisible, [&](){ ui.check_box->setChecked(true); });
	QObject::connect(anim, &Animation::animationUnvisible, [&](){ ui.check_box->setChecked(false); });
	QObject::connect(ui.check_box, &QAbstractButton::clicked, [&](bool clicked) { if (clicked) anim->show(); else anim->hide(); });

	ui.check_box->setChecked(true);
}

SpriteList::~SpriteList() {
	delete line_edit;
	delete sprite_frame;
	hash.erase(hash.find(anim));
}

SpriteList& SpriteList::getFromAnimation(Animation& anim) {
	return *hash[&anim];
}

void SpriteList::setName(const QString& name) {
	line_edit->setText(name);
}