#pragma once
#include "bonus.h"

class ScoreBonus :
	public Bonus
{
public:
	ScoreBonus(void);
	~ScoreBonus(void);
	ScoreBonus(int color);
	void ExecuteBonus(Player *player, Console &con);
};

