// Добавить в односвязный список добавление элемента в конец списка,
// удаление из конца списка, написать функцию добавления в отсортированный список с сохранением порядка.

#include<iostream> 
#include<cstring>

using namespace std;

struct Node //объявление узла
{
	int data; //данные узла
	Node*next; //указатель на следующий узел
};

Node* insert(Node *head, int value, int pos) //добавление по индексу
{
	Node* cur = (Node*)malloc(sizeof(Node));//создает узел
	cur->data = value; //сохраняем данные в новый узел
	cur->next = NULL; //задаем указатель
	if (pos == 0) //если номер ноль до добавление элемента в начало списка
	{
		cur->next = head; //указатель нового элемента направляем на текущую голову
		head = cur; //смещение головы списка
		return head;
	}
	Node*element = head; //создаем вспомогательный элемент 
	for (int i = 0; (i < pos) && (element != NULL); i++, element = element->next); //поиск позиции для вставки
	if (element) //проверка на допустимость позиции
	{
		cur->next = element->next; //присвоение новому элементу указателя на элемент после него в списке
		element->next = cur; //присвоение предыдущему (находящемуся на введенной позиции) элементу указателя на новый элемент
	}
	else cout << "Error";
	return head;
}

Node*insert_back(Node *head, int value) //добавление по индексу//только в конец списка
{
	Node* cur = (Node*)malloc(sizeof(Node));
	cur->data = value;
	cur->next = NULL;
	if (!head)
	{
		cur->next = head;
		head = cur;
		return head;
	}
	Node*element = head;
	for (element; element->next != NULL; element = element->next);
	if (element) element->next = cur;
	else cout << "Error";
	return head;
}

Node* insert_sort(Node *head, int value) //добавление по индексу//в отсортированный список
{
	Node* cur = (Node*)malloc(sizeof(Node));
	cur->data = value;
	cur->next = NULL;
	if (value <= head->data)
	{
		cur->next = head;
		head = cur;
		return head;
	}
	Node*element = head;
	for (; (cur->data >= (element->next)->data) && ((element->next)->next) != NULL; element = element->next);
	if ((element->next)->next == NULL&&cur->data >= (element->next)->data)
	{
		(element->next)->next = cur;
		return head;
	}
	else if (element)
	{
		cur->next = element->next;
		element->next = cur;
	}
	else cout << "Error";
	return head;
}

void print(Node*head)
{
	while (head)
	{
		cout << head->data << " ";
		head = head->next;
	}
}

Node* remove(Node *head, int value) //удаление по значению//просто указатель
{
	Node *cur = head, *prev = NULL;
	while (cur->data != value&&cur) //поиск элемента по значению или поиск конца списка
	{
		prev = cur; //сохранияем текущий элемент
		cur = cur->next; //переход к следующему элемента
	}
	if (cur) //если нашли элемент
	{
		if (prev) //если перед ним есть элемент (а не ничего нет)
			prev->next = cur->next; //переставляем указатель из предыдущего элемента на следующий элемент за удаляемым
		else //если удаляем первый элемент(т.е. нет перед ним элементов)
			head = cur->next; //изменяем голову списка на следующий за удаляемым
		free(cur);
		return head;
	}
	if (head)cout << "Element not found" << endl;
	else cout << "List is empty" << endl;
}

void delete_back(Node **head)//удаление только последнего
{
	Node *cur = *head, *prev = NULL;
	while (cur->next)
	{
		prev = cur;
		cur = cur->next;
	}
	if (cur)
	{
		if (prev)
			prev->next = cur->next;
		else *head = cur->next;
		free(cur);
		return;
	}
	if (*head)cout << "Element not found" << endl;
	else cout << "List is empty" << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Node*list = NULL;

	cout << "Односвязный список: ";
	list = insert(list, 10, 0);
	list = insert(list, 20, 0);
	list = insert(list, 30, 1);

	print(list);
	cout << endl;

	cout << "Добавление элемента в конец списка: ";
	list = insert_back(list, 1001);
	print(list);
	cout << endl;

	cout << "Удаление из конца списка: ";
	delete_back(&list);
	print(list);
	cout << endl << endl;

	Node*list2 = NULL;

	cout << "Отсортированный список: ";
	list2 = insert(list2, 30, 0);
	list2 = insert(list2, 20, 0);
	list2 = insert(list2, 10, 0);
	print(list2);
	cout << endl;

	cout << "Добавления в отсортированный список с сохранением порядка: ";
	list2 = insert_sort(list2, 12);
	list2 = insert_sort(list2, 24);
	list2 = insert_sort(list2, 33);
	print(list2);
	cout << endl << endl;
	return 0;
}
