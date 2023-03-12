// brass.h -- bank account classes
#ifndef BRASS_H_
#define BRASS_H_

#include <QtCore>

class Brass
{
private:
	QString fullName;
	long accountNummer;
	double balance;
public:
	Brass(const QString& s = "Nullbody", long an = -1, double bal = 0.0);
	void Deposit(double amt);
	virtual void Withdraw(double amt);
	double Balance() const;
	virtual void ViewAccount() const;
	virtual ~Brass();
};

class BrassPlus
{
private:
	double maxLoan;
	double rate;
	double owesBank;
public:
	BrassPlus(const QString& s = "Nullbody", long an = -1, double bal = 0.,
		double ml = 500, double r = 0.11125);
	BrassPlus(const Brass& ba, double ml = 500, double r = 0.11125);
	virtual void ViewAccount() const;
	virtual void Withdraw(double amt);
	void ResetMax(double& m) { maxLoan = m; }
	void ResetRate(double& r) { rate = r; }
	void ResetOwes() { owesBank = 0; }
};

#endif // !BRASS_H_
