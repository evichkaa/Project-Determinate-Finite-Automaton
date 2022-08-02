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
		/* Главно меню */
		switch (main_menu())
		{
			/* Ръчно въвеждане на данни */
		case 1:
			create_automaton();
			break;
			/* Автоматично въвеждане на данни чрез файл */
		case 2:
			file_input_automaton();
			break;
			/* Край на програмата */
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