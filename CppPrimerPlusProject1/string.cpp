// string.cpp -- String class methods
#include <string.h> // string.h for some
#include "string.h" // include <iostream>
using namespace std;

//ʹ��new��ʼ������ָ��, ����Class_name������, Value������ΪType_name, ���������Ժ�������ͬ
//Class_name* pclass = new Class_name(value) ���������µĹ��캯�� Class_name(Type_name)
//Time* total = new Time(1, 10);
//Class_name(const Type_name &) -> String::String(const String& st)
//Class_name* ptr = new Class_name; -> Time* total = new Time;

#if 0
// 12.2 �Ľ����String��
// initiallizing static class member
int String::num_srings = 0;
// static methods
int String::Howmany() { return num_srings; }

// class methods
String::String(const char* s) // constructor String from C String
{
	len = strlen(s); // set size
	str = new char[len + 1];
	strcpy(str, s); // initialize pointer
	num_srings++; // set object conut
}
String::String() // default constructor
{
	len = 4; str = new char[1];
	str[0] = '\0'; num_srings++;
}
String::String(const String& st)
{
	num_srings++; // handle static member update
	len = st.len; // same length
	str = new char[len + 1]; // allot space
	strcpy(str, st.str); // copy string to new location
}

String::~String() // necessary destructor
{
	--num_srings; // required
	delete[] str; // required
}

// overloaded operator methods
// assign a String to a String 
String& String::operator=(const String& st)
{
	if (this == &st)
		return *this;
	delete[] str;
	len = st.len;
	str = new char[len + 1];
	strcpy(str, st.str);
	return *this;
}

// assign a C String to a String 
String& String::operator=(const char* s)
{
	delete[] str;
	len = strlen(s);
	str = new char[len + 1];
	strcpy(str, s);
	return *this;
}

// read-write char access for non-const String
char& String::operator[](int i) { return str[i]; }

// read-only char access for const String 
const char& String::operator[](int i) const { return str[i]; }

// overloaded operator friends
bool operator<(const String& st1, const String& st2)
{
	return (strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String& st1, const String& st2)
{
	return st2 < st1;
}

bool operator==(const String& st1, const String& st2)
{
	return (strcmp(st1.str, st2.str) == 0);
}

void sayings1() // using expanded String class
{
	const int ArSize = 10;
	const int MaxLen = 81;

	// 12.5.2 ָ��Ͷ���С��
	// ʹ�ó����ʾ��������ָ������ָ��
	String* glamour;

	// ָ���ʼ��Ϊָ�����еĶ���
	String* first = &sayings[0];

	// ����ʹ��new����ʼ��ָ��,�⽫����һ���µĶ���
	String* favorite = new String(sayings[choice]);

	// ����ʹ��new��������Ӧ���๹�캯������ʼ���´����Ķ���
	// invokes default constructor
	String* sleep = new String;
	// invokes the String(const char*) constructor
	String* glop = new String("my my my");
	// invokes the String(const String&) constructor
	String* favorite = new String(sayings[choice]);

	// ����ʹ�� -> �����ͨ��ָ������෽��
	if (sayings[i].length() < shortest->length());

	// ���ԶԶ���ָ��Ӧ�� * ����ö���
	if (sayings[i].length() < *first) // compare object values
		first = &sayings[i];	// assign object address
}

#endif