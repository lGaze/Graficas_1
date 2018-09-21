#pragma once
class CCanvas
{
public:
	CCanvas();
	~CCanvas();

	bool init(int w, int h, int p);
	void set(int x , int y, int canal, unsigned char info);
	void set(unsigned char * inicio, int canal, unsigned char info);
	unsigned char *  get(int x, int y);
	void drawLine(int xi, int yi, int xf, int yf, unsigned char info); 
	void copy(void * dest, const void * src, size_t siz);
	unsigned char * buffer;

private:

	int m_width;
	int m_height;
	int m_pitch;
	int m_lengh;
	int m_widthNormal;
	int m_heightNormal;
};

