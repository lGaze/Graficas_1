#pragma once
#include <iostream>

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
		unsigned char * RGBA[4];
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

