#include "Header.h"

int main(){
	setlocale(LC_ALL, "RUS");
	Application obj(nullptr);
	obj.build();
	return obj.launch();
}