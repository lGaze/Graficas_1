#pragma once

#include "CPixel.h"

enum FORMAT
{
	R32G32B32A32 = 0x05,
	R32G32B32 = 0x06,
	R32G32 = 0x07,
	R32 = 0x08,

};

class CPixel32f
{
public:

	CPixel32f(int format);
	~CPixel32f();
	float getChannel(char channel);
	float * getPixel();
	//int getColor();
	void setChannel(char channel, float info);
	void setPixel(float * RGBA);
	//void setColor(int Color);

private:

	int m_format;
	union
	{
		float RGBA[4];
		struct
		{
			float R;
			float G;
			float B;
			float A;

		};
	};
};

