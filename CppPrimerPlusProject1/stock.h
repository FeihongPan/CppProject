// stock.h -- augmented version
#ifndef STOCK_H_
#define STOCK_H_
#include <QtCore/QCoreApplication>

class Stock // 股票
{
private:
	QString company;
	int shares; // 股票数
	double shareValue; // 股票价值
	double totalValue; // 总价值
	void setTotalValue() { totalValue = shares * shareValue; } // 算总价值
public:
	Stock();
	Stock(const QString& co, long n = 0, double price = 0.);
	~Stock();
	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	double getTotalValue() const;
	const Stock* getTopValue(const Stock* s) const;
	const Stock& getTopValue(const Stock& s) const;
};

#endif // STOCK_H_