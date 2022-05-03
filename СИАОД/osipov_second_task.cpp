#include <iostream>
#include <vector>
using namespace std;
int const Rows = 30;
int const Cols = 30;

//static
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void input_matrix_with_keyboard(int matrix[Rows][Cols], int rows, int cols)
{
	setlocale(LC_CTYPE, "Russian");

	for (int i = 0; i < rows; i++)
	{
		cout << "Вводим " << i + 1 << " cтроку: ";
		for (int j = 0; j < cols; j++)
			cin >> matrix[i][j];
	}
}

void input_matrix_on_random(int matrix[Rows][Cols], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			matrix[i][j] = rand() % 100;
	}
}

void show_the_matrix(int matrix[Rows][Cols], int rows, int cols)
{
	setlocale(LC_CTYPE, "Russian");
	for (int i = 0; i < rows; i++)
	{
		cout << i + 1 << " строка: ";
		for (int j = 0; j < cols; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << '\n';
	}
}

void task(int matrix[Rows][Cols], int size)
{
	bool flag;
	flag = true;

	for (int n = 0; n < size; n++)
	{
		int decrease = 0;
		int increase = 0;

		for (int m = 1; m < size; m++)
		{
			if (matrix[n][m] > matrix[n][m - 1])
				decrease++;

			if (matrix[n][m] < matrix[n][m - 1])
				increase++;

			if ((decrease == size - 1 || increase == size - 1) && flag)
			{
				cout << "Эти стоки образуют монотонную последовательность: ";
				flag = false;
			}

			if (!flag && (decrease == size - 1 || increase == size - 1))
				cout << n << ' ';

		}
	}
	if (flag)
		cout << "Не существует монотонной последовательности в данных строчках" << '\n';
}

//dynamic
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void allocMatrix(int**& dynamic_matrix, int rows, int cols)
{
	dynamic_matrix = new int* [rows];

	for (int i = 0; i < rows; i++)
	{
		dynamic_matrix[i] = new int[cols];
	}
}

void input_matrix_with_keyboard_dynamic(int** dynamic_matrix, int rows, int cols)
{
	setlocale(LC_CTYPE, "Russian");

	for (int i = 0; i < rows; i++)
	{
		cout << "Вводим " << i + 1 << " cтроку: ";
		for (int j = 0; j < cols; j++)
			cin >> dynamic_matrix[i][j];
	}
}

void input_matrix_on_random_dynamic(int** dynamic_matrix, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			dynamic_matrix[i][j] = rand() % 100;
	}
}

void show_the_matrix_dynamic(int** dynamic_matrix, int rows, int cols)
{
	setlocale(LC_CTYPE, "Russian");
	for (int i = 0; i < rows; i++)
	{
		cout << i + 1 << " строка: ";
		for (int j = 0; j < cols; j++)
		{
			cout << dynamic_matrix[i][j] << " ";
		}
		cout << '\n';
	}
}

void task_dynamic(int**& dynamic_matrix, int size)
{
	bool flag;
	flag = true;

	for (int n = 0; n < size; n++)
	{
		int decrease = 0;
		int increase = 0;

		for (int m = 1; m < size; m++)
		{
			if (dynamic_matrix[n][m] > dynamic_matrix[n][m - 1])
				decrease++;

			if (dynamic_matrix[n][m] < dynamic_matrix[n][m - 1])
				increase++;

			if ((decrease == size - 1 || increase == size - 1) && flag)
			{
				cout << "Эти стоки образуют монотонную последовательность: ";
				flag = false;
			}

			if (!flag && (decrease == size - 1 || increase == size - 1))
				cout << n << ' ';

		}
	}
	if (flag)
		cout << "Не существует монотонной последовательности в данных строчках";
}

//vector
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void input_matrix_with_keyboard_vector(vector<vector<int> >& vector_matrix, int rows, int cols)
{
	setlocale(LC_CTYPE, "Russian");
	for (int i = 0; i < rows; i++)
	{
		cout << "Вводим " << i + 1 << " cтроку: ";
		for (int j = 0; j < cols; j++)
			cin >> vector_matrix[i][j];
	}

}

