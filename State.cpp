#include "State.h"

using namespace std;

State::State(MyString name) : name(name) {}

MyString State::get_name() const
{
	return name;
}

void State::set_name(MyString name)
{
	this->name = name;
}

/* Предефиниран оператор за извеждане в конзолата */
ostream& operator << (ostream& out, const State& object)
{
	out << object.get_name();
	return out;
}

/* Предефиниран оператор за въвеждане чрез конзолата */
istream& operator >> (istream& in, State& object)
{
	MyString name;
	in >> name;
	object.set_name(name);
	return in;
}