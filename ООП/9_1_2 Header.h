#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Hex {
private:
	unsigned char templ, base;
public:
	Hex() {} ;
	Hex(int base, int templ) : base(static_cast<unsigned char>(base)), templ(static_cast<unsigned char>(templ)) {};
	int getId();
	Hex& operator &=(Hex& other);
	Hex& operator |=(Hex& other);
};

