#pragma once
class CCanvas
{
public:
	CCanvas();
	~CCanvas();

	bool init(int w, int h, int p);
	void set(int refer, unsigned char info);
	int get(int x, int y);
	void drawLine(int xi, int yi, int xf, int yf); 
	void copy(void * dest, const void * src, size_t siz);
	unsigned char * buffer;

private:

	int m_width;
	int m_height;
	int m_pitch;
};

