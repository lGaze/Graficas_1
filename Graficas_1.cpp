// Graficas_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "CCanvas.h"

using namespace std;

int main()
{
	CCanvas obj1;
	obj1.init(3, 3, 4);
	obj1.drawLine(0, 0, 0, 2, '1');
	obj1.drawLine(1, 0, 1, 2, '2');
	obj1.drawLine(2,0,2,2, '3');
	
	for (int i = 0; i < 36; i++)
	{
		cout << obj1.buffer[i];
	}
	
}

