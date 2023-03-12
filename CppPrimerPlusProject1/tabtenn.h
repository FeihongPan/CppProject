#pragma once
// 13.1 一个简单的基类
// tabtenn.h -- a table - tennis
#ifndef TABTENN_H_
#define TABTENN_H_
#include <string>
#include <QtCore/QCoreApplication>
using namespace std;

// simple base class
class TableTennisPlayer
{
private:
	string firstname;
	string lastname;
	bool hasTable;
public:
	TableTennisPlayer(const string& fn = "none",
		const string& ln = "none", bool ht = false);
	int Name() const;
	bool HasTable() const { return hasTable; };
	void setTable(bool v) { hasTable = v; };
};


// simple derived class
class RatedPlayer : public TableTennisPlayer
{
private:
	unsigned int rating;
public:
	RatedPlayer(unsigned int r = 0, const string& fn = "none",
		const string& ln = "none", bool ht = false);
	RatedPlayer(const unsigned int r, const TableTennisPlayer& tp);
	RatedPlayer(unsigned int r, const TableTennisPlayer* tp);
	unsigned int getRating() const { return rating; }
	void setRating(unsigned int r) { rating = r; }
};

#endif // !#define TABTENN_H_
