// Реализовать 4 - х байтовую целую переменную, к которой можно обращаться и как к знаковому целому,
// и как беззнаковому целому, без явного преобразования типов.
// Для этого используйте объединение.

#include<iostream>
#include<cstring>

using namespace std;

union INT
{
	int data;
	unsigned int byte;
};

int main()
{
	INT u;
	u.data = -10;
	cout << u.byte << endl;
	cout << u.data << endl;
	return 0;
}