void show_the_matrix_vector(vector<vector<int> >& vector_matrix, int rows, int cols)
{
	setlocale(LC_CTYPE, "Russian");
	for (int i = 0; i < rows; i++)
	{
		cout << i + 1 << " строка: ";
		for (int j = 0; j < cols; j++)
		{
			cout << vector_matrix[i][j] << " ";
		}
		cout << '\n';
	}
}

void input_matrix_on_random_vector(vector<vector<int> >& vector_matrix, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			vector_matrix[i][j] = rand() % 100;
	}
}

void task_vector(vector<vector<int> >& vector_matrix, int size)
{
	bool flag;
	flag = true;

	for (int n = 0; n < size; n++)
	{
		int decrease = 0;
		int increase = 0;

		for (int m = 1; m < size; m++)
		{
			if (vector_matrix[n][m] > vector_matrix[n][m - 1])
				decrease++;

			if (vector_matrix[n][m] < vector_matrix[n][m - 1])
				increase++;

			if ((decrease == size - 1 || increase == size - 1) && flag)
			{
				cout << "Эти стоки образуют монотонную последовательность: ";
				flag = false;
			}

			if (!flag && (decrease == size - 1 || increase == size - 1))
				cout << n << ' ';

		}
	}
	if (flag)
		cout << "Не существует монотонной последовательности в данных строчках";
}

//task 2
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void task_2(int N)
{
	int n1 = 0;
	int n2 = 0;
	int n3 = 0;
	int n4 = 0;
	cout << "Введите координаты точек:" << '\n';

	for (int i = 0; i < N; i++)
	{
		int x;
		int y;
		std::cout << i + 1 << ": ";
		cin >> x >> y;
		if (x > 0 && y > 0) { n1++; }
		if (x < 0 && y > 0) { n2++; }
		if (x < 0 && y < 0) { n3++; }
		if (x > 0 && y < 0) { n4++; }
	}
	int s;
	s = (n1 * n2) + (n2 * n3) + (n3 * n4) + (n4 * n1);
	cout << "Количество отрезко: " << s << '\n';
}

