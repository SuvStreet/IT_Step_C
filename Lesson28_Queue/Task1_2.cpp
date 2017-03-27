// Даны две очереди  Q1 и Q2, заполненные произвольными целыми числами.
// Создать третью очередь  Q3, в которую занести сумму элементов, Q3[i] = Q1[i] + Q2[i],
// третью очередь мы заполняем до тех пор, пока одна из очередей не опустеет.
// (Реализация очереди на базе динамического списка)

#include<iostream>
#include<cstring>
#include<stdlib.h>

using namespace std;

struct Node // создание узла очереди
{
	int data; // данные которые хранятся в узле
	Node* next; // указатель на следующий узел
};

struct FIFO // объявление очереди
{
	Node* head; // указатель на голову
	Node* tail; // указатель на хвост
};

void init(FIFO* q) // инициализация очереди
{
	q->head = NULL; // голова пуста ссылаемся на нуль
	q->tail = NULL; // хвост пуст ссылаемся на нуль
}

FIFO push_back(FIFO que, int value) // добовляем элемент в очередь
{
	Node* cur = (Node*)malloc(sizeof(Node)); // создаёт узел
	cur->data = value; // сохраняем данные в новый узел
	cur->next = NULL; // задаём указатель
	if (que.tail) // если есть элементы в очереди
		que.tail->next = cur; // переместили указатель хвоста с NULL на новый элемент cur
	que.tail = cur; // изменили хвост очереди на добавленный элемент
	if (que.head == NULL) // если в очереди ничего не было
		que.head = que.tail; // то изменяем и голову очереди
	return que;
}

int pop_front(FIFO* que) // удаление элементов из очереди
{
	int temp;
	Node* cur = que->head; // создаём копию головы очереди
	if (que->head == NULL) // если очередь пуста выходим из функции
	{
		//cout << "Queue is empty\n"; // очередь пуста
		return 0;
	}
	que->head = cur->next; // перемещение головы на следующий элемент
	temp = cur->data; // копируем данные из головы в переменную temp
	free(cur); // удаляем узел
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
