#include<iostream>
#include<cstring>

using namespace std;

struct bit
{
	bool a0 : 1;
	bool a1 : 1;
	bool a2 : 1;
	bool a3 : 1;
	bool a4 : 1;
	bool a5 : 1;
	bool a6 : 1;
	bool a7 : 1;
};

union INT
{
	int data;
	bit x[sizeof(int)];
	unsigned char byte[sizeof(int)];
};

union FLOAT
{
	float data;
	bit y[sizeof(float)];
	unsigned char byte[sizeof(float)];
};

void byte(INT);
void print_byte_vibor(INT, int);
void print_byte_2(INT);
void print_byte_16(INT);

void print_byte_2(FLOAT);
void print_byte_16(FLOAT);
void print_byte_vibor(FLOAT, int);
void byte(FLOAT);


int main()
{
	setlocale(LC_ALL, "Russian");
	INT x;
	FLOAT y;

	cout << "Введите целое число: ";
	cin >> x.data;
	cout << "Ваше число в байтах: ";
	byte(x);
	int i;
	cout << "\nПросмотреть выбранный байт числа [от 0 до 3]: ";
	cin >> i;
	print_byte_vibor(x, i);
	cout << "\nВаше число в двоичной с/с: ";
	print_byte_2(x);
	cout << "\nВаше число в шестнадцатеричной с/с: ";
	print_byte_16(x);
	cout << endl;

	cout << "\n=========================================\n";

	cout << "\nВведите вещественное число: ";
	cin >> y.data;
	cout << "Ваше число в байтах: ";
	byte(y);
	cout << "\nПросмотреть выбранный байт числа [от 0 до 3]: ";
	cin >> i;
	print_byte_vibor(y, i);
	cout << "\nВаше число в двоичной с/с: ";
	print_byte_2(y);
	cout << "\nВаше число в шестнадцатеричной с/с: ";
	print_byte_16(y);
	cout << endl << endl;
	return 0;
}

void print_byte_2(INT x) // вывод числа в двоичной с/с
{
	for (int i = 3; i >= 0; i--)
		cout << x.x[i].a7 << x.x[i].a6 << x.x[i].a5 << x.x[i].a4 << x.x[i].a3 << x.x[i].a2 << x.x[i].a1 << x.x[i].a0 << " ";
}

void print_byte_16(INT x) // вывод числа в шестнадцатеричной с/с
{
	for (int i = 3; i >= 0; i--) 
		cout << hex << (int)x.byte[i] << "  ";
}

void print_byte_vibor(INT x, int i) // вывод выбранного байта числа
{
	cout << (int)x.byte[i];
}

void byte(INT x) // вывод все байты числа
{
	for (int i = 3; i >= 0; i--)
		cout << (int)x.byte[i] << " ";
}

void print_byte_2(FLOAT y) // вывод числа в двоичной с/с
{
	for (int i = 3; i >= 0; i--)
		cout << y.y[i].a7 << y.y[i].a6 << y.y[i].a5 << y.y[i].a4 << y.y[i].a3 << y.y[i].a2 << y.y[i].a1 << y.y[i].a0 << " ";
}

void print_byte_16(FLOAT y) // вывод числа в шестнадцатеричной с/с
{
	for (int i = 3; i >= 0; i--)
		cout << hex << (int)y.byte[i] << "  ";
}

void print_byte_vibor(FLOAT y, int i) // вывод выбранного байта числа
{
	cout << (int)y.byte[i];
}

void byte(FLOAT y) // вывод все байты числа
{
	for (int i = 3; i >= 0; i--)
		cout << (int)y.byte[i] << " ";
}
