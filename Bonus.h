#pragma once
#include "rectangle.h"
#include "Player.h"

class Bonus : public Rectangle
{
protected:
public:
	Bonus(void);
	~Bonus(void);
	void draw(Console &con, int color);
	void draw(Console &con);
	void erase(Console &con);
	virtual void ExecuteBonus(Player *player, Console &con)=0;
};

