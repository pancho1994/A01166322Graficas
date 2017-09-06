#include "Rectangle.h"
//rectangle
Rectangle::Rectangle() {
	_width = 1.0;
	_height = 1.0;
	

}
Rectangle::Rectangle(float w, float h) {
	_width = 1.0f;
	_height = 1.0f;
}

float Rectangle::getWidth() {
	return _width;
}
