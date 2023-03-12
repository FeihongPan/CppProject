// dma.h -- inherutance and dynamic memory allocation
#ifndef DMA_H_
#define DMA_H_
#include <iostream>
#include <QtCore>
using namespace std;

// Base Class Using DMA
class baseDMA
{
private:
	char* label;
	int rating;

public:
	baseDMA(const char* l = "null", int r = 0);
	baseDMA(const baseDMA& rs);
	virtual ~baseDMA();

public:
	baseDMA& operator=(const baseDMA& rs);
	friend ostream& operator<<(ostream& os, const baseDMA& rs);
};

class lacksDMA : public baseDMA
{
private:
	enum { COL_LEN = 40 };
	char color[COL_LEN];

public:
	lacksDMA(const char* c = "blank", const char* l = "null", int r = 0);
	lacksDMA(const char* c, const baseDMA& rs);
	friend ostream& operator<<(ostream& os, const lacksDMA& rs);
};

class hasDMA : public baseDMA
{
private:
	char* style;

public:
	hasDMA(const char* c = "blank", const char* l = "null", int r = 0);
	hasDMA(const char* c, const baseDMA& rs);
	hasDMA(const hasDMA& hs);
	~hasDMA();

public:
	hasDMA& operator=(const hasDMA& hs);
	friend ostream& operator<<(ostream& os, const hasDMA& rs);
};

#endif // !DMA_H_
