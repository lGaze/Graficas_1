#include "pch.h"
#include "CPixel.h"


CPixel::CPixel(int format)
{
	m_format = format;
	
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
	return RGBA;
}

int CPixel::getColor()
{
	return Color;
}

void CPixel::setChannel(char channel, unsigned char info)
{
	if (channel == 'R')
	{
		R = info;
	}
	else if (channel == 'G')
	{
		G = info;
	}
	else if (channel == 'B')
	{
		B = info;
	}
	else if (channel == 'A')
	{
		A = info;
	}
}


void CPixel::setChannel(char channel, float info)
{
	char color = info * 0xff;

	if (channel == 'R')
	{
		R = color;
	}
	else if (channel == 'G')
	{
		G = color;
	}
	else if (channel == 'B')
	{
		B = color;
	}
	else if (channel == 'A')
	{
		A = color;
	}
}

void CPixel::setPixel(unsigned char * Pix)
{
	for (int i = 0; i < m_format; i++)
	{
		RGBA[i] = Pix[i];
	}
}


void CPixel::setPixel(float * Pix)
{

	for (int i = 0; i < m_format; i++)
	{
		char color = Pix[i] * 0xff;
		RGBA[i] = color;
	}
}

void CPixel::setColor(int Color)
{
	Color = Color;
}


