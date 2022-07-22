#include <stdio.h>
#include <iostream>
#include "Manager.h"

using namespace std;

int main()
{
	cout << "					BEAT"<<endl<<endl;
	char name[10];
	cout << "Enter Name:"<<endl<<endl;
	cin >> name;
	Manager m(name);
	m.Run();
}
