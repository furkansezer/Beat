#pragma once
#include "rectangle.h"
//#include "Ball.h"

class Bar : public Rectangle
{
protected:
public:
	Bar(void);
	~Bar(void);
	Bar(Vector position, Vector size, int color);
	void SetBar(Vector position, Vector size, int color);
	void draw(Console &con, int color);
	void draw(Console &con);
	void erase(Console &con);
	Vector GetSize();
	void move(Console &con, char ch); // i)erase ii)get new position iii) draw at new position
	void Smart(Rectangle ball, Console &con); // move bar of the computerplayer according to current position of the ball
};

