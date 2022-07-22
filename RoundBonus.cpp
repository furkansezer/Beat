#include "RoundBonus.h"


RoundBonus::RoundBonus(void)
{
}

RoundBonus::~RoundBonus(void)
{
}

RoundBonus::RoundBonus(int color)
{
	this->color= color;
	this->position= Vector((5+ rand()%70),(5+ rand()%15));
}

void RoundBonus::ExecuteBonus(Player *player, Console &con)
{
	player->SamePlayerRound(TRUE);
}