// Реализовать 3 функции, каждая из которых принимает указатель на массив и количество
// элементов и возвращает указатель на новый массив. Первая функция ищет простые числа и заносит их в новый массив,
// вторая – все числа кратные трем, третья – все четные числа.
// Напишите функцию, которая принимает указатель на функцию в качестве параметра.
// Добавьте меню, в котором пользователь может выбрать желаемую операцию. Меню реализовать двумя способами.
// Сначала посчитайте количество простых элементов в массиве, потом уже создайте новый массив и занесите туда эти числа. 

#include<iostream>
#include<ctime>
using namespace std;

int* give_memory(int *, int);
int* free_memory(int*);
void init_array(int*, int);
void print_array(int*, int, char);
int* simple(int*, int*);
int* three(int*, int*);
int* even(int*, int*);
int* (*getfunptr(int*(*[])(int*, int*)))(int*, int*);
int* returnArray(int*, int*, int*(*)(int*, int*));

int main()
{
	setlocale(LC_ALL, "Russian");
	srand((unsigned)time(0));
	int *(*functions[])(int *, int *) = { simple, three, even };

	int *arr = NULL;
	int size;

	cout << "Введите размер массива = ";
	cin >> size;
	cout << endl;

	arr = give_memory(arr, size);
	init_array(arr, size);

	cout << "Исходный массив:" << endl;
	print_array(arr, size, 'A');
	cout << endl;

	arr = returnArray(arr, &size, getfunptr(functions));
	print_array(arr, size, 'B');
	cout << endl;

	arr = free_memory(arr);

	return 0;
}

int* give_memory(int *A, int size) // Функция распределения динамической памяти
{
	A = (int*)malloc(size * sizeof(int));
	return A;
}

int* free_memory(int* A) // Функция удаления динамического массива
{
	free(A);
	A = NULL;
	return A;
}

void init_array(int* A, int size) // Функция инициализации динамического массива
{
	for (int *i = A; i < A + size; i++)
	{
		*i = rand() % 50;
	}
}

void print_array(int* A, int size, char simvol) // Функция печати динамического массива
{
	for (int i = 0; i < size; i++)
	{
		cout << simvol << "[" << i << "] = " << *(A + i) << "\n";
	}
}

int *simple(int* a, int* size) // Функция проверки элементов массива на простые числа
{
	int *arr = nullptr;
	arr = give_memory(arr, *size);
	int counter = 0;
	for (int i = 0; i < *size; i++)
	{
		bool flag = true;
		for (int j = 2; j < a[i] / 2; j++)
		{
			if (a[i] % j == 0)
			{
				flag = false;
				continue;
			}
		}
		if (flag)
		{
			arr[counter] = a[i];
			counter++;
		}
	}
	*size = counter;
	return arr;
}

int *three(int* a, int* size) // Функция проверки элементов массива на кратность трём
{
	int *arr = nullptr;
	arr = give_memory(arr, *size);
	int counter = 0;
	for (int i = 0; i < *size; i++)
	{
		if (a[i] % 3 == 0)
		{
			arr[counter] = a[i];
			counter++;
		}
	}
	*size = counter;
	return arr;
}

int *even(int* a, int* size) // Функция проверки элементов массива на чётность
{
	int *arr = nullptr;
	arr = give_memory(arr, *size);
	int counter = 0;
	for (int i = 0; i < *size; i++)
	{
		if (a[i] % 2 == 0)
		{
			arr[counter] = a[i];
			counter++;
		}
	}
	*size = counter;
	return arr;
}

int* (*getfunptr(int*(*a[])(int*, int*)))(int*, int*) // меню
{
	int choice;
	cout << "Какие числа вывести в отдельный массив?\n1.Простые числа\n2.Числа кратные трем\n3.Чётные числа\nВаш выбр = ";
	cin >> choice;
	cout << endl;
	return a[choice - 1];
}

int* returnArray(int* a, int* size, int*(*alg)(int*, int*)) // возвращение массива после проверки задонного пользователем
{
	return alg(a, size);
}
