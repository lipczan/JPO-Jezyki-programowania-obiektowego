#include <iostream>
#include <string>
#include<stdio.h> 
#include<stdlib.h> 

#include "header_6.h"
#include "header_7.h"
#include "header_9.h"

using namespace std;


int main() {
	/*
	Tree<double> bst;

	int number_to_add = iToCheck();

	for (int i = 0; i < number_to_add; i++) {
		double tmp_number = valueToCheck();
		bst.insert(tmp_number);
	}

	int number_to_remove = iToCheck();

	for (int i = 0; i < number_to_remove; i++) {

		//double tmp_remove=valueToCheck();
		double tmp_remove;
		cin >> tmp_remove;
		bst.remove(bst.root, tmp_remove);
	}

	int choice = i2ToCheck();

	switch (choice) {
	case 0:
	{
		bst.preorder(bst.root);
		break;
	}
	case 1:
	{
		bst.inorder(bst.root);
		break;
	}
	case 2:
	{
		bst.postorder(bst.root);
		break;
	}
	}
	*/
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