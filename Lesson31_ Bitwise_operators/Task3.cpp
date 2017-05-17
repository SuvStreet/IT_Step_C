// Дан массив целых чисел, в котором все числа кроме одного встречаются четное количество раз,
// одно число встречается нечетное количество раз. Найти это число.
// Решить задачу используя битовые операции.

#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	int arr[] = { 1, 1, 2, 2, 3, 3, 3, 4, 4, 5, 5 }; // сортируем массив
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl;

	for (int i = 1; i < sizeof(arr) / sizeof(int); i += 2)
	{
		if (arr[i] ^ arr[i - 1])
		{
			cout << arr[i - 1];
			break;
		}
	}

	cout << endl;
	return 0;
}
