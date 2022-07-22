#include "Player.h"

Player::Player(Vector position, int color, char name[] ): name(name), position(position)
{
	score = 0;
	fuel = 20;
	round = false;
}

Player::~Player(void)
{
}

void Player::draw(Console&con)
{
	bar.draw(con);
}

void Player::IncreaseScore(Console &con)
{
	int i;
	if((bar.GetPosition()).getY()>10)	i=24; //"i" is used to distinguish between computer player and human player.
	else								i=0;
	score++;
	con.PrintChar(7,i,'0'+(score/10));  //Printing the updated scores for each player
	con.PrintChar(8,i,'0'+(score%10));
}

void Player::PrintName(Console& con, int y1)
{
	char s[] ="Score:";
	char f[] ="Fuel:";
	
	for (int i = 0; s[i] ; i++)
	{
		con.PrintChar(i,y1,s[i]);
	}

	for (int i = 0; f[i] ; i++)
	{
		con.PrintChar(i+70,y1,f[i]);
	}

	for (int x = 37; name[x-37] ; x++)
	{
		con.PrintChar(x,y1,name[x-37]);
	}
}

void Player::AddFuel(Console &con)
{
	int i;
	if((bar.GetPosition()).getY()>10)	i=24;//"i" is used to distinguish between computer player and human player.
	else								i=0;
	fuel++;
	con.PrintChar(76,i,'0'+(fuel/10));       //Printing the updated fuels for each player
	con.PrintChar(77,i,'0'+(fuel%10));
}

void Player::SamePlayerRound(bool b)
{
	round=b;
}

bool Player::RoundChance()
{
	return round;
}

bool Player::GotFuel()
{
	if(fuel>=0)
	return TRUE ;
	return FALSE;
}

void Player::Firing(Console &con)
{
	int i;
	if((bar.GetPosition()).getY()>10)	i=24;//"i" is used to distinguish between computer player and human player.
	else								i=0;
	fuel--;
	con.PrintChar(76,i,'0'+(fuel/10)); //Printing the updated fuels for each player
	con.PrintChar(77,i,'0'+(fuel%10));
}
