#include <iostream>
#include <malloc.h>
#include <vector>
#include <iterator>

const int Len = 1000;
int counter = 0;
int counter_for_print = 1;

//subsidiary functions
void print_of_array(int* array, int length)
{
	for (int i = 0; i < length; i++)
		std::cout << array[i] << " ";
}

void print_of_array_vector(std::vector< int >& array_v, int length)
{
	for (int i = 0; i < length; i++)
		std::cout << array_v[i] << ' ';
}

bool contains_five(int element)
{
	while (element != 0)
	{

		if (element % 10 != 5)
		{
			element = element / 10;
		}

		else
		{
			counter += 1;
			return true;
		}
	}
	return false;
}

//tasks with static massive
bool check_desc_static(int* array_s, int length)
{
	for (int i = 1; i < length; i++)
	{
		if (array_s[i - 1] < array_s[i])
			return false;
	}

	return true;
}

void del_5_static(int* array_s, int length)
{
	int j = 0;
	for (int i = 0; i < length; i++)
	{
		if (!contains_five(array_s[i]))
			array_s[j++] = array_s[i];
	}

	for (; j < length; j++)
		array_s[j] = 0;

}

int add_element_static(int* array_s, int length)
{
	int new_element = 0;
	int second_index;
	std::cout << "Input the new element: ";
	std::cin >> new_element;
	for (int i = 0; i < length; i++)
	{
		if (array_s[i] <= new_element)
		{
			second_index = i;
			break;
		}
		else
			second_index = length;
	}

	for (int j = length; j >= second_index; j--)
	{
		array_s[j + 1] = array_s[j];
	}

	array_s[second_index] = new_element;
	return *array_s;
}

//tasks with dynamic massive
bool check_desc_dynamic(int* array_d, int length)
{
	for (int i = 1; i < length; i++)
	{
		if (array_d[i - 1] < array_d[i])
			return false;
	}

	return true;
}

void del_5_dynamic(int* array_d, int length)
{
	int j = 0;
	for (int i = 0; i < length; i++)
	{
		if (!contains_five(array_d[i]))
			array_d[j++] = array_d[i];
	}
	for (; j < length; j++)
		array_d[j] = 0;
	if (length - 1 > length)
		array_d = (int*)realloc((void*)array_d, (length = length - 1) * sizeof(int));
}

int add_element_dynamic(int* array_d, int length)
{
	int new_element = 0;
	int second_index;
	std::cout << "Input the new element: ";
	std::cin >> new_element;
	for (int i = 0; i < length; i++)
	{
		if (array_d[i] <= new_element)
		{
			second_index = i;
			break;
		}
		else
			second_index = length;
	}

	for (int j = length; j >= second_index; j--)
	{
		array_d[j + 1] = array_d[j];
	}

	array_d[second_index] = new_element;
	return *array_d;
	array_d = (int*)realloc((void*)array_d, (length = length + 1) * sizeof(int));
}

//tasks with dynamic massive and with vector library
bool check_desc_vector(std::vector< int >& array_v, int length)
{
	for (int i = 1; i < length; i++)
	{
		if (array_v[i - 1] < array_v[i])
			return false;
	}

	return true;
}

void del_5_vector(std::vector< int >& array_v, int length)
{
	int j = 0;
	for (int i = 0; i < length; i++)
	{
		if (!contains_five(array_v[i]))
			array_v[j++] = array_v[i];
	}
	for (; j < length; j++)
		array_v[j] = 0;
	
}

void add_element_vector(std::vector< int >& array_v, int length)
{
	int new_element;
	int second_index;
	std::cout << "Input the new element: ";
	std::cin >> new_element;
	for (int i = 0; i < length; i++)
	{
		if (array_v[i] <= new_element)
		{
			second_index = i;
			break;
		}
		else
			second_index = length;
	}
	array_v.emplace(array_v.begin() + second_index, new_element);
}

//main function
int main()
{
	int restart_button = 1;
	while (restart_button == 1)
	{
		//interface
		int type_of_array;
		std::cout << "Pick the type of array:" << '\n' <<
			"1 - Static array" << '\n' <<
			"2 - Dynamic array" << '\n' <<
			"3 - Dynamic array with vector" << '\n';
		std::cout << "******************************" << '\n';
		std::cin >> type_of_array;
		std::cout << "******************************" << '\n';

		//type of array
		if (type_of_array == 1)
		{
			//fill the static array
			int array_s[Len];
			int i;
			int length;
			std::cout << "Input the number of elements in the array: ";
			std::cin >> length;
			if ((length > 0) and (length < Len))
			{
				std::cout << "Input " << length << " numbers: ";
				for (i = 0; i < length; i++)
					std::cin >> array_s[i];
			}
			int restart_button_for_func = 1;
			while (restart_button_for_func == 1)
			{
				//tasks
				std::cout << "******************************" << '\n';
				std::cout << "Pick the number of task:" << '\n' <<
					"1 - check the array for  descending" << '\n' <<
					"2 - If array is not descending then we should delete the element where the number **5** is present" << '\n' <<
					"3 - If array is descending then we should add the element which is less than the minimum" << '\n';
				std::cout << "******************************" << '\n';
				int number_of_func;
				std::cin >> number_of_func;
				std::cout << "******************************" << '\n';

				if (number_of_func == 1)
				{
					if (check_desc_static(array_s, length) == 1)
						std::cout << "true";
					else
						std::cout << "false";
				}

				if (number_of_func == 2)
				{
					if (!check_desc_static(array_s, length))
					{
						del_5_static(array_s, Len);
						print_of_array(array_s, length - counter);
						counter = 0;
						counter_for_print = counter_for_print - 1;
					}
					else
						std::cout << "this array is descending";
				}

				if (number_of_func == 3)
				{
					if (check_desc_static(array_s, length))
					{
						add_element_static(array_s, length);
						print_of_array(array_s, length + counter_for_print);
						counter_for_print += 1;
					}
					else
						std::cout << "this array is not descending";
				}

				std::cout << '\n';
				std::cout << "Do you wanna continue work with tasks (press 1): ";
				std::cin >> restart_button_for_func;
			}
			counter_for_print = 1;
		}

		else if (type_of_array == 2)
		{
			//fill the dynamic array
			int* array_d;
			int length;
			std::cout << "Input the number of elements in the array: ";
			std::cin >> length;
			array_d = (int*)malloc(length * sizeof(int));
			std::cout << "Input " << length << " numbers: ";
			for (int i = 0; i < length; i++)
				std::cin >> array_d[i];
			std::cout << counter_for_print;
			int restart_button_for_func = 1;
			while (restart_button_for_func == 1)
			{
				//tasks
				std::cout << "******************************" << '\n';
				std::cout << "Pick the number of task:" << '\n' <<
					"1 - check the array for  descending" << '\n' <<
					"2 - If array is not descending then we should delete the element where the number **5** is present" << '\n' <<
					"3 - If array is descending then we should add the element which is less than the minimum" << '\n';
				std::cout << "******************************" << '\n';
				int number_of_func;
				std::cin >> number_of_func;
				std::cout << "******************************" << '\n';
				if (number_of_func == 1)
				{
					if (check_desc_dynamic(array_d, length) == 1)
						std::cout << "true";
					else
						std::cout << "false";
				}

				if (number_of_func == 2)
				{
					if (!check_desc_dynamic(array_d, length))
					{
						del_5_dynamic(array_d, length);
						print_of_array(array_d, length - counter);
						counter = 0;
						counter_for_print = counter_for_print - 1;
					}
					else
						std::cout << "this array is descending";
				}

				if (number_of_func == 3)
				{
					if (check_desc_dynamic(array_d, length))
					{
						add_element_dynamic(array_d, length);
						print_of_array(array_d, length + counter_for_print);
						counter_for_print += 1;
					}
					else
						std::cout << "this array is not descending";
				}

				std::cout << '\n';
				std::cout << "Do you wanna continue work with tasks (press 1): ";
				std::cin >> restart_button_for_func;
			}
			counter_for_print = 1;
		}

		else if (type_of_array == 3)
		{
			int length;
			int element;
			std::vector< int > array_v;
			std::cout << "Input the number of elements in the array: ";
			std::cin >> length;
			std::cout << "Input " << length << " numbers: ";
			for (int i = 0; i < length; i++)
			{
				std::cin >> element;
				array_v.push_back(element);
			}
			int restart_button_for_func = 1;
			while (restart_button_for_func == 1)
			{
				std::cout << "******************************" << '\n';
				std::cout << "Pick the number of task:" << '\n' <<
					"1 - check the array for  descending" << '\n' <<
					"2 - If array is not descending then we should delete the element where the number **5** is present" << '\n' <<
					"3 - If array is descending then we should add the element which is less than the minimum" << '\n';
				std::cout << "******************************" << '\n';
				int number_of_func;
				std::cin >> number_of_func;
				std::cout << "******************************" << '\n';

				if (number_of_func == 1)
				{
					if (check_desc_vector(array_v, length) == 1)
						std::cout << "true";
					else
						std::cout << "false";
				}

				if (number_of_func == 2)
				{
					if (!check_desc_vector(array_v, length))
					{
						del_5_vector(array_v, length);
						print_of_array_vector(array_v, length - counter);
						counter = 0;
						counter_for_print = counter_for_print - 1;
					}
					else
						std::cout << "this array is descending";

				}

				if (number_of_func == 3)
				{
					if (check_desc_vector(array_v, length))
					{
						add_element_vector(array_v, length);
						print_of_array_vector(array_v, length + counter_for_print);
						counter_for_print += 1;
					}
					else
						std::cout << "this array is not descending";
				}

				std::cout << '\n';
				std::cout << "Do you wanna continue work with tasks (press 1): ";
				std::cin >> restart_button_for_func;
			}
			counter_for_print = 1;
		}

		else
			std::cout << "You input the wrong number, please try again";
		std::cout << '\n';
		std::cout << "Do you wanna continue? (press 1): " << '\n';
		std::cin >> restart_button;
		if (restart_button != 1)
		{
			break;
		}
	}
}
