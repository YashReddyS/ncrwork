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
	
	int deleteFront();
	int deleteRear();
	
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
	struct node *temp;
	temp = new node;
	temp->data = e;
	temp->next = NULL;
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
	while (cur != NULL)
	{
		cout << cur->data << "--->";
		cur = cur->next;
	}
	cout << endl;
}
void dequeue::travelBackward()
{
	struct node *cur;
	cur = rear;
	while (cur != NULL)
	{
		cout << cur->data << "--->";
		cur = cur->prev;
	}
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
			rear = NULL;
		else
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
		else
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

	dequeue s1;
	int x;
	while (1) {
		cout << endl << "Select any one of the options below : " << endl;
		cout << "1. Enqueue font" << endl;
		cout << "2. Dequeue front" << endl;
		cout << "3. Enqueue rear" << endl;
		cout << "4. Dequeue rear" << endl;
		cout << "5. Display" << endl;
		cout << "6. Exit" << endl << endl;
		cin >> x;
		switch (x) {
		case 1:
			
				cout << endl << "Enter the number to be Enqueued into the deQueue : " << endl << endl;
				cin >> x;
				d.insertFront(x);
				cout << endl << x << " has been Enqueued into the deQueue " << endl << endl;
			break;
		case 2:
			cout << endl << d.deleteFront() << " has been dequeued from the Queue " << endl << endl;
			break;
		case 3:
			cout << endl << "Enter the number to be Enqueued into the Queue : " << endl << endl;
			cin >> x;
			d.insertRear(x);
			cout << endl << x << " has been Enqueued into the Queue " << endl << endl;
			break;
		case 4:
			cout << endl << d.deleteRear() << " has been dequeued from the Queue " << endl << endl;
			break;
		case 5:
			d.travelForward(); break;
		case 6:
			exit(0);
		default:
			cout << endl << "Please choose from one of the options given only" << endl;
		}
		getchar();
		getchar();
		system("cls");
	}
}
