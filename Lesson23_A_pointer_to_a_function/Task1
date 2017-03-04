// Реализовать 4 функции на простейшие арифметические операции (+,-,*,/).
// Каждая функция должна принимать два вещественных числа и возвращать результат операции в виде вещественного числа.
// Напишите функцию, которая принимает указатель на функцию в качестве параметра.
// Добавьте меню, в котором пользователь может выбрать желаемую операцию. Меню реализовать двумя способами.

#include <iostream>

using namespace std;

double summa(double, double); // сложение
double difference(double, double); // отрицание
double multiply(double, double); // умножение
double division(double, double); // деление
double(*getfunptr())(double, double); // функция которая возвращает указатель на функцию, а в качестве параметра принимает массив указателя на функцию
void print(double, double, double(*)(double, double)); // наш ответ

int main()
{
	setlocale(LC_ALL, "Russian");
	double a, b;
	cout << "\nПривествую вас, в симуляторе 'Калькулятор'.\n";
	cout << "\nВведите первое число = ";
	cin >> a;
	cout << "Введите второе число = ";
	cin >> b;
	print(a, b, getfunptr());
	cout << "\n\n";
	return 0;
}

double summa(double el1, double el2) // сложение
{
	return el1 + el2;
}

double difference(double el1, double el2) // отрицание
{
	return el1 - el2;
}

double multiply(double el1, double el2) // умножение
{
	return el1 * el2;
}

double division(double el1, double el2) // деление
{
	if (el2 != 0) return el1 / el2;
	else cout << "Делить на ноль нельзя!!!";
}

double(*getfunptr())(double, double) // функция которая возвращает указатель на функцию, а в качестве параметра принимает массив указателя на функцию
{
	double(*ptr)(double, double) = NULL;
	char choice; // выбор
	cout << "\nВыберете что вы хотите сделать с числами\n\n'+'\n'-'\n'*'\n'/' = ";
	cin >> choice;
	switch (choice)
	{
	case '+': ptr = &summa; break;
	case '-': ptr = &difference; break;
	case '*': ptr = &multiply; break;
	case '/': ptr = &division; break;
	}
	cout << endl;
	return ptr;
}

void print(double a, double b, double(*alg)(double, double))
{
	cout << "\nОтвет = " << (*alg)(a, b);
}
