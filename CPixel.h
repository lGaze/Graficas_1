#pragma once
#include <iostream>

enum FORMAT
{
	R8G8B8A8 = 0x01,
	R8G8B8 = 0x02,
	R8G8 = 0x03,
	R8 = 0x04,
};

class CPixel
{
public:

	CPixel(int format);
	~CPixel();
	unsigned char getChannel(char channel);
	unsigned char * getPixel();
	int getColor();
	void setChannel(char channel, unsigned char info);
	void setPixel(unsigned char * RGBA);
	void setColor(int Color);

private:

	int m_format;
	union 
	{
		unsigned char RGBA[4];
		struct 
		{
			unsigned char R;
			unsigned char G;
			unsigned char B;
			unsigned char A;

		};
		unsigned int Color;
	};
};

