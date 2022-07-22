#include "Rectangle.h"

Rectangle::Rectangle(void)
{

}

Rectangle::~Rectangle(void)
{

}

Rectangle::Rectangle(Vector position, Vector size, int color)
{
	this->position = position;
	this->size = size;
	this->color = color;
}

void Rectangle::draw(Console &con, int color)
{
	int x_start, x_end, y_start, y_end;
	
	x_start = (position.getX());
	x_end = (position.getX() + size.getX());
	y_start = (position.getY());
	y_end =(position.getY() + size.getY());
	
	for (int x = x_start; x < x_end; ++x )
	{
		for (int y = y_start; y < y_end; ++y)
		{
			con.SetColor(x, y, color);
			con.PrintChar(x, y, ' ');
		}
	}

}

void Rectangle::draw(Console&con)
{
	draw(con, color);
}

Vector Rectangle::GetPosition()
{
	return position;
}

