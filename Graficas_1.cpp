// Graficas_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "CCanvas.h"

using namespace std;

int main()
{
	CCanvas obj1;
	unsigned char * result = new unsigned char[4];
	unsigned char * hola = new unsigned char[4];
	obj1.init(3, 3, 4);
	obj1.drawLine(0.0, 0.0,1.0, 0.0);
		
	
}

