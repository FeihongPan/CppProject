// stock.h -- augmented version
#ifndef STOCK_H_
#define STOCK_H_
#include <QtCore/QCoreApplication>

class Stock // ��Ʊ
{
private:
	QString company;
	int shares; // ��Ʊ��
	double shareValue; // ��Ʊ��ֵ
	double totalValue; // �ܼ�ֵ
	void setTotalValue() { totalValue = shares * shareValue; } // ���ܼ�ֵ
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