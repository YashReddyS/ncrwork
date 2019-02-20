#include<iostream>

using namespace std;

struct stac {

	int top;
	char *a;
	int size;

};

class stack {

	struct stac s;

public:
	stack(int);
	int isEmpty();
	int isFull();
	char peek();
	void push(char);
	char pop();
	void display();

};

stack::stack(int n) {

	s.a = new char[n];
	s.size = n;
	s.top = -1;

}

int stack::isEmpty() {

	return(s.top == -1);

}

int stack::isFull() {

	return s.top == s.size - 1;

}

char stack::peek() {

	return s.a[s.top];

}

void stack::push(char n) {

	if (!isFull())
		s.a[++s.top] = n;
	else
		cout << "overflow" << endl;

}

char stack::pop() {

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

int getPrecedence(char a) {

	switch (a) {

	case '(': return 0;
	case ')': return 0;
	case '+': return 1;
	case '-': return 1;
	case '/': return 2;
	case '*': return 2;

	}

}

int main() {

	stack s(20);
	char c[30] = "a+(b/c-(d*f))+g-h";



	for (int i = 0; i < strlen(c); i++) {


		if (c[i] >= 97 && c[i] <= 122)
			cout << c[i];
		else if (c[i] == '(')
			s.push(c[i]);
		else if(getPrecedence(s.peek()) < getPrecedence(c[i]))
			s.push(c[i]);
		else {
			while (getPrecedence(c[i]) <= getPrecedence(s.peek())) {
				if (s.peek() != '(' && s.peek() != ')') {
					cout << s.pop();
					if (s.isEmpty())
						break;
				}
				else {
					s.pop();
					if (s.isEmpty())
						break;
				}

			}
			s.push(c[i]);
		}
	}

	while(!s.isEmpty())
		if(s.peek() != '(' && s.peek() != ')')
		cout << s.pop();


	getchar();
	getchar();
	return 0;
}


