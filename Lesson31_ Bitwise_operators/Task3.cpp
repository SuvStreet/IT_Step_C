#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	int arr[] = { 1, 1, 2, 2, 3, 4, 4, 5, 5 }; // сортируем массив
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	for (int i = 1; i < sizeof(arr)/sizeof(int); i+=2) // шаг = 2, ибо по условию
	{
		if (arr[i] ^ arr[i - 1]) // с помощью xor сравниваем значения, если они равны, то даст 0
		{
			cout << arr[i - 1]; 
			break;
		}
	}
	
	cout << endl;
	return 0;
}
