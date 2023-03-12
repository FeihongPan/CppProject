// interface for a queue
#ifndef QUEUE_H_
#define QUEUE_H_
#include <QtCore/QCoreApplication>

// this queue will contain Customer items
class Customer
{
private:
	long arrive; // arrive time for customer
	int processtime; // processing time for customer
public:
	Customer() { arrive = processtime = 0; }
public:
	void setArriveTime(long time);
	long getArriveTime() const { return arrive; }
	int getProcessTime() const { return processtime; }
};

class Queue
{
private:
	
};

#endif // !QUEUE_H_
