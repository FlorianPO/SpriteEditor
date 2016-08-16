#include "State2Button.h"

#include "Source Files/Application/Resource/ResourceController.h"

State2Button::State2Button(QWidget* parent, QString* path_enabled, QString* path_disabled, bool active) : QPushButton(parent) {
	setFlat(true);
	setFocusPolicy(Qt::NoFocus);
	resize(QSize(25, 25));
	setIconSize(QSize(23, 23));

	if (path_enabled != NULL)
		iconEnabled = new QIcon(RES->directory_qt + *path_enabled);
	if (path_disabled != NULL)
		iconDisabled = new QIcon(RES->directory_qt + *path_disabled);

	if (active)
		enable();
	else
		disable();

	QObject::connect(this, SIGNAL(clicked()), this, SLOT(buttonClicked()), Qt::DirectConnection);
}

void State2Button::buttonClicked() {
	if (!state) {
		enable();
		emit enabled();
	}
	else {
		disable();
		emit disabled();
	}
}

void State2Button::enable() {
	state = true;
	if (iconEnabled != NULL)
		setIcon(*iconEnabled);
	else
		setIcon(QIcon());
}

void State2Button::disable() {
	state = false;
	if (iconDisabled != NULL)
		setIcon(*iconDisabled);
	else
		setIcon(QIcon());
}