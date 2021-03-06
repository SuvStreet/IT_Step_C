// Счет в банке представляет собой структуру с полями :
// • номер счета,
// • код счета,
// • фамилия владельца,
// • сумма на счете,
// • дата открытия счета,
// • годовой процент начисления.
// Реализовать поиск в массиве структур по номеру счета, по коду счета и по владельцу.
// Реализовать сортировку по фамилии владельца и по номеру счета.
// Реализовать удаление в массиве структур по коду счета и по владельцу.

#include<iostream> 
#include<cstring>

using namespace std;

const int size = 5;

struct Node
{
	int nomer, kod, summa, data, procent;
	char familia[10];
	Node*next;
};

Node *read(Node *vladel)
{
	Node* cur = (Node*)malloc(sizeof(Node));
	cur->next = NULL;
	cout << "\nВведите фамилию: ";
	cin >> cur->familia;
	cout << "Введите номер счета: ";
	cin >> cur->nomer;
	cout << "Введите код счета: ";
	cin >> cur->kod;
	cout << "Введите сумму на счету: ";
	cin >> cur->summa;
	cout << "Введите дату открытия счета: ";
	cin >> cur->data;
	cout << "Введите годовой процент начисления: ";
	cin >> cur->procent;
	cin.get();
	cout << endl;
	if (!vladel)
	{
		cur->next = vladel;
		vladel = cur;
		return vladel;
	}
	Node*element = vladel;
	for (element; element->next != NULL; element = element->next);
	if (element) element->next = cur;
	else cout << "Error";
	return vladel;
}

void print(Node* vladel)
{
	cout << "\nФамилия: " << vladel->familia << endl;
	cout << "Номер счета: " << vladel->nomer << endl;
	cout << "Код счета: " << vladel->kod << endl;
	cout << "Сумма на счету: " << vladel->summa << endl;
	cout << "Дата открытия счета: " << vladel->data << endl;
	cout << "Годовой процент начисления: " << vladel->procent << endl << endl;
}

void print_spisok(Node* vladel)
{
	if (vladel == NULL)
	{
		cout << "\nСписок пуст\n";
		return;
	}
	for (int i = 0; vladel; i++, vladel = vladel->next)
		print(vladel);
}

void poisk_nomer(Node* vladel)
{
	int nomer_cheta;
	cout << "\nВведите номер счета для поиска в базе: ";
	cin >> nomer_cheta;
	cout << endl;
	bool pok = false;
	for (int i = 0; i < size; i++, vladel = vladel->next)
	{
		if (vladel->nomer == nomer_cheta)
		{
			cout << "Владелец найден." << endl;
			print(vladel);
			pok = true;
		}
	}
	if (pok == false) cout << "Владельца с таким НОМЕРОМ счета не существует." << endl << endl;
}

void poisk_kod(Node* vladel)
{
	int kod_cheta;
	cout << "\nВведите КОД счета для поиска в базе: ";
	cin >> kod_cheta;
	cout << endl;
	bool pok = false;
	for (int i = 0; i < size; i++, vladel = vladel->next)
	{
		if (vladel->kod == kod_cheta)
		{
			cout << "Владелец найден." << endl;
			print(vladel);
			pok = true;
		}
	}
	if (pok == false) cout << "Владельца с таким номером КОДОМ не существует." << endl << endl;
}

void poisk_fam(Node* vladel)
{
	char fam[10];
	cout << "\nВведите ФАМИЛИЮ для поиска в базе: ";
	cin >> fam;
	cout << endl;
	bool pok = false;
	for (int i = 0; i < size; i++, vladel = vladel->next)
	{
		if (strcmp(vladel->familia, fam) == 0)
		{
			cout << "Владелец найден." << endl;
			print(vladel);
			pok = true;
		}
	}
	if (pok == false) cout << "Владельца с такой ФАМИЛИЕЙ не существует." << endl << endl;
}

Node* remove_kod(Node *head) //удаление по коду счета
{
	int value;
	cout << "\nВведите КОД счета для удаления из базы: ";
	cin >> value;
	cout << endl;
	Node *cur = head, *prev = NULL;
	while (cur->kod != value&&cur)
	{
		prev = cur;
		cur = cur->next;
		if (cur == NULL) break;
	}
	if (cur)
	{
		if (prev)
			prev->next = cur->next;
		else
			head = cur->next;
		free(cur);
		return head;
	}
	if (head)
	{
		cout << "Element not found" << endl;
		return head;
	}
	else
	{
		cout << "List is empty" << endl;
		return head;
	}
}

