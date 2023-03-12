// tabtenn.cpp -- simple base-class methods
// derived::derived(type1 x, type2 y): base(x,y) // initializer list
#include "tabtenn.h"
#include <iostream>

// 使用对象引用, 其中Class_name是类名, Value的类型为Type_name, 类型名可以和类名相同
// Class_name class(value) 调用了如下的构造函数 Class_name(Type_name)
// Class_name& pclass = class;
// TableTennisPlayer& rt = rp1; TableTennisPlayer* pt = &rp1;
// RatedPlayer(unsigned int r, const TableTennisPlayer* tp):TableTennisPlayer(*tp)
// TableTennisPlayer* pt = &rp1;

// TableTennisPlayer methods
TableTennisPlayer::TableTennisPlayer(const string& fn,
	const string& ln, bool ht)
{
	firstname = fn; lastname = ln; hasTable = ht;
}

int TableTennisPlayer::Name() const
{
	// printf("%s, %s", firstname, lastname);
	return (firstname.size() + lastname.size());
}

// 13.1.3 使用派生类
// RatedPlayer methods
RatedPlayer::RatedPlayer(unsigned int r, const string& fn,
	const string& ln, bool ht) : TableTennisPlayer(fn, ln, ht)
{
	rating = r;
}

RatedPlayer::RatedPlayer(unsigned int r,
	const TableTennisPlayer& tp) : TableTennisPlayer(tp)
{
	rating = r;
}

RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer* tp)
	: TableTennisPlayer(*tp)
{
	rating = tp->Name();
}
