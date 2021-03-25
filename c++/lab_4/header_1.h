#pragma once
#include <iostream> 
#include <cctype>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

const double pi = 3.14159265358979323846;

class Shape{
public:
	virtual double area() = 0;
	virtual double perimeter() = 0;
	virtual string getName()=0;
};


class Kwadrat:public Shape {
private:
	string name_;
	double a_;
public:
	Kwadrat(string name,double a) {
		name_ = name;
		a_ = a;
	}
	double area(){
		return a_ * a_;
	}
	double perimeter(){
		return a_ * sqrt(2);
	}
	string getName() {
		return name_;
	}
};

class Prostokat :public Shape {
private:
	string name_;
	double a_, b_;
public:
	Prostokat(string name,double a, double b){
		name_ = name;
		a_ = a;
		b_ = b;
	}
	double area() {
		return a_ * b_;
	}
	double perimeter() {
		return sqrt(a_*a_ + b_ * b_);
	}
	string getName() {
		return name_;
	}
};

class Kolo :public Shape {
private:
	string name_;
	double r_;
public:
	Kolo(string name, double r) {
		name_ = name;
		r_ = r;
	}
	double area() {
		return r_ * r_* pi;
	}
	double perimeter() {
		return 2 * pi*r_;
	}
	string getName() {
		return name_;
	}
};

class Elipsa :public Shape {
private:
	string name_;
	double a_, b_;
public:
	Elipsa(string name, double a, double b ) {
		name_ = name;
		a_ = a;
		b_ = b;
	}
	double area() {
		return pi * a_*b_;
	}
	double perimeter() {
		return pi * (1.5*(a_ + b_) - sqrt(a_*b_));
	}
	string getName() {
		return name_;
	}
};

class ShapeContainer {
private:
	vector<Shape*>arr;

public:
	ShapeContainer() {}

	void addShape(Shape*toAdd) {
		arr.push_back(toAdd);
	}
	void displayAll() {
		//cout << arr.size();
		
		for (Shape* tmp : arr) {
			cout << "Nazwa: " << tmp->getName();
			cout<<" Pole: "<<tmp->area();
			cout <<" Przekatna: "<<tmp->perimeter();
			cout << endl;
		}
	}
};