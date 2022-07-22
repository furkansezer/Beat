#include "Vector.h"

Vector::Vector(int x, int y) : x(x) , y(y) {}



Vector Vector::operator=(Vector &vec)
{
	x = vec.x;
	y = vec.y;
	return *this;
}

Vector Vector::operator+=(Vector &vec)
{
	x += vec.x;
	y += vec.y;
	return *this;
}

int Vector::getX()
{
	return x;
}

int Vector::getY()
{
	return y;
}
