#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Tree {
protected:
	string name;
	Tree* head;
	vector<Tree*> children;
	bool ready; // ��_3_1
public:
	Tree(Tree* head, string name = "root");
	void set_name(string name);
	string get_name();
	void set_head(Tree* head); // ������� �������� ������
	Tree* get_head();
	void print(int count = 1);
	Tree* getByName(string name);

	// ��_3_1
	void set_ready(int input_ready); // ����� ���������� �������
	void build_ready(); // ��������� ���������� �������
	void print_ready(string tab); // ����� ���������� ��������
};

class Application : public Tree {
public:
	Application(Tree* head);
	void build();
	int launch();
};

class Class2 : public Tree {
public:
	Class2(Tree* head, string name);
};

class Class3 : public Tree {
public:
	Class3(Tree* head, string name);
};
class Class4 : public Tree {
public:
	Class4(Tree* head, string name);
};

class Class5 : public Tree {
public:
	Class5(Tree* head, string name);
};

class Class6 : public Tree {
public:
	Class6(Tree* head, string name);
};