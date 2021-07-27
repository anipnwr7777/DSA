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

void left_view(Node *root, int *maxlevel, int level){
	// level is the level of the current node (local to the function call)
	// maxlevel is the max level printed till now, it has to be reflected back and is not local
	if(root == nullptr)
		return;

	// this is preorder traversal with printing on a special condition
	if(level > *maxlevel){
		cout << root->key << " ";
		*maxlevel = level;
	}
	left_view(root->left, maxlevel, level+1);
	left_view(root->right, maxlevel, level+1);
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

	int maxlevel = 0;
	left_view(root, &maxlevel, 1);

    return 0;
}