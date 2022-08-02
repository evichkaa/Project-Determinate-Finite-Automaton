#include "MyString.h"
#include "SafeInput.h"
#include <iostream>

using namespace std;

/* ��������� �� ����� �� ���� ���� ���� SafeInput. */
int safe_input_menu_choice()
{
	int input;
	SafeInput<int> sin;
	sin >> input;
	return input;
}

/* ���������� �� �������� � ��������� � ���������� �� �������
���� ��������� safe_input_menu_choice(). */
int main_menu()
{
	system("cls");
	cout << "### Main Menu ###\n\n"
		<< "#1 Input automaton data manually\n"
		<< "#2 Input automaton data by file\n\n"
		<< "#0 Exit program\n"
		<< "\n"
		<< "#: ";
	return safe_input_menu_choice();
}

void undefined_input_error()
{
	system("cls");
	cout << "### Error: This menu option does not exist.Try again. ###\n";
	system("pause");
}