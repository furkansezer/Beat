#pragma once
#include "bonus.h"

class RoundBonus :
	public Bonus
{
public:
	RoundBonus(void);
	~RoundBonus(void);
	RoundBonus(int color);
	void ExecuteBonus(Player *player, Console &con);
};

