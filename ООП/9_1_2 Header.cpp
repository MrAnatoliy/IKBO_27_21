#include "Header.h"

int Hex::getId() {
	return static_cast<int>(base);
}

Hex& Hex::operator&=(Hex& other) {
	unsigned char templ1 = base, templ2 = other.base;
	unsigned char tmp = templ & other.templ;
	templ1 &= tmp;
	templ2 &= tmp;
	templ2 &= templ1;

	base &= ~tmp;
	base |= templ2;

	return *this;
}

Hex& Hex::operator |=(Hex& other) {
	base = base | (other.base & (templ & other.templ));
	return *this;
}