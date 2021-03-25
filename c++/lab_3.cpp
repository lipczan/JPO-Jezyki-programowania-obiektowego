#include <iostream>
#include <string>
#include <time.h>
#include <windows.h>
#include <fstream>
#include <cassert>
#include <locale.h>
#include <cmath>

using namespace std;


class Shape
{
protected:
	string name_;
public:
	Shape(string name = "") :name_(name)
	{
		cout << "Konstruktor klasy Shape zosta� wywolany." << endl;
	}
	~Shape()
	{
		cout << "Destruktor klasy Shape zosta� wywolany" << endl;
	}
	void setName(string name)
	{
		name_ = name;
	}
	string getName()
	{
		return name_;
	}
	virtual double area() = 0;
};

class PROSTOKAT :public Shape
{
protected:
	double width_;
	double height_;
public:
	PROSTOKAT(string name = "", double width = 0, double height = 0) :Shape(name), width_(width), height_(height)
	{
		cout << "Konstruktor klasy Rectangle zosta� wywolany." << endl;
	}
	~PROSTOKAT()
	{
		cout << "Destruktor klasy Rectangle zosta� wywolany" << endl;
	}
	double area()
	{
		double area = width_ * height_;
		return area;
	}
};

class Square : public PROSTOKAT
{
public:
	Square(string name = "", double width = 0) :PROSTOKAT(name, width, width)
	{
		cout << "Konstruktor klasy Square zosta� wywolany." << endl;
	}
	~Square()
	{
		cout << "Destruktor klasy Square zosta� wywolany" << endl;
	}
	double area()
	{
		double area = width_ * width_;
		return area;
	}
};

class Function
{
public:
	Function() {}
	virtual float oblicz(float x) = 0;

};

class LineFunction :public Function
{
protected:
	double a, b;

public:
	LineFunction(float a, float b) :a(a), b(b) {}
	float oblicz(float x)
	{
		return (a*x + b);
	}
};

class Summary {
private:
	float x_, e_;

public:
	Summary(float x, float e) {
		e_ = e;
		x_ = x;
	}

	int factorial(int n)
	{
		return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
	}

	double sum(int x, int n)
	{
		double i, total = 1.0, multi = x;
		for (i = 1; i <= n; i++)
		{
			total = total + multi / factorial(i);
			multi = multi * x;
		}
		return total;
	}

	float result() {
		int n;
		float result;

		n = 1;
		while (true)
		{
			result = (sum(x_, n) - sum(x_, n - 1));
			if (result < e_) {
				break;
			}
			n++;
		}
		return sum(x_, n);
	}

	void printSum() {
		cout.precision(7);
		cout << result();
	}
};

class Teksty {
private:
	string pomoc_;
	fstream data_;

	int ile_razy(string line) {
		if (pomoc_.length() == 0) return 0;
		int count = 0;
		for (size_t offset = line.find(pomoc_); offset != string::npos;
			offset = line.find(pomoc_, offset + pomoc_.length())) {
			++count;
		}
		return count;
	}

public:
	Teksty(string pomoc, string path) {
		pomoc_ = pomoc;
		data_.open(path, ios::in);
	}

	void zestawienie(int arr[], int counter_line) {
		int tmp_2 = 0;
		for (int i = 0; i < counter_line; i++) {
			tmp_2 = tmp_2 + arr[i];
			//cout << tmp_2;
		}
		cout << tmp_2;
	}

	void najlepszy(int arr[]) {
		/*
			//pointer przesuniety na koniec pliku, NIE MOZNA wrocic do poczatku mimo deklaracji nowej zmiennej
			data_.clear();
			string line_2;
			int i = 0;
			while (getline( data_, line_2 )) {
				cout << "Wers " << ++i << ". ";
				cout << ile_razy( line_2 ) << endl;
			}
		*/
		int max = 0;
		for (int i = 0; i < 50; i++) {
			if (max < arr[i])
				max = arr[i];
		}
		cout << max;


	}
	void czytaj() {
		const int size = 50;
		int arr[size];

		string line, line_2;
		int i = 0;
		int tmp = 0;
		int counter_line = 0;

		while (getline(data_, line)) {
			tmp = ile_razy(line);
			arr[i] = tmp;
			counter_line++;
			cout << "Wers " << ++i << ". ";
			cout << tmp << endl;
		}

		cout << "Najlepszy ciag(o najwiekszej liczbie wystapien wzorca) to: ";
		najlepszy(arr);
		cout << endl << "Suma wystapien wszystkich wzorcow w pliku: ";
		zestawienie(arr, counter_line);
		cout << endl;
	}

};

/*
int countSubstring( const string& str, const string& sub ) {
	if (sub.length() == 0) return 0;
	int count = 0;
	for (size_t offset = str.find( sub ); offset != string::npos;
		  offset = str.find( sub, offset + sub.length() )) {
		++count;
	}
	return count;
}
*/

class PomiarCzasu {
private:
	clock_t start, stop;
	double czas;

public:
	void Start() {
		start = GetTickCount();
	}
	void Stop() {
		stop = GetTickCount();
	}
	void PodajCzasPocz() {
		cout << start;
	}
	void PodajCzasKon() {
		cout << stop;
	}
	double IleCzasu() {
		return	(double)(stop - start) / CLOCKS_PER_SEC;
	}
	void PodajIleCzasu() {
		cout << IleCzasu() << " s" << endl;
	}

	double getStart() {
		return start / CLOCKS_PER_SEC;
	}

};

void sortowanie_babelkowe(int* tab, int n) {
	for (int i = 1; i < n; i++) {
		for (int j = n - 1; j >= 1; j--) {
			if (tab[j] < tab[j - 1]) {
				int bufor;
				bufor = tab[j - 1];
				tab[j - 1] = tab[j];
				tab[j] = bufor;
			}
		}
	}
}

void quicksort(int* tablica, int lewy, int prawy) {
	int v = tablica[(lewy + prawy) / 2];
	int i, j, x;
	i = lewy;
	j = prawy;
	do {
		while (tablica[i] < v) i++;
		while (tablica[j] > v) j--;
		if (i <= j) {
			x = tablica[i];
			tablica[i] = tablica[j];
			tablica[j] = x;
			i++;
			j--;
		}
	} while (i <= j);
	if (j > lewy) quicksort(tablica, lewy, j);
	if (i < prawy) quicksort(tablica, i, prawy);
}

void heapify(int arr[], int n, int i) {
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && arr[l] > arr[largest])
		largest = l;

	if (r < n && arr[r] > arr[largest])
		largest = r;

	if (largest != i) {
		swap(arr[i], arr[largest]);

		heapify(arr, n, largest);
	}
}

void heapSort(int arr[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	for (int i = n - 1; i >= 0; i--) {
		swap(arr[0], arr[i]);

		heapify(arr, i, 0);
	}
}

class rim;
class tire;
class wheel;

class rim {
private:
	float rim_weight_;
	float rim_width_;
	float rim_diameter_;
public:
	rim();
	rim(float rim_weight, float rim_width, float rim_diameter) {
		rim_weight_ = rim_weight;
		rim_width_ = rim_width;
		rim_diameter_ = rim_diameter;
	}

};

class tire {
private:
	float tire_weight_;
	float tire_diameter_;
	float tire_set_;		//inch
public:
	tire();
	tire(float tire_weight, float tire_diameter, float tire_set) {
		tire_weight_ = tire_weight;
		tire_diameter_ = tire_diameter;
		tire_set_ = tire_set;
	}
};

class wheel :public rim, tire {
private:
	float wheel_weight_;	//rim+tire
	rim *rim;
	tire *tire;

public:
	wheel(float wheel_weight) {
		//,const rim & r, const tire & t
		wheel_weight_ = wheel_weight;
		//*rim = new rim(x,y,z);
		//*tire = new tire(x, y, z);
	}

	void mount_rim() {

	}
	void mount_tire() {

	}
};


int main()
{
	setlocale(LC_CTYPE, "Polish");
	cout << "Wprowadz numer zadania: " << endl;
	int zad;
	cin >> zad;

	switch (zad) {
	case 1: {
		PROSTOKAT rectangle2("rect", 5, 5);
		Square square2("kwadrat", 10);
		PROSTOKAT &rectangle2_2 = square2;
		PROSTOKAT* rectangle2_3 = &square2;

		cout << "Pole: " << rectangle2_2.area() << endl;
		cout << "Pole: " << rectangle2_3->area() << endl;
		break;
	}
	case 3: {

		float a, b, x;
		cout << "Podaj wspolczynnik a: " << endl;
		cin >> a;
		cout << "Podaj wspolczynnik b: " << endl;
		cin >> b;
		cout << "Podaj punkt x: " << endl;
		cin >> x;
		LineFunction y(a, b);
		cout << "Wartosc funkcji " << a << "x+" << b << " w punkcie " << x << " wynosi: " << y.oblicz(x);
		cout << endl;

		break;
	}
	case 5: {
		float x;
		float e;
		x = 2;
		e = 0.01;
		Summary arr(x, e);
		arr.printSum();

		break;
	}
	case 6: {
		/*
			string wzorzec;

			cin >> wzorzec;

			//cout << countSubstring( napis, wzorzec );

			fstream data;
			data.open( "data.txt", ios::in );

			string line;
			while (getline( data, line )) {
				cout << countSubstring( line, wzorzec ) << endl;
			}
			cout << endl;
		*/
		Teksty text("nan", "data.txt");
		text.czytaj();
		break;
	}
	case 7: {
		int ile;
		cout << "Porownanie czasow sortowania v.2" << endl;

		cout << "Ile losowych liczb w tablicy: ";
		cin >> ile;

		//dynamiczna alokacja tablicy
		int* tablica;
		tablica = new int[ile];

		//inicjowanie generatora
		srand(time(NULL));

		//wczytywanie losowych liczb do tablicy
		for (int i = 0; i < ile; i++) {
			tablica[i] = rand() % 100000 + 1;
		}

		cout << "Sortuje teraz babelkowo. Prosze czekac!" << endl;
		PomiarCzasu t1;
		t1.Start();
		sortowanie_babelkowe(tablica, ile);
		t1.Stop();
		cout << endl << "Czas sortowania babelkowego: ";
		t1.PodajIleCzasu();


		cout << endl << "Sortuje teraz algorytmem quicksort. Prosze czekac!" << endl;
		PomiarCzasu t2;
		t2.Start();
		quicksort(tablica, 0, ile - 1);
		t2.Stop();
		cout << endl << "Czas sortowania quicksort: ";
		t2.PodajIleCzasu();

		cout << endl << "Sortuje teraz algorytmem heapsort. Prosze czekac!" << endl;

		int n = sizeof(tablica) / sizeof(tablica[0]);
		PomiarCzasu t3;
		t3.Start();
		heapSort(tablica, n);
		t3.Stop();
		cout << endl << "Czas sortowania heapsort: ";
		t3.PodajIleCzasu();

		delete[] tablica;

		break;
	}
	case 8: {
		//wheel w(56);

		break;
	}
	default: {
		cout << "Podaj poprawny numer zadania!" << endl;
		break;
	}
	}
	return 0;
}
