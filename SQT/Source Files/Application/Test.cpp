#include "App.h"

void App::test() {
	/*NEW (my_var_name, App, 
		(NULL), 
		(1, 2)
	);

	my_var_name->property("prout");*/
}

/*bool LayerList::eventFilter(QObject* object, QEvent* event) {
	if (object == sprite_view && event->type() == QEvent::MouseButtonPress)
		mousePressEvent(static_cast<QMouseEvent*>(event));
	return false;
}*/

/*const sf::Uint8* raw_data = layer->getImage()->getPixelsPtr();
QImage myImage = QImage(ARG_VECTOR(layer->getSize()), QImage::Format_ARGB32);
for (int y = 0; y < myImage.height(); y++)
	memcpy(myImage.scanLine(y), raw_data + y * myImage.bytesPerLine(), myImage.bytesPerLine());
myImage = myImage.rgbSwapped();

myLabel->setPixmap(QPixmap::fromImage(myImage));*/