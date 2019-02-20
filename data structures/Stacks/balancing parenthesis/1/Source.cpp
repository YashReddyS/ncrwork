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




int main() {

	stack s(10);
	/*

	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);

	s.display();

	s.pop();
	s.pop();


	s.display();

	cout << s.peek() << endl;

	s.display();*/

	char a[20] = "()({({({})})})";
	
	int i;
	for ( i = 0; i < strlen(a); i++) {
	
		switch (a[i]) {
		
		case '{':s.push('}'); s.display(); continue;
		case '(':s.push(')'); s.display(); continue;
		case '[':s.push(']'); s.display(); continue;
		
			
		}

		if (a[i] == s.peek()) {
			if (s.isEmpty())
				break;
			s.pop();
		}
		else
			break;

		s.display();
	
	}

	if (s.isEmpty() && i == (strlen(a)))
		cout << "balanced";
	else
		cout << "unbalanced";

	getchar();
	getchar();
}