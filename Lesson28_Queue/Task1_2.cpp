// Даны две очереди  Q1 и Q2, заполненные произвольными целыми числами.
// Создать третью очередь  Q3, в которую занести сумму элементов, Q3[i] = Q1[i] + Q2[i],
// третью очередь мы заполняем до тех пор, пока одна из очередей не опустеет.
// (Реализация очереди на базе динамического списка)

#include<iostream>
#include<cstring>
#include<stdlib.h>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

struct FIFO // структура данных
{
	Node* head; // голова
	Node* tail; // хвост
};

void init(FIFO* q)
{
	q->head = NULL; // если голова пуста ссылаемся на нуль
	q->tail = NULL;
}

FIFO push_back(FIFO que, int value) // добавление элементов в очередь
{
	Node* cur = (Node*)malloc(sizeof(Node)); // создаём новый узел
	cur->data = value;
	cur->next = NULL;
	if (que.tail)
		que.tail->next = cur;
	que.tail = cur;
	if (que.head == NULL)
		que.head = que.tail;
	return que;
}

int pop_front(FIFO* que) // взятие элементов из очереди
{
	int temp;
	Node* cur = que->head;
	if (que->head == NULL)
	{
		//cout << "Queue is empty\n"; // очередь пуста
		return 0;
	}
	que->head = cur->next;
	temp = cur->data;
	free(cur);
	return temp;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	FIFO Q1, Q2, Q3;
	int	size_Q1, size_Q2;
	init(&Q1);
	init(&Q2);
	init(&Q3);

	cout << "Введите количество элементов первой очереди: ";
	cin >> size_Q1;

	for (int i = 0; i < size_Q1; i++) // вводим рандомом элементы первой очереди
	{
		Q1=push_back(Q1, rand() % 10 + 1);
	}

	cout << "Введите количество элементов второй очереди: ";
	cin >> size_Q2;

	for (int i = 0; i < size_Q2; i++) // вводим рандомом элементы второй очереди
	{
		Q2=push_back(Q2, rand() % 10 + 1);
	}

	int x, y, i = 0, a = 0;
	while ((x = pop_front(&Q1)) && (y = pop_front(&Q2)))
	{
		i++;
		Q3=push_back(Q3, x + y);
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
