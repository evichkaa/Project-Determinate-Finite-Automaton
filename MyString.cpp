#include "MyString.h"

using namespace std;

/* Конструктор, който може да създава и празен MyString */
MyString::MyString(const char* string)
{
	if (string != "." && string != NULL)
	{
		length = strlen(string);
		this->string = new char[length + 1];
		for (size_t i = 0; i < length; i++)
			this->string[i] = string[i];
		this->string[length] = '\0';
	}
	else
	{
		this->string = new char[1];
		this->string[0] = '\0';
		length = 0;
	}
}

/* Копиращ конструктор */
MyString::MyString(const MyString& right)
{
	length = right.length;
	string = new char[length + 1];
	for (size_t i = 0; i < length; i++)
	{
		string[i] = right.string[i];
	}
	string[length] = '\0';
}

/* Деконструктор */
MyString::~MyString()
{
	if (length != 0)
	{
		delete[] string;
	}
}

/* Оператор за сравнение */
bool MyString::operator == (const MyString& right)
{
	if (this->length == right.length)
	{
		for (size_t i = 0; i < this->length; i++) {
			if (this->string[i] != right.string[i]) {
				return false;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}

/* Оператор за сравнение */
bool MyString::operator != (const MyString& right)
{
	if (this->length != right.length)
	{
		for (size_t i = 0; i < this->length; i++) {
			if (this->string[i] != right.string[i]) {
				return true;
			}
		}
		return false;
	}
	else
	{
		return true;
	}
}

/* Оператор за присвояване */
MyString& MyString::operator = (const MyString& right)
{
	if (this != &right)
	{
		length = right.length;
		if (this != NULL)
		{
			delete[] string;
		}
		string = new char[length + 1];
		for (size_t i = 0; i < length; i++)
		{
			string[i] = right.string[i];
		}
		string[length] = '\0';
	}
	return *this;
}

/* Оператор за 'прибавяне' на друг MyString с присвояване */
MyString& MyString::operator += (const MyString& right)
{
	char* temp = new char[length + right.length + 1];
	for (size_t i = 0; i < length; i++)
	{
		temp[i] = string[i];
	}
	for (size_t i = 0, j = length; i < right.length; i++)
	{
		temp[j++] = right.string[i];
	}
	length += right.length;
	temp[length] = '\0';
	delete[] string;
	string = new char[length + 1];
	for (size_t i = 0; i < length; i++)
	{
		string[i] = temp[i];
	}
	string[length] = '\0';
	delete[] temp;
	return *this;
}

/* Оператор за 'прибавяне' на целочислена стойност към MyString с присвояване */
MyString& MyString::operator += (int value)
{
	size_t size = 0;
	size_t tempValue = value;
	for (; tempValue > 10; tempValue /= 10, size++);
	char* temp = new char[size + 2];
	for (int i = size; i >= 0; i--)
	{
		temp[i] = '0' + (value % 10);
		value /= 10;
	}
	temp[size + 1] = '\0';
	MyString TMP(temp);
	TMP.set_length(size + 4);
	delete[] temp;
	*this += TMP;
	return *this;
}

/* Оператор за 'прибавяне' на друг MyString без присвояване */
MyString MyString::operator + (const MyString& right) const
{
	char* temp = new char[length + right.length + 1];
	for (size_t i = 0; i < length; i++)
	{
		temp[i] = string[i];
	}
	for (size_t i = 0, j = length; i < right.length; i++)
	{
		temp[j++] = right.string[i];
	}
	temp[length + right.length] = '\0';
	MyString TMP(temp);
	delete[] temp;
	return TMP;
}

/* Оператор за 'прибавяне' на целочислена стойност към MyString без присвояване */
MyString MyString::operator + (int value) const
{
	size_t size = 0;
	size_t tempValue = value;
	while (tempValue > 10)
	{
		tempValue /= 10;
		size++;
	}
	char* temp = new char[size + 2];
	for (int i = size; i >= 0; i--)
	{
		temp[i] = '0' + (value % 10);
		value /= 10;
	}
	temp[size + 1] = '\0';
	MyString TMP_R(temp);
	TMP_R.set_length(size + 4);
	delete[] temp;
	MyString TMP(this->get_string());
	TMP += TMP_R;
	return TMP;
}

/* Оператор за обръщане на MyString към целочислен тип */
int MyString::to_int()
{
	/* Проверка дали MyString всъщност е число */
	for (size_t i = 0; i < length; i++)
	{
		if (string[i] < 48 || string[i] > 57)
		{
			return 0;
		}
	}
	int converted = 0;
	for (size_t i = 0; i < length; i++)
	{
		converted += ((string[i] - 48) * pow(10, length - i - 1));
	}
	return converted;
}

/* Getters & Setters */
void MyString::set_string(char* string)
{
	this->length = strlen(string);
	delete[] this->string;
	this->string = new char[length + 1];
	for (size_t i = 0; i < length; i++)
	{
		this->string[i] = string[i];
	}
	this->string[length] = '\0';
}

void MyString::set_length(size_t length)
{
	this->length = length;
}

char* MyString::get_string() const
{
	return string;
}

size_t MyString::get_length() const
{
	return length;
}

/* Предефиниран оператор за извеждане в конзолата */
ostream& operator << (ostream& out, const MyString& object)
{
	out << object.get_string();
	return out;
}

/* Предефиниран оператор за въвеждане чрез конзолата */
istream& operator >> (istream& in, MyString& object)
{
	char* temp = new char[1024];
	in >> temp;
	object.set_string(temp);
	delete[] temp;
	return in;
}