#include<iostream>

using namespace std;

class point{

	float x;
	float y;

	point(float a, float b) {
		x = a;
		y = b;
	}

	friend void distance(point, point);
	friend int main();
};

int main() {

	point p1(0,0);
	point p2(2, 1);

	distance(p1, p2);

	getchar();
	return 0;
}

void distance(point a, point b) {

	cout << sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));

}