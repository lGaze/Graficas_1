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
	m_pitch = w;
	m_lengh = m_width * m_pitch;
	*buffer = new CPixel(m_format)[m_width*m_height];
	unsigned char * clearPix = new unsigned char[m_format];
	for (int i = 0; i < m_format; i++)
	{
		clearPix[i] = '0';
	}

	for (int i = 0; i < m_width*m_height; i++)
	{
		buffer[i].setPixel(clearPix);
	}
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
		int x = (m_width - 1) * U;
		int y = (m_height - 1) *  V;
		int salto = jump(x, y);
		for (int i = 0; i < m_format; i++)
		{
		  buffer[salto+i] = pSource[i];
		}
	}
}
 
void CCanvas::set(int x, int y, unsigned char info)
{
	int salto = jump(x, y);
	buffer[salto] = info;

}

void CCanvas::set(CVector coord, unsigned char * Destiny)
{
	int x = coord.getValueX();
	int y = coord.getValueY();
	int salto = jump(x, y);
	for (int i = 0; i < m_format; i++)
	{
		buffer[salto + i] = Destiny[i];
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
		int x = (m_width - 1) * U;
		int y = (m_height - 1) *  V;
		int salto = jump(x, y);
		Result = &buffer[salto];
	}
		
}

int CCanvas::get(int x, int y)
{
	int salto = jump(x, y);
	return salto;
}

void CCanvas::get(CVector coord, unsigned char * Result)
{
	int x = coord.getValueX();
	int y = coord.getValueY();
	int salto = jump(x, y);
	for (int i = 0; i < m_format; i++)
	{
		Result[i] = buffer[salto + i];
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
		int xi = (m_width - 1) * Ui;
		int yi = (m_height - 1) *  Vi;
		int xf = (m_width - 1) * Uf;
		int yf = (m_height - 1) *  Vf;

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

void CCanvas::copy(CCanvas * dest)
{
	int destSize = dest->m_width * dest->m_height * dest->m_format;
	unsigned char * result = new unsigned char[m_format];
	for (int i = 0; i<destSize;)
	{
		get(getCoords(i), result);
		dest->set(getCoords(i), result);
		i = i + m_format;
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
		}
		m = deltaY / deltaX;

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
		}
		m = deltaX / deltaY;

		float x = Xi;
		for (int y = Yi; y < Yf; y++)
		{
			x += m;
			set(round(x), y, c);
		}
	}
	
	

}

void CCanvas::drawLineBresenham(int Xi, int Yi, int Xf, int Yf, unsigned char c)
{
	int deltaX = Xf - Xi;
	int deltaY = Yf - Yi;



	if (std::abs(deltaX) >= std::abs(deltaY))
	{
		if (deltaX < 0)
		{
			std::swap(Xf, Xi);
			std::swap(Yf, Yi);
			deltaX = -deltaX;
			deltaY = -deltaY;
		}

		int error = 0;
		int y = Yi;
		for (int x = Xi; x < Xf; x++)
		{
			error += deltaY * 2;
			if (error >= deltaX)
			{
				error -= deltaX * 2;
				y++;
			}
			set(x, y, c);
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
		}
		

		int error = 0;
		int x = Xi;
		for (int y = Yi; y < Yf; y++)
		{
			error += deltaX * 2;
			if (error >= deltaY)
			{
				error -= deltaY * 2;
				x++;
			}
			set(x, y, c);
		}
	}


}

CVector CCanvas::getCoords(int index)
{
	CVector coordenadas;
	coordenadas.setValueX((index / m_width)/m_width);
	coordenadas.setValueY((index % m_width)/m_height);
	return coordenadas;
}



