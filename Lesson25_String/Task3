//Строка состоит из целых чисел, возможно отрицательных,
//разделенных пробелами или запятыми, найти сумму этих чисел.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	char str[100];
	cout << "Введите строку: ";
	cin.getline(str, 100);

	char delim[3] = " ,";
	char *s = strtok(str, delim);

	int sum = 0;

	while (s != NULL)
	{
		sum += atoi(s); // преобразуем строку s в тип int
		s = strtok(0, delim);
	}

	cout << "Сумма чисел = " << sum;

	cout << endl << endl;

	return 0;
}
