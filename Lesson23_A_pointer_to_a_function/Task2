// Реализовать 3 функции, каждая из которых принимает вещественное число и возвращает вещественное число.
// Первая функция вычисляет квадратный корень числа, вторая – куб числа, третья – синус числа.
// Напишите функцию, которая принимает указатель на функцию в качестве параметра.
// Добавьте меню, в котором пользователь может выбрать желаемую операцию. Меню реализовать двумя способами.

#include <iostream>
#include <cmath> // подключение библиотеки математических функций

using namespace std;

int sqrt(int n);
int cube(int n);
int sinus(int n);
void find(int n, int(*func)(int));
int (*choice(int(*a[])(int)))(int);

int main()
{
	setlocale(LC_ALL, "Russian");
	int (*mass[3])(int) = { sqrt, cube, sinus };
	
	int a;
	cout << "Введите число = ";
	cin >> a;

	find(a, choice(mass));
	cout << endl << endl;

	return 0;
}

int sqrt(int n) // Функция нахождения квадратного корня
{
	cout << "\nКвадратный корень числа = ";
	return pow(n, 1. / 2);
}

int cube(int n) // Функция нахождения куба
{
	cout << "\nКуб числа = ";
	return pow(n, 3);
}

int sinus(int n) // Функция нахождения синуса
{
	cout << "\nСинус числа = ";
	return sin(n);
}

void find(int n, int(*func)(int))
{
	cout << (*func)(n);
}

int(*choice(int(*a[])(int)))(int) // меню
{
	int ch;
	cout << "\nВыберите операцию над числом: \n1. Квадратный корень числа\n2. Куб числа\n3. Синус числа\nВаш выбр = ";
	cin >> ch;
	return a[ch - 1];
}
