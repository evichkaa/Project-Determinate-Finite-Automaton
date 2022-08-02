#include <iostream>
#include "MyString.h"

using namespace std;

int main_menu();
void undefined_input_error();

void create_automaton();
void file_input_automaton();

bool running = true;

int main(int argc, const char* argv[])
{
	do
	{
		/* ������ ���� */
		switch (main_menu())
		{
			/* ����� ��������� �� ����� */
		case 1:
			create_automaton();
			break;
			/* ����������� ��������� �� ����� ���� ���� */
		case 2:
			file_input_automaton();
			break;
			/* ���� �� ���������� */
		case 0:
			running = false;
			break;
		default:
			undefined_input_error();
			break;
		}
	} while (running);

	return 0;
}