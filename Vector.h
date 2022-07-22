#pragma once
#include <Math.h>
class Vector
{
int x, y;
public:
	Vector(){}
	Vector(int x, int y);
	Vector operator=(Vector & vec);
	Vector operator +=(Vector & vec);
	int getX();
	int getY();
};