//main function
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int restart_button = 1;
	while (restart_button == 1)
	{
		int type_of_task;
		cout << "Выберите номер задачи:" << '\n' <<
			"1 - Задание с матрицой" << '\n' <<
			"2 - Задание с плоскостью " << '\n';
		cin >> type_of_task;
		if (type_of_task == 1)
		{
			setlocale(LC_CTYPE, "Russian");
			int rows, cols;
			int matrix[Rows][Cols];
			cout << "Введите кол-во строк: ";
			cin >> rows;
			cout << '\n';
			cout << "Введите кол-во столбцов: ";
			cin >> cols;
			int type_of_matrix;
			cout << "Выберите тип двумерного массива/задачу" << '\n' <<
				"1 - Статический двумерный массив" << '\n' <<
				"2 - Динамический двумерный массив" << '\n' <<
				"3 - Динамический двумерный массив с использованием вектора" << '\n';
			cin >> type_of_matrix;
			if (type_of_matrix == 1)
			{
				int restart_button_for_func = 1;
				while (restart_button_for_func == 1)
				{
					int type_of_input;
					cout << "Выберите тип ввода чисел в двумерный массив" << '\n' <<
						"1 - Ввод чисел с помощью клавиатуры" << '\n' <<
						"2 - Датчиком случайных чисел" << '\n';
					cin >> type_of_input;

					if (type_of_input == 1)
					{
						input_matrix_with_keyboard(matrix, rows, cols);
						cout << '\n' << "Ваша матрица:" << '\n';
						show_the_matrix(matrix, rows, cols);

						if (!(rows == cols))
							cout << "Ваши значения не удвлетворяют условию задачи";
						else
						{
							int size;
							size = rows;
							task(matrix, size);
						}
					}

					else if (type_of_input == 2)
					{
						input_matrix_on_random(matrix, rows, cols);
						cout << '\n' << "Ваша матрица:" << '\n';
						show_the_matrix(matrix, rows, cols);

						if (!(rows == cols))
							cout << "Ваши значения не удвлетворяют условию задачи";
						else
						{
							int size;
							size = rows;
							task(matrix, size);
						}
					}
					cout << '\n';
					cout << "Если хотите продолжить, то нажмите 1: ";
					cin >> restart_button_for_func;
				}
			}
			if (type_of_matrix == 2)
			{
				int restart_button_for_func = 1;
				while (restart_button_for_func == 1)
				{
					int** dynamic_matrix = NULL;

					int type_of_input;
					cout << "Выберите тип ввода чисел в двумерный массив" << '\n' <<
						"1 - Ввод чисел с помощью клавиатуры" << '\n' <<
						"2 - Датчиком случайных чисел" << '\n';
					cin >> type_of_input;
					if (type_of_input == 1)
					{
						allocMatrix(dynamic_matrix, rows, cols);
						input_matrix_with_keyboard_dynamic(dynamic_matrix, rows, cols);
						cout << '\n' << "Ваша матрица:" << '\n';
						show_the_matrix_dynamic(dynamic_matrix, rows, cols);

						if (!(rows == cols))
							cout << "Ваши значения не удвлетворяют условию задачи";
						else
						{
							int size;
							size = rows;
							task_dynamic(dynamic_matrix, size);
						}
					}

					else if (type_of_input == 2)
					{
						allocMatrix(dynamic_matrix, rows, cols);
						input_matrix_on_random_dynamic(dynamic_matrix, rows, cols);
						cout << '\n' << "Ваша матрица:" << '\n';
						show_the_matrix_dynamic(dynamic_matrix, rows, cols);

						if (!(rows == cols))
							cout << "Ваши значения не удвлетворяют условию задачи";
						else
						{
							int size;
							size = rows;
							task_dynamic(dynamic_matrix, size);
						}
					}
					cout << '\n';
					cout << "Если хотите продолжить, то нажмите 1: ";
					cin >> restart_button_for_func;
				}
			}
			if (type_of_matrix == 3)
			{
				int restart_button_for_func = 1;
				while (restart_button_for_func == 1)
				{
					vector<vector<int>> vector_matrix(rows, vector<int>(cols, 0));
					int type_of_input;
					cout << "Выберите тип ввода чисел в двумерный массив" << '\n' <<
						"1 - Ввод чисел с помощью клавиатуры" << '\n' <<
						"2 - Датчиком случайных чисел" << '\n';
					cin >> type_of_input;
					if (type_of_input == 1)
					{
						input_matrix_with_keyboard_vector(vector_matrix, rows, cols);
						cout << '\n' << "Ваша матрица:" << '\n';
						show_the_matrix_vector(vector_matrix, rows, cols);

						if (!(rows == cols))
							cout << "Ваши значения не удвлетворяют условию задачи";
						else
						{
							int size;
							size = rows;
							task_vector(vector_matrix, size);
						}
					}

					else if (type_of_input == 2)
					{
						input_matrix_on_random_vector(vector_matrix, rows, cols);
						cout << '\n' << "Ваша матрица:" << '\n';
						show_the_matrix_vector(vector_matrix, rows, cols);

						if (!(rows == cols))
							cout << "Ваши значения не удвлетворяют условию задачи";
						else
						{
							int size;
							size = rows;
							task_vector(vector_matrix, size);
						}
					}
					cout << '\n';
					cout << "Если хотите продолжить, то нажмите 1: ";
					cin >> restart_button_for_func;
				}
			}
		}

		if (type_of_task == 2)
		{
			int N;
			cout << "Введите кол-во точек: ";
			cin >> N;
			task_2(N);
		}

		cout << '\n';
		cout << "Если хотите вернуться к выбору типа задачи, то нажмите 1: ";
		cin >> restart_button;
		cout << '\n';
		if (restart_button != 1)
		{
			break;
		}
	}
}