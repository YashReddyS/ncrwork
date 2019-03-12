#include<iostream>

using namespace std;

struct node {
	int coeff;
	int pow;
	struct node *next;
};

class linkedList{

	struct node *start;

	public:
	linkedList() {
		start = NULL;
	}

	void insertLast(int c,int p) {
		struct node *cur = start;
		struct node *temp;
		temp = new node;
		temp->coeff = c;
		temp->pow = p;
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
			cout << cur->coeff<<"x"<<cur->pow <<" -> ";
			cur = cur->next;
		}
		cout << endl;
	}

	friend linkedList addPolynomials(linkedList,linkedList);
};

linkedList addPolynomials(linkedList p1, linkedList p2) {

	linkedList p3;
	struct node *ptr1 = p1.start;
	struct node *ptr2 = p2.start;
	struct node *ptr3;
	while (ptr1 != NULL && ptr2  != NULL) {
		if (ptr1->pow > ptr2->pow) {
			p3.insertLast(ptr1->coeff, ptr1->pow);
			ptr1 = ptr1->next;
		}
		else if (ptr1->pow < ptr2->pow) {
			p3.insertLast(ptr2->coeff, ptr2->pow);
			ptr2 = ptr2->next;
		}
		else {			
			p3.insertLast(ptr2->coeff + ptr1->coeff, ptr2->pow);
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}
	}

	
	while (ptr1 != NULL) {
		p3.insertLast(ptr1->coeff,ptr1->pow);		
		ptr1 = ptr1->next;
	}
	
	while (ptr2 != NULL) {
		p3.insertLast(ptr1->coeff, ptr1->pow);	
		ptr1 = ptr1->next;
	}
	
	return p3;
}

int main() {


	linkedList p1, p2,p3;

	p1.insertLast(5, 3);
	p1.insertLast(4, 1);
	p1.insertLast(-3, 0);

	p2.insertLast(4, 2);
	p2.insertLast(3, 1);
	p2.insertLast(-1, 0); 

	p1.travelForward();
	p2.travelForward();

	p3 = addPolynomials(p1, p2);
	p3.travelForward();
	
	
	




	getchar();
	return 0;
}