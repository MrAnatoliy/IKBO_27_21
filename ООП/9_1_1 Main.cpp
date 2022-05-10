//#include <stdlib.h>
//#include <stdio.h>
#include "con1.h"

const Triangles operator +(Triangles other1, Triangles other2) {
	Triangles temp;
	temp.a = other1.a + other2.a;
	temp.b = other1.b + other2.b;
	temp.c = other1.c + other2.c;
	if (temp.a + temp.b > temp.c && temp.a + temp.c > temp.b && temp.b + temp.c > temp.a) {
		return temp;
	}
	else {
		temp.a = other1.a;
		temp.b = other1.b;
		temp.c = other1.c;
		return temp;
	}
}

const Triangles operator -(Triangles other1, Triangles other2) {
	Triangles temp;
	temp.a = other1.a - other2.a;
	temp.b = other1.b - other2.b;
	temp.c = other1.c - other2.c;
	if (temp.a + temp.b > temp.c && temp.a + temp.c > temp.b && temp.b + temp.c > temp.a) {
		return temp;
	}
	else {
		temp.a = other1.a;
		temp.b = other1.b;
		temp.c = other1.c;
		return temp;
	}
}

int main() {
	// program here
	setlocale(LC_ALL, "");
	int n, a, b, c;
	int num1, num2;
	char oper;

	cout << "Размер массив: ";
	cin >> n; cout << endl;

	vector<Triangles> mas;
	
	cout << "Введите значения a, b, c:\n";
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		Triangles temp(a, b, c);
		mas.push_back(Triangles(temp));
	}

	cout << "Выберите номер треугольник и оператор (num1 '+ or -' num2)\n";
	while (cin >> num1 >> oper >> num2) {
		if (oper == '+') {
			mas[num1 - 1] = mas[num1 - 1] + mas[num2 - 1];
		}
		else if (oper == '-'){
			mas[num1 - 1] = mas[num1 - 1] - mas[num2 - 1];
		}
	}
	cout << "a = " << mas[num1 - 1].a << "; ";
	cout << "b = " << mas[num1 - 1].b << "; ";
	cout << "c = " << mas[num1 - 1].c << ".";

	return(0);
}
