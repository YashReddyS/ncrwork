#include<iostream>
#include<stack>

using namespace std;

//for function defined in other files(multifile program implmentation)
extern float multiply(float, float);
extern float divide(float, float);
extern float add(float, float);
extern float subtract(float, float);

//node entity of the list
struct node {
	char data;
	struct node *next;
};

//stack_char implemented using linked list
class stack_char {

	struct node *top;

public:
	stack_char() {
		top = NULL;
	}

	~stack_char() {
		struct node *temp;
		while (top != NULL) {
			temp = top;
			top = top->next;
			delete(temp);
		}
	}


	// stack_char oerations
	void push(char);
	char pop();
	char peek();

	int isEmpty();

	void displayTopToBottom();
	void displayBottomToTop();

};

//stack_char operations...
void stack_char::push(char e) {
	struct node *temp;
	temp = new node;
	temp->data = e;
	temp->next = top;
	top = temp;
}
char stack_char::pop() {
	char x = NULL;
	if (top != NULL) {
		x = top->data;
		struct node *temp = top;
		top = top->next;
		delete(temp);
	}
	else
		cout << "list is empty";
	return x;
}
char stack_char::peek() {

	if (top != NULL)
		return top->data;
	else
		return  NULL;
}
int stack_char::isEmpty() {

	return(top == NULL);

}
void stack_char::displayTopToBottom() {
	struct node *cur = top;
	while (cur != NULL) {
		cout << cur->data << " -> ";
		cur = cur->next;
	}
}
void stack_char::displayBottomToTop() {
	static struct node *cur = top;
	int d;
	if (cur == NULL)
		return;
	d = cur->data;
	cur = cur->next;
	displayBottomToTop();
	cout << d << " -> ";
}



//expression evaluation methods
int are_paranthesis_balanced(char *a) {
	int i;
	stack_char s;
	for (i = 0; i < strlen(a); i++) {
		if (a[i] == '}' || a[i] == ')' || a[i] == ']' || a[i] == '{' || a[i] == '(' || a[i] == '[') {
			switch (a[i]) {
			case '{':s.push('}');  continue;
			case '(':s.push(')');  continue;
			case '[':s.push(']');  continue;
			}

			if (s.isEmpty())
				break;
			if (a[i] == s.peek()) {
				s.pop();
			}
			else
				break;
		}
	}
	if (s.isEmpty() && i == (strlen(a)))
		return 1;
	else
		return 0;
}

int are_valid_chars(char *a) {
	for (int i = 0; i < strlen(a); i++) {
		if ( (a[i] >= '0' && a[i] <= '9') || a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/' || a[i] == '(' || a[i] == ')' || a[i] == ' ')
			continue;
		else
			return 0;
	}
		
	return 1;
}

int has_valid_operator_order(char *a) {
	
	int left, right;
	for (int i = 0; i < strlen(a); i++) {
		if (a[i] == '+' || a[i] == '-' || a[i] == '/' || a[i] == '*') {
			left = i - 1;
			right = i + 1;
			while (a[left] != ' ')
				left--;
			while (a[right] != ' ')
				right--;
		}
		if (a[left] == ')' || (a[left] >= '0' && a[i=left] <= '9'))
			continue;
		else
			return 0;

		if (a[right] == '(' || (a[right] >= '0' && a[right] <= '9'))
			continue;
		else
			return 0;
	}

	return 1;
}

int is_valid_expression(char *a) {
	if (are_paranthesis_balanced(a) && are_valid_chars(a) && has_valid_operator_order(a)) {
			return 1;
	}
	return 0;
}

float operation(float operand1, float operand2, char operator1) {

	switch (operator1) {

	case '*':return multiply(operand1, operand2);
	case '/':return divide(operand1, operand2);
	case '+':return add(operand1, operand2);
	case '-':return subtract(operand1, operand2);

	}

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

char* infixToPostfix(char *Expression) {

	stack_char s;
	char *postfixExpression = new char[50];
	int postfixIterator = 0;

	for (int iterator = 0; iterator < strlen(Expression); iterator++) {

		if (Expression[iterator] == ' ')
			continue;

		else if (Expression[iterator] >= '0' && Expression[iterator] <= '9')
			postfixExpression[postfixIterator++] = Expression[iterator];

		else if (Expression[iterator] == '(')
			s.push(Expression[iterator]);

		else if (getPrecedence(s.peek()) < getPrecedence(Expression[iterator])) {

			if(postfixExpression[postfixIterator-1] >= '0' &&  postfixExpression[postfixIterator-1] <= '9')
			postfixExpression[postfixIterator++] = '@';

			s.push(Expression[iterator]);
		}
		else {

			if (postfixExpression[postfixIterator - 1] >= '0' &&  postfixExpression[postfixIterator - 1] <= '9')
			postfixExpression[postfixIterator++] = '@';

			while (getPrecedence(Expression[iterator]) <= getPrecedence(s.peek())) {
				if (s.peek() != '(' && s.peek() != ')') {
					postfixExpression[postfixIterator++] = s.pop();
				}
				else {
					s.pop();
				}
				if (s.isEmpty())
					break;
			}

			s.push(Expression[iterator]);
		}
	}

	if (postfixExpression[postfixIterator - 1] >= '0' &&  postfixExpression[postfixIterator - 1] <= '9')
	postfixExpression[postfixIterator++] = '@';
	while (!s.isEmpty())
		if (s.peek() != '(' && s.peek() != ')')
			postfixExpression[postfixIterator++] = s.pop();
		else
			s.pop();

	postfixExpression[postfixIterator] = '\0';

	return postfixExpression;
}

float evaluatePostfix(char *expression) {

	stack <float> s;
	float o1,o2,c,b;
	for (int i = 0; i < strlen(expression); i++) {
		if (expression[i] >= 42 && expression[i] <= 47) {
			o1 = s.top();
			s.pop();
			o2 = s.top();
			s.pop();
			s.push(operation(o2, o1, expression[i]));
		}
		else {
			c = 0, b = 1;
			while (expression[i] != '@') {
				c = c * b + (expression[i] - 48);
				b = b * 10;
				i++;
			}
			s.push(c);
		}
	}
	
	return s.top();
}



int main() {

	char expression[40];

	while (1) {
		cout << "Enter expression to be evaluated:";
		cin >> expression;
		
		if (is_valid_expression(expression)) {
			cout << infixToPostfix(expression) << endl;
			cout << "The value of expression " << expression << " is equal to " << evaluatePostfix(infixToPostfix(expression)) << endl;
		}
		else
			cout << "Enter a valid expression" << endl;
		getchar();
		cout << "Press 'Y' to continue,other to exit:";
		if ('y' == getchar()) {
			getchar();
			system("cls");
		}
		else
			exit(0);
	}
	return 0;
}

