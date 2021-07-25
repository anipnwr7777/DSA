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

int height(Node *root){
	if(root == nullptr)
		return 0;
	int lefth = height(root->left);
	int righth = height(root->right);

	return max(lefth , righth) + 1;
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

	cout << "height of the tree is " << height(root) << endl;
    return 0;
}