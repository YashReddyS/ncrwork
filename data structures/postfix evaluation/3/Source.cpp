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

char getVal(int b, int a, char c) {

	switch(c){
	
	case '*':return (a*b) + 48;
	case '/':return (a/b) + 48;
	case '+':return (a+b) + 48;
	case '-':return (a-b) + 48;
	
	}

}

int main() {

	char c[20] = "122/21*-+1+1-";
	stack s(10);
	for (int i = 0; i < strlen(c); i++) {
	
		s.display();
		if (c[i] >= 48 && c[i] <= 57) {
			s.push(c[i]);	
		}
		else {
		
			
			s.push(getVal(s.pop()-48,s.pop()- 48,c[i]));
		
		}	
	}

	cout << s.pop();

	getchar();
	getchar();
	return 0;
}