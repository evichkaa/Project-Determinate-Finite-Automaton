#ifndef _MY_STRING_H
#define _MY_STRING_H

#include <iostream>

using namespace std;

/* Собствен String клас, който имплементира почти всички нужни
функции за един string, като използваните променливи тук са
указател от тип char и size_t за дължината на MyString */
class MyString {

public:
	MyString(const char* = ".");
	MyString(const MyString&);
	~MyString();

	bool operator == (const MyString&);
	bool operator != (const MyString&);
	MyString& operator = (const MyString&);
	MyString& operator += (const MyString&);
	MyString& operator += (int);
	MyString operator + (const MyString&) const;
	MyString operator + (int) const;

	int to_int();
	void set_string(char*);
	void set_length(size_t);
	char* get_string() const;
	size_t get_length() const;

private:
	size_t length;
	char* string;

};

ostream& operator << (ostream&, const MyString&);
istream& operator >> (istream&, MyString&);

#endif /* _MY_STRING_H */