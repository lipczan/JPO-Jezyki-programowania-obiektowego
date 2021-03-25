#include<iostream>
#include<string>

using namespace std;

class matrix {
public:
	unsigned int r_, c_;
	double **M;

	matrix();
	matrix(unsigned int r,unsigned int c);

	~matrix() {
		for (int i = 0; i < r_; i++)
		{
			delete[]M[i];
		}
		delete[] M;
	}

	//konstruktor kopiu¹cy
	matrix(matrix const & source);

	void input();

	friend ostream& operator<< (ostream&, const matrix &A);
	
	//matrix & operator=(const matrix &A);

	friend matrix operator*=(const matrix &B, const double tmp);
	friend matrix operator+=(const matrix &B, const double tmp);
	friend matrix operator/=(const matrix &B, const double tmp);
	friend matrix operator-=(const matrix &B, const double tmp);


	friend matrix operator+(const matrix &B, const matrix &A);
	friend matrix operator*(const matrix &B, const matrix &A);
	friend matrix operator-(const matrix &B, const matrix &A);

	matrix &  operator=(const matrix &A);
	matrix &  operator==(const matrix &A);

};


//kontruktor/////////////////////////////////////////////////////////
matrix::matrix(unsigned int r, unsigned int c) {
	r_ = r;
	c_ = c;
	//double val;
	M = new double *[r_];
	for (int i = 0; i < r_; i++) {
		M[i] = new double[c_];
	}
}

//konstruktor kopiujacy////////////////////////////////////////////////
matrix::matrix(matrix const &m) {
	c_ = m.c_;
	r_ = m.r_;
	M= new double *[r_];

	for (int i = 0; i < r_; i++) {
		M[i] = new double[c_];
	}

	for (int i = 0; i < r_; i++) {
		for (int p = 0; p < c_; p++) {
			M[i][p] = m.M[i][p];
		}
	}
}

//wprowadzanie danych//////////////////////////////////////////////
void matrix::input() {
	double value;
	cout << "\nINPUT:" << endl;

	for (int i = 0; i < r_; i++) {
		for (int j = 0; j < c_; j++) {
			cout << "Input M[" << j + 1 << "," << i + 1 << "]=";
			//cin >> M[i][j];
			cin >> value;
			M[i][j] = value;
		}
	}
}

//mnozenie przez stala////////////////////////////////////
matrix operator*=(const matrix &B, const double tmp) {
	matrix il(B);

	for (int i = 0; i < B.r_; i++)
		for (int j = 0; j < B.c_; j++)
			B.M[i][j] = B.M[i][j] * tmp;
	cout << "Mnozenie: " << endl;
	return B;
}
//dodawanie stalej////////////////////////////////////////
matrix operator+=(const matrix &B, const double tmp) {
	matrix sum(B);

	for (int i = 0; i < B.r_; i++)
		for (int j = 0; j < B.c_; j++)
			B.M[i][j] = B.M[i][j] + tmp;
	cout << "Dodawanie: " << endl;
	return B;
}

////problem z wartosciami, przeciazony operator bierze poprzednia tablice do obliczen!!!!!!!!!!!!!!
////

//odejmowanie stalej//////////////////////////////////////
matrix operator-=(const matrix &A, const double tmp) {
	matrix ro(A);

	for (int i = 0; i < A.r_; i++)
		for (int j = 0; j < A.c_; j++)
			A.M[i][j] = A.M[i][j] - tmp;
	cout << "Odejmowanie: " << endl;
	return A;
}
//dzielenie przez stala//////////////////////////////////
matrix operator/=(const matrix &B, const double tmp) {
	if (tmp == 0) {
		cout << "Nie dziel przez 0.";
	}
	else {
		matrix sum(B);

		for (int i = 0; i < B.r_; i++)
			for (int j = 0; j < B.c_; j++)
				B.M[i][j] = B.M[i][j] / tmp;
		cout << "Dzielenie: " << endl;
		return B;
	}

}

//przeciazony operator wyswietlania//////////////////////////////////////////////
ostream& operator<<(ostream& out, const matrix &A) {
	for (int i = 0; i < A.r_; i++) {
		for (int j = 0; j < A.c_; j++)
			out << A.M[i][j] << " ";

		out << endl;
	}
	return out;
}


