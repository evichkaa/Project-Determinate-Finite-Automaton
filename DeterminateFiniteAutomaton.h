#ifndef _DETERMINATE_FINITE_AUTOMATON_H
#define _DETERMINATE_FINITE_AUTOMATON_H

#include <vector>
#include "State.h"
#include "MyString.h"

using namespace std;

/* Абстрактен базов клас за йерархията */
class DeterminateFiniteAutomaton {

public:
	virtual MyString** get_table() const = 0;
	virtual int get_num_of_states() const = 0;
	virtual int get_num_of_final_states() const = 0;
	virtual int get_num_of_symbols() const = 0;
	virtual State get_init_state() const = 0;
	virtual vector<State> get_states() const = 0;
	virtual vector<State> get_final_states() const = 0;

	virtual void push_new_state(MyString nameOfState) = 0;
	virtual void push_new_final_state(MyString nameOfFinalState) = 0;
	virtual void set_num_of_symbols(int numOfSymbols) = 0;
	virtual void set_num_of_states(int numOfStates) = 0;
	virtual void set_num_of_final_states(int numOfFinalStates) = 0;
	virtual void set_init_state(State initState) = 0;
	virtual void set_states(vector<State> states) = 0;

protected:
	MyString** table;

	int numOfStates;
	vector<State> states;
	
	State initState;
	int numOfFinalStates;
	vector<State> finalStates;

	int numOfSymbols;
};

#endif /* _DETERMINATE_FINITE_AUTOMATON_H */