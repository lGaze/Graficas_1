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

bool CCanvas::init(int w, int h, int f)
{
	m_format = f;
	m_width = w;
	m_height = h;
	m_pitch = w * f;
	m_lengh = m_width * m_pitch;
	buffer = new unsigned char[m_width*m_height*m_pitch];
	return true;
}

void CCanvas::set(float U, float V, const unsigned char *Destiny)
{ 
	
	if (U > 1.0f|| U< 0.0f || V > 1.0f || V < 0.0f)
	{
		cout << "Fuera de rango" << endl;
	}
	else
	{
		int x = m_height * U;
		int y = m_width *  V;
		for (int i = 0; i<m_format; i++)
		{
		  buffer[this->jump(x, y)+i] = Destiny[i];
		}
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
		int x = U * m_height;
		int y = V * m_width;
		for (int i = 0; i < m_format; i++)
		{
			Result[i] = buffer[this->jump(x, y)+i];
		}
	}
		
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
		int xi = Ui * m_height;
		int yi = Vi * m_width;
		int xf = Uf * m_height;
		int yf = Vf * m_width;
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
			for (int i = 0; i<delta; i++)
			{
				buffer[jump(xi,yi)+ i] = '1';
			}
		}
		else
		{
			int puntoInicial = jump(xi, yi);
			int puntoFinal = jump(xf, yf);

			for (int i = puntoInicial; i< puntoFinal ; i++)
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
	int salto = (x * m_pitch) + (y * m_format);
	return salto;
}

void CCanvas::copy(void * dest, const void * src, size_t siz)
{
	memcpy(dest, src, siz);
}


//Sin terminar.
void CCanvas::drawLineMath(float Ui, float Vi, float Uf, float Vf)
{
	if (Ui > 1.0f || Ui < 0.0f || Vi > 1.0f || Vi < 0.0f || Uf > 1.0f || Uf < 0.0f || Vf>1.0f || Vf < 0.0f)
	{
		cout << "Fuera de rango" << endl;
	}
	float deltaX = Ui - Uf;
	float deltaY = Vi - Vf;
	float m;
	float magnitud;
	int xi = m_height * Ui;
	int yi = m_width * Vi;
	int xf = m_height * Uf;
	int yf = m_width * Vf;
	


	if (deltaX > deltaY)
	{
		m = deltaX / deltaY;
	}
	else
	{
		m = deltaY / deltaX;
	}
}



