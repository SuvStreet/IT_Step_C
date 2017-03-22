// Дана строка символов. Определить количество букв, количество цифр и количество остальных символов, присутствующих в строке.

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	char str[1000];
	cout << "Введите строку:  ";
	cin.getline(str, 1000);
	int bukva = 0;
	int cifra = 0;
	int simvol = 0;
	
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (isalpha(str[i]))bukva++;
		else if (isdigit(str[i]))cifra++;
		else simvol++;
	}

	cout << "\nКоличество букв в вашей строке: " << bukva << "\nКоличество цифр в вашей строке: "\
		<< cifra << "\nКоличество символов в вашей строке ( ,.-!:; и т.д.): " << simvol << endl << endl;
	return 0;
}
