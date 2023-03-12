#include <iostream>
#ifndef CPPBASIC_H
#define CPPBASIC_H

class QWidget;

class CRectangle1
{
private:
	int x, y;
public:
	void setValues(int a, int b);
	int getarea() { return x * y; }
};

class CRectangle2
{
private:
	int width, height;
public:
	CRectangle2(int a, int b);
	int getarea() { return width * height; }
};

class CRectangle3
{
private:
	int width, height;
public:
	CRectangle3();
	CRectangle3(int a, int b);
	int getarea() { return width * height; }
};

class CVector
{
public:
	int x, y;
	CVector();
	CVector(int a, int b);
	CVector operator+(CVector* pCVector);
	CVector& operator=(const CVector& param);
};

class CDummy
{
public:
	int isitme(CDummy& pcd);
	static int number;
};

class CRectangle4
{
private:
	int width, height;
public:
	CRectangle4() {};
	CRectangle4(int a, int b);
	int getarea() { return width * height; }
	friend CRectangle4* duplicate(CRectangle4& pcr);
};

class CSquare;

class CRectangle5
{
private:
	int width, height;
public:
	int getarea() { return width * height; }
	void convert(CSquare* pcs);
};

class CSquare
{
private:
	int side;
public:
	void setSide(int a) { side = a; }
	friend class CRectangle5;
};

class CPolygon
{
protected:
	int width, height;
public:
	virtual int getarea() { return 0; }
	void setValues(int a, int b) { width = a; height = b; }
};

class CRectangle : public CPolygon
{
public:
	virtual int getarea() { return width * height; }
};

class CTriangle : public CPolygon
{
public:
	virtual int getarea() { return width * height / 2; }
};

class mother
{
public:
	mother() {};
	mother(int a) { a = 1; };
};

class daughter : public mother
{
public:
	daughter(int a) { a = 2; };
};

class son : public mother
{
public:
	son(int a) : mother(a) { };
};

#endif // !CPPBASIC_H