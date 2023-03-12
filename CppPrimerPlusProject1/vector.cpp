#include <cmath>
#include <iostream>
#include "vector.h"
using namespace std;

namespace VECTOR
{
	// compute derees in one radian 
	const double Rad_to_deg = 45.0 / atan(1.0); // be about 57.2957795130823

	// private methods
	// calculates magnitude from x and y
	void Vector::set_mag() { mag = sqrt(x * x + y * y); }
	void Vector::set_ang() { if (x == 0.0 && y == 0.0) ang = 0.0; else ang = atan2(y, x); }

	// set x from polar coordinate
	void Vector::set_x() { x = mag * cos(ang); }
	// set y from polar coordinate
	void Vector::set_y() { y = mag * sin(ang); }

	// public methods
	Vector::Vector()
	{ // default constructor 
		x = y = mag = ang = 0.0; mode = RECT;
	}

	// construct vector from rectangular coordinates if form is r
	// the default or else from polar coordinates if form is p
	Vector::Vector(double n1, double n2, Mode form)
	{
		mode = form;
		if (mode == RECT) { x = n1; y = n2; set_mag(); set_ang(); }
		else if (mode == POL) { mag = n1; ang = n2 / Rad_to_deg; set_x(); set_y(); }
		else
		{
			cout << "Incorrect 3rd argument to Vector() -- " << endl;
			cout << "vector set to 0 -- " << endl;
			x = y = mag = ang = 0;
			mode = RECT;
		}
	}

	// reset vector from rectangular coordinates if from RECT the default or 
	// else from polar coordinates is from is POL
	void Vector::reset(double n1, double n2, Mode form)
	{
		mode = form;
		if (mode == RECT) { x = n1; y = n2; set_mag(); set_ang(); }
		else if (mode == POL) { mag = n1; ang = n2 / Rad_to_deg; set_x(); set_y(); }
		else
		{
			cout << "Incorrect 3rd argument to Vector() -- " << endl;
			cout << "vector set to 0 -- " << endl;
			x = y = mag = ang = 0;
			mode = RECT;
		}
	}

	Vector::~Vector() {} // destructor
	void Vector::polar_mode() { mode = POL; } // set to polar mode
	void Vector::rect_mode() { mode = RECT; } // set to rectangular mode

	// operator overloading
	// add two Vectors
	// 12.4.3 返回对象
	Vector Vector::operator+(const Vector& b) const { return Vector(x + b.x, y + b.y); }
	// subtracy Vector b from a
	Vector Vector::operator-(const Vector& b) const { return Vector(x - b.x, y - b.y); }
	// reverse sign of Vector
	Vector Vector::operator-() const { return Vector(-x, -y); }
	// multiple vector by n
	Vector Vector::operator*(double n) const { return Vector(n * x, n * y); }

	// friend methods
	// multiply n vector by a
	Vector operator*(double n, const Vector a)
	{
		return a * n;
	}

	// display rectangular coordinates if mode is RECT, else display polar coordinates if mode is POL
	std::ostream& operator << (std::ostream& os, const Vector& v)
	{
		if (v.mode == Vector::RECT)
		{
			os << "(x,y)=(" << v.x << ", " << v.y << ")";
		}
		else if (v.mode == Vector::POL)
		{
			os << "(m,a)=(" << v.mag << ", " << v.ang * Rad_to_deg << ")";
		}
		else
		{
			os << "Vector object mode is invalid";
		}
		return os;
	}


	// 12.4.1 返回指向const对象的引用
	// 返回两个Vector对象中较大的一个
	// version 1
	Vector Vector::Max(const Vector& v1, const Vector& v2) const
	{
		if (v1.magval() > v2.magval())
			return v1;
		else
			return v2;
	}

	// vesion 2
	// 返回类型必须为const,因为变量是引用类型
	const Vector& Vector::Max2(const Vector& v1, const Vector& v2)
	{
		if (v1.magval() > v2.magval())
			return v1;
		else
			return v2;
	}

	// 

} // end namespace VECTOR