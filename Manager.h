#pragma once
#include <iostream>
#include "Console.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "Ball.h"
#include "Bar.h"
#include "Bonus.h"
#include "FuelBonus.h"
#include "ScoreBonus.h"
#include "RoundBonus.h"
#include "Rectangle.h"

using namespace std;

class Manager
{
	Bonus **bonuspoints; // array constructed to store randomly placed 10 (different) bonusses
	Player *humanplayer, *computerplayer;
	Ball ball;
	Console con;

public:
	Manager(char *NameDown);
	~Manager(void);
	void CreateBonus(int); // creates new bonus in random according to the possibility ( %80 Fuel Bonus, %10 Round Bonus, %10 Score Bonus)
	void Run();
	void Pause(); // take a break for 10 sec with the key "p"
	void Exit(); // wait for 3 sec and then exit console with the key "x" 
};

