#include<bits/stdc++.h>
using namespace std;
int diameter_length = 0; // final value of diameter

struct Node{
	int key;
	Node *left = nullptr, *right = nullptr;
	Node(int key){   // constructor 
		this->key = key;
		this->left = this->right = nullptr;
	}
};

int diameter(Node *root){
	// post order traversal
	if(root == nullptr)
		return 0; // no node means 0 number of nodes under it and containing itself

	int left = 0, right = 0;
	if(root->left)
		left = diameter(root->left);
	else
		left = 0;

	if(root->right)
		right = diameter(root->right);
	else
		right = 0;

	if((1 + left + right) > diameter_length){
		diameter_length = 1 + left + right;
	}

	return 1 + max(left, right);
}

int main(){

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

	diameter(root);
	cout << " the diameter length is: " << diameter_length << endl;
    return 0;
}