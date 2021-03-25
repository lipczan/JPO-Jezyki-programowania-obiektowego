#include <iostream>
#include <string> 
#include <fstream>
using namespace std;

class Student {
	private:
	int id_;
	string name_;
	string name_2_;

	public:
	Student(int id, string name, string name_2) {
		id_ = id;
		name_ = name;
		name_2_ = name_2;
	}

	int getId() {
		return id_;
	}
	string getName() {
		return name_;
	}
	string getName_2() {
		return name_2_;
	}
};