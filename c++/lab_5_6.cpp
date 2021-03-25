#include <iostream>
#include <string>
#include<stdio.h> 
#include<stdlib.h> 
using namespace std;

template <class T> class Node;
template <class T> class Tree;

//================================CLASS: ELEMENT=======================
template <class T>
class Node {
public:
	T value;

	int level;
	Node(T value, Node<T> *left_ptr = nullptr, Node<T> *right_ptr = nullptr);

protected:
	Node <T> *left_ptr;
	Node <T> *right_ptr;

	friend class Tree <T>;
};

//================================CLASS: TREE=======================
template <class T>
class Tree {
public:
	Tree(Node <T> *root = nullptr);
	Node <T> *root;

	void AddElement(T val);

	Node<T> *DeleteElement(Node<T> *ptr, T val);

	//pre-, in-, postorder
	void preorder(Node <T> *ptr);
	void postorder(Node <T> *ptr);
	void inorder(Node <T> *ptr);

	Node<T> *minValueNode(Node<T> * node);
	void examine(Node <T> *ptr);

	Node<T> *search(Node<T> * node);

	//display tree
	void PrintTree(Node <T> *ptr);

	//isEmpty
	bool isEmpty() {
		if (root == nullptr) {
			return true;
		}
		else {
			return false;
		}
	}

	bool Search(Node<T> *ptr, T val)
	{
		if (ptr == NULL) { return false; }
		else if (ptr->value == val) { return true; }
		else if (val <= ptr->value) { Search(ptr->left_ptr, val); }
		else { Search(ptr->right_ptr, val); }
	}

};

template <class T>
Node<T>::Node(T value, Node<T> *left_ptr, Node<T> *right_ptr) :value(value), left_ptr(left_ptr), right_ptr(right_ptr) {}

//FUNKCJE pre-, in- oraz postorder.
//====================================================================
template <class T>
void Tree <T> ::preorder(Node <T> *ptr) {
	if (ptr) {
		examine(ptr);
		preorder(ptr->left_ptr);
		preorder(ptr->right_ptr);
	}
}

template <class T>
void Tree <T> ::postorder(Node <T> *ptr) {
	if (ptr) {
		postorder(ptr->left_ptr);
		postorder(ptr->right_ptr);
		examine(ptr);
	}
}

template <class T>
void Tree <T> ::inorder(Node <T> *ptr) {
	if (ptr) {
		inorder(ptr->left_ptr);
		examine(ptr);
		inorder(ptr->right_ptr);
	}
}

template <class T>
void Tree <T> ::PrintTree(Node <T> *ptr) {

	cout << "PreOrder: ";
	preorder(ptr);
	cout << endl;

	cout << "InOrder: ";
	inorder(ptr);
	cout << endl;

	cout << "PostOrder: ";
	postorder(ptr);
	cout << endl;

}
//====================================================================

template <class T>
void Tree <T> ::AddElement(T val) {
	if (Search(root, val))
		cout << "Wartosc "<<val<<" nie zostala dodana do BST. Wykryto duplikat!" << endl;
	else
	{
		if (root) {
			Node <T> *current = root, *child;
			while (current) {
				if (current->value > val) {
					child = current->left_ptr;
					if (!child) {
						current->left_ptr = new Node<T>(val);
						return;
					}
				}
				else {
					child = current->right_ptr;
					if (!child) {
						current->right_ptr = new Node<T>(val);
						return;
					}
				}
				current = child;
			}
		}
		else {
			root = new Node <T>(val);
		}
	}
}

template <class T>
Tree<T>::Tree(Node<T> *root) :root(root) {}

template<class T>
void Tree<T>::examine(Node<T> *ptr) {
	cout << ptr->value << " ";
}
//==================================REMOVE======================================
template <class T>
Node<T> * Tree<T>::minValueNode(Node<T> *ptr) {
	Node<T>* current = ptr;

	while (current->right_ptr != nullptr)
		current = current->right_ptr;

	return current;
}

template <class T>
Node<T> * Tree<T> ::DeleteElement(Node<T> *ptr, T val) {
	if (isEmpty()) {
		cout << "BST jest puste! ";
	}
	if (!Search(root,val)) {
		cout << "Wartosc "<<val<<" nie zostala usunieta. " << endl;
	}
	else {
		if (ptr == nullptr)
			return ptr;

		if (val > ptr->value)
			ptr->right_ptr = DeleteElement(ptr->right_ptr, val);

		else if (val < ptr->value)
			ptr->left_ptr = DeleteElement(ptr->left_ptr, val);

		else {
			/*
				if (ptr->left_ptr == nullptr) {
				Node<T> *tmp = ptr->right_ptr;
				delete ptr;
				return tmp;
			}
				else if (ptr->right_ptr == nullptr) {
				Node<T> *tmp = ptr->left_ptr;
				delete ptr;
				return tmp;
			}
			*/
			if (ptr->left_ptr == nullptr and ptr->right_ptr == nullptr) {
				Node<T> *tmp = nullptr;
				delete ptr;
				cout << "Usunieto lisc!" << endl;
				return tmp;
				
			}
			else {
				Node<T> *tmp = nullptr;
				cout << "Wartosc nie jest lisciem!" << endl;
				return tmp;
			}
			
				Node <T> *tmp = minValueNode(ptr->left_ptr);
				ptr->value = tmp->value;
				ptr->left_ptr = DeleteElement(ptr->left_ptr, tmp->value);

		}
		return ptr;
	}
	
}

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

	//konstruktor kopiu�cy
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

