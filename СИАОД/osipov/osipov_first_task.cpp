#include <iostream>
#include <malloc.h>
#include <vector>
const int Len = 1000;
int counter = 0;
int counter_for_print = 1;
int second_index = 1;

using namespace std;

void show_the_array(int* array, int length)
{
	for (int i = 0; i < length; i++)
		cout << array[i] << " ";
}

void show_the_array_v(std::vector< int >& vector_array, int length)
{
	for (int i = 0; i < length; i++)
		cout << vector_array[i] << " ";
}

int sum(int elem)
{
	int sum = 0;
	while (elem != 0)
	{
		sum = sum + elem % 10;
		elem = elem / 10;

	}
	return sum;
}

int find_the_index_s(int* static_array, int length)
{
	for (int i = 0; i < length; i++)
	{
		if (sum(static_array[i]) % 7 == 0)
		{
			return i;
		}
	}
}

int insert_s(int* static_array, int length)
{

	int new_elem;
	int min = static_array[0];
	cout << "Введите элемент, который вы хотите вставить: ";
	cin >> new_elem;
	for (int i = 0; i < length; i++)
	{
		if (sum(static_array[i]) % 7 == 0 and static_array[i] < min)
		{
			min = static_array[i];
		}

	}

	for (int i = 0; i < length; i++)
	{
		if (sum(static_array[i]) % 7 == 0 and static_array[i] == min)
		{
			second_index = i;
		}

	}

	for (int j = length; j >= second_index; j--)
	{
		static_array[j + 1] = static_array[j];
	}

	static_array[second_index] = new_elem;
	return *static_array;

}

int del_element(int* static_array, int length)
{
	int j = 0;
	for (int i = 0; i < length; i++)
	{
		if (sum(static_array[i]) % 7 != 0)
		{
			counter += 1;
			static_array[j++] = static_array[i];
		}
	}

	for (; j < length; j++)
		static_array[j] = 0;
	return *static_array;
}

int find_the_index_d(int* dynamic_array, int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		if (sum(dynamic_array[i]) % 7 == 0)
		{
			return i;
		}
	}
}

int insert_d(int* dynamic_array, int length)
{

	int new_elem;
	int min = dynamic_array[0];
	cout << "Введите элемент, который вы хотите вставить: ";
	cin >> new_elem;
	for (int i = 0; i < length; i++)
	{
		if (sum(dynamic_array[i]) % 7 == 0 and dynamic_array[i] < min)
		{
			min = dynamic_array[i];
		}

	}

	for (int i = 0; i < length; i++)
	{
		if (sum(dynamic_array[i]) % 7 == 0 and dynamic_array[i] == min)
		{
			second_index = i;
		}

	}

	for (int j = length; j >= second_index; j--)
	{
		dynamic_array[j + 1] = dynamic_array[j];
	}
	dynamic_array[second_index] = new_elem;
	return *dynamic_array;
	dynamic_array = (int*)realloc((void*)dynamic_array, (length = length - 1) * sizeof(int));

}

int del_element_d(int* dynamic_array, int length)
{
	int j = 0;
	for (int i = 0; i < length; i++)
	{
		if (sum(dynamic_array[i]) % 7 != 0)
		{
			counter += 1;
			dynamic_array[j++] = dynamic_array[i];
		}
	}

	for (; j < length; j++)
		dynamic_array[j] = 0;
	return *dynamic_array;
	dynamic_array = (int*)realloc((void*)dynamic_array, (length = length - 1) * sizeof(int));
}

int find_the_index_v(std::vector< int >& vector_array, int length)
{
	for (int i = 0; i < length; i++)
	{
		if (sum(vector_array[i]) % 7 == 0)
		{
			return i;
		}
	}
}

void insert_v(std::vector< int >& vector_array, int length)
{
	int new_elem;
	int min = vector_array[0];
	cout << "Введите элемент, который вы хотите вставить: ";
	cin >> new_elem;
	for (int i = 0; i < length; i++)
	{
		if (sum(vector_array[i]) % 7 == 0 and vector_array[i] < min)
		{
			min = vector_array[i];
		}

	}

	for (int i = 0; i < length; i++)
	{
		if (sum(vector_array[i]) % 7 == 0 and vector_array[i] == min)
		{
			second_index = i;
		}
	}

	vector_array.emplace(vector_array.begin() + second_index, new_elem);
}

void del_element_v(std::vector< int >& vector_array, int length)
{
	int j = 0;
	for (int i = 0; i < length; i++)
	{
		if (sum(vector_array[i]) % 7 != 0)
		{
			counter += 1;
			vector_array[j++] = vector_array[i];
		}
	}

	for (; j < length; j++)
		vector_array[j] = 0;
}


