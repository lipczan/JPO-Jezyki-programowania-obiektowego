#include <iostream>
#include <cmath>

using namespace std;

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
	cout << "Rozwiniêcie: ";
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

