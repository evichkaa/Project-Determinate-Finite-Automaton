#ifndef SAFE_INPUT_H
#define SAFE_INPUT_H

#include <iostream>
#include "MyString.h"

using namespace std;

template <typename T>
class SafeInput {

public:
	/* ��������� '>>' � ������������ �� ��������� �� �����, ����� �� �� ��� Template t,
	 ���� ��� ����������� ���� cin ��������� ������ � ��������� ������� �����������
	 ������� ��� ���������, �� �� �������� ������������ �� ���������� ��������. */
	inline SafeInput& operator >> (T& t) {
		for (cin >> t; cin.fail(); cin.clear(),
			cout << "Error: Invalid input. Try again: ",
			cin.getline(buffer, 1023),
			cin >> t);
		return *this;
	}

private:
	MyString error;
	char buffer[1024];

};

#endif /* SAFE_INPUT_H */