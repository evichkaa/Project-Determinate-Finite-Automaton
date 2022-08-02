#include "AutomatonStateException.h"
#include <iostream>

using namespace std;

AutomatonStateException::AutomatonStateException(MyString e) : e(e) {}

MyString AutomatonStateException::get_exception() const
{
	return e;
}

ostream& operator << (ostream& out, const AutomatonStateException& object)
{
	out << object.get_exception();
	return out;
}