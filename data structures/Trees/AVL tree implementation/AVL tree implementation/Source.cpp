#include<iostream>
#include<algorithm>

using namespace std;

struct node{
	int data;
	struct node *left;
	struct node *right;
};


class avl {

	struct node *root;

public:

	avl() {
		root = NULL;
	}

	void inorder();
	void preorder();
	void postorder();

	void insert(int e);

	friend node* balance(struct node *);
};

int height(struct node *cur) {
	if (cur == NULL)
		return -1;
	else
		return max(height(cur->left), height(cur->right)) + 1;
}

int bf(struct node *cur) {
	return(height(cur->left) - height(cur->right));
}

node* lrot(struct node *cur) {
	struct node *temp;
	temp = cur->right;
	cur->right = temp->left;
	temp->left = cur;
	return temp;
}

node* rrot(struct node *cur) {
	struct node *temp;
	temp = cur->left;
	cur->left = temp->right;
	temp->right = cur;
	return temp;
}

node* rlrot(struct node *cur) {
	struct node *temp = cur->right;
	temp = rrot(temp);
	cur->right = temp->left;
	temp->left = cur;
	return temp;
}

node* lrrot(struct node *cur) {
	struct node *temp = cur->left;
	temp = lrot(temp);
	cur->left = temp->right;
	temp->right = cur;
	return temp;
}

node* balance(struct node *cur) {
	if (bf(cur) > 1) {
		if (bf(cur->left) == -1)
			return lrrot(cur);
		else
			return rrot(cur);
	}
	else if(bf(cur) < -1){
		if (bf(cur->right) == 1)
			return rlrot(cur);
		else
			return lrot(cur);
	}
	return cur;
}

node* i(int e, struct node *cur) {
	if (cur == NULL) {
		struct node *n;
		n = new node;
		n->data = e;
		n->left = NULL;
		n->right = NULL;
		return n;
	}
	else {
		if (e < cur->data) {
			cur->left = i(e, cur->left);
			cur = balance(cur);
		}
		else {
			cur->right = i(e, cur->right);
			cur = balance(cur);
		}
	}
	return cur;
}

void avl::insert(int e) {
	if (root == NULL)
		root = i(e, root);
	else
		i(e, root);
}

void ino(struct node *cur) {
	if (cur != NULL) {
		ino(cur->left);
		cout << cur->data << " ";
		ino(cur->right);
	}
}

void avl::inorder() {
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

void avl::preorder() {
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

void avl::postorder() {
	post(root);
}




int main() {

	avl t;

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

	

	getchar();
	return 0;
}