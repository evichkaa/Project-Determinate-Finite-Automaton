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

/* ��������� �� ������� ���� ����� ��������� �� ����� */
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
		/* ��������� �� ������� � ������ �� ����� */
		DeterminateFiniteAutomatonInt automaton;
		cin >> automaton; /* ��������� �� ����� �� �������� */
		cout << automaton; /* ��������� �� ����� �� �������� */
		system("pause");
	}
	else if (choice == 2)
	{
		/* ��������� �� ������� � ������ �� ����� � ����� ������� */
		DeterminateFiniteAutomatonChar automaton;
		cin >> automaton; /* ��������� �� ����� �� �������� */
		cout << automaton; /* ��������� �� ����� �� �������� */
		system("pause");
	}
	else
	{
		system("cls");
		cout << "### Error: This option does not exist. Try again. ###\n";
		system("pause");
	}
}

/* ��������� �� ������� ���� ����������� ��������� �� ���� input.txt,
������� �� � �������� ���������� �� ���� ���� */
void file_input_automaton()
{
	system("cls");
	cout << "### Entering data for automaton automatically via a file ###\n"
		<< "Reading file...\n";
	/* ��������� �� ������ ����� �� ����� ��� �������� */
	DeterminateFiniteAutomatonChar automaton;
	ifstream file("input.txt");
	/* ��������� �� ���� ��������� */
	int numOfStates;
	file >> numOfStates;
	automaton.set_num_of_states(numOfStates);
	vector<State> states;
	/* ��������� �� ����� ��������� */
	for (size_t i = 0; i < numOfStates; i++)
	{
		MyString symbol;
		file >> symbol;
		states.push_back(State(symbol));
	}
	automaton.set_states(states);
	/* ��������� �� ���� ������� */
	int numOfSymbols;
	file >> numOfSymbols;
	automaton.set_num_of_symbols(numOfSymbols);
	vector<MyString> symbols;
	/* ��������� �� ����� ������ */
	for (size_t i = 0; i < numOfStates; i++)
	{
		MyString symbol;
		file >> symbol;
		symbols.push_back(symbol);
	}
	automaton.set_symbols(symbols);
	MyString** table = new MyString * [numOfStates];
	/* ��������� �� ��������� */
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
	/* ��������� �� ������� ��������� */
	MyString initState;
	file >> initState;
	automaton.set_init_state(initState);
	/* ��������� �� ���� ������� ��������� */
	int numOfFinalStates;
	file >> numOfFinalStates;
	automaton.set_num_of_final_states(numOfFinalStates);
	vector<State> finalStates;
	/* ��������� �� ������� ��������� */
	for (size_t i = 0; i < numOfFinalStates; i++)
	{
		MyString symbol;
		file >> symbol;
		finalStates.push_back(State(symbol));
	}
	automaton.set_final_states(finalStates);
	cout << automaton; /* ��������� �� ��������� ����� �� �������� */
	system("pause");
}
