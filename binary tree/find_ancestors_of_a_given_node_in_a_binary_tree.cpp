#include<bits/stdc++.h>
using namespace std;
vector<int> path;

struct Node {
	int key;
	Node *left = nullptr, *right = nullptr;
	Node(int key) {  // constructor
		this->key = key;
		this->left = this->right = nullptr;
	}
};

void printPath() {
	if (path.size() == 0)
		cout << "no ancestors exist, this is probably the root node" << endl;
	else {
		for (auto x : path)
			cout << x << ", ";
		cout << endl;
	}
}

bool doesExist(Node *root, int a) {
	if(root == nullptr)
		return false;

	if (root->key == a)
		return true;

	bool left = false, right = false;
	if (root->left)
		left = doesExist(root->left, a);
	if (root->right)
		right = doesExist(root->right, a);

	return left || right;
}

void findAncestors(Node *root, int a) {
	if (root == nullptr)
		return;

	if (root->key == a) {
		printPath();
	}

	path.push_back(root->key);  // do this while entering the node

	findAncestors(root->left, a);  // call left
	findAncestors(root->right, a);  // call right

	path.pop_back();  // do this while exiting the node

}

int main() {

	/*
	     root-> 3
			   / \
			  4   5
			 / \ / \
			7  8 10 11
			    \
			     12
			      \
			      20
	*/

	Node *root = new Node(3);
	root->left = new Node(4);
	root->right = new Node(5);
	root->left->left = new Node(7);
	root->left->right = new Node(8);
	root->right->left = new Node(10);
	root->right->right = new Node(11);
	root->left->right->right = new Node(12);
	root->left->right->right->right = new Node(20);

	int a;
	cin >> a;
	if (doesExist(root, a)) {
		findAncestors(root, a);
	}
	else {
		cout << "no such node in the tree" << endl;
	}
	return 0;
}