#include <iostream>
#include <cctype>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

const double pi = 3.14159265358979323846;

class Shape
{
public:
	virtual double area() = 0;
	virtual double perimeter() = 0;
	virtual string getName() = 0;
};

class Kwadrat : public Shape
{
private:
	string name_;
	double a_;

public:
	Kwadrat(string name, double a)
	{
		name_ = name;
		a_ = a;
	}
	double area()
	{
		return a_ * a_;
	}
	double perimeter()
	{
		return a_ * sqrt(2);
	}
	string getName()
	{
		return name_;
	}
};

class Prostokat : public Shape
{
private:
	string name_;
	double a_, b_;

public:
	Prostokat(string name, double a, double b)
	{
		name_ = name;
		a_ = a;
		b_ = b;
	}
	double area()
	{
		return a_ * b_;
	}
	double perimeter()
	{
		return sqrt(a_ * a_ + b_ * b_);
	}
	string getName()
	{
		return name_;
	}
};

class Kolo : public Shape
{
private:
	string name_;
	double r_;

public:
	Kolo(string name, double r)
	{
		name_ = name;
		r_ = r;
	}
	double area()
	{
		return r_ * r_ * pi;
	}
	double perimeter()
	{
		return 2 * pi * r_;
	}
	string getName()
	{
		return name_;
	}
};

class Elipsa : public Shape
{
private:
	string name_;
	double a_, b_;

public:
	Elipsa(string name, double a, double b)
	{
		name_ = name;
		a_ = a;
		b_ = b;
	}
	double area()
	{
		return pi * a_ * b_;
	}
	double perimeter()
	{
		return pi * (1.5 * (a_ + b_) - sqrt(a_ * b_));
	}
	string getName()
	{
		return name_;
	}
};

class ShapeContainer
{
private:
	vector<Shape *> arr;

public:
	ShapeContainer() {}

	void addShape(Shape *toAdd)
	{
		arr.push_back(toAdd);
	}
	void displayAll()
	{
		//cout << arr.size();

		for (Shape *tmp : arr)
		{
			cout << "Nazwa: " << tmp->getName();
			cout << " Pole: " << tmp->area();
			cout << " Przekatna: " << tmp->perimeter();
			cout << endl;
		}
	}
};

class Doskonala
{
	//long long int n_;
public:
	Doskonala() {}
	Doskonala(long long int m, long long int n)
	{
		//this->Dowod(m,n);
	}
	~Doskonala() {}

	void Dowod(long long int m, long long int n)
	{
		for (int k = m; k < 10000; k++)
			if (isPerfect(k))
				divisors(k);
	}

	bool isPerfect(long long int n)
	{
		// To store sum of divisors
		long long int sum = 1;

		// Find all divisors and add them
		for (long long int i = 2; i * i <= n; i++)
		{
			if (n % i == 0)
			{
				if (i * i != n)
					sum = sum + i + n / i;
				else
					sum = sum + i;
			}
		}
		// If sum of divisors is equal to
		// n, then n is a perfect number
		if (sum == n && n != 1)
			return true;

		return false;
	}

	void divisors(long long int n)
	{
		cout << n << " = ";
		cout << "1";
		for (int i = 2; i < n; i++)
		{
			if (n % i == 0)
			{
				cout << " + " << i;
			}
		}
		cout << endl;
	}
};

class Liczby_doskonale : public Doskonala
{
public:
	Liczby_doskonale() {}
	Liczby_doskonale(long long int m, long long int n)
	{
		//this->Dowod(m, n);
	}
	~Liczby_doskonale(){};
};

class Doskonalav2
{
	//long long int n_;
public:
	Doskonalav2() {}
	Doskonalav2(long long int m, long long int n)
	{
		//this->Dowod(m,n);
	}
	~Doskonalav2(){};

	virtual void Dowod(long long int m, long long int n) = 0;
};

class Liczby_doskonalev2 : public Doskonalav2
{
public:
	Liczby_doskonalev2(long long int m, long long int n)
	{
		//this->Dowod(m, n);
	}
	~Liczby_doskonalev2(){};

	void Dowod(long long int m, long long int n)
	{
		int counter = 0;
		for (int k = m; k < n; k++)
			if (isPerfect(k))
			{
				counter++;
				cout << counter << ". ";
				divisors(k);
			}
	}

	bool isPerfect(long long int n)
	{
		// To store sum of divisors
		long long int sum = 1;

		// Find all divisors and add them
		for (long long int i = 2; i * i <= n; i++)
		{
			if (n % i == 0)
			{
				if (i * i != n)
					sum = sum + i + n / i;
				else
					sum = sum + i;
			}
		}
		// If sum of divisors is equal to
		// n, then n is a perfect number
		if (sum == n && n != 1)
			return true;

		return false;
	}

	void divisors(long long int n)
	{
		cout << n << " = ";
		cout << "1";
		for (int i = 2; i < n; i++)
		{
			if (n % i == 0)
			{
				cout << " + " << i;
			}
		}
		cout << endl;
	}
};

int main()
{
	int nr;
	cout << "Wprowadz numer zadania: ";
	cin >> nr;
	switch (nr)
	{
	case 5:
	{
		ShapeContainer *container = new ShapeContainer();
		Kwadrat *k_1 = new Kwadrat("kwadrat_1", 5);
		Prostokat *p_1 = new Prostokat("prostokat_1", 5, 4);
		Kolo *ko_1 = new Kolo("kolo_1", 5);
		Elipsa *e_1 = new Elipsa("elipsa_1", 5, 4);

		container->addShape(k_1);
		container->addShape(p_1);
		container->addShape(ko_1);
		container->addShape(e_1);

		container->displayAll();

		break;
	}
	case 6:
	{

		break;
	}
	case 7:
	{
		//zakres
		long long int m = 6;
		long long int n = 10000;
		cout << "Liczby doskonale w podanych zakresie to: \n";
		Liczby_doskonale perfect(m, n);

		Doskonala *ldosk = &perfect;
		ldosk->Dowod(m, n);

		break;
	}
	case 8:
	{
		//zakres
		long long int m = 6;
		long long int n = 10000;
		cout << "Liczby doskonale w podanych zakresie to: \n";
		Liczby_doskonalev2 perfect(m, n);

		Doskonalav2 *ldosk = &perfect;
		ldosk->Dowod(m, n);

		break;
	}

	default:
	{
		cout << "Wprowadz poprawny numer zadania!";
		break;
	}
	}
	return 0;
}
