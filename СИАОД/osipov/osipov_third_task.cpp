#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const char validChars[] = 
{
'1', '2', '3', '4', '5', '6', '7', '8', '9',
'A', 'B', 'C', 'D', 'E', 'F',
'a', 'b', 'c', 'd', 'e', 'f'
};

int getDecimal(string hex)
{
	return stol(hex, nullptr, 16);
}


bool isValidChar(char c)
{
	for (int i = 0; i < 9 + 6 + 6; ++i)
	{
		if (validChars[i] == c)
			return true;
	}

	return false;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Введите строку: ";
	string str;
	getline(cin, str);

	vector<int> decimals = vector<int>();

	string buffer = "";
	for (unsigned int i = 0; i < str.length(); ++i)
	{
		if (str[i] == ' ')
		{
			if (buffer.length() == 0)
				continue;

			decimals.push_back(getDecimal(buffer));
			buffer = "";
		}

		if (!isValidChar(str[i]))
		{
			buffer = "";
			continue;
		}

		buffer += str[i];
	}

	cout << "Ваша изменненая строка: ";
	for (unsigned int i = 0; i < decimals.size(); ++i)
		cout << decimals[i] << ' ';
	cout << '\n';
}