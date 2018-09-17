#include "pch.h"
#include "CCanvas.h"
#include "string.h"
#include <iostream>

using namespace std;

CCanvas::CCanvas()
{

}


CCanvas::~CCanvas()
{
}

bool CCanvas::init(int w, int h, int p)
{
	m_width = w;
	m_height = h;
	m_pitch = p;
	buffer = new unsigned char[m_width*m_height*m_pitch];

	return true;
}

/**
 * 
 */
void CCanvas::set(int refer, unsigned char info)
{	
	buffer[refer] = info;
}

/**
 * 
 */
int CCanvas::get(int x, int y)
{
	if (y >= m_width)
	{
		cout << "fuera de rango";
		return 0;
	}
	else if (x>= m_height)
	{
		cout << "fuera de rango";
		return 0;
	}

	int blockStart = (x*m_width) + y;
	blockStart = blockStart * m_pitch;
	return blockStart;
}

void CCanvas::drawLine(int xi, int yi, int xf, int yf)
{
	bool isHorizontal = false;

	int start = this->get(xi,yi);
	int finish = this->get(xf, yf);
	
	if (xi - xf == 0)
	{
		isHorizontal = true;
	}

	if (isHorizontal)
	{
		int len = (finish - start) + m_pitch;
		for (int i = 0; i < len; i++)
		{
			this->set(start + i, '1');
		}
	}
	else
	{
		
	}
}

void CCanvas::copy(void * dest, const void * src, size_t siz)
{
	memcpy(dest, src, siz);
}

