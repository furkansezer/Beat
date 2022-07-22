#include "Bar.h"

Bar::Bar(void)
{
}

Bar::~Bar(void)
{
}

Bar::Bar(Vector position, Vector size, int color)
{
	this->position = position;
	this->size= size;
	this->color=color;
}

void Bar::SetBar(Vector position, Vector size, int color)
{
	this->position = position;
	this->size= size;
	this->color=color;
}

void Bar::draw(Console &con, int color)
{
	int x_start, x_end, y;
	
	x_start = (position.getX());
	x_end = (position.getX() + size.getX());
	y = (position.getY());
	
	for (int x = x_start; x < x_end; ++x )
	{
			con.SetColor(x, y, color);
			con.PrintChar(x, y, ' ');
	}

}

void Bar::erase(Console &con)
{
	this->draw(con, con.rgb_b(0,0,0,0));
}

void Bar::move(Console &con, char ch)
{
	erase(con);
	if(ch == 'k')
		position += Vector(-3, 0);
	else if(ch== 'l')
		position += Vector(3,0);
	draw(con);
}

void Bar::draw(Console &con)
{
	this->draw(con, color);
}

Vector Bar::GetSize()
{
	return size;
}

void Bar::Smart(Rectangle ball, Console &con)
{
		if((position.getX()+6)>(ball.GetPosition()).getX())
			this->move(con, 'k');
		else if((position.getX()+7)<(ball.GetPosition()).getX())
			this->move(con, 'l');
}



