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
