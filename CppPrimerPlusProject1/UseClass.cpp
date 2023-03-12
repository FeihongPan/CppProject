#include <QtCore/QCoreApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}

// usestock.cpp -- using the Stock class
// compile with stock.cpp
#include "stock.h"
#include "mytime.h"
#include "tabtenn.h"

int useStock()
{
  const int STKS = 4;
  Stock stock1 = Stock("P1", 12, 20.);
  Stock* stock2 = new Stock("P2", 200, 2.);
  Stock& stock3 = stock1;
  const Stock* top = &stock1;
  
  top = top->getTopValue(stock2);
  return 0;
}

void useTime0()
{
	// 未被初始化的对象，调用默认构造函数
	Time planning; // use default 

	// 初始化新对象
	Time* total = new Time(1, 10); // dynamic object
	Time coding(2, 40); // short form
	Time fixing(5, 55);
	total = coding.Sum(fixing);
	planning = fixing.Sum(total);
	planning.Show();
	coding.Show();
	fixing.Show();
	total->Show();

	delete total;
}

void useTime1()
{
	Time planning;
	Time* total = new Time(1, 10); // dynamic object
	Time coding(2, 40);
	Time fixing(5, 55);

	// operator notation
	total = coding + fixing;
	total->Show();

	Time* morefixing = new Time(3, 28);
	total = morefixing->operator+(coding);
	delete total, morefixing;
}

void useTime2()
{
	Time* total = new Time;
	Time diff;
	Time adjusted;
	Time weeding(4, 35);
	Time waxing(2, 47);

	// use operator+()
	total = weeding + waxing;

	// use operator-()
	diff = weeding - &waxing;

	// use operatpr*()
	adjusted = *total * 1.5;
}

void useTabtenn0()
{
	TableTennisPlayer player1("P1", "P2", true);
	TableTennisPlayer* player2 = new TableTennisPlayer("P3", "P4", false);
	player1.Name();
	player2->Name();
}

void useTabtenn1()
{
	TableTennisPlayer player1("p1", "p2", false);
	// 指针对象的实现
	RatedPlayer* rplayer1 = new RatedPlayer(1140, "rp1", "rp2", true);
	player1.Name();
	rplayer1->Name();

	// 引用对象的实现
	RatedPlayer rplayer2(1212, player1);
	RatedPlayer& rplayer3 = rplayer2;
	rplayer3.Name();

	// 13.1.4 基类和派生类的关系
	RatedPlayer rp1(1140, "p1", "p2", true);

	// 可以用基类指针和引用指向子类的对象, 反过来不行
	TableTennisPlayer& rt = rp1;
	TableTennisPlayer* pt = &rp1;
	rt.Name(); // invoke Name() with reference
	pt->Name(); // invoke Name() with pointer
}


