#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>

#include "class_1.h"
#include "class_2.h"
#include "class_3.h"
#include "header_4.h"

using namespace std;



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
