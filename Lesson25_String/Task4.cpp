//Строка представляет собой арифметическое бесскобочное выражение, состоящее из операндов и арифметических бинарных операций(+, -,*, /).
//•	Вывести операции.
//•	Вывести операнды.
//•	Вычислить значение выражения.

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	char str[100]; // массив строки
	char *s; // указатель
	char oper[20]; // массив операций
	const char operation[5] = "*/+-"; // массив операций константа для использование внутри функции strpbrk
	int arr[20]; // массив операндов(числа)
	int	n_arr = 0; // количество чисел в строке
	int size_operation = 0; // количество операций в строке

	cout << "Введите арифметическое вырожение:	";
	cin.getline(str, 100);

	while (s = strpbrk(str, operation)) // заполнения массива операциями из строки
	{
		oper[size_operation++] = *s;
		*s = ' ';
	}

	s = strtok(str, " "); 
	while (s) // заполнения массив операндов из строки
	{
		arr[n_arr++] = atoi(s);
		s = strtok(0, " ");
	}

	cout << "\nВаши числа введённые выше = ";
	for  (int i = 0; i < n_arr; i++) // выводим операнды(числа)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	 
	cout << "Ваши математические операции введённые выше = ";
	for (int i = 0; i < size_operation; i++) // выводим операции(*/+-)
	{
		cout << oper[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < size_operation; i++) // операнды * и / имеют более высокий приоритет над + и -, делаем цикл на проверку операндов, выполняем операцию и смещаем размер массива на -2
	{
		if (oper[i] == '*')
		{
			arr[i] *= arr[i + 1];
			memcpy(&arr[i + 1], &arr[i + 2], sizeof(int)*n_arr - (i + 1) - 1);
			n_arr--;
			memcpy(&oper[i], &oper[i + 1], size_operation - (i + 1));
			size_operation--;
			i--;
		}
		else if (oper[i] == '/')
		{
			arr[i] /= arr[i + 1];
			memcpy(&arr[i + 1], &arr[i + 2], sizeof(int)*n_arr - (i + 2));
			n_arr--;
			memcpy(&oper[i], &oper[i + 1], size_operation - (i + 1));
			size_operation--;
			i--;
		}
	}

	for (int i = 0; i < size_operation; i++) // завершаем решение массива выполняя оставшиеся операции + и -
	{
		if (oper[i] == '+')
		{
			arr[i + 1] += arr[i];
		}
		else if (oper[i] == '-')
		{
			arr[i + 1] = arr[i] - arr[i + 1];
		}
	}
	cout << "\nОтвет = " << arr[size_operation] << endl << endl;
	return 0;
}
