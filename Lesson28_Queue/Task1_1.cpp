// Даны две очереди  Q1 и Q2, заполненные произвольными целыми числами.
// Создать третью очередь  Q3, в которую занести сумму элементов, Q3[i] = Q1[i] + Q2[i],
// третью очередь мы заполняем до тех пор, пока одна из очередей не опустеет.
// (Реализация очереди на базе статического массива)

#include<iostream>
#include<cstring>
#include<stdlib.h>

using namespace std;

const int size = 20;
struct FIFO // структура данных
{
	int queue[size]; // очередь
	int head; // голова
	int tail; // хвост
};

void push_back(FIFO* st, int data) // добавление элементов в очередь
{
	if (st->tail + 1 == st->head || st->tail + 1 == size && st->head == 0)
	{
		cout << "Queue is overflowed\n"; // очередь переполнена
		return;
	}
	st->tail++;
	if (st->tail == size) st->tail = 0; // организация кругового цикла для очереди
	st->queue[st->tail] = data;
}

int pop_front(FIFO* st) // взятие элементов из очереди
{
	if (st->head == st->tail)
	{
		//cout << "Queue is empty\n"; // очередь пуста
		return 0;
	}
	st->head++;
	if (st->head == size) st->head = 0; // организация кругового цикла для очереди
	return st->queue[st->head];
}

int main()
{
	setlocale(LC_ALL, "Russian");
	FIFO Q1, Q2, Q3;
	int	size_Q1, size_Q2;
	Q1.head = 0;
	Q1.tail = 0;
	Q2.head = 0;
	Q2.tail = 0;
	Q3.head = 0;
	Q3.tail = 0;

	cout << "Введите количество элементов первой очереди: ";
	cin >> size_Q1;

	for (int i = 0; i < size_Q1; i++) // вводим рандомом элементы первой очереди
	{
		push_back(&Q1, rand() % 10 + 1);
	}

	cout << "Введите количество элементов второй очереди: ";
	cin >> size_Q2;

	for (int i = 0; i < size_Q2; i++) // вводим рандомом элементы второй очереди
	{
		push_back(&Q2, rand() % 10 + 1);
	}

	int x, y, i = 0, a = 0;
	while ((x = pop_front(&Q1)) && (y = pop_front(&Q2)))
	{
		i++;
		push_back(&Q3, x + y);
		cout << "\n[" << i << "] Элемент первой очереди : " << x << " " << endl;
		cout << "[" << a << "] Элемент второй очереди: " << y << " " << endl;
		a++;
	}
	cout << endl;

	int z;
	i = 0, a = 0;
	while (z = pop_front(&Q3))
	{
		i++;
		cout << "[" << i << " + " << a << "] Сумма элементов двух очередей: " << z << endl;
		a++;
	}

	cout << endl;
	return 0;
}
