// Дана шахматная доска.Найти минимальное количество ходов за которое конь переместится из одной клетки в другую.
// Использовать структуру данных очередь.

#include<iostream>
#include<cstring>

using namespace std;

const int size = 130;

struct FIFO
{
	int queue[size];
	int head, tail;
};

void push(FIFO*st, int data)
{
	if (st->tail + 1 == st->head || st->tail + 1 == size &&st->head == 0)
	{
		cout << " queue is full";
		return;
	}
	st->tail++;
	if (st->tail == size) st->tail = 0; //организация кругового цикла для очереди
	st->queue[st->tail] = data;
}

int pop(FIFO *st)
{
	if (st->head == st->tail)
	{
		cout << "queue is empty\n";
		return 0;
	}
	st->head++;
	if (st->head == size) st->head = 0;
	return st->queue[st->head];
}

int function(int x, int y, int x1, int y1, FIFO &que)
{
	que.head = 0;
	que.tail = 0;
	int board[8][8];
	for (int i = 1; i < 8; i++)
	for (int j = 1; j < 8; j++)
		board[i][j] = -1;
	push(&que, y);
	push(&que, x);
	board[x][y] = 0;

	int move = 0, size = 0;
	while (x != x1 || y != y1)
	{
		move++;
		size = (que.tail - que.head) / 2;
		for (int i = 0; i < size; i++)
		{
			x = pop(&que);
			y = pop(&que);
			if (x == x1 && y == y1) break;


			if (x + 2 > 0 && x + 2 <= 8)
			if (y + 1 > 0 && y + 1 <= 8)
			if (board[x + 2][y + 1] == -1)
			{
				board[x + 2][y + 1] = move;
				push(&que, x + 2);
				push(&que, y + 1);
			}

			if (x - 2 > 0 && x - 2 <= 8)
			if (y + 1 > 0 && y + 1 <= 8)
			if (board[x - 2][y + 1] == -1)
			{
				board[x - 2][y + 1] = move;
				push(&que, x - 2);
				push(&que, y + 1);
			}

			if (x + 2 > 0 && x + 2 <= 8)
			if (y - 1 > 0 && y - 1 <= 8)
			if (board[x + 2][y - 1] == -1)
			{
				board[x + 2][y - 1] = move;
				push(&que, x + 2);
				push(&que, y - 1);
			}

			if (x - 2 > 0 && x - 2 <= 8)
			if (y - 1 > 0 && y - 1 <= 8)
			if (board[x - 2][y - 1] == -1)
			{
				board[x - 2][y - 1] = move;
				push(&que, x - 2);
				push(&que, y - 1);
			}

			if (y + 2 > 0 && y + 2 <= 8)
			if (x + 1 > 0 && x + 1 <= 8)
			if (board[x + 1][y + 2] == -1)
			{
				board[x + 1][y + 2] = move;
				push(&que, x + 1);
				push(&que, y + 2);
			}

			if (y - 2 > 0 && y - 2 <= 8)
			if (x + 1 > 0 && x + 1 <= 8)
			if (board[x + 1][y - 2] == -1)
			{
				board[x + 1][y - 2] = move;
				push(&que, x + 1);
				push(&que, y - 2);
			}

			if (y + 2 > 0 && y + 2 <= 8)
			if (x - 1 > 0 && x - 1 <= 8)
			if (board[x - 1][y + 2] == -1)
			{
				board[x - 1][y + 2] = move;
				push(&que, x - 1);
				push(&que, y + 2);
			}

			if (y - 2 > 0 && y - 2 <= 8)
			if (x - 1 > 0 && x - 1 <= 8)
			if (board[x - 1][y - 2] == -1)
			{
				board[x - 1][y - 2] = move;
				push(&que, x - 1);
				push(&que, y - 2);
			}
		}
	}
	return board[x][y];
}

int main()
{
	setlocale(LC_ALL, "Russian");
	FIFO que;
	que.head = 0;
	que.tail = 0;
	int x, y;
	cout << "Поле 8х8. По горизонтали от 0 до 7. По вертикали от 0 до 7.\n\n";
	cout << "Введите начальное положение коня(через пробел, первое горизонталь):  ";
	cin >> x >> y; //начальные координаты
	int x1, y1;
	cout << "Введите конечные результаты(через пробел, первое горизонталь): ";
	cin >> x1 >> y1; //конечные координаты

	cout << "\nНужно пройти " << function(x, y, x1, y1, que) << " ход(-ов, -a)" << endl << endl;

	return 0;
}
