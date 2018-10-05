#pragma once

enum FORMATO
{
	R8G8B8A8 = 0x01,
	R8G8B8 = 0x02,
	R8G8 = 0x03,
	R8 = 0x04,
};
class CCanvas
{
public:
	CCanvas();
	~CCanvas();

	/** 
	*  Inicializa las variables y el buffer.
	*  Recibe un entero whidth , un entero height y un formato.
	*/
	bool init(int w, int h, int f);

	/** 
	*	Setea informacion dentro del buffer.
	*	Recibe cordenadas X y Y, recibe tambien un puntero que contiene la informacion a setear.
	*/
	void set(float x, float y, const unsigned char *Destiny);

	/**
	 *  Setea informacion en la posicion exacta del buffer.
	 *	Recibe cordenadas X y Y de tipo entero y la informacion a setear.
	 */
	void set(int x, int y, unsigned char info);

	/** 
	*	Obtiene la referencia de memoria del inicio del bloque.
	*	Recibe cordenadas X y Y, recibe un puntero donde se va a guardar la informacion.
	*/
	void get(float x, float y,  unsigned char *Result);

	/**
	 *	 Obtine la posicion exacta en el buffer
	 *	 Recibe cordenadas X y Y de tipo entero.
	 */
	int get(int x, int y);

	/** 
	*	Dibuja una linea ya sea horizontal o vetical.
	*   Recibe cordenadas del punto inicial y del punto final.
	*/
	void drawLine(float xi, float yi, float xf, float yf); 

	/** 
	*	Copia la informacion de un buffer a otro
	*	Recibe un puntero de destino, un puntero constate del souce.
	*/
	void copy(CCanvas * dest, const CCanvas * src);

	/** 
	*  Calcula saltos en el buffer.
	*  Recibe cordenadas X,Y y regresa el salto 
	*/
	int jump(int x, int y);

	/**
	 *	Linea matematica.
	 *	Recibe cordenas de un punto inicial y un punto final, y setea la informacion que recibe.
	 */
	void drawLineMath(int Xi, int Yi, int Xf, int Yf, unsigned char c);

	/**
	 *	Linea de Bresenham.
	 *	Recibe cordenas de un punto inicial y un punto final, y setea la informacion que recibe.
	 */
	void drawLineBresenham(int Xi, int Yi, int Xf, int Yf, unsigned char c);
	

	unsigned char * buffer;
	
private:

	int m_width;
	int m_height;
	int m_pitch;
	int m_lengh;
	int m_format;
};

