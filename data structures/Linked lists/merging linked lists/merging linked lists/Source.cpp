
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

	void insertLast(int d) {
		struct node *cur = start;
		struct node *temp;
		temp = new node;
		temp->data = d;
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

	void travelForward() {
		struct node *cur = start;
		while (cur != NULL) {
			cout << cur->data << " -> ";
			cur = cur->next;
		}
		cout << endl;
	}

	friend linkedList merge(linkedList, linkedList);
	friend void sort(linkedList &);
};

void sort(linkedList &l) {
		
	struct node *p1 = l.start;
	struct node *p2;

	for (;p1 != NULL; p1 = p1->next) {
		for (p2 = p1->next; p2 != NULL; p2 = p2->next) {
			if (p2->data < p1->data) {
				int t = p1->data;
				p1->data = p2->data;
				p2->data = t;
			}
		}
	}
}

linkedList merge(linkedList p1, linkedList p2) {

	linkedList p3;
	struct node *ptr1 = p1.start;
	struct node *ptr2 = p2.start;
	struct node *ptr3;
	while (ptr1 != NULL && ptr2 != NULL) {
		if (ptr1->data > ptr2->data) {
			p3.insertLast(ptr2->data);
			ptr2 = ptr2->next;
		}
		else if (ptr1->data < ptr2->data) {
			p3.insertLast(ptr1->data);
			ptr1 = ptr1->next;
		}
		else {
			p3.insertLast(ptr1->data);
			p3.insertLast(ptr2->data);
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}
	}


	while (ptr1 != NULL) {
		p3.insertLast(ptr1->data);
		ptr1 = ptr1->next;
	}

	while (ptr2 != NULL) {
		p3.insertLast(ptr2->data);
		ptr2 = ptr2->next;
	}

	return p3;
}

int main() {


	linkedList p1, p2, p3;

	int a[] = { 1,2,12,14,17,20,4,4,10,11,};
	int b[] = { 1,3,4,13,19,2,5,6,7,1,29 };

	for (int i = 0; i < 10; i++) {
		p1.insertLast(a[i]);
		p2.insertLast(b[i]);
	}
	
	p1.travelForward();
	p2.travelForward();

	sort(p1);
	sort(p2);

	p1.travelForward();
	p2.travelForward();

	p3 = merge(p1, p2);
	p3.travelForward();







	getchar();
	return 0;
}