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

	/**
	 * @brief Constructor de la clase CPixel.
	 * @param representa el formato que se utilizará.
	 */
	CPixel(int format);

	/**
	 * @brief Destructor de la clase CPixel.
	 */
	~CPixel();

	/**
	 * @brief Obtiene el canal que le pidas.
	 * @param Representa el canal que le estas pidiendo.
	 * @return El canal que pediste.
	 */
	unsigned char getChannel(char channel);

	/**
	 * @brief Obtiene el Pixel.
	 * @return El pixel.
	 */
	unsigned char * getPixel();

	/**
	 * @brief Obtiene el color.
	 * @return El color.
	 */
	int getColor();

	/**
	 * @brief Setea informacion en el canal requerido.
	 * @param Representa el canal que se esta pidiendo.
	 * @param Representa la informacion a setear.
	 */
	void setChannel(char channel, unsigned char info);

	/**
	 * @brief Overload de la funcion setChanel.
	 * @param Representa el canal que se esta pidiendo.
	 * @param Representa la informacion a setear en flotantes.
	 */
	void setChannel(char channel, float info);

	/**
	 * @brief Setea un pixel.
	 * @param Representa el pixel a setear.
	 */
	void setPixel(unsigned char * RGBA);

	/**
	 * @brief Overload de la funcion setPixel.
	 * @param representa el pixel en 32f a setear.
	 */
	void setPixel(float * RGBA);

	/**
	 * @brief Setea un color.
	 * @param Representa el color a setear.
	 */
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

