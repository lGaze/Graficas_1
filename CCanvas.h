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

	/** Inicializa las variables y el buffer.
	*  Recibe un entero whidth , un entero height y un formato.
	*/
	bool init(int w, int h, int f);

	/** Setea informacion dentro del buffer.
	*	Recibe cordenadas X y Y, recibe tambien un puntero que contiene la informacion a setear.
	*/
	void set(float x, float y, const unsigned char *Destiny);

	/** Obtiene la referencia de memoria del inicio del bloque.
	*	Recibe cordenadas X y Y, recibe un puntero donde se va a guardar la informacion.
	*/
	void get(float x, float y,  unsigned char *Result);

	/** Dibuja una linea ya sea horizontal o vetical.
	*   Recibe cordenadas del punto inicial y del punto final.
	*/
	void drawLine(float xi, float yi, float xf, float yf); 

	/** Copia la informacion de un buffer a otro
	*	Recibe un puntero de destino, un puntero constate del souce.
	*/
	void copy(CCanvas * dest, const CCanvas * src);

	/** Calcula saltos en el buffer.
	*  Recibe cordenadas X,Y y regresa el salto 
	*/
	int jump(int x, int y);
	/**
	 * 
	 */
	void drawLineMath(float xi, float yi, float xf, float yf);
	

	unsigned char * buffer;
	
private:

	int m_width;
	int m_height;
	int m_pitch;
	int m_lengh;
	int m_format;
};

