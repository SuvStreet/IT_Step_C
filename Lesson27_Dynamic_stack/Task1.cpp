// Создать структуру данных студент с полями :
// - ФИО
// - ГРУППА
// - НОМЕР ЗАЧЕТКИ
// - Массив оценок
// В массиве структур имеется следующая информация о студентах :
// - Иванов		4 456345   5 3 10
// - Петров		4 456348   4 8 4
// - Иванова	5 456340   5 3 5
// - Петрова	5 456349   4 5 4
// Составить программу получения :
// •	среднего балла каждого студента
// •	общего среднего балла
// •	общего списка, состоящего из фамилии, номера группы, номера зачетки, среднего балла.
// •	списка отличников, состоящего из фамилии, номера группы, номера зачетки
// •	списка имеющих неудовлетворительные  оценки, состоящего из фамилии, номера группы, номера зачетки
// •	Для проверки результатов информацию созданных списков вывести на экран.

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;

const int size = 3;

struct Student
{
	char FIO[40];
	short group;
	unsigned long num_zuch;
	int marks[3];
};

Student read()
{
	Student student;

	cout << "Введите фамилию: ";
	cin.getline(student.FIO, 40);

	cout << "Введите группу: ";
	cin >> student.group;

	cout << "Введите номер зачётки: ";
	cin >> student.num_zuch;

	cout << "Введите три оценки: ";
	for (int i = 0; i < 3; i++)
		cin >> student.marks[i];
	
	cout << endl;

	cin.get();
	return student;
}

void output(Student student)
{
	cout << "Студент: " << student.FIO << " ";
	cout << student.group << " ";
	cout << student.num_zuch << " ";
	for (int i = 0; i < 3; i++)
		cout << student.marks[i] << " ";
}

float avg(Student student)
{
	float sred = 0;
	for (int i = 0; i < 3; i++)
		sred += student.marks[i];

	return sred / 3;
}

float whole_avg(Student *student, int size)
{
	float w_sred = 0;
	for (int i = 0; i < size; i++)
		w_sred += avg(student[i]);

	return w_sred / size;
}

bool otlichniki(Student student)
{
	bool flag = 1;
	for (int i = 0; i < 3; i++)
	if (student.marks[i] < 9) flag = 0;

	return flag;
}

void change_marks(Student *student, char *name)
{
	if (strcmp(name, student->FIO) == 0)
	{
		for (int i = 0; i < 3; i++)
		{
			cout << "Введите " << i + 1 << " оценку: ";
			cin >> student->marks[i];
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	Student student[size];

	for (int i = 0; i < size; i++)
		student[i] = read();

	for (int i = 0; i < size; i++)
	{
		output(student[i]);
		cout << " средний балл = " << avg(student[i]) << endl;
	}

	cout << "\nОбщий средний балл: " << whole_avg(student, size) << endl;

	cout << "Отличники: ";
	for (int i = 0; i < size; i++)
	{
		if (otlichniki(student[i]))
			cout << student[i].FIO << " ";
	}
	cout << endl;

	char st[20];
	cout << "\nВведите студента для изменения оценки: ";
	cin >> st;
	for (int i = 0; i < size; i++)
		change_marks(&student[i], st);
	cout << endl;

	for (int i = 0; i < size; i++)
	{
		output(student[i]);
		cout << endl;
	}

	cout << endl;

	return 0;
}
