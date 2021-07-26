#include<bits/stdc++.h>
using namespace std;

struct Node{
	int key;
	Node *left = nullptr, *right = nullptr;
	Node(int key){   // constructor 
		this->key = key;
		this->left = this->right = nullptr;
	}
};

void reverse_level_order(Node *root){
	queue<Node*> q;
	q.push(root);
	stack<int> values;  // if you find "reverse" word somewhere you can think of stack there.

	while(!q.empty()){
		Node *node = q.front();
		q.pop();
		values.push(node->key);

		if(node->right)	q.push(node->right);
		if(node->left) q.push(node->left);
	}
	while(!values.empty()){
		cout << values.top() << " ";
		values.pop();
	}
}

int main(){

	/*
	     root-> 3
			   / \
			  4   5
			 / \ / \
			7  8 10 11   
	*/

	Node *root = new Node(3);
	root->left = new Node(4);
	root->right = new Node(5);
	root->left->left = new Node(7);
	root->left->right = new Node(8);
	root->right->left = new Node(10);
	root->right->right = new Node(11);

	reverse_level_order(root);

    return 0;
}