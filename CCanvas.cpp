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
	m_lengh = m_width * m_pitch;
	buffer = new unsigned char[m_width*m_height*m_pitch];
	return true;
}

/**
 * 
 */
void CCanvas::set(int x, int y, int canal, unsigned char info)
{	
	if (y >= m_width)
	{
		cout << "Fuera de rango" << endl;
		
	}

	else if (x >= m_height)
	{
		cout << "Fuera de rango" << endl;

	}
	else
	{
		int block = (x*m_width) + y;
		buffer[block + canal] = info;
	}
		
	
}

/**
 * 
 */
void CCanvas::set(unsigned char * inicio, int canal, unsigned char info)
{
	for (int i = 0; i<canal; i++)
	{
		*inicio++;
	}

	*inicio = info; 

}

/**
 * 
 */
unsigned char * CCanvas::get(int x, int y)
{
	if (y >= m_width)
	{
		cout << "Fuera de rango" << endl;
		return nullptr;
	}
	else if (x >= m_height)
	{
		cout << "Fuera de rango" << endl;
		return nullptr;
	}
	else
	{
		unsigned char * inicio = &buffer[((x*m_width) + y) * m_pitch];
		return inicio;
	}
		
}

/**
 * 
 */
void CCanvas::drawLine(int xi, int yi, int xf, int yf, unsigned char info)
{
	bool isHorizontal = false;
	if (yi >= m_width || yf >= m_width)
	{
		cout << "Fuera de rango" << endl;
		
	}
	else if (xi >= m_height || xf >=m_height)
	{
		cout << "Fuera de rango" << endl;
		
	}
	else
	{
		if (xi - xf == 0)
		{
			isHorizontal = true;
		}

		if (isHorizontal)
		{
			int len = (yf - yi) * m_pitch;
			for (int i = 0; i < len + 4; i++)
			{
				this->set(this->get(xi, yi), i, info);
			}
		}
		else
		{  

			for (int i = yi; i < yf; i++)
			{
			  
			}
		}
	}
	
}

void CCanvas::copy(void * dest, const void * src, size_t siz)
{
	memcpy(dest, src, siz);
}

