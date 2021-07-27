#include<bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	Node *left = nullptr, *right = nullptr;
	Node(int key) {  // constructor
		this->key = key;
		this->left = this->right = nullptr;
	}
};

bool is_complete(Node *root) {
	queue<Node*> q;
	q.push(root);
	bool flag = false;  // last node not found

	while (!q.empty()) {
		Node *node = q.front();
		q.pop();

		if(flag && (node->left || node->right)){
			return false;
		}
		if(node->left == nullptr && node->right){
			return false;
		}

		if (node->left) {
			q.push(node->left);
		}
		else{
			flag = true;
		}
		if (node->right) {
			q.push(node->right);
		}
		else{
			flag = true;
		}	
	}
	return true;
}

int main() {

	/*
	     root-> 3
			   / \
			  4   5
			 / \ / \
			7  8 10 11
			 \    \
			  13   15
	*/

	Node *root = new Node(3);
	root->left = new Node(4);
	root->right = new Node(5);
	root->left->left = new Node(7);
	root->left->right = new Node(8);
	root->right->left = new Node(10);
	root->right->right = new Node(11);
	root->right->right = new Node(11);
	root->left->left->right = new Node(13);
	root->right->left->right = new Node(15);

	cout << (is_complete(root) ? "is complete" : "not complete") << endl;
	return 0;
}