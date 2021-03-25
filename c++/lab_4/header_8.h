#pragma once
#include <iostream> 
#include <cctype>
using namespace std;

class Doskonalav2 {
	//long long int n_;
public:
	Doskonalav2() {}
	Doskonalav2(long long int m, long long int n) {
		//this->Dowod(m,n);	
	}
	~Doskonalav2() {};

	virtual void Dowod(long long int m, long long int n)=0;
};

class Liczby_doskonalev2 :public Doskonalav2 {
public:
	Liczby_doskonalev2(long long int m, long long int n) {
		//this->Dowod(m, n);
	}
	~Liczby_doskonalev2() {};

	void Dowod(long long int m, long long int n){
		int counter = 0;
		for (int k = m; k < n; k++)
			if (isPerfect(k)) {
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