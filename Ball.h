#pragma once
#include "rectangle.h"
#include "Bar.h"
#include "Player.h"
#include "Bonus.h"

class Ball :public Rectangle
{
	Vector velocity;
public:
	
	Ball(Console&con);
	~Ball(void);
	void draw(Console &con, int color);
	void draw(Console &con);
	void erase(Console &con);
	void move(Console &con);         // Ball uses that function to move when it is not stuck with the bar.
	void move(Console &con, char ch);// Ball uses that function to move when it is  stuck with the bar.
	void stop();                     // This function sets velocity to zero.
	bool IsInTouchWithBar(Bar &bar);
	bool IsInTouchWithBonus(Bonus *bonus);
	bool IsOutOfScope();
	void Reposition(int x); // Ball repositioned with same position but 3 different velocity (towards up or down and random)
	void Shoot(char ch); // Direction of the ball is specified with q, w, e char inputs or r char input for random choice of computer
	bool WhoShot(); // controls vertical velocity of the ball
};

