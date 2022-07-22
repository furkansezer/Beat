#pragma once
#include "rectangle.h"
#include "Bar.h"
#include <iostream>

using namespace std;

class Player
{
	int score;
	int fuel;
	bool round;
protected:
	char* name;
	Vector size, position;
public:
	Bar bar;
	Player(Vector position, int color, char name[]);
	~Player(void);
	void draw(Console&con);
	void IncreaseScore(Console &con); // increase score by one and print console new status
	void PrintName(Console &con, int i);
	void AddFuel(Console &con); // incrase fuel by one and print console new status
	void SamePlayerRound(bool); // change value of round according to input
	bool RoundChance();
	bool GotFuel();
	void Firing(Console &con); // decrease fuel by one and print console new status
};

