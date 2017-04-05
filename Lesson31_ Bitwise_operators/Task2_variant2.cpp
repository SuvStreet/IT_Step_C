// Дано число, вывести  его двоичное представление, используя только битовые операции.

#include<iostream>
#include<cstring>

using namespace std;

void displayBits(unsigned);

int main()
{
	setlocale(LC_ALL, "Russian");
	unsigned x;
	cout << "Введите число = ";
	cin >> x;
	displayBits(x);
	return 0;
}

void displayBits(unsigned value)
{
	unsigned c, displayMask = 1 << 15;

	cout << value << " = ";
	for (c = 1; c <= 16; c++)
	{
		putchar(value & displayMask ? '1' : '0');
		value <<= 1;
		if (c % 8 == 0)
			putchar(' ');
	}
	putchar('\n');
}
