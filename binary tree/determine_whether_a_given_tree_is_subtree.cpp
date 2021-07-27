#include<bits/stdc++.h>
using namespace std;
bool final = false, flag = false;

struct Node{
	int key;
	Node *left = nullptr, *right = nullptr;
	Node(int key){   // constructor 
		this->key = key;
		this->left = this->right = nullptr;
	}
};

bool match(Node *root, Node *root2){
	// cout << "hello" << endl;
	if(root->key != root2->key)
		return false;

	bool left = true, right = true;
	if((root->left && !root2->left) || (!root->left && root2->left)){
		left = false;
	}
	else if(!root->left && !root2->left){
		left = true;
	}
	else{
		left = match(root->left, root2->left);
	}

	if((root->right && !root2->right) || (!root->right && root2->right)){
		right = false;
	}
	else if(!root->right && !root2->right){
		right = true;
	}
	else{
		right = match(root->right, root2->right);
	}

	return left && right;
}

void check(Node *root, Node *root2){
	if(root == NULL)
		return;

	if(root->key == root2->key && !flag){
		final = match(root, root2);
		if(final == true)
			flag = true;
	}
	if(root->left) check(root->left, root2);
	if(root->right) check(root->right, root2);
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

	Node *root2 = new Node(4);
	root2->left = new Node(7);
	root2->right = new Node(8);
	root2->right->right = new Node(12);
	root2->right->right->right = new Node(20);

	check(root, root2);

	cout << (flag ? "subtree is present" : "subtree not present") << endl;
    return 0;
}