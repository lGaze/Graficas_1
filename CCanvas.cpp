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
	*buffer = new CPixel(m_format)[m_width*m_height];
	for (int i = 0; i < m_width*m_height; i++)
	{
		buffer[i].setChannel('R', '0');
		buffer[i].setChannel('G', '0');
		buffer[i].setChannel('B', '0');
		buffer[i].setChannel('A', '0');
	}
	return true;
}

void CCanvas::drawLineHorizontal(int xi, int yi, int xf, int yf, unsigned char * RGBA)
{
	int delta;

	if (xi - xf == 0)
	{
		int puntoInicial = jump(xi, yi);
		int puntoFinal = jump(xf, yf);
		delta = puntoFinal - puntoInicial;

		for (int i = 0; i<delta; i++)
		{
			buffer[puntoInicial + i].setPixel(RGBA);
		}
	}

	else
	{
		
	}
}

void CCanvas::drawLineVertical(int xi, int yi, int xf, int yf, unsigned char * RGBA)
{
	int puntoInicial = jump(xi, yi);
	int puntoFinal = jump(xf, yf);

	for (int i = puntoInicial; i == puntoFinal; )
	{
		buffer[i].setPixel(RGBA);
		i += m_pitch;
	}
}

int CCanvas::jump(int x, int y)
{
	int salto = (y * m_width) + x;
	return salto;
}

void CCanvas::copy(CCanvas * dest)
{
	int destSize = dest->m_width * dest->m_height;
	unsigned char * result = new unsigned char[m_format];
	for (int i = 0; i < destSize; i++)
	{
		int destx = dest->getCoords(i).getValueX();
		int desty = dest->getCoords(i).getValueY();

		float u = destx / float(dest->m_width - 1);
		float v = desty / float(dest->m_height - 1);

		int x = u * (m_width - 1);
		int y = v * (m_height - 1);
		int iSrc = this->jump(x, y);

		memcpy(&dest->buffer[i], &this->buffer[iSrc], sizeof(CPixel));
	}
}

void CCanvas::drawLineMath(int Xi, int Yi, int Xf, int Yf, unsigned char * RGBA)
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
			buffer[jump(x, round(y))].setPixel(RGBA);
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
			buffer[jump(round(x),y)].setPixel(RGBA);
		}
	}
	
	

}

void CCanvas::drawLineBresenham(int Xi, int Yi, int Xf, int Yf, unsigned char * RGBA)
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
			buffer[jump(x, y)].setPixel(RGBA);
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
			buffer[jump(x, y)].setPixel(RGBA);
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

void CCanvas::get(float U, float V, unsigned char * Result)
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
		Result = buffer[salto].getPixel();
	}
}

void CCanvas::set(float U, float V, unsigned char * RGBA)
{
	if (U > 1.0f || U< 0.0f || V > 1.0f || V < 0.0f)
	{
		cout << "Fuera de rango" << endl;
	}
	else
	{
		int x = (m_width - 1) * U;
		int y = (m_height - 1) *  V;
		int salto = jump(x, y);
		buffer[salto].setPixel(RGBA);
	}
}



