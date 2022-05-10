#include "con1.h"

//Triangles::Triangles(int a, int b, int c) {
//	this->a = a;
//	this->b = b;
//	this->c = c;
//}
Triangles::Triangles(const Triangles &other) {
	this->a = other.a;
	this->b = other.b;
	this->c = other.c;
}
//const Triangles Triangles::operator +(Triangles other) {
//	Triangles temp;
//	temp.a = this->a + other.a;
//	temp.b = this->b + other.b;
//	temp.c = this->c + other.c;
//	if (temp.a + temp.b > temp.c && temp.a + temp.b > temp.c && temp.b + temp.c > temp.a){
//		return temp;
//	}
//	else {
//		temp.a = a;
//		temp.b = b;
//		temp.c = c;
//		return temp;
//	}
//}
//const Triangles Triangles::operator -(Triangles other) {
//	Triangles temp;
//	temp.a = this->a - other.a;
//	temp.b = this->b - other.b;
//	temp.c = this->c - other.c;
//	if (temp.a + temp.b > temp.c && temp.a + temp.b > temp.c && temp.b + temp.c > temp.a) {
//		return temp;
//	}
//	else {
//		temp.a = a;
//		temp.b = b;
//		temp.c = c;
//		return temp;
//	}
//}
