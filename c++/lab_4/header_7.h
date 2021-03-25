#pragma once
#include <iostream> 
#include <cctype>
using namespace std;

class Doskonala {
	//long long int n_;
public:
	Doskonala() {}
	Doskonala(long long int m,long long int n) {
		//this->Dowod(m,n);	
	}
	~Doskonala() {}

	void Dowod(long long int m, long long int n) {
		for (int k = m; k < 10000; k++)
			if (isPerfect(k))
				divisors(k);
	}

	bool isPerfect(long long int n)
	{
		// To store sum of divisors 
		long long int sum = 1;

		// Find all divisors and add them 
		for (long long int i = 2; i*i <= n; i++)
		{
			if (n%i == 0)
			{
				if (i*i != n)
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

	void divisors(long long int n) {
		cout << n << " = ";
		cout << "1";
		for (int i = 2; i < n; i++) {
			if (n%i == 0) {
				cout << " + " << i;
			}
		}
		cout << endl;
	}
	

};

class Liczby_doskonale :public Doskonala {
public:
	Liczby_doskonale() {}
	Liczby_doskonale(long long int m, long long int n) {
		//this->Dowod(m, n);
	}
	~Liczby_doskonale() {};

};