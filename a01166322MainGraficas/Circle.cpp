#include "Circle.h"

Circle::Circle() {
	_radius = 1.0;
	_color = "red";

}
Circle::Circle(double r) {
	_radius = r;
	_color = "red";
}

double Circle::getRadius() {
	return _radius;
}
double Circle::getArea() {
	return 3.14159 * _radius * _radius;
}

void Circle::setRadius(double r) {
	_radius = r;

}

void Circle::setColor(std::string c) {
	_color = c;

}

std::string Circle::getColor() {
	return _color;
}

Circle::Circle(double r, std::string c) {
	_radius = r;
	_color = c;
}