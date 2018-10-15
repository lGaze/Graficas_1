#include "pch.h"
#include "CPixel.h"


CPixel::CPixel(int format)
{
}

CPixel::~CPixel()
{
}

unsigned char CPixel::getChannel(char channel)
{
	if(channel == 'R')
	{
		return R;
	}
	else if (channel == 'G')
	{
		return G;
	}
	else if (channel == 'B')
	{
		return B;
	}
	else if (channel == 'A')
	{
		return A;
	}
	else
	{
		return '\0';
	}
} 

unsigned char * CPixel::getPixel()
{
	return *RGBA;
}

int CPixel::getColor()
{
	return Color;
}

void CPixel::setChannel(char channel, unsigned char info)
{
	if (channel == 'R')
	{
		this->R = info;
	}
	else if (channel == 'G')
	{
		this->G = info;
	}
	else if (channel == 'B')
	{
		this->B = info;
	}
	else if (channel == 'A')
	{
		this->A = info;
	}
}

void CPixel::setPixel(unsigned char * Pix)
{
	this->RGBA[0] = &Pix[0];
	this->RGBA[1] = &Pix[1];
	this->RGBA[2] = &Pix[2];
	this->RGBA[3] = &Pix[3];
}

void CPixel::setColor(int Color)
{
	Color = Color;
}

