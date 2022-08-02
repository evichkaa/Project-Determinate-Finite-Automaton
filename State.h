#ifndef _STATE_H
#define _STATE_H

#include "MyString.h"

using namespace std;

class State {

public:
	State(MyString name = "No Name");

	MyString get_name() const;
	void set_name(MyString name);

private:
	MyString name;

};

ostream& operator << (ostream&, const State&);
istream& operator >> (istream&, State&);

#endif /* _STATE_H */
