#include <iostream>
#include <iomanip> 
#include <string> 
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

class TimeSpan {
private:
	unsigned int hours_;
	unsigned int minutes_;
	unsigned int seconds_;

public:
	TimeSpan(unsigned int seconds) {
		hours_ = seconds / 3600;
		minutes_ = (seconds - hours_ * 3600) / 60;
		seconds_ = seconds - hours_ * 3600 - minutes_ * 60;

	}

	void print() {
		cout << "Wprowadzona liczba sekund to: " << endl;
		cout << setfill('0') << setw(2) << hours_ << ":"
			<< setfill('0') << setw(2) << minutes_ << ":"
			<< setfill('0') << setw(2) << seconds_;
	}

	int getHours() const {
		return hours_;
	}

	int getMinutes() const {
		return minutes_;
	}

	int getSeconds() const {
		return seconds_;
	}
};

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

template <class T> class Node;
template <class T> class Tree;

template <class T> class Node {
public:
	T value;
	Node(T value_, Node<T>* leftPtr_ = nullptr, Node<T>* rightPtr_ = nullptr);

protected:
	Node <T>* rightPtr;
	Node <T>* leftPtr;
	friend class Tree <T>;
};

template<class T>
Node<T>::Node(T value_, Node<T>* leftPtr_, Node<T>* rightPtr_) {
	value = value_;
	leftPtr = leftPtr_;
	rightPtr = rightPtr_;
}

template <class T>
class Tree {
public:
	Tree(Node<T>* root = nullptr);
	void insert(T val);
	void inorder(Node <T>* ptr);
	void examine(Node <T>* ptr);

	//korzen
	Node <T>* root;

	void DeleteTree(Node <T>* tmp);

	bool isEmpty();

	bool contains(Node<T>* ptr, T val);
};

template<class T>
Tree<T>::Tree(Node<T>* root) :root(root) {}

template<class T>
void Tree<T>::examine(Node<T>* ptr) {
	cout << ptr->value << " ";
}

template <class T>
void Tree <T> ::inorder(Node <T>* ptr) {
	if (ptr) {
		inorder(ptr->leftPtr); examine(ptr);
		inorder(ptr->rightPtr);
	}
}

//WSTAWIANIE DO DRZEWA
template <class T>
void Tree <T> ::insert(T val) {
	if (root) {
		Node <T>* current = root, *child;
		while (current) {
			if (current->value > val) {
				child = current->leftPtr;
				if (not child) {
					current->leftPtr = new Node<T>(val);
					return;
				}
			}
			else {
				child = current->rightPtr;
				if (not child) {
					current->rightPtr = new Node<T>(val);
					return;
				}
			}
			current = child;
		}
	}
	else root = new Node <T>(val);
}

template <class T>
void Tree <T>::DeleteTree(Node <T>* tmp) {
	if (tmp != nullptr) {
		if (tmp->leftPtr != nullptr) {
			DeleteTree(tmp->leftPtr);
		}

		if (tmp->rightPtr != nullptr) {
			DeleteTree(tmp->rightPtr);
		}

		delete tmp;
		root = nullptr;
	}
}

template <class T>
bool Tree<T>::isEmpty() {
	if (root == nullptr) {
		return true;
	}
	else {
		return false;
	}
}
template <class T>
bool Tree <T>::contains(Node<T>* ptr, T val) {
	if (ptr == nullptr) return false;
	else if (ptr->value == val) return true;
	else if (val <= ptr->value) contains(ptr->leftPtr, val);
	else contains(ptr->rightPtr, val);
}


struct Element {
	char cyfra;
	int reszta;
	Element* nast;
} *poc = NULL, *okr;

bool ulamek_okresowy(int x) {
	for (okr = poc; okr != NULL && okr->reszta != x; okr = okr->nast)
		;
	return okr != NULL;
}

void rozwin_ulamek(int x, int y) {
	Element* p, *kon = NULL;
	for (; x != 0 && !ulamek_okresowy(x); x %= y) {
		(p = new Element)->reszta = x;
		p->cyfra = (x *= 10) / y;
		if (kon != NULL)
			kon->nast = p;
		else
			poc = p;
		(kon = p)->nast = NULL;
	}
}

void drukuj_ulamek(int x, int y) {
	cout << "Rozwini�cie: ";
	if (x * y < 0) cout << "-";
	cout << abs(x / y);
	if (poc == NULL) return;
	cout << ".";
	for (Element* p = poc; p != NULL; p = p->nast) {
		if (p == okr) cout << "(";
		cout << int(p->cyfra);
	}
	if (okr != NULL) cout << ")";
	cout << endl;
}

void usun_liste() {
	Element* p;
	while (poc != NULL) {
		poc = (p = poc)->nast;
		delete p;
	}
}

bool czytaj_dane(int& p, int& q) {
	cout << "Licznik: ";
	if (!(cin >> p)) return false;
	cin.ignore(1000, '\n');
	cout << "Mianownik: ";
	return ((cin >> q) && q != 0);
}

