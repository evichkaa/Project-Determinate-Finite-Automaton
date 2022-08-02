#ifndef _DETERMINATE_FINITE_AUTOMATON_CHAR_H
#define _DETERMINATE_FINITE_AUTOMATON_CHAR_H

#include <vector>
#include "State.h"
#include "DeterminateFiniteAutomaton.h"

using namespace std;

class DeterminateFiniteAutomatonChar : public DeterminateFiniteAutomaton {

public:
	DeterminateFiniteAutomatonChar();
	DeterminateFiniteAutomatonChar(int numOfStates, int numOfSymbols, int numOfFinalStates, MyString** table,
		vector<State> states, State* initState, vector<State> finalStates, vector<MyString> symbols);
	~DeterminateFiniteAutomatonChar();

	MyString** get_table() const;
	MyString get_table_at(int i, int j) const;
	int get_num_of_states() const;
	int get_num_of_final_states() const;
	int get_num_of_symbols() const;
	State get_init_state() const;
	vector<State> get_states() const;
	vector<State> get_final_states() const;
	vector<MyString> get_symbols() const;

	void push_new_state(MyString nameOfState);
	void push_new_final_state(MyString nameOfFinalState);
	void push_new_symbol(MyString symbol);
	void set_num_of_states(int numOfStates);
	void set_num_of_symbols(int numOfSymbols);
	void set_num_of_final_states(int numOfFinalStates);
	void set_final_states(vector<State> finalStates);
	void set_init_state(State initState);
	void set_states(vector<State> states);
	void set_symbols(vector<MyString> symbols);
	void set_table_user_input();
	void set_table(MyString** table);

private:
	vector<MyString> symbols;

};

ostream& operator << (ostream&, const DeterminateFiniteAutomatonChar&);
istream& operator >> (istream&, DeterminateFiniteAutomatonChar&);

#endif /* _DETERMINATE_FINITE_AUTOMATON_CHAR_H */