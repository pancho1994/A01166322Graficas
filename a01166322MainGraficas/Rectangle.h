#pragma once
#include <string>
class Rectangle
{
public:
	Rectangle();
	Rectangle(float r, float h);

	float getWidth();
	void setWidth(float w);
	float getHeight();
	void setHeight(float w);
	float getArea();
	float getPerimeter();

private:
	float _width = 1.0f; 
	float _height = 1.0f;
};