#include <iostream>
#include <vector>
#include <fstream>
#include "State.h"
#include "SafeInput.h"
#include "MyString.h"
#include "DeterminateFiniteAutomaton.h"
#include "DeterminateFiniteAutomatonInt.h"
#include "DeterminateFiniteAutomatonChar.h"

using namespace std;

/* Създаване на автомат чрез ръчно въвеждане на данни */
void create_automaton()
{
	system("cls");
	cout << "### Entering data for automaton manually ###\n\n"
		<< "Input a type for the language of the automaton (1 - integer, 2 - character): ";
	int choice;
	SafeInput<int> sin;
	sin >> choice;
	if (choice == 1)
	{
		/* Създаване на автомат с азбука от числа */
		DeterminateFiniteAutomatonInt automaton;
		cin >> automaton; /* Въвеждане на данни за автомата */
		cout << automaton; /* Извеждане на данни за автомата */
		system("pause");
	}
	else if (choice == 2)
	{
		/* Създаване на автомат с азбука от букви и други символи */
		DeterminateFiniteAutomatonChar automaton;
		cin >> automaton; /* Въвеждане на данни за автомата */
		cout << automaton; /* Извеждане на данни за автомата */
		system("pause");
	}
	else
	{
		system("cls");
		cout << "### Error: This option does not exist. Try again. ###\n";
		system("pause");
	}
}

/* Създаване на автомат чрез автоматично въвеждане от файл input.txt,
намиращ се в главната директория на сорс кода */
void file_input_automaton()
{
	system("cls");
	cout << "### Entering data for automaton automatically via a file ###\n"
		<< "Reading file...\n";
	/* Въвеждане на всички данни от файла към автомата */
	DeterminateFiniteAutomatonChar automaton;
	ifstream file("input.txt");
	/* Въвеждане на брой състояния */
	int numOfStates;
	file >> numOfStates;
	automaton.set_num_of_states(numOfStates);
	vector<State> states;
	/* Въвеждане на всяко състояние */
	for (size_t i = 0; i < numOfStates; i++)
	{
		MyString symbol;
		file >> symbol;
		states.push_back(State(symbol));
	}
	automaton.set_states(states);
	/* Въвеждане на брой символи */
	int numOfSymbols;
	file >> numOfSymbols;
	automaton.set_num_of_symbols(numOfSymbols);
	vector<MyString> symbols;
	/* Въвеждане на всеки символ */
	for (size_t i = 0; i < numOfStates; i++)
	{
		MyString symbol;
		file >> symbol;
		symbols.push_back(symbol);
	}
	automaton.set_symbols(symbols);
	MyString** table = new MyString * [numOfStates];
	/* Въвеждане на преходите */
	for (size_t i = 0; i < numOfStates; i++)
	{
		table[i] = new MyString[numOfSymbols];
	}
	for (size_t i = 0; i < numOfStates; i++)
	{
		for (size_t j = 0; j < numOfSymbols; j++)
		{
			MyString symbol;
			file >> symbol;
			table[i][j] = symbol;
		}
	}
	automaton.set_table(table);
	/* Въвеждане на начално състояние */
	MyString initState;
	file >> initState;
	automaton.set_init_state(initState);
	/* Въвеждане на брой финални състояния */
	int numOfFinalStates;
	file >> numOfFinalStates;
	automaton.set_num_of_final_states(numOfFinalStates);
	vector<State> finalStates;
	/* Въвеждане на финални състояния */
	for (size_t i = 0; i < numOfFinalStates; i++)
	{
		MyString symbol;
		file >> symbol;
		finalStates.push_back(State(symbol));
	}
	automaton.set_final_states(finalStates);
	cout << automaton; /* Извеждане на събраните данни за автомата */
	system("pause");
}
