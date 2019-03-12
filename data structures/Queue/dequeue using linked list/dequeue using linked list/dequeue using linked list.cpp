#include<iostream>

using namespace std;

struct node
{
	int data;
	struct node *prev;
	struct node *next;
};
class dequeue
{
	struct node *front;
	struct node *rear;

public:
	dequeue()
	{
		front = NULL;
		rear = NULL;
	}
	void insertFront(int e);
	void insertRear(int e);
	void insertAfter(int e, int k);
	void insertBefore(int e, int k);

	int deleteFront();
	int deleteRear();
	void deleteSpecific(int e);

	void travelForward();
	void travelBackward();
	~dequeue();
};
void dequeue::insertFront(int e) {
	struct node *temp;
	temp = new node;
	temp->data = e;
	if (front != NULL)
		front->prev = temp;
	else
		rear = temp;

	temp->next = front;
	temp->prev = NULL;
	front = temp;
	
}
void dequeue::insertRear(int e) {
	struct node *temp, *cur;
	temp = new node;
	temp->data = e;
	temp -> next = NULL;
	
	temp->prev = rear;
	if (rear != NULL)
		rear->next = temp;
	else
		front = temp;
	rear = temp;
}
void dequeue::travelForward()
{
	struct node *cur;
	cur = front;
	while (cur != rear)
	{
		cout << cur->data << "--->";
		cur = cur->next;
	}
	cout << cur->data;
	cout << endl;
}
void dequeue::travelBackward()
{
	struct node *cur;
	cur = rear;
	while (cur != front)
	{
		cout << cur->data << "--->";
		cur = cur->prev;
	}
	cout << cur->data;
	cout << endl;
}

int dequeue::deleteFront()
{
	struct node *temp;
	int e = -1;
	if (front != NULL)
	{
		temp = front;

		front = front->next;
		if (front == NULL)
			rear == NULL;
		front->prev = NULL;
		e = temp->data;
		delete temp;
	}
	return e;
}
int dequeue::deleteRear()
{
	struct node *temp;
	int e = -1;
	if (rear != NULL)
	{
		temp = rear;
		rear = rear->prev;
		if (rear == NULL)
			front = NULL;
		rear->next = NULL;
		e = temp->data;
		delete temp;
	}
	return e;

}

dequeue ::~dequeue()
{
	struct node *cur, *temp;
	cur = front;
	while (cur != rear)
	{
		temp = cur;
		cur = cur->next;
		delete temp;
	}
	front = NULL;
	delete(rear);
	rear = NULL;
	cout << "deleted";
}
int main()
{
	dequeue d;

	d.insertFront(1);
	d.insertFront(2);
	d.insertFront(3);

	d.travelForward();

	d.insertRear(4);
	d.insertRear(5);

	d.travelForward();

	d.deleteFront();
	d.deleteFront();

	d.travelForward();
	
	d.deleteRear();
	d.deleteRear();
	d.travelForward();

	getchar();
}