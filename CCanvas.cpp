#include "pch.h"
#include "CCanvas.h"
#include "string.h"
#include <iostream>
#include "math.h"
using namespace std;

CCanvas::CCanvas()
{

}


CCanvas::~CCanvas()
{

}

bool CCanvas::init(int w, int h, int f)
{
	m_format = f;
	m_width = w;
	m_height = h;
	m_pitch = w * f;
	m_lengh = m_width * m_pitch;
	buffer = new unsigned char[m_width*m_height*m_format];
	return true;
}

void CCanvas::set(float U, float V, const unsigned char *pSource)
{ 
	
	if (U > 1.0f|| U< 0.0f || V > 1.0f || V < 0.0f)
	{
		cout << "Fuera de rango" << endl;
	}
	else
	{
		int x = m_width * U;
		int y = m_height *  V;
		int salto = jump(x, y);
		for (int i = 0; i<m_format; i++)
		{
		  buffer[salto+i] = pSource[i];
		}
	}
}

void CCanvas::set(int x, int y, unsigned char info)
{
	int salto = jump(x, y);
	for (int i = 0; i < m_format; i++)
	{
		buffer[salto + i] = info;
	}
}

void CCanvas::get(float U, float V, unsigned char *Result)
{
	if (U > 1.0f || U < 0.0f || V > 1.0f || V < 0.0f)
	{
		cout << "Fuera de rango" << endl;
	}
	else
	{
		int x = U * m_width;
		int y = V * m_height;
		int salto = jump(x, y);
		for (int i = 0; i < m_format; i++)
		{
			Result[i] = buffer[salto+i];
		}
	}
		
}

int CCanvas::get(int x, int y)
{
	int salto = jump(x, y);
	return salto;
}


void CCanvas::drawLine(float Ui, float Vi, float Uf, float Vf)
{
	bool isHorizontal = false;
	if (Ui > 1.0f || Ui < 0.0f || Vi > 1.0f || Vi < 0.0f || Uf > 1.0f || Uf < 0.0f || Vf>1.0f || Vf < 0.0f)
	{
		cout << "Fuera de rango" << endl;
	}

	else
	{
		int xi = Ui * m_width;
		int yi = Vi * m_height;
		int xf = Uf * m_width;
		int yf = Vf * m_height;


		int delta;

		if (Ui - Uf == 0)
		{
			isHorizontal = true;
			int puntoInicial = jump(xi, yi);
			int puntoFinal = jump(xf, yf);
			delta = puntoFinal - puntoInicial;
		}

		if (isHorizontal)
		{
			int salto = jump(xi, yi);

			for (int i = 0; i<delta; i++)
			{
				buffer[salto + i] = '1';
			}
		}
		else
		{
			int puntoInicial = jump(xi, yi);
			int puntoFinal = jump(xf, yf);

			for (int i = puntoInicial; i < puntoFinal ; i++)
			{
				puntoInicial = i;

				for (int j = 0; j < m_format; j++)
				{
					buffer[puntoInicial + j] = '1';
				}

				i += m_pitch-1;
			}
		}
	}
	
}

int CCanvas::jump(int x, int y)
{
	int salto = (y * m_pitch) + (x * m_format);
	return salto;
}

//Sin terminar.
void CCanvas::copy(CCanvas * dest, const CCanvas * src)
{

	for (int i = 0; i < src->buffer[dest->m_width*dest->m_height*dest->m_format]; i++)
	{
		dest->buffer[i] = src->buffer[i];
	}


}


void CCanvas::drawLineMath(int Xi, int Yi, int Xf, int Yf, unsigned char c)
{

	int deltaX = Xf - Xi;
	int deltaY = Yf - Yi;
	float m = 0;


	if (std::abs(deltaX) >= std::abs(deltaY))
	{
		if (deltaX < 0)
		{
			std::swap(Xf, Xi);
			std::swap(Yf, Yi);
			deltaX = -deltaX;
			deltaY = -deltaY;
			m = deltaX / deltaY;
		}
		else
		{
			m = deltaX / deltaY;
		}

		float y = Yi;
		for (int x = Xi; x < Xf; x++)
		{
			y += m;
			set(x, round(y), c);
		}


	}
	else
	{
		if (deltaY < 0)
		{
			std::swap(Xf, Xi);
			std::swap(Yf, Yi);
			deltaX = -deltaX;
			deltaY = -deltaY;
			m = deltaY / deltaX;
		}
		else
		{
			m = deltaY / deltaX;
		}

		float x = Xi;
		for (int y = Yi; y < Yf; y++)
		{
			x += m;
			set(round(x), y, c);
		}
	}
	
	

}



