#include "Bonus.h"


Bonus::Bonus(void)
{
	size=Vector(1,1);
}


Bonus::~Bonus(void)
{
}

void Bonus::draw(Console &con, int color)
{
	int x, y;
	
	x = (position.getX());
	y = (position.getY());
			
	con.SetColor(x, y, color);
	con.PrintChar(x, y, ' ');
}

void Bonus::erase(Console &con)
{
	this->draw(con, con.rgb_b(0,0,0,0));
}

void Bonus::draw(Console &con)
{
	this->draw(con, color);
}