Node* remove_fam(Node *head) //удаление по фамилии счета
{
	char fam[10];
	cout << "\nВведите ФАМИЛИЮ для удаления из базы: ";
	cin >> fam;
	Node *cur = head, *prev = NULL;
	while (strcmp(cur->familia, fam) && cur)
	{
		prev = cur;
		cur = cur->next;
		if (cur == NULL) break;
	}
	if (cur)
	{
		if (prev)
			prev->next = cur->next;
		else
			head = cur->next;
		free(cur);
		return head;
	}
	if (head)
	{
		cout << "Element not found" << endl;
		return head;
	}
	else
	{
		cout << "List is empty" << endl;
		return head;
	}
}

Node* sort_nomer(Node *head) //сортировка по номеру
{
	cout << "\nСортировка по НОМЕРУ." << endl;
	if (head->next == NULL) return head;
	Node *cur, *temp, *temp2, *prev, *end = NULL;
	bool flag = true;

	while (flag)
	{
		flag = false;
		cur = head;
		prev = NULL;
		if (cur->nomer > (cur->next)->nomer)
		{
			temp = cur; temp2 = cur->next->next;
			head = temp->next;
			head->next = temp;
			head->next->next = temp2;
			flag = true;
		}
		else cur = cur->next;
		prev = head;
		while (cur->next != NULL)
		{
			if (cur->nomer>cur->next->nomer)
			{
				prev->next = cur->next;
				cur->next = cur->next->next;
				prev->next->next = cur;
				flag = true;
			}
			else cur = cur->next;
			prev = prev->next;
		}
	}
	return head;
}

Node* sort_fam(Node *head) //сортировка по номеру
{
	cout << endl << "\nСортировка по ФАМИЛИИ." << endl;
	if (head->next == NULL) return head;
	Node *cur, *temp, *temp2, *prev, *end = NULL;
	bool flag = true;

	while (flag)
	{
		flag = false;
		cur = head;
		prev = NULL;
		if (strcmp(cur->familia, cur->next->familia)>0)
		{
			temp = cur; temp2 = cur->next->next;
			head = temp->next;
			head->next = temp;
			head->next->next = temp2;
			flag = true;
		}
		else cur = cur->next;
		prev = head;
		while (cur->next != NULL)
		{
			if (strcmp(cur->familia, cur->next->familia)>0)
			{
				prev->next = cur->next;
				cur->next = cur->next->next;
				prev->next->next = cur;
				flag = true;
			}
			else cur = cur->next;
			prev = prev->next;
		}
	}
	return head;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Node* list = NULL;
	bool flag = true;

	while (flag)
	{

		cout << "Что вы хотите сделать ?\n"
			"1.Вывести список счетов\n"
			"2.Добавить счет\n"
			"3.Найти по номеру счета\n"
			"4.Найти по коду счета\n"
			"5.Найти фамилии владельца\n"
			"6.Удалить по фамилии владельца\n"
			"7.Удалить покоду счета\n"
			"8.Отсортирвоать список по номеру счета\n"
			"9.Отсортирвоать список по фамилии владельца\n"
			"0.Выход\n\n";
		int choice;
		cin >> choice;
		if (choice == 1)
		{
			print_spisok(list);
		}
		else if (choice == 2)
		{
			list = read(list);
		}
		else if (choice == 3)
		{
			poisk_nomer(list);
		}
		else if (choice == 4)
		{
			poisk_kod(list);
		}
		else if (choice == 5)
		{
			poisk_fam(list);
		}
		else if (choice == 6)
		{
			list = remove_fam(list);
		}
		else if (choice == 7)
		{
			list = remove_kod(list);
		}
		else if (choice == 8)
		{
			list = sort_nomer(list);
		}
		else if (choice == 9)
		{
			list = sort_fam(list);
		}
		else if (choice == 0)
		{
			flag = false;
		}
		else cout << "Введите корректный пункт меню.\n\n";
	}
	return 0;
}
