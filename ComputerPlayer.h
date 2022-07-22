#pragma once
#include "player.h"

class ComputerPlayer :public Player
{
	char *name;
public:
	ComputerPlayer(Vector position, int color, char name[]);
	~ComputerPlayer(void);
};

