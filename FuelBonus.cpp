#include "FuelBonus.h"


FuelBonus::FuelBonus(void)
{
}

FuelBonus::~FuelBonus(void)
{
}

FuelBonus::FuelBonus(int color)
{
		this->color= color;
		this->position= Vector((5+ rand()%70),(5+ rand()%15));
}

void FuelBonus::ExecuteBonus(Player *player, Console &con)
{
	player->AddFuel(con);
}