#include<iostream>

using namespace std;

class Time {

	int hours;
	int minutes;
	int seconds;

public:

	Time() {
		hours = 0;
		minutes = 0;
		seconds = 0;
	}

	Time(int h, int m, int s) {
		hours = h;
		minutes = m;
		seconds = s;
	}

	void display() {
		cout << hours << ":" << minutes << ":" << seconds<< endl;
	}

	void add(Time a, Time b) {
		
		seconds = (a.seconds + b.seconds)%60;
		minutes = (a.minutes + b.minutes + (a.seconds + b.seconds)/60)%60;
		hours = a.hours + b.hours + (a.minutes + b.minutes + (a.seconds + b.seconds) / 60)/60;
	}

};

int main() {

	Time t1(11, 43, 34);
	t1.display();
	Time t2(11, 44, 33);
	t2.display();

	Time t;
	t.add(t1, t2);
	t.display();
	getchar();

	return 0;
}

