#include "Header.h"
#include <iomanip>

//--Tree class--------------------------------------

Tree::Tree(Tree* head, string name) {
	this->name = name;
	this->head = head;
	if (head != nullptr) {
		head->children.push_back(this);
	}
}

void Tree::set_name(string name) {
	this->name = name;
}

string Tree::get_name() {
	return name;
}

void Tree::set_head(Tree* head) {
	this->head = head;
}

Tree* Tree::get_head() {
	return head;
}
void Tree::print(int count) {
	if (head == nullptr) {
		cout << this->name;
	}
	if (children.empty())
		return;
	for (Tree* element : children) {
		cout << endl;
		for (int i = 0; i < count; i++) {
			cout << "    ";
		}
		cout << element->get_name();
		element->print(++count);
		--count;
	}
}

Tree* Tree::getByName(string name) {
	if (this->name == name) {
		return this;
	}
	Tree* result;
	for (int i = 0; i < children.size(); i++) {
		result = children[i]->getByName(name);
		if (result != nullptr) {
			return result;
		}
	}
	return nullptr;
}

// КЛ_3_1
void Tree::set_ready(int input_ready) {
	if (input_ready == 0) {
		ready = false;
		for (int i = 0; i < children.size(); i++) {
			children[i]->set_ready(0);
		}
	}
	else {
		Tree* temp = this->head;
		while (temp != nullptr) {
			if (temp->ready == 0) {
				ready = false;
				return;
			}
			temp = temp->head;
		}
		this->ready = true;
	}
	
}

void Tree::build_ready() { // Установка готовности объекта
	string name;
	int input_ready;
	
	while(cin >> name >> input_ready){
		if (getByName(name) != nullptr) {
			(getByName(name))->set_ready(input_ready);
		}
	}
}

void Tree::print_ready(string tab) { // Вывод готовности объектов
	//string end_ready;
	if (ready == true) {
		cout << get_name() << " is ready";
	}
	else {
		cout << get_name() << " is not ready";
	}
	if (children.size() != 0) {
		tab += "    ";
		for (Tree* element : children) {
			cout << endl << tab;
			element->print_ready(tab);
		}
	}
}



//--Application class------------------------------

Application::Application(Tree* head) : Tree(head) {}

void Application::build() {
	string parentName, childName;
	int object_number;
	cin >> name;
	while (true) {
		cin >> parentName;
		if (parentName == "endtree") {
			build_ready();
			break;
		}
		cin >> childName >> object_number;
		if(object_number == 2)
			Class2* child = new Class2(this->getByName(parentName), childName);
		else if(object_number == 3)
			Class3* child = new Class3(this->getByName(parentName), childName);
		else if (object_number == 4)
			Class4* child = new Class4(this->getByName(parentName), childName);
		else if (object_number == 5)
			Class5* child = new Class5(this->getByName(parentName), childName);
		else if (object_number == 6)
			Class6* child = new Class6(this->getByName(parentName), childName);

	}
}

// КЛ_3_1



int Application::launch() {
	cout << "Object tree\n";
	print();
	cout << "\nThe tree of objects and their readiness\n";
	print_ready("");
	return 0;
}


//--Class--------------------------------------------

Class2::Class2(Tree* head, string name) : Tree(head, name) {}

Class3::Class3(Tree* head, string name) : Tree(head, name) {}

Class4::Class4(Tree* head, string name) : Tree(head, name) {}

Class5::Class5(Tree* head, string name) : Tree(head, name) {}

Class6::Class6(Tree* head, string name) : Tree(head, name) {}