// Удалить из строки заданное слово.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	char str[100];
	cout << "Введите строку: ";
	setlocale(LC_ALL, ".866");
	cin.getline(str, 100);

	char str2[15];
	setlocale(LC_ALL, "Russian");
	cout << "Введите слово которое вы хотите удалить: ";
	setlocale(LC_ALL, ".866");
	cin >> str2;

	char delim[2] = " ";
	char *s = strtok(str, delim);
	char str3[100] = "";

	while (s != NULL)
	{
		if (strcmp(s, str2))
		{
			strcat(str3, s);
			strcat(str3, " ");
		}
		s = strtok(0, delim);
	}

	setlocale(LC_ALL, "Russian");
	cout << "Исправленное предложение: ";
	setlocale(LC_ALL, ".866");
	cout << str3;

	cout << endl << endl;
	return 0;
}