//dodawanie macierzy/////////////////////////////////////////////////////////////
matrix operator+(const matrix &m1,const matrix &m2)
{
	if (!(m1.r_ == m2.r_ && m1.c_ == m2.c_))
		cout<< "Wymiary macierzy nie sa zgodne, nie mozna wykonac dodawania";
	else
	{
		matrix m3(m1);
		for (int i = 0; i < m3.r_; i++)
			for (int j = 0; j < m3.c_; j++)
			{
				m3.M[i][j] += m2.M[i][j];
			}
		return m3;
	}
}
//mnozenie macierzy/////////////////////////////////////////////////////////////
matrix operator*(const matrix &m1, const matrix &m2)
{
	if (m1.c_ != m2.r_)
		cout << "Wymiary macierzy nie sa zgodne, nie mozna wykonac mnozenia";
	else
	{
		matrix m3(m1);
		for (int i = 0; i < m1.r_; i++)
		{
			for (int j = 0; j < m2.c_; j++)
			{
				m3.M[i][j] = 0;
			}
		}

		for (int i = 0; i < m1.r_; i++)
		{
			for (int j = 0; j < m2.c_; j++) {
				for (int k = 0; k < m2.r_; k++) {
					m3.M[i][j] = m3.M[i][j] + m1.M[i][k] * m2.M[k][j];
				}
			}
		}
		return m3;
	}
}
//odejmowanie macierzy//////////////////////////////////////////////////////////
matrix operator-(const matrix &m1, const matrix &m2)
{
	if (m1.r_ != m2.r_ || m1.c_ != m2.c_)
		cerr << "Wymiary macierzy nie sa zgodne, nie mozna wykonac odejmowania";
	else
	{
		matrix m3(m1);
		for (int i = 0; i < m3.r_; i++)
			for (int j = 0; j < m3.c_; j++)
			{
				m3.M[i][j] -= m2.M[i][j];
			}
		return m3;
	}
}

/*
matrix operator+(const matrix &B,const matrix &A) {
	matrix sum(B.size);
	for (int i = 0; i < B.size; i++) {
		for (int j = 0; j < B.size; j++) {
			sum.M[i][j] = M[i][j] + B.M[i][j];
		}
	}
	return sum;
}

matrix:: ~matrix() {
	for (int i = 0; i < size; i++) {
		delete[] M[i];
	}
	delete[] M;
}
matrix::matrix(int s) :size(s) {
	M = new double*[s];
	for (int i = 0; i < s; i++) {
		M[i] = new double[s];
	}
}
matrix::matrix(const matrix & source) :size(source.size) {
	M = new double*[size];
	for (int i = 0; i < size; i++) {
		M[i] = new double[size];
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			M[i][j] = source.M[i][j];
		}
	}
}


matrix matrix:: operator-(matrix &B) {
	matrix sum(B.size);
	for (int i = 0; i < B.size; i++) {
		for (int j = 0; j < B.size; j++) {
			sum.M[i][j] = M[i][j] - B.M[i][j];
		}
	}
	return sum;
}
matrix & matrix:: operator=(const matrix &A) {
	for (int i = 0; i < A.size; i++) {
		for (int j = 0; j < A.size; j++) {
			M[i][j] = A.M[i][j];
		}
	}
	return (*this);
}

matrix  operator*(matrix &B, matrix &A) {
	matrix sum(B.size);

	for (int i = 0; i < B.size; i++) {
		for (int j = 0; j < B.size; j++) { sum.M[i][j] = 0; }
	}

	for (int i = 0; i < B.size; i++) {
		for (int j = 0; j < B.size; j++) {

			for (int g = 0; g < B.size; g++) { sum.M[i][j] = sum.M[i][j] + (sum.M[i][g] * B.M[g][j]); }


		}
	}
	return sum;
}

*/


matrix & matrix:: operator=(const matrix &A) {
	for (int i = 0; i < A.r_; i++) {
		for (int j = 0; j < A.c_; j++) {
			M[i][j] = A.M[i][j];
		}
	}
	return (*this);
}

matrix & matrix:: operator==(const matrix &A) {
	for (int i = 0; i < A.r_; i++) {
		for (int j = 0; j < A.c_; j++) {
			M[i][j] = A.M[i][j];
		}
	}
	return (*this);
}