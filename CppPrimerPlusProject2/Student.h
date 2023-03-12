#ifndef STUDENT_H
#define STUDENT_H

#include <QtCore>
#include <iostream>
#include <valarray>
using namespace std;

class Student
{
private:
	typedef valarray<double> ArrayDb;
	QString name;
	ArrayDb scores;
	ostream& scoresOut(ostream& os) const;

public:
	Student(): name("Null Student"), scores() {}
	explicit Student(const QString& s) : name(s), scores() {}
	explicit Student(int n) : name("S1"), scores(n) {}
	Student(const QString& s, int n): name(s), scores(n) {}
	Student(const QString& s, const ArrayDb& a) 
					{ name = s, scores = a; }
	Student(const QString* str, const double* pd, int n) 
					{ name = *str, scores = pd[n]; }
	~Student() {};

public:
	double Average() const;
	const QString& Name() const;
	double& operator[] (int i);
	double operator[] (int i) const;

public:
	friend istream& operator>>(istream& is, Student& stu);
	friend istream& getline(istream& is, Student& stu);
	friend ostream& operator<<(ostream& os, Student& stu);
};


#endif // !STUDENT_H