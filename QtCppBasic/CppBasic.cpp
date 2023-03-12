#include <iostream>
#include "CppBasic.h"
#include <QtWidgets/QApplication>
using namespace std;

// 1.Class
// 1.1 Class definition
void CRectangle1::setValues(int a, int b)
{
	x = a;
	y = b;
}

int useCRectangle1()
{
	CRectangle1* rect = new CRectangle1;
	rect->setValues(3, 4);
	return rect->getarea();
}

// 1.2 Construcor and destructor
CRectangle2::CRectangle2(int a, int b)
{
	width = a;
	height = b;
}

int useCRectangle2()
{
	CRectangle2* rect = new CRectangle2(3, 4);
	return rect->getarea();
}

// 1.3 Overloading Construcor
CRectangle3::CRectangle3()
{
	width = 5;
	height = 5;
}

CRectangle3::CRectangle3(int a, int b)
{
	width = a;
	height = b;
}

// 1.4 Pointers to classes
int useCRectangle3()
{
	CRectangle3* rect1 = new CRectangle3(3, 4);
	CRectangle3* rect2 = new CRectangle3();
	return rect2->getarea();
}

// 1.5 Overloading operator
CVector::CVector() { x = 5; y = 5; };

CVector::CVector(int a, int b) { x = a; y = b; };

CVector CVector::operator+(CVector* pCVector)
{
	CVector pcv;
	pcv.x = pCVector->x + x;
	pcv.y = pCVector->y + y;
	return pcv;
}

CVector* useCVector()
{
	CVector pcv1 = CVector(3, 1);
	CVector* pcv2 = new CVector(1, 2);
	CVector pcv3;
	pcv3 = pcv1 + pcv2;
	return &pcv3;
}

// 1.6 this
CVector& CVector::operator=(const CVector& param)
{
	this->x = param.x + x;
	this->y = param.y + y;
	return *this;
}

int CDummy::isitme(CDummy& pcd)
{
	if (&pcd == this)
		return true;
	else
		return false;
}

bool useCDummy()
{
	CDummy a;
	CDummy* b = &a;
	CDummy& c = a;
	if (b->isitme(a))
		return true;
	else
		return false;
}

// 1.7 static members
int CDummy::number = 0;
int usenumber()
{
	CDummy* pcd = new CDummy;
	pcd->number = 5;
	delete pcd;
	return CDummy::number;
}

// 2.Friendship and inheritance
// 2.1 Friend functions
CRectangle4::CRectangle4(int a, int b)
{
	width = a;
	height = b;
}

CRectangle4* duplicate(CRectangle4& pcr)
{
	CRectangle4* cr = new CRectangle4;
	pcr.width = cr->width * 2;
	pcr.height = cr->height * 2;
	return cr;
}

int useCRectangle4()
{
	CRectangle4 rect1 = CRectangle4(2, 3);
	CRectangle4* rect2 = duplicate(rect1);
	return rect2->getarea();
}

// 2.2 Friendclass
void CRectangle5::convert(CSquare* pcs)
{
	width = pcs->side;
	height = pcs->side;
};

int useFriendclass()
{
	CSquare* pcs = new CSquare;
	CRectangle5* pcr = new CRectangle5;
	pcs->setSide(4);
	pcr->convert(pcs);
	return pcr->getarea();
}

// 2.3 Inheritance bwtween classes
int useInheritance()
{
	CRectangle* rect = new CRectangle;
	CTriangle* trgl = new CTriangle;
	rect->setValues(4, 5);
	trgl->setValues(4, 5);
	return rect->getarea() / trgl->getarea();
}

int usemother()
{
	daughter d(0);
	son s(0);
	return 0;
}

// 2.4 Polymorphism
int usePolymorphism()
{
	CRectangle rect;
	CTriangle trgl;
	CPolygon* cp1 = &rect;
	CPolygon* cp2 = &trgl;
	cp1->setValues(4, 5);
	cp2->setValues(4, 5);
	return cp1->getarea() / cp2->getarea();
}

// 2.5 virtual member
// 2.6 abstact base class

// 3.Templates
// 3.1 Funtion templates
template <class T>
T GetMax(T a, T b)
{
	T result;
	result = (a > b) ? a : b;
	return result;
}

int useFuntionTemplates()
{
	int i = 5, j = 6, k;
	long a = 10, b = 5, c;
	k = GetMax(i, j);
	c = GetMax(a, b);
	return k + c;
}

// 3.2 class templates
template <class T>
class mypair
{
	T a, b;
public:
	mypair(T first, T second) { a = first; b = second; };
	T getmax();
};

template <class T>
T mypair<T>::getmax()
{
	T result;
	result = (a > b) ? a : b;
	return result;
}

int useClassTemplates()
{
	mypair<int> myobject(100, 75);
	return myobject.getmax();
}

// 3.3 Non-type parameters for templates


// 4.Namespace


// 5.Exceptions


// 6.Type Casting
// 6.1 Implicit conversion

// 6.2 Explicit conversion

// 6.3 dynamic_cast<CTriangle*>()

// 6.4 static_cast<double>()


// 7.Preprocessor directives
// 7.1 macro definitions (#define, #undef)

// 7.2 Conditional inclusions (#ifdef, #ifndef, #if, #endif, #else and #elif)

// 7.3 Line control (#line)

// 7.4 Error directive (#error)

// 7.5 Source file inclusion (#include)

// 7.6 Pragma directive (#pragma)