int main() {
	cout << "Podaj numer zadania: ";
	int nr;
	cin >> nr;
	switch (nr) {
	case 6: {
		Tree<double> bst;

		bst.DeleteElement(bst.root, 10);

		for (int i = 0; i < 10; i++) {
			cout << "Dodano wartosc " << i << " do drzewa." << endl;
			bst.AddElement(i);
		}

		cout << "Ponowne dodanie 1 do drzewa." << endl;
		bst.AddElement(1);

		cout << "Proba usuniecia 10 do BST." << endl;
		bst.DeleteElement(bst.root, 10);

		cout << "Proba usuniecia liscia z wartoscia 9" << endl;
		bst.DeleteElement(bst.root, 9);

		bst.PrintTree(bst.root);

		break;
	}
	case 7: {
		cout << "Wybierz operacje: " << endl;
		cout << "a) przypisanie" << endl;
		cout << "b) dodawanie, odejmowanie, mnozenie, dzielenie przez stala" << endl;
		cout << "c) dodawanie, odejmowanie, mnozenie przez macierz" << endl;

		char tmp;
		int r, c;
		cin >> tmp;
		
		switch (tmp) {
		case 'a': {
			cout << "Wprowadz rozmiar macierzy:" << endl;
			cout << "Liczba wierszy: ";
			cin >> r;
			cout << "Liczba kolumn: ";
			cin >> c;

			matrix moja(r, c);
			moja.input();
			cout << "Macierz nr. 1: " << endl;
			cout << moja;

			cout << endl;
			cout << "Liczba wierszy drugiej macierzy: ";
			cin >> r;
			cout << "Liczba kolumn drugiej macierzy: ";
			cin >> c;

			matrix twoja(r, c);
			twoja.input();
			cout << "Macierz nr. 2: " << endl;
			cout << twoja;
			cout << endl;

			cout << "Przypisana macierz: " << endl;
			moja == twoja;
			cout << moja;

			break;
		}
		case 'b': {
			
			cout << "Wprowadz rozmiar macierzy:" << endl;
			cout << "Liczba wierszy: ";
			cin >> r;
			cout << "Liczba kolumn: ";
			cin >> c;

			matrix moja(r,c);
			moja.input();
			cout << "Wprowadz stala k: ";
			double k;
			cin >> k;

			char h;
			cout << "Wprowadz typ obliczenia(+,-,*,/): ";
			cin >> h;
			switch (h) {
			case'+': {
				moja += k;
				cout << moja;
				break;
			}
			case'-': {
				moja -= k;
				cout << moja;
				break;
			}
			case'*': {
				moja *= k;
				cout << moja;
				break;
			}
			case'/': {
				moja /= k;
				cout << moja;
				break;
			}
			default: {
				cout << "Podaj poprawny typ!" << endl;
			}
			}

			//moja += k;
			//cout << moja;

			//moja -= k;
			//cout << moja;

			//moja *= k;
			//cout << moja;

			//moja /= k;
			//cout << moja;

			break;
		}
		case 'c': {
			cout << "Wprowadz rozmiar macierzy:" << endl;
			cout << "Liczba wierszy: ";
			cin >> r;
			cout << "Liczba kolumn: ";
			cin >> c;

			matrix moja(r, c);
			moja.input();
			cout << "Macierz nr. 1: " << endl;
			cout << moja;

			cout << endl;
			cout << "Liczba wierszy drugiej macierzy: ";
			cin >> r;
			cout << "Liczba kolumn drugiej macierzy: ";
			cin >> c;

			matrix twoja(r, c);
			twoja.input();
			cout << "Macierz nr. 2: " << endl;
			cout << twoja;

			char h;
			cout << "Wprowadz typ obliczenia(+,-,*): ";
			cin >> h;

			switch (h) {
			case'+': {
				cout << "Suma: " << endl;
				matrix suma = moja + twoja;
				cout << suma;
				break;
			}
			case'-': {
				cout << "Roznica: " << endl;
				matrix ro = moja - twoja;
				cout << ro;
				break;
			}
			case'*': {
				cout << "Iloczyn: " << endl;
				matrix il = moja * twoja;
				cout << il;
				break;
			}
			default: {
				cout << "Podaj poprawny typ!" << endl;
			}
			}

			/*
				cout << "Suma: " << endl;
				matrix suma = moja + twoja;
				cout << suma;
			
				cout << "Iloczyn: " << endl;
				matrix il = moja * twoja;
				cout << il;

				cout << "Roznica: " << endl;
				matrix ro = moja - twoja;
				cout << ro;
			*/
	
			break;
		}
		default: {
			cout << "Niepoprawna operacja." << endl;
		}
		}

		cout << endl;

		break;
	}
	case 9: {
		
		break;
	}
	default: {
		cout << "Podaj poprawny numer zadania!" << endl;
		break;
	}

	}

	return 0;
}