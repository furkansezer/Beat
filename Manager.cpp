#include "Manager.h"

Manager::Manager(char *NameDown): ball(con)
{
	humanplayer = new HumanPlayer( Vector(33,0), con.rgb_b(1,0,0,0) , NameDown);
	computerplayer = new ComputerPlayer( Vector(33,24),  con.rgb_b(0,1,0,0), "Last Champion");

	humanplayer->PrintName(con, 24);
	computerplayer->PrintName(con, 0);

		con.PrintChar(76,0,'2');	con.PrintChar(76,24,'2');
		con.PrintChar(77,0,'0');	con.PrintChar(77,24,'0');
		con.PrintChar(7,0,'0');		con.PrintChar(7,24,'0');
		con.PrintChar(8,0,'0');		con.PrintChar(8,24,'0');

	bonuspoints = new Bonus*[10];
	for(int count=0; count < 10; count++)
		bonuspoints[count] = NULL;
	for(int count=0; count < 10; count++)
		CreateBonus(count);
}

Manager::~Manager()
{
	for(int i = 0; i < 10; i++)	
		delete bonuspoints[i];
		
		delete[] bonuspoints;
		delete humanplayer;
		delete computerplayer;
}

void Manager::Run()
{	
	Bar & hbar = humanplayer->bar;
	Bar & cbar = computerplayer->bar;
		
		humanplayer->draw(con);
		computerplayer->draw(con);
		ball.draw(con);
			
			while (humanplayer->GotFuel() && computerplayer->GotFuel())
			{
				Sleep(50);

				ball.move(con);
				cbar.Smart(ball, con); //Computer moves its bar with that function.
				
				if(_kbhit())
				{
						char ch= _getch();
						hbar.move(con, ch);			
						if (ch=='p') Pause();
						if (ch=='x') Exit();
				}
				
				for (int i = 0; i < 10; i++)
				{
					if(ball.IsInTouchWithBonus(bonuspoints[i]))
					{
						bonuspoints[i]->erase(con);
						
						if(ball.WhoShot())
							bonuspoints[i]->ExecuteBonus(humanplayer, con);
						else
							bonuspoints[i]->ExecuteBonus(computerplayer, con);
						
						CreateBonus(i);
					}
				}

				while(ball.IsInTouchWithBar(hbar) || ball.IsInTouchWithBar(cbar) || ball.IsOutOfScope())
				{
						if(ball.IsOutOfScope())
						{
							if(ball.WhoShot())
								humanplayer->IncreaseScore(con);
							else
								computerplayer->IncreaseScore(con);
							
							ball.stop();
							ball.erase(con);
							
							if(humanplayer->RoundChance())
							{	ball.Reposition(1);	humanplayer->SamePlayerRound(FALSE);}
							else if(computerplayer->RoundChance())
							{	ball.Reposition(2);	computerplayer->SamePlayerRound(FALSE);}
							else
								ball.Reposition(0);
							
							ball.move(con);
							
							if(_kbhit())
							{
								char ch= _getch();
								hbar.move(con, ch);
							}
							
								break;
						}
						
								ball.stop();
						
						if(ball.IsInTouchWithBar(hbar))
						{
							if(_kbhit())
							{
								char ch= _getch();
								ball.move(con, ch);
								hbar.move(con, ch);				
								if(ch=='q' || ch=='w' || ch=='e')
								{
									ball.Shoot(ch);
									humanplayer->Firing(con); // Each calling of this function decreases player's fuel by one.
								}
								if (ch=='x') Exit();
								ball.move(con);

							}
						}
						
						if(ball.IsInTouchWithBar(cbar))
						{
							ball.Shoot('r');
							computerplayer->Firing(con);
							ball.move(con);
							
							if(_kbhit())
							{
								char ch= _getch();
								hbar.move(con, ch);				
							}
						}
										
				}
			}		
}

void Manager::CreateBonus(int i)
{
	Bonus* RandomBonus;
	int ratio = (rand()%10+1);
	
	if (ratio <= 8) 
	{	
		RandomBonus = new FuelBonus(con.rgb_b(1,1,0,0));
	}
	
	else if(ratio == 9)
	{	
		RandomBonus = new RoundBonus(con.rgb_b(1,0,0,1));	
	}

	else
	{
		RandomBonus = new ScoreBonus(con.rgb_b(0,1,1,0));
	}
	
	if (bonuspoints[i]) // Deletion of taken bonus
		delete bonuspoints[i];
	
	bonuspoints[i] = RandomBonus;
	bonuspoints[i]-> draw(con);
}

void Manager::Pause()
{
	con.PrintChar(10,24,'P');
	Sleep(10000); // Wait 10 sec
	con.PrintChar(10,24,' ');
}

void Manager::Exit()
{
	con.PrintChar(10,24,'E');
	Sleep(3000); // Wait 3 sec
	con.PrintChar(10,24,'D');
	exit(EXIT_SUCCESS); // exit console
}