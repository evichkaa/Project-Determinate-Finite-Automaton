#ifndef AUTOMATON_EXCEPTION_H
#define AUTOMATON_EXCEPTION_H

#include <iostream>
#include <exception>
#include "MyString.h"

using namespace std;

class AutomatonException : public std::exception {

public:
	AutomatonException(MyString e = "exception");

	MyString get_exception() const;

private:
	MyString e;

};

ostream& operator << (ostream&, const AutomatonException&);

#endif /* AUTOMATON_EXCEPTION_H */