int main()
{
	int restart_button = 1;
	while (restart_button == 1)
	{
		setlocale(LC_ALL, "Russian");
		int type_arr;
		cout << "Выберите тип массива:" << '\n' <<
			"1 - Cтатический массив" << '\n' <<
			"2 - Динамический массив" << '\n' <<
			"3 - Динамический массив с использованием вектора" << '\n';
		cin >> type_arr;

		if (type_arr == 1)
		{
			int static_array[Len];
			int length;
			cout << "Введите кол-во элементов: ";
			cin >> length;

			if ((length > 0) and (length < Len))
			{
				cout << "Введите " << length << " элементов: ";
				for (int i = 0; i < length; i++)
				{
					cin >> static_array[i];
				}
			}
			//задачи
			int restart_button_for_tasks = 1;
			int couter_for_tasks = 0;
			while (restart_button_for_tasks == 1)
			{
				int number_of_task;
				cout << "Выберите задание:" << '\n' <<
					"1 - Нахождение индекса элемента, сумма чисел которого кратна 7" << '\n' <<
					"2 - Добавление нового элемента перед минимальным элементом, сумма чисел которого кратна 7" << '\n' <<
					"3 - Удаление элемента, сумма чисел которого кратна 7 " << '\n';
				cin >> number_of_task;
				if (number_of_task == 1)
				{

					cout << "Элемент находится под индексом: ";
					cout << find_the_index_s(static_array, Len);
				}

				if (number_of_task == 2)
				{
					insert_s(static_array, length);
					show_the_array(static_array, length + counter_for_print);
					counter_for_print += 1;
				}

				if (number_of_task == 3)
				{
					del_element(static_array, length);
					show_the_array(static_array, length);
					counter = 0;
				}
				cout << '\n';
				cout << "Если хотите продолжить выполнять задачи, то введите число 1: ";
				cin >> restart_button_for_tasks;
			}
		}

		if (type_arr == 2)
		{
			int* dynamic_array;
			int length;
			cout << "Введите кол-во элементов: ";
			cin >> length;
			dynamic_array = (int*)malloc(length * sizeof(int));
			cout << "Введите " << length << " элементов";
			for (int i = 0; i < length; i++)
			{
				cin >> dynamic_array[i];
			}

			int restart_button_for_tasks = 1;
			int couter_for_tasks = 0;
			int number_of_task;
			while (restart_button_for_tasks == 1)
			{
				cout << "Выберите задание:" << '\n' <<
					"1 - Нахождение индекса элемента, сумма чисел которого кратна 7" << '\n' <<
					"2 - Добавление нового элемента перед минимальным элементом, сумма чисел которого кратна 7" << '\n' <<
					"3 - Удаление элемента, сумма чисел которого кратна 7 " << '\n';
				cin >> number_of_task;
				if (number_of_task == 1)
				{
					cout << "Элемент находится под индексом: ";
					cout << find_the_index_d(dynamic_array, length);
				}

				if (number_of_task == 2)
				{
					insert_d(dynamic_array, length);
					show_the_array(dynamic_array, length + counter_for_print);
					counter_for_print += 1;

				}

				if (number_of_task == 3)
				{
					del_element_d(dynamic_array, length);
					show_the_array(dynamic_array, length);
					counter = 0;
				}
				cout << '\n';
				cout << "Если хотите продолжить выполнять задачи, то введите число 1: ";
				cin >> restart_button_for_tasks;
			}
		}

		if (type_arr == 3)
		{
			int length;
			int element;
			std::vector< int > vector_array;
			std::cout << "Введите кол-во элементов ";
			std::cin >> length;
			std::cout << "Введите " << length << " элементов: ";
			for (int i = 0; i < length; i++)
			{
				std::cin >> element;
				vector_array.push_back(element);
			}

			int restart_button_for_tasks = 1;
			int couter_for_tasks = 0;
			while (restart_button_for_tasks == 1)
			{
				int number_of_task;
				cout << "Выберите задание:" << '\n' <<
					"1 - Нахождение индекса элемента, сумма чисел которого кратна 7" << '\n' <<
					"2 - Добавление нового элемента перед минимальным элементом, сумма чисел которого кратна 7" << '\n' <<
					"3 - Удаление элемента, сумма чисел которого кратна 7 " << '\n';
				cin >> number_of_task;
				if (number_of_task == 1)
				{
					cout << "Элемент находится под индексом: ";
					cout << find_the_index_v(vector_array, length);
				}

				if (number_of_task == 2)
				{
					cout << length + counter_for_print << ' ';
					insert_v(vector_array, length);
					show_the_array_v(vector_array, length + counter_for_print);
					counter_for_print += 1;
				}

				if (number_of_task == 3)
				{
					del_element_v(vector_array, length);
					show_the_array_v(vector_array, length);
					counter = 0;
				}

				cout << '\n';
				cout << "Если хотите продолжить выполнять задачи, то введите число 1: ";
				cin >> restart_button_for_tasks;
			}
		}

		cout << '\n';
		cout << "Если хотите перейти к выбору типа массива, то введите число 1: ";
		cin >> restart_button;
	}
}


