#include <iostream>
#include <string>
#include <iomanip>
int main()
{
	std::string str;
	std::cout << "Input the string: ";
	std::getline(std::cin, str);
	char curChar = str[0];
	int count = 0;
	std::cout << "Your changed string: ";
	for (unsigned int i = 1; i < str.length(); ++i)
	{
		if (str[i] == curChar)
		{
			if (count < 0)
			{
				std::cout << curChar << '(' << count - 1 << ')';
				count = 0;
			}

			else
			{
				++count;
			}
		}

		else if (str[i] != curChar)
		{
			if (count > 0)
			{
				std::cout << curChar << '(' << count + 1 << ')';
				count = 0;
			}

			else
			{
				std::cout << curChar;
				--count;
			}
		}

		curChar = str[i];
	}

	if (count >= 0)
		std::cout << curChar << '(' << count + 1 << ')';

	else if (count < 0)
		std::cout << curChar << '(' << count - 1 << ')';
	std::cout << '\n';
}