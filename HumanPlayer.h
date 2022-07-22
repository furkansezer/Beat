#pragma once
#include "Player.h"
#include "Bar.h"
#include "Ball.h"

class HumanPlayer :public Player
{
	char* name;
public:
	HumanPlayer(Vector position, int color, char name[]);
	~HumanPlayer(void);
};

