#include<iostream>
#include<cstring>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int a, b;
	cout << "Введите числа через пробел: ";
	cin >> a >> b;
	cout << "Ведите операцию над ними */+-: ";
	char symb;
	cin >> symb;
	int result;
	switch (symb)
	{
	case '*': result = a * b; break;
	case '/': result = a / b; break;
	case '+': result = a + b; break;
	case '-': result = a - b; break;
	}
	for (int i = 31; i < 0; --i)
	{
		cout << ((result >> i) & 1); // побитовый сдвиг на единицу и битовое & с единицей для получения каждого отдельного бита
		if (i % 8 == 0)
			cout << " ";
	}
	int number;
	cout << "Введите номер байта (0 - 3): ";
	cin >> number;
	int new_result = ((255 << (3 - number) * 8)&result) >> ((3 - number) * 8);
	// (3 - number) * 8) - выбор на сколько сдвинуть 255 (0-8-16-24)
	// (255 << (3 - number) * 8) - сдвиг 255 для получения нужного байта
	// ((255 << (3 - number) * 8)&result) - к полученому байту применяем битовое & для получения заданного байта
	// >> ((3 - number) * 8) - сдвиг обратно на ((0-8-16-24)битиков)

	cout << endl;

	for (int i = 7; i >= 0; --i)
	{
		cout << ((new_result >> i) & 1);
	}

	cout << endl << endl;
	return 0;
}
