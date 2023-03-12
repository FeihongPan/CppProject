// stock.cpp -- augmented version
#include <iostream>
#include "stock.h"
using namespace std;

Stock::Stock()
{
	company = "no name";
	shares = 0;
	shareValue = 0.;
	totalValue = 0.;
}

Stock::Stock(const QString& co, long n, double price)
{
	company = co;
	if (n < 0)
		shares = 0;
	else
		shares = n;
	shareValue = price;
	setTotalValue();
}

Stock::~Stock()
{
}

void Stock::buy(long num, double price)
{
	if (num < 0)
		return;
	else
		shares += num;
		shareValue = price;
		setTotalValue();
}

void Stock::sell(long num, double price)
{
	if (num < 0)
		return;
	else if (num > shares)
		return;
	else
	{
		shares -= num;
		shareValue = price;
		setTotalValue();
	}
}

void Stock::update(double price)
{
	shareValue = price;
	setTotalValue();
}

double Stock::getTotalValue() const
{
	return totalValue;
}

const Stock* Stock::getTopValue(const Stock* s) const
{
	if (s->getTotalValue() > totalValue)
		return s;
	else
		return this;
}

const Stock& Stock::getTopValue(const Stock& s) const
{
	if (s.getTotalValue() > totalValue)
		return s;
	else
		return *this;
}