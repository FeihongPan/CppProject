// working classes

#ifndef WORKER_H_
#define WORKER_H_

#include <Qtcore>

class Worker // an abstract base class
{
private:
	QString fullname;
	long id;
public:
	Worker() : fullname("no one"), id(0L) {};
	Worker(const QString& s, long n) :fullname(s), id(n) {};
	virtual ~Worker() = 0;
	virtual void set();
	virtual void Show() const;
};

class Waiter : public Worker
{
private:
	int panache;
public:
	Waiter() : Worker(), panache(0) {};
	Waiter(const QString& s, long n, int p = 0) : Worker(s, n), panache(n) {};
	Waiter(const Worker& wk, int p = 0) :Worker(wk), panache(p) {};
	virtual void set();
	virtual void Show() const;
};

class Singer :public Worker
{
protected:
	enum type { other, alto, contralto, soprano, bass, baritone, tenor };
	enum { Vtypes = 7 };
private:
	static char* pv[Vtypes];
	int voice;
public:
	Singer() :Worker(), voice(other) {};
	Singer(const QString& s, long n, int v = other) :Worker(s, n), voice(v) {};
	Singer(const Worker& wk, int v = other) :Worker(wk), voice(v) {};
	virtual void set();
	virtual void Show() const;
};

#endif // !WORKER_H_
