// Выяснить является ли число степенью двойки, используя битовые операции.

#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int a;
	cout << "Введите число: ";
	cin >> a;
	bool flag = true;
	while (a > 1)
	{
		if (a == 2)
		{
			cout << "Число является степенью двойки\n";
			flag = false;
			break;
		}
		a >>= 1;
	}
	if (flag) cout << "Число не является степенью двойки\n";

	cout << endl;
	return 0;
}