int main()
{
	cout << "Wprowadz numer zadania: ";
	int nr;
	cin >> nr;

	switch (nr) {
	case 1: {
		int sec;
		cout << "Podaj liczbe sekund: ";
		cin >> sec;
		TimeSpan ts(sec);
		ts.print();
		break;
	}
	case 2:
	{
		vector <Student> BazaStudentow;

		bool end = true;
		while (end) {
			cout << "Wybierz operacje: " << endl;
			cout << "a) dodaj nowego studenta" << endl;
			cout << "b) pokaz liste studentow" << endl;
			cout << "c) wyszukaj po nr indeksu studenta" << endl;
			cout << "d) usun wybranego studenta po nr indeksu" << endl;
			cout << "e) zapisz cala baze do pliku" << endl;
			cout << "f) odczyt calej bazy z pliku" << endl;
			cout << "g) czyszczenie calej bazy studentow" << endl;
			cout << "h) zakoncz" << endl;

			char choose;
			cout << "Wybor: ";
			cin >> choose;

			switch (choose) {
			case 'a': {
				int id;
				string name;
				string name_2;

				cout << "Podaj nr indeksu: ";
				cin >> id;
				cout << "Podaj imie: ";
				cin >> name;
				cout << "Podaj nazwisko: ";
				cin >> name_2;

				Student s(id, name, name_2);

				BazaStudentow.push_back(s);
				cout << "Dodano studenta!" << endl;
				cout << endl;

				break;
			}
			case 'b': {
				//BazaStudentow.print();

				for (int i = 0; i < BazaStudentow.size(); i++) {
					cout << BazaStudentow[i].getId()
						<< ", " << BazaStudentow[i].getName()
						<< ", " << BazaStudentow[i].getName_2() << endl;
				}
				cout << endl;

				break;
			}
			case 'c':
			{
				int id;
				cout << "Wprowadz nr indeksu: ";
				cin >> id;

				for (int i = 0; i < BazaStudentow.size(); i++) {
					if (id == BazaStudentow[i].getId()) {
						cout << "Odnaleziono studenta: ";
						cout << BazaStudentow[i].getId()
							<< ", " << BazaStudentow[i].getName()
							<< ", " << BazaStudentow[i].getName_2() << endl;
						cout << endl;
					}
					else {
						cout << "Nie znaleziono studenta!" << endl;
						cout << endl;
					}
				}

				break;
			}
			case 'd': {
				int id;
				cout << "Wprowadz nr indeksu studenta: ";
				cin >> id;

				for (int i = 0; i < BazaStudentow.size(); i++) {
					if (id == BazaStudentow[i].getId()) {
						BazaStudentow.erase(BazaStudentow.begin() + i);
						cout << "Usunieto studenta!" << endl;
						cout << endl;
					}
				}

				break;
			}
			case 'e': {
				fstream data;
				data.open("data.txt", ios::out);

				for (int i = 0; i < BazaStudentow.size(); i++) {
					data << BazaStudentow[i].getId()
						<< ", " << BazaStudentow[i].getName()
						<< ", " << BazaStudentow[i].getName_2() << endl;
				}
				data.close();
				cout << "Poprawnie wyeksportowano dane!" << endl;
				cout << endl;

				break;
			}

			case 'f': {
				fstream data;
				data.open("data.txt", ios::in);

				string line;
				int nr_line = 1;
				while (getline(data, line)) {
					cout << line << endl;
					nr_line++;
				}
				cout << endl;

				break;
			}
			case 'g': {
				BazaStudentow.clear();
				cout << "Wyczyszczono baze danych!" << endl;
				break;
			}
			case 'h': {
				end = false;
				break;
			}
			default: {
				cout << "Niepoprawny wybor!" << endl;
				end = false;
				break;
			}
			}
		}

		break;
	}
	case 3:
	{
		Tree<int> bst;

		cout << "Dodaje zawartosc drzewa..." << endl;
		bst.insert(5);
		bst.insert(3);
		bst.insert(7);
		bst.insert(4);
		bst.insert(2);
		bst.insert(1);
		bst.insert(8);

		bst.inorder(bst.root);
		cout << endl;

		//wartosc poszukiwana
		int to_look = 3;

		if (bst.contains(bst.root, 3)) cout << "Drzewo zawiera wartosc: " << to_look << endl;
		else cout << "Drzewo NIE zawiera wartosci: " << to_look << endl;

		cout << "Usuwam zawartosc drzewa..." << endl;
		bst.DeleteTree(bst.root);

		if (bst.isEmpty()) cout << "Drzewo jest puste" << endl;
		else cout << "Drzewo NIE jest puste" << endl;


		if (bst.contains(bst.root, to_look)) cout << "Drzewo zawiera wartosc: " << to_look << endl;
		else cout << "Drzewo NIE zawiera wartosci: " << to_look << endl;

		break;
	}
	case 4: {
		int x, y;
		cout << "Rozwiniecie dziesietne ulamka\n"
			"-----------------------------\n";
		if (!czytaj_dane(x, y)) {
			cout << "Problem z danymi.\n";
			return 1;
		}
		rozwin_ulamek(abs(x % y), abs(y));
		drukuj_ulamek(x, y);
		usun_liste();

		break;
	}
	default:
	{
		cout << "Wrong task number!" << endl;
		break;
	}
	}

	return 0;
}