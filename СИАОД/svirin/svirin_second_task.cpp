
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

int getDecimal(std::string hex)
{
	return std::stol(hex, nullptr, 16);
}

const char validChars[] = {
'1', '2', '3', '4', '5', '6', '7', '8', '9',
'A', 'B', 'C', 'D', 'E', 'F',
'a', 'b', 'c', 'd', 'e', 'f'
};

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
	std::string str = "aba hihi A8 B 95 hahi 45 miau AABE owo";
	std::vector<int> decimals = std::vector<int>();

	std::string buffer = "";
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

	for (unsigned int i = 0; i < decimals.size(); ++i)
		std::cout << decimals[i] << ' ';
	std::cout << '\n';
}