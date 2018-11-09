#include "pch.h"
#include "CPixel32f.h"


CPixel32f::CPixel32f(int format)
{
	m_format = format;
}


CPixel32f::~CPixel32f()
{
}

float CPixel32f::getChannel(char channel)
{
	if (channel == 'R')
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

float * CPixel32f::getPixel()
{
	return RGBA;
}

void CPixel32f::setChannel(char channel, float info)
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

void CPixel32f::setPixel(float * Pix)
{
	for (int i = 0; i < m_format; i++)
	{
		RGBA[i] = Pix[i];
	}
}