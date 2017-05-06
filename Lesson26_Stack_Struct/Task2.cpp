// Пусть дана без ошибок формула, имеющая следующий синтаксис :
// <формула>:: = <цифра> | max(<формула>, < формула >) | min(<формула>, < формула >)
// <цифра>:: = 0  1  2  3  4  5  6  7  8   9
// Например, 8 или max(4, min(3, 5)) или  min(min(3, 5), max(2, max(3, 4))).
// Вычислить значение формулы, используя структуру данных стек.

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;

const int size = 20;
struct LIFO // структура данных
{
	char stack[size];
	int top;
};

void push(LIFO* st, char ch) // добавление элементов в стек
{
	if (st->top == size)
	{
		cout << "Steck is overflowed\n"; // стек переполнен
		return;
	}
	st->stack[st->top++] = ch;
}

char pop(LIFO* st) // взятие элементов из стека
{
	if (st->top == 0)
	{
		cout << "Steck is empty\n"; // стек пустой
		return 0;
	}
	return st->stack[--st->top];
}

char max(char a, char b)
{
	if (a > b) return a;
	else return b;
}

char min(char a, char b)
{
	if (a < b) return a;
	else return b;
}

char check(char* str)
{
	LIFO st;
	st.top = 0;
	int i = 0;
	while (str[i])
	{
		if (str[i] == 'a')push(&st, str[i]);
		else if (str[i] == 'i')push(&st, str[i]);
		else if (isdigit(str[i]))push(&st, str[i]); // isdigit - возвращает значение true, если с является цифрой, и false в других случаях
		else if (str[i] == ')')
		{
			char a, b, c;
			a = pop(&st);
			b = pop(&st);
			c = pop(&st);

			if (c == 'a') push(&st, max(a, b));
			else if (c == 'i') push(&st, min(a, b));
		}
		i++;
	}
	return st.stack[st.top - 1];
}

int main()
{
	setlocale(LC_ALL, "Russian");
	char str[1000];
	cout << "Введите строку:  ";
	cin.getline(str, 1000);
	cout << check(str) << endl << endl;
	return 0;
}
