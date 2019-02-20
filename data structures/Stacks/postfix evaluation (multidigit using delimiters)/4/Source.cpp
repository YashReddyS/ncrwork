#include<iostream>

using namespace std;

struct stac {

	int top;
	int *a;
	int size;

};

class stack {

	struct stac s;

public:
	stack(int);
	int isEmpty();
	int isFull();
	int peek();
	void push(int);
	int pop();
	void display();

};

stack::stack(int n) {

	s.a = new int[n];
	s.size = n;
	s.top = -1;

}

int stack::isEmpty() {

	return(s.top == -1);

}

int stack::isFull() {

	return s.top == s.size - 1;

}

int stack::peek() {

	return s.a[s.top];

}

void stack::push(int n) {

	if (!isFull())
		s.a[++s.top] = n;
	else
		cout << "overflow" << endl;

}

int stack::pop() {

	if (!isEmpty())
		return s.a[s.top--];
	else {
		cout << "underflow" << endl;
		return -999;
	}
}

void stack::display() {

	for (int i = 0; i <= s.top; i++)
		cout << s.a[i] << " ";
	cout << endl;
}

int getVal(int a, int b, char c) {

	switch (c) {

	case '*':return (a*b);
	case '/':return (a / b);
	case '+':return (a + b);
	case '-':return (a - b);

	}

}

int main() {

	char c[20] = "12@3@/2@2@*-";
	stack s(10);
	int c1 , c2 ,b;
	for (int i = 0; i < strlen(c); i++) {

		s.display();
		if (c[i] >= 42 && c[i] <= 47)
			s.push(getVal(s.pop(), s.pop(), c[i]));
		else {
			c1 = 0, b = 1;
			while (c[i] != '@') {
				c1 = c1 * b + (c[i] - 48);
				b = b * 10;
				i++;
			}
			s.push(c1);
		}
		

	}

	cout << s.pop();

	getchar();
	getchar();
	return 0;
}