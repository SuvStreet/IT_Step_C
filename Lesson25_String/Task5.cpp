//Строка состоит из целых чисел бинарных арифметических операций и пробелов.
//Определить является ли строка арифметическим выражением.
//Например: 34 + 56 * 4 арифметическое выражение.
//Например: 34 + * 56 не является арифметическим выражением.
//Например: 56 56 + не является арифметическим выражением.

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int main()
{
	setlocale(0, "");
	char str[100], *s;
	const char op[10] = "+-*/";
	cout << "Введите арифметическое выражение: ";
	cin.getline(str, 100);
	s = str;
	bool flag = true;
	while (s = strchr(s, ' '))
	{
		if (isdigit(*(s - 1)) && isdigit(*(s + 1)))
		{
			flag = false;
			cout << "Пробел между цифрами." << endl;
			break;
		}
		else s++;
	}
	if (flag)
	{
		s = str;
		while (s = strpbrk(s, op))
		{
			if (*(s + 1) == '/0')
			{
				flag = false;
				break;
			}
			else if (*(s - 1) == ' ' && *(s + 1) == ' ')
			{
				if (isdigit(*(s - 2)) && isdigit(*(s + 2))) s++;
				else
				{
					flag = false;
					break;
				}
			}
			else
			{
				flag = false;
				break;
			}
		}
	}
	if (flag) cout << "Строка является арифметическим выражением." << endl;
	else cout << "Строка не является арифметическим выражением." << endl;

	cout << endl;

	return 0;
}
