// Напишите программу, которая определит, правильно ли расставлены скобки в выражении,
// если оно состоит из скобок типа : ()[] {}.
// (использовать структуру данных стек)

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

const int size = 20;
struct LIFO
{
	char stack[size];
	int top;
};
void push(LIFO *st, char ch)
{
	if (st->top == size)
	{
		cout << "Stack is overflow"; // стек переполнение, стек заполнен
		return;
	}

	st->stack[st->top++] = ch;
}
char pop(LIFO *st)
{
	if (st->top == 0){
		cout << "Stack is empty"; // стек пуст, стек освобождён
		return 0;
	}

	return st->stack[--st->top];
}

bool check(char *str)
{
	LIFO st;
	st.top = 0;
	int i = 0;
	while (str[i] != NULL)
	{
		if (str[i] == '(' || str[i] == '{' || str[i] == '[')
			push(&st, str[i]);
		else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
		{
			if (str[i] == ')' && st.stack[st.top - 1] == '(') pop(&st);
			else if (str[i] == '}' && st.stack[st.top - 1] == '{') pop(&st);
			else if (str[i] == ']' && st.stack[st.top - 1] == '[') pop(&st);
			else return 0;
		}
		i++;
	}
	if (st.top != 0) return false;
	else return true;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	char str[100];
	cout << "Введите скобки: ";
	cin >> (str);
	if (check(str))
		cout << "Скобки расставлены правильно\n";
	else cout << "Скобки расставлены неправльно\n";

	cout << endl;

	return 0;
}
