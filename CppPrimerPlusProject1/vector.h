#pragma once
#pragma once
// 11.5  ∏¡ø¿‡vector
// vector.h Vector class with <<, mode state

#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>
#include <QtCore/QCoreApplication>

namespace VECTOR
{
	class Vector
	{
	public:
		enum Mode { RECT, POL };
		// RECT for rectabgular, POL for Polar modes

	private:
		double x; double y;
		double mag; // length of vector in degrees
		double ang; // direction of vector in derees
		Mode mode; // RECT or POL

		// private methods for setting values
		void set_mag();
		void set_ang();
		void set_x();
		void set_y();

	public:
		Vector();
		Vector(double n1, double n2, Mode form = RECT);
		void reset(double n1, double n2, Mode form = RECT);
		~Vector();

		// get the value from property
		double xval() const { return x; }
		double yval() const { return y; }
		double magval() const { return mag; }
		double angval() const { return ang; }
		void polar_mode(); //set mode to POL
		void rect_mode(); //set mode to RECT

		Vector Max(const Vector& v1, const Vector& v2) const;
		const Vector& Max2(const Vector& v1, const Vector& v2);


		// operator overloading
		Vector operator+ (const Vector& b) const;
		Vector operator- (const Vector& b) const;
		Vector operator- () const;
		Vector operator* (double n) const;

		// friends
		friend Vector operator*(double n, const Vector& a);
		friend std::ostream& operator<<(std::ostream& os, const Vector& v);
	};
} // end namespace VECTOR

#endif // !VECTOR_H_


