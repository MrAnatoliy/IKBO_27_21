#pragma once
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Triangles {
public:
	int a, b, c;
	Triangles() {};
	Triangles(int a, int b, int c) : a(a), b(b), c(c) {};
	Triangles(const Triangles &other);
	//const Triangles operator +(Triangles other);
	//const Triangles operator -(Triangles other);
};

