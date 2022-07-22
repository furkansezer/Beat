#include "ScoreBonus.h"


ScoreBonus::ScoreBonus(void)
{
}


ScoreBonus::~ScoreBonus(void)
{
}

ScoreBonus::ScoreBonus(int color)
{
		this->color= color;
		this->position= Vector((5+ rand()%70),(5+ rand()%15));
}

void ScoreBonus::ExecuteBonus(Player *player, Console &con)
{
	player->IncreaseScore(con);
}