#include<iostream>

using namespace std;

struct node {

	int data;
	struct node *next;

};

class linkedList {

	struct node *start;


public:
	linkedList() {
		start = NULL;
	}

	~linkedList() {
		struct node *temp;
		while (start != NULL) {
			temp = start;
			start = start->next;
			delete(temp);
		}
	}

	void insertFirst(int);
	void insertLast(int);
	void insertAfter(int, int);
	void insertBefore(int, int);

	int deleteFirst();
	int deleteLast();
	void deleteSpec(int);

	void travelForward();
	void travelBackward();

	void reverse();









};

void linkedList::insertFirst(int e) {
	struct node *temp;
	temp = new node;
	temp->data = e;
	temp->next = start;
	start = temp;
}

void linkedList::insertLast(int e) {
	struct node *cur = start;
	struct node *temp;
	temp = new node;
	temp->data = e;
	temp->next = NULL;
	if (start == NULL) {
		start = temp;
	}
	else {
		while (cur->next != NULL) {
			cur = cur->next;
		}
		cur->next = temp;
	}
}

void linkedList::insertAfter(int s, int e) {

	if (start != NULL) {
		struct node *cur = start;
		while (cur != NULL && cur->data != s)
			cur = cur->next;
		if (cur != NULL) {
			struct node *temp;
			temp = new node;
			temp->data = e;
			temp->next = cur->next;
			cur->next = temp;
		}
		else
			cout << "element not found";
	}
	else
		cout << "list is empty";
}

void linkedList::insertBefore(int s, int e) {

	if (start != NULL) {
		if (start->data == e) {
			struct node *temp;
			temp = new node;
			temp->data = e;
			temp->next = start;
			start = temp;
		}
		else {
			struct node *cur = start;
			while (cur->next != NULL && cur->next->data != s)
				cur = cur->next;
			if (cur->next != NULL) {
				struct node *temp;
				temp = new node;
				temp->data = e;
				temp->next = cur->next;
				cur->next = temp;
			}
			else
				cout << "element not found";
		}
	}
	else
		cout << "list is empty";
}

int linkedList::deleteFirst() {
	int x = -999;
	if (start != NULL) {
		x = start->data;
		struct node *temp = start;
		start = start->next;
		delete(temp);
	}
	else
		cout << "list is empty";
	return x;
}


int linkedList::deleteLast() {

	int x = -999;

	if (start != NULL) {
		if (start->next != NULL) {
			struct node *cur = start;
			while (cur->next->next != NULL) {
				cur = cur->next;
			}
			x = cur->next->data;
			delete(cur->next);
			cur->next = NULL;
		}
		else {
			x = start->data;
			delete(start);
			start = NULL;
		}
	}
	else
		cout << "list is empty";

	return x;
}

void linkedList::deleteSpec(int s) {
	if (start != NULL) {
		if (start->data == s) {
			struct node *temp = start;
			start = start->next;
			delete(temp);
		}
		else {
			struct node *temp, *cur = start;
			while (cur->next != NULL && cur->next->data != s)
				cur = cur->next;
			if (cur->next != NULL) {
				temp = cur->next;
				cur->next = cur->next->next;
				delete(temp);
			}
			else
				cout << "element not found";
		}
	}
	else
		cout << "list is empty";
}


void linkedList::travelForward() {
	struct node *cur = start;
	while (cur != NULL) {
		cout << cur->data << " -> ";
		cur = cur->next;
	}
}

void linkedList::travelBackward() {
	static struct node *cur = start;
	int d;
	if (cur == NULL)
		return;
	d = cur->data;
	cur = cur->next;
	linkedList::travelBackward();
	cout << d << " -> ";
}




int main() {



	linkedList l1;
	l1.insertFirst(1);
	l1.insertFirst(2);
	l1.insertFirst(3);
	l1.insertFirst(4);
	l1.insertLast(5);
	l1.insertLast(6);
	l1.insertLast(7);
	l1.insertLast(8);
	l1.insertAfter(1, 10);
	l1.insertBefore(10, 20);
	l1.travelForward();
	cout << endl;
	l1.deleteFirst();
	l1.travelForward();
	cout << endl;
	l1.deleteLast();
	l1.travelForward();
	cout << endl;
	l1.deleteSpec(20);
	l1.deleteSpec(10);
	l1.travelForward();







	cout << endl;
	getchar();
	return 0;
}