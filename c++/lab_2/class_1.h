#include <iostream>
#include <iomanip> 
using namespace std;

class TimeSpan {
	private:
	unsigned int hours_;
	unsigned int minutes_;
	unsigned int seconds_;

	public:
	TimeSpan( unsigned int seconds ) {
		hours_ = seconds/3600;
		minutes_ = (seconds - hours_ * 3600) / 60;
		seconds_ = seconds - hours_ * 3600 - minutes_ * 60;

	}

	void print() {
		cout << "Wprowadzona liczba sekund to: " << endl;
		cout << setfill( '0') <<setw(2)<< hours_ << ":"
			<< setfill( '0' ) << setw( 2 ) << minutes_ << ":"
			<< setfill( '0' ) << setw( 2 ) << seconds_;
	}

	int getHours() const{
		return hours_;
	}

	int getMinutes() const {
		return minutes_;
	}

	int getSeconds() const {
		return seconds_;
	}
};

