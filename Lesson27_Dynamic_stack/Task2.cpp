// В постфиксной записи(или обратной польской записи) операция записывается после двух операндов.
// Например, сумма двух чисел A и B записывается как A B + .
// Запись B C + D * обозначает, привычное нам(B + C) * D, а запись A B C + D * +означает A + (B + C) * D.
// Достоинство постфиксной записи в том, что она не требует скобок и дополнительных соглашений о приоритете операторов для своего чтения.
// Вычислить значение выражения, записанного в постфиксной записи используя динамическую структуру данных стек.

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;

struct LIFO
{
	char data;
	LIFO *prev;
};

LIFO *push(LIFO *top, char ch)
{
	LIFO *cur = (LIFO*)malloc(sizeof(LIFO));
	cur->data = ch;
	cur->prev = top;
	top = cur;
	return top;
}

char pop(LIFO **top)
{
	char temp;
	LIFO *cur = *top;
	if (*top == NULL) return 0;
	temp = (*top)->data;
	*top = cur->prev;
	free(cur);
	return temp;
}

int pol_function(char str_2[][5], int size)
{
	LIFO *st = NULL;
	int n1, n2, oper;
	int i = 0;
	while (i != size)
	{
		if (isdigit(*str_2[i]))
			st = push(st, atoi(str_2[i]));
		else
		{
			n2 = pop(&st);
			n1 = pop(&st);

			if (*str_2[i] == '*') st = push(st, n1*n2);
			else if (*str_2[i] == '/') st = push(st, n1 / n2);
			else if (*str_2[i] == '+') st = push(st, n1 + n2);
			else if (*str_2[i] == '-') st = push(st, n1 - n2);
		}
		i++;
	}
	return pop(&st);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	char str[30];
	char str_2[30][5];
	cout << "Введите польскую запись: ";
	cin.getline(str, 30);
	char prob[] = " ";
	char *ptr = strtok(str, prob);
	int i = 0;
	while (ptr != NULL)
	{
		strcpy(str_2[i], ptr);
		i++;
		ptr = strtok(0, prob);
	}
	cout << "Ответ = " << pol_function(&str_2[0], i);

	cout << endl;

	return 0;
}
