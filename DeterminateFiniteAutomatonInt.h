#ifndef _DETERMINATE_FINITE_AUTOMATON_INT_H
#define _DETERMINATE_FINITE_AUTOMATON_INT_H

#include <vector>
#include "State.h"
#include "DeterminateFiniteAutomaton.h"

using namespace std;

class DeterminateFiniteAutomatonInt : public DeterminateFiniteAutomaton {

public:
	DeterminateFiniteAutomatonInt();
	DeterminateFiniteAutomatonInt(int numOfStates, int numOfSymbols, int numOfFinalStates, MyString** table,
		vector<State> states, State* initState, vector<State> finalStates, vector<int> symbols);
	~DeterminateFiniteAutomatonInt();

	MyString** get_table() const;
	MyString get_table_at(int i, int j) const;
	int get_num_of_states() const;
	int get_num_of_final_states() const;
	int get_num_of_symbols() const;
	State get_init_state() const;
	vector<State> get_states() const;
	vector<State> get_final_states() const;
	vector<int> get_symbols() const;

	void push_new_state(MyString nameOfState);
	void push_new_final_state(MyString nameOfFinalState);
	void push_new_symbol(int symbol);
	void set_num_of_states(int numOfStates);
	void set_num_of_symbols(int numOfSymbols);
	void set_num_of_final_states(int numOfFinalStates);
	void set_final_states(vector<State> finalStates);
	void set_init_state(State initState);
	void set_states(vector<State> states);
	void set_symbols(vector<int> symbols);
	void set_table_user_input();
	void set_table(MyString** table);

private:
	vector<int> symbols;

};

ostream& operator << (ostream&, const DeterminateFiniteAutomatonInt&);
istream& operator >> (istream&, DeterminateFiniteAutomatonInt&);

#endif /* _DETERMINATE_FINITE_AUTOMATON_INT_H */