#include<iostream>
#include<conio.h>

using namespace std;

typedef struct {
	int front, rear;
	int *a;
	int size;
}CircularQueue;

class CircularQueues {
	CircularQueue s;
public:
	CircularQueues() {
		s.front = s.rear = -1;
		s.a = NULL;
		s.size = 0;
	}
	void enQueue(int ele) {
		if (!isFull()) {
			if (s.front == -1)
				s.front++;
			s.rear = (s.rear + 1) % s.size;
			s.a[s.rear] = ele;
		}
	}
	int deQueue() {
		int ele = 0;
		if (!isEmpty()) {
			ele = s.a[s.front];
			s.front = (s.front + 1) % s.size;
			if (s.front == s.rear)
				s.front = s.rear = -1;
		}
		return ele;
	}
	bool isEmpty() {
		return (s.rear == -1 && s.front == -1);
	}
	bool isFull() {
		return (((s.rear + 1) % s.size) == s.front);
	}
	void display() {
		int i;
		if (!isEmpty()) {
			for (i = s.front; i != s.rear; i = (i + 1) % s.size)
				cout << s.a[i] << " ";
			cout << s.a[i];
		}
		cout << endl;
	}
	void setSize(int n) {
		s.size = n;
		s.a=new int[n];
	}
	~CircularQueues() {
		free(s.a); 
		cout << endl << "CircularQueue deleted" << endl << endl;
	}
};

int main() {
	int x;
	{
		CircularQueues s1;
		cout << endl << "Enter the size of the CircularQueue : ";
		cin >> x;
		s1.setSize(x);
		system("cls");
		while (1) {
			cout << endl << "Select any one of the options below : " << endl;
			cout << "1. Enqueue" << endl;
			cout << "2. Dequeue" << endl;
			cout << "3. Display" << endl;
			cout << "4. Exit" << endl << endl;
			cin >> x;
			switch (x) {
			case 1:
				if (!s1.isFull()) {
					cout << endl << "Enter the number to be Enqueued into the CircularQueue : " << endl << endl;
					cin >> x;
					s1.enQueue(x);
					cout << endl << x << " has been Enqueued into the CircularQueue " << endl << endl;
				}
				else
					cout << endl << "CircularQueue Overflow, can't Enqueue" << endl;
				break;
			case 2:
				if (!s1.isEmpty())
					cout << endl << s1.deQueue() << " has been Dequeued out of the CircularQueue" << endl;
				else
					cout << endl << "CircularQueue Underflow, can't Dequeue any more" << endl;
				break;
			case 3:
				cout << endl;
				s1.display();
				break;
			case 4:
				exit(0);
			default:
				cout << endl << "Please choose from one of the options given only" << endl;
			}
			getchar();
			getchar();
			system("cls");
		}
	}
	return 0;
}