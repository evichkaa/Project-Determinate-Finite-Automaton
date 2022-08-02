#include "DeterminateFiniteAutomatonInt.h"
#include "AutomatonException.h"
#include "AutomatonStateException.h"
#include "SafeInput.h"
#include <exception>
#include <iostream>
#include <vector>

using namespace std;

DeterminateFiniteAutomatonInt::DeterminateFiniteAutomatonInt() {}

DeterminateFiniteAutomatonInt::DeterminateFiniteAutomatonInt(int numOfStates, int numOfSymbols, int numOfFinalStates, 
	MyString** table, vector<State> states, State* initState, vector<State> finalStates, vector<int> symbols)
{
	this->numOfStates = numOfStates;
	this->numOfSymbols = numOfSymbols;
	this->numOfFinalStates = numOfFinalStates;
	this->states = states;
	this->initState = *initState;
	this->finalStates = finalStates;
	this->table = table;
	this->symbols = symbols;
}

DeterminateFiniteAutomatonInt::~DeterminateFiniteAutomatonInt()
{
	for (size_t i = 0; i < numOfStates; i++) {
		delete[] table[i];
	}
	delete[] table;
}

/* Getters & Setters */
MyString** DeterminateFiniteAutomatonInt::get_table() const
{
	return table;
}

MyString DeterminateFiniteAutomatonInt::get_table_at(int i, int j) const
{
	return table[i][j];
}

int DeterminateFiniteAutomatonInt::get_num_of_states() const
{
	return numOfStates;
}

int DeterminateFiniteAutomatonInt::get_num_of_final_states() const
{
	return numOfFinalStates;
}

int DeterminateFiniteAutomatonInt::get_num_of_symbols() const
{
	return numOfSymbols;
}

vector<State> DeterminateFiniteAutomatonInt::get_states() const
{
	return states;
}

vector<State> DeterminateFiniteAutomatonInt::get_final_states() const
{
	return finalStates;
}

vector<int> DeterminateFiniteAutomatonInt::get_symbols() const
{
	return symbols;
}

State DeterminateFiniteAutomatonInt::get_init_state() const
{
	return initState;
}

void DeterminateFiniteAutomatonInt::push_new_state(MyString nameOfState)
{
	this->states.push_back(State(nameOfState));
}

void DeterminateFiniteAutomatonInt::push_new_final_state(MyString nameOfFinalState)
{
	bool exists = false;
	for (auto it = this->states.begin(); it != this->states.end(); ++it)
	{
		if (it->get_name() == nameOfFinalState)
		{
			exists = true;
			this->finalStates.push_back(State(nameOfFinalState));
		}
	}
	if (exists == false)
	{
		throw AutomatonStateException("State does not exist.");
	}

}

void DeterminateFiniteAutomatonInt::push_new_symbol(int symbol)
{
	symbols.push_back(symbol);
}

void DeterminateFiniteAutomatonInt::set_num_of_states(int numOfStates)
{
	this->numOfStates = numOfStates;
}

void DeterminateFiniteAutomatonInt::set_num_of_symbols(int numOfSymbols)
{
	this->numOfSymbols = numOfSymbols;
}

void DeterminateFiniteAutomatonInt::set_num_of_final_states(int numOfFinalStates)
{
	this->numOfFinalStates = numOfFinalStates;
}

void DeterminateFiniteAutomatonInt::set_final_states(vector<State> finalStates)
{
	this->finalStates = finalStates;
}

void DeterminateFiniteAutomatonInt::set_init_state(State initState)
{
	bool exists = false;
	for (auto it = this->states.begin(); it != this->states.end(); ++it)
	{
		if (it->get_name() == initState.get_name())
		{
			exists = true; 
			this->initState = initState;
		}
	}
	if (exists == false)
	{
		throw AutomatonStateException("State does not exist.");
	}
}

void DeterminateFiniteAutomatonInt::set_states(vector<State> states)
{
	this->states = states;
}

void DeterminateFiniteAutomatonInt::set_symbols(vector<int> symbols)
{
	this->symbols = symbols;
}

void DeterminateFiniteAutomatonInt::set_table(MyString** table)
{
	this->table = table;
}

void DeterminateFiniteAutomatonInt::set_table_user_input()
{
	/* Двумерен динамичен масив за функцията на преходите */
	this->table = new MyString * [numOfStates];
	for (size_t i = 0; i < numOfStates; i++)
	{
		this->table[i] = new MyString[numOfSymbols];
	}
	for (size_t i = 0; i < numOfStates; i++)
	{
		for (size_t j = 0; j < numOfSymbols; j++)
		{
			cout << "Please enter (" << states.at(i) << ", " << symbols.at(j) << ")-> ";
			MyString symbol;
			cin >> symbol;
			this->table[i][j] = symbol;
		}
	}
}

/* Предефиниран оператор за извеждане в конзолата */
ostream& operator << (ostream& out, const DeterminateFiniteAutomatonInt& object)
{
	out << "\nAutomaton:\n\n"
		<< "Number of symbols: " << object.get_num_of_symbols() << "\n"
		<< "Symbols: ";
	vector<int> symbols = object.get_symbols();
	for (auto it = symbols.begin(); it != symbols.end(); ++it)
	{
		out << *it << " ";
	}
	out << "\n\n";
	out << "Number of states: " << object.get_num_of_states() << "\n"
		<< "States: ";
	vector<State> states = object.get_states();
	for (auto it = states.begin(); it != states.end(); ++it)
	{
		out << *it << " ";
	}
	out << "\n\n";
	out << "Initial state: " << object.get_init_state() << "\n"
		<< "Number of final states: " << object.get_num_of_final_states() << "\n"
		<< "Final states: ";
	vector<State> finalStates = object.get_final_states();
	for (auto it = finalStates.begin(); it != finalStates.end(); ++it)
	{
		out << *it << " ";
	}
	out << "\n\n";
	out << "Transitions: \n";
	for (size_t i = 0; i < object.get_num_of_states(); i++)
	{
		for (size_t j = 0; j < object.get_num_of_symbols(); j++)
		{
			out << "(" << states.at(i) << ", " << symbols.at(j) << ")-> "
				<< object.get_table_at(i, j) << "\n";
		}
	}
	return out;
}

/* Предефиниран оператор за въвеждане чрез конзолата */
istream& operator >> (istream& in, DeterminateFiniteAutomatonInt& object)
{
	/* Въвеждане на брой на състоянията и самите състояния */
	cout << "Please enter the number of states: ";
	SafeInput<int> sint;
	int numOfStates;
	do {
		sint >> numOfStates;
	} while (numOfStates < 0);
	object.set_num_of_states(numOfStates);
	for (size_t i = 1; i <= numOfStates; i++)
	{
		cout << "Please enter state number[" << i << "]: ";
		MyString nameOfState;
		in >> nameOfState;
		object.push_new_state(nameOfState);
	}

	/* Въвеждане на броя символи от азбуката и самите символи */
	cout << "Please enter the number of symbols in the language of the automaton: ";
	int numOfSymbols;
	do {
		sint >> numOfSymbols;
	} while (numOfSymbols < 0);
	object.set_num_of_symbols(numOfSymbols);
	for (size_t i = 1; i <= numOfSymbols; i++)
	{
		cout << "Please enter symbol number[" << i << "]: ";
		int symbol;
		sint >> symbol;
		object.push_new_symbol(symbol);
	}

	/* Функция на преходите */
	object.set_table_user_input();

	/* Въвеждане на начално състояние */
	cout << "Please enter an initial state: ";
	bool initStateSet = false;
	MyString initStateName;
	do { /* Функцията set_init_state проверява дали това състояние съществува
	   и хвърля exception от тип AutomatonStateException, който се прихваща и обработва тук. */
		in >> initStateName;
		try
		{
			object.set_init_state(State(initStateName));
			initStateSet = true;
		}
		catch (AutomatonStateException e)
		{
			cerr << "Exception: " << e << "\n";
			cout << "Try again: ";
		}
	} while (initStateSet == false);

	/* Въвеждане на крайни състояния */
	cout << "Please enter the number of final states: ";
	int numOfFinalStates;
	sint >> numOfFinalStates;
	object.set_num_of_final_states(numOfFinalStates);
	for (size_t i = 1; i <= numOfFinalStates; i++)
	{
		cout << "Please enter state number[" << i << "]: ";
		bool finalStateSet = false;
		MyString nameOfFinalState;
		do { /* Функцията push_new_final_state проверява дали това състояние съществува
			 и хвърля exception от тип AutomatonStateException, който се прихваща и обработва тук. */
			in >> nameOfFinalState;
			try
			{
				object.push_new_final_state(nameOfFinalState);
				finalStateSet = true;
			}
			catch (AutomatonStateException e)
			{
				cerr << "Exception: " << e << "\n";
				cout << "Try again: ";
			}
		} while (finalStateSet == false);	
	}
	return in;
}