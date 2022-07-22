#pragma once
#include "bonus.h"

class FuelBonus :
	public Bonus
{
public:
	FuelBonus(void);
	~FuelBonus(void);
	FuelBonus(int color);
	void ExecuteBonus(Player *player, Console &con);
};

