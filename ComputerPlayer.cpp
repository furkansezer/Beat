#include "ComputerPlayer.h"


ComputerPlayer::ComputerPlayer(Vector position, int color, char name[])
	: name(name), Player(position, color, name)
{
		bar.SetBar(Vector(33,1), Vector(15,1), color);
}


ComputerPlayer::~ComputerPlayer(void)
{
}
