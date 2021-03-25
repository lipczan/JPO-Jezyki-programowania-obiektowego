#include <iostream> 
#include <cctype>

#include "header_1.h"
#include "header_7.h"
#include "header_8.h"
using namespace std;

// Returns true if n is perfect 


// Driver program 
int main()
{
	int nr;
	cout << "Wprowadz numer zadania: ";
	cin >> nr;
	switch (nr) {
	case 5: {
		ShapeContainer *container = new ShapeContainer();
		Kwadrat *k_1=new Kwadrat ("kwadrat_1",5);
		Prostokat *p_1 = new Prostokat("prostokat_1", 5,4);
		Kolo *ko_1 = new Kolo("kolo_1", 5);
		Elipsa *e_1 = new Elipsa("elipsa_1", 5, 4);

		container->addShape(k_1);
		container->addShape(p_1);
		container->addShape(ko_1);
		container->addShape(e_1);

		container->displayAll();

		break;
	}
	case 6: {

		break;
	}
	case 7: {
		//zakres
		long long int m = 6;
		long long int n = 10000;
		cout << "Liczby doskonale w podanych zakresie to: \n";
		Liczby_doskonale perfect(m, n);

		Doskonala *ldosk = &perfect;
		ldosk->Dowod(m, n);

		break;
	}
	case 8: {
		//zakres
		long long int m = 6;
		long long int n = 10000;
		cout << "Liczby doskonale w podanych zakresie to: \n";
		Liczby_doskonalev2 perfect(m, n);

		Doskonalav2 *ldosk = &perfect;
		ldosk->Dowod(m, n);

		break;
	}

	default :{
		cout << "Wprowadz poprawny numer zadania!";
		break;
	}
	}
	return 0;
}

