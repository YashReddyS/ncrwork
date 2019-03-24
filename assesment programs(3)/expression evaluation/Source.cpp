#include<iostream>
#include<stack>

#define EXPRESSION_LENGTH 50

using namespace std;

//for functions defined in other files(multifile program implmentation)
float multiply(float, float);
float divide(float, float);
float add(float, float);
float subtract(float, float);

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

//checks if paranthesis in the expression are balanced.
//()(()()) is balanced while ()())) is unbalanced.
int are_paranthesis_balanced(char *expression) {

	int itr;
	stack_char char_stack_object;

	//push into stack corresponding bracket eg ')' is pushed if '(' is encountered 
	for (itr = 0; itr < strlen(expression); itr++) {
		if (expression[itr] == '}' || expression[itr] == ')' || 
			expression[itr] == ']' || expression[itr] == '{' || 
			expression[itr] == '(' || expression[itr] == '[') {

			switch (expression[itr]) {
			case '{':char_stack_object.push('}');  continue;
			case '(':char_stack_object.push(')');  continue;
			case '[':char_stack_object.push(']');  continue;
			}

			// check if top of stack is bracket encountered
			if (char_stack_object.isEmpty())
				break;
			if (expression[itr] == char_stack_object.peek()) {
				char_stack_object.pop();
			}
			else
				break;
		}
	}
	if (char_stack_object.isEmpty() && itr == (strlen(expression)))
		return 1;
	else
		return 0;
}

//if exression contains only numbers,operands and brackets
int are_valid_chars(char *expression) {
	for (int i = 0; i < strlen(expression); i++) {
		if ( (expression[i] >= '0' && expression[i] <= '9') ||
			expression[i] == '+' || expression[i] == '-' ||
			expression[i] == '*' || expression[i] == '/' ||
			expression[i] == '(' || expression[i] == ')' || expression[i] == ' ')

			continue;
		else
			return 0;
	}
		
	return 1;
}

//if operators are surrounded by operands or coresponding brackets(skip spaces if encountered)
int has_valid_operator_order(char *expression) {
	
	int left, right;
	for (int i = 0; i < strlen(expression); i++) {
		if (expression[i] == '+' || expression[i] == '-' || expression[i] == '/' || expression[i] == '*') {
			left = i - 1;
			right = i + 1;

			//ignore spaces
			while (expression[left] == ' ')
				left--;
			while (expression[right] == ' ')
				right++;


			if (expression[left] == ')' || (expression[left] >= '0' && expression[left] <= '9'))
				continue;
			else
				return 0;

			if (expression[right] == '(' || (expression[right] >= '0' && expression[right] <= '9'))
				continue;
			else
				return 0;
		}
	}

	return 1;
}

//if above conditions are met
int is_valid_expression(char *expression) {
	if (are_paranthesis_balanced(expression) && 
		are_valid_chars(expression) && 
		has_valid_operator_order(expression)) {

			return 1;
	}
	return 0;
}

//arithematic operation
float operation(float operand1, float operand2, char operator1) {

	switch (operator1) {

	case '*':return multiply(operand1, operand2);
	case '/':return divide(operand1, operand2);
	case '+':return add(operand1, operand2);
	case '-':return subtract(operand1, operand2);

	}

}

int getPrecedence(char Char) {

	switch (Char) {

	case '(': return 0;
	case ')': return 0;
	case '+': return 1;
	case '-': return 1;
	case '/': return 2;
	case '*': return 2;

	}

}

char* infixToPostfix(char *Expression) {

	stack_char stack_object;
	char *postfixExpression = new char[50];
	int postfixIterator = 0;

	for (int iterator = 0; iterator < strlen(Expression); iterator++) {

		//ignore spaces
		if (Expression[iterator] == ' ')
			continue;

		//append to postfix if char is a number
		else if (Expression[iterator] >= '0' && Expression[iterator] <= '9')
			postfixExpression[postfixIterator++] = Expression[iterator];

		//push to stack for '('
		else if (Expression[iterator] == '(')
			stack_object.push(Expression[iterator]);

		//if char precedence on top of stack is less than char precedence then push to stack else
		else if (getPrecedence(stack_object.peek()) < getPrecedence(Expression[iterator])) {

			if(postfixExpression[postfixIterator-1] >= '0' &&  postfixExpression[postfixIterator-1] <= '9')
			postfixExpression[postfixIterator++] = '@';

			stack_object.push(Expression[iterator]);
		}

		//pop and append to postfix until above condition is met and then push char to the stack
		else {

			if (postfixExpression[postfixIterator - 1] >= '0' &&  postfixExpression[postfixIterator - 1] <= '9')
			postfixExpression[postfixIterator++] = '@';

			while (getPrecedence(Expression[iterator]) <= getPrecedence(stack_object.peek())) {
				if (stack_object.peek() != '(' && stack_object.peek() != ')') {
					postfixExpression[postfixIterator++] = stack_object.pop();
				}
				else {
					stack_object.pop();
				}
				if (stack_object.isEmpty())
					break;
			}

			stack_object.push(Expression[iterator]);
		}
	}

	if (postfixExpression[postfixIterator - 1] >= '0' &&  postfixExpression[postfixIterator - 1] <= '9')
	postfixExpression[postfixIterator++] = '@';
	while (!stack_object.isEmpty())
		if (stack_object.peek() != '(' && stack_object.peek() != ')')
			postfixExpression[postfixIterator++] = stack_object.pop();
		else
			stack_object.pop();

	postfixExpression[postfixIterator] = '\0';

	return postfixExpression;
}

float evaluatePostfix(char *expression) {

	stack <float> s;
	float operator_1, operator_2,sum,base;
	for (int i = 0; i < strlen(expression); i++) {
		if (expression[i] >= 42 && expression[i] <= 47) { //in operator range
			operator_1 = s.top();
			s.pop();
			operator_2 = s.top();
			s.pop();
			s.push(operation(operator_2, operator_1, expression[i]));
		}
		else {
			sum = 0, base = 1;
			while (expression[i] != '@') {
				sum = sum * base + (expression[i] - 48);
				base = base * 10;
				i++;
			}
			s.push(sum);
		}
	}
	
	return s.top();
}


int main() {

	char expression[EXPRESSION_LENGTH];

	while (1) {
		cout << "Enter expression to be evaluated:";
		cin >> expression;
		
		if (is_valid_expression(expression)) {
			//cout << infixToPostfix(expression) << endl;
			cout << "The value of expression " << expression << " is equal to " << evaluatePostfix(infixToPostfix(expression)) << endl;
		}
		else
			cout << "Enter a valid expression" << endl;
		getchar();
		cout << "Press 'E' to exit,other key to continue:";
		if ('e' == getchar()) 
			exit(0);
		
		system("cls");
	}
	return 0;
}

