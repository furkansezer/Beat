#include "HumanPlayer.h"


HumanPlayer::HumanPlayer(Vector position, int color, char name[])
	:  name(name), Player(position, color, name)
{
	bar.SetBar(Vector(33,23), Vector(15,1), color);
}


HumanPlayer::~HumanPlayer(void)
{
}


