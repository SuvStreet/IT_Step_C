//Дана строка символов. Определить количество букв,
//количество цифр и количество остальных символов, присутствующих в строке.

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	char str[100];
	cout << "Введите строку символов:\n";
	cin.getline(str, 100);
	int number = 0, letter = 0;

	for (int i = 0; i < strlen(str); i++)
	{
		if (isalpha(str[i])) letter++; // isalpha(str[i]) возвращает значение true, если str[i] является буквой, и false в других случаях
		if (isdigit(str[i])) number++; // isdigit(str[i]) возвращает значение true, если str[i] является цифрой, и false в других случаях
	}

	cout << "Количество букв: " << letter << "\nКоличетво чисел: " << number << "\nКоличиство остальных символов: " << strlen(str) - letter - number;

	cout << endl;

	return 0;
}
