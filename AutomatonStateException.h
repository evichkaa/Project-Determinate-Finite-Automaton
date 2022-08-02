#ifndef AUTOMATON_STATE_EXCEPTION_H
#define AUTOMATON_STATE_EXCEPTION_H

#include <iostream>
#include <exception>
#include "MyString.h"

using namespace std;

class AutomatonStateException : public std::exception {

public:
	AutomatonStateException(MyString e = "exception");

	MyString get_exception() const;

private:
	MyString e;

};

ostream& operator << (ostream&, const AutomatonStateException&);

#endif /* AUTOMATON_STATE_EXCEPTION_H */