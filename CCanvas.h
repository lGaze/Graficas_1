#pragma once
#include "CVector.h"
#include "CPixel.h"
#include "CPixel32f.h"


class CCanvas
{
public:

	/**
	 * @brief Constructor default de CCanvas 
	 */
	CCanvas();

	/**
	* @brief destructor de CCanvas
	*/
	~CCanvas();

	/** 
	* @brief Inicializa las variables y el buffer.
	* @param Representa el largo de el buffer.
	* @param Representa el alto de el buffer.
	* @param Representa el formato de los pixeles.
	* @return Un valor booleano para verificar la inicializacion.
	*/
	bool init(int width, int height, int format);

	/**
	 * @brief Dibuja una linea Horizontal
	 * @param Representa la coordenada x inicial.
	 * @param Representa la coordenada y inicial.
	 * @param Representa la coordenada y final.
	 * @param Representa la coordenada y final.
	 * @param Representa el color de la linea a dibujar.
	 */
	void drawLineHorizontal(int xi, int yi, int xf, int yf, unsigned char * RGBA);  

	/**
	 * @brief Dibuja una linea Vertical
	 * @param Representa la coordenada X inicial.
	 * @param Representa la coordenada Y inicial.
	 * @param Representa la coordenada X final.
	 * @param Representa la coordenada Y final.
	 * @param Representa el color de la linea a dibujar.
	 */
	void drawLineVertical(int xi, int yi, int xf, int yf, unsigned char * RGBA);

	/** 
	* @brief Copia la informacion de un buffer a otro.
	* @param Representa el lugar a donde se copiara la informacion.
	*/
	void copy(CCanvas * dest);

	/** 
	* @brief Calcula saltos en el buffer.
	* @param Representa la coordenada en X dentro del buffer.
	* @param Representa la coordenada en Y dentro del buffer.
	* @return Un inidce que representa el salto.
	*/
	int jump(int x, int y);

	/**
	 * @brief Dibuja una linea calculada a partir de la formula matematica.
	 * @param Representa la coordenada X inicial.
	 * @param Representa la coordenada Y inicial.
	 * @param Representa la coordenada X final.
	 * @param Representa la coordenada Y final.
	 * @param Representa el color de la linea a dibujar.
	 */
	void drawLineMath(int Xi, int Yi, int Xf, int Yf, unsigned char * RGBA);

	/**
	 * @brief Dibuja una linea de Bresenham.
	 * @param Representa la coordenada X inicial.
	 * @param Representa la coordenada Y inicial.
	 * @param Representa la coordenada X final.
	 * @param Representa la coordenada Y final.
	 * @param Representa el color de la linea a dibujar.
	 */
	void drawLineBresenham(int Xi, int Yi, int Xf, int Yf, unsigned char * RGBA);
	
	/**
	 * @brief Obtiene las coordenadas dentro de un buffer a partir de un indice.
	 * @param Representa el indice de donde se scaran las coordenadas.
	 * @return Un vector con las coordenadas. 
	 */
	CVector getCoords(int index);

	/**
	 * @brief Obtiene el largo de el buffer.
	 * @return Un valor entero que representa el largo del buffer.
	 */
	int getW() { return m_width; }

	/**
	 * @brief Obtiene el alto de el buffer.
	 * @return Un valor entero que representa el largo del buffer.
	 */
	int getH() { return m_height; }

	/**
	 * @brief Obtiene el pitch.
	 * @return Un valor entero que representa el pitch.
	 */
	int getP() { return m_pitch; }

	/**
	 * @brief Obtiene el formato.
	 * @return Un valor entero que representa el formto.
	 */
	int getF() { return m_format; }

	/**
	 * @brief Obtiene un pixel por medio de coordenadas UV.
	 * @param Representa la coordenada U dentro del buffer.
	 * @param Representa la coordenada V dentro del buffer.
	 * @param Representa el lugar donde se guardará el pixel.
	 */
	void get(float U, float V, unsigned char * Result);

	/**
	 * @brief Setea informacion en las coordenadas UV deseadas.
	 * @param Representa la coordenada U dentro del buffer.
	 * @param Representa la coordenada V dentro del buffer.
	 * @param Representa la informacion a setear.
	 */
	void set(float U, float V, unsigned char * RGBA);

private:

	CPixel * buffer;
	int m_width;
	int m_height;
	int m_pitch;
	int m_format;
};

