#pragma once
#include "Console.h"
#include "Vector.h"

class Rectangle
{
	
protected:
	int color;
	Vector size, position;
public:
	Rectangle(void); 
	Rectangle(Vector position, Vector size, int color);
	~Rectangle(void);
	void draw(Console&con, int color);
	void draw(Console&con);
	Vector GetPosition();
};

