#include "AutomatonException.h"

AutomatonException::AutomatonException(MyString e) : e(e) {}

MyString AutomatonException::get_exception() const
{
	return e;
}

ostream& operator << (ostream& out, const AutomatonException& object)
{
	out << object.get_exception();
	return out;
}
