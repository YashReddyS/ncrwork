#include<iostream>
#include<algorithm>

using namespace std;

struct node {
	int data;
	struct node *left;
	struct node *right;
};

node* i(int,struct node *);
void ino(struct node *);

class Tree {

	struct node *root;


public:
	Tree() {
		root = NULL;
	}

	void insert(int);
	void deleteNode(int);

	void inorder();
	void preorder();
	void postorder();

	int findMax(struct node *);
	int findMin(struct node *);

	int height();
	int depth(node);
	int noOfLeadNodes();
	int noOfNodes();

	friend node* i(int ele, struct node *);
	node* d(int ele, struct node *);
};

int h(struct node *cur) {
	if (cur == NULL)
		return -1;
	else
		return max(h(cur->left), h(cur->right)) + 1;
}

int Tree::height() {
	if (h(root) == -1)
		cout << "there is no tree";
	return h(root);
}

void Tree::insert(int ele) {
	if (root == NULL)
		root = i(ele, root);
	else
		i(ele, root);
}
node* i(int ele,struct node *cur) {
	if (cur == NULL) {
		struct node *n;
		n = new node;
		n->data = ele;
		n->left = NULL;
		n->right = NULL;	
		return n;
	}
	else{
		if (ele < cur->data)
			cur->left = i(ele, cur->left);
		else
			cur->right = i(ele, cur->right);
	}
	return cur;
}


void ino(struct node *cur) {
	if (cur != NULL) {
		ino(cur->left);
		cout << cur->data << " ";
		ino(cur->right);
	}
}

void Tree::inorder() {
	ino(root);
	cout << endl;
}


void pre(struct node *cur) {
	if (cur != NULL) {
		cout << cur->data << " ";
		pre(cur->left);
		pre(cur->right);
	}
}

void Tree::preorder() {
	pre(root);
	cout << endl;
}

void post(struct node *cur) {
	if (cur != NULL) {
		post(cur->left);
		post(cur->right);
		cout << cur->data << " ";
	}
}

void Tree::postorder() {
	post(root);
	cout << endl;
}


int Tree::findMax(struct node *cur) {
	if (cur != NULL) {
		while (cur->left != NULL)
			cur = cur->left;
		return cur->data;
	}
	return -1;
}

int Tree::findMin(struct node *cur) {
	if (cur != NULL) {
		while (cur->right != NULL)
			cur = cur->right;
		return cur->data;
	}
	return -1;
}

void Tree::deleteNode(int ele) {
	if (d(ele, root) == NULL)
		cout << "element not found";
		
}
node* Tree::d(int ele,struct node *cur) {
	if (cur != NULL) {
		if (ele > cur->data)
			cur->right = d(ele, cur->right);
		else if((ele < cur->data))
			cur->left = d(ele, cur->left);
		else{
			if (cur->left != NULL && cur->right != NULL) {
				cur->data = findMax(cur->left);
				cur->left = d(cur->data, cur->left);
			}
			else {
				struct node *temp = cur;
				if (cur->left == NULL)
					cur = cur->right;
				else
					cur = cur->left;
				delete temp;
			}
		}
	}
	return cur;
}

int main() {

	int x;
	Tree t;

	t.insert(31);
	t.insert(5);
	t.insert(12);
	t.insert(21);
	t.insert(17);
	t.insert(19);
	t.insert(1);
	t.insert(14);
	t.insert(8);
	t.insert(9);
	t.insert(35);
	t.insert(16);

	t.inorder();
	t.preorder();
	t.postorder();

	while (1) {
		cout << endl << "Select any one of the options below : " << endl;
		cout << "1. insert" << endl;
		cout << "2. delete" << endl;
		cout << "3. display(inorder)" << endl;
		cout << "4. Exit" << endl << endl;
		cin >> x;
		switch (x) {
		case 1:
				cout << endl << "Enter the number to be inserted into the tree : " << endl << endl;
				cin >> x;
				t.insert(x);
				cout << endl << x << " has been inserted into the tree " << endl << endl;
			    break;
		case 2:
			cout << endl << "Enter the number to be deleted from the tree : " << endl << endl;
			cin >> x;
			t.deleteNode(x);
			cout << endl << x << " has been deleted from the tree " << endl << endl;
			break;
		case 3:
			cout << endl;
			t.inorder();
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

