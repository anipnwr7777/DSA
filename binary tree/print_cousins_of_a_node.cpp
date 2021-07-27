#include<bits/stdc++.h>
using namespace std;
int parent = -1;
int level = -1;

struct Node{
	int key;
	Node *left = nullptr, *right = nullptr;
	Node(int key){   // constructor 
		this->key = key;
		this->left = this->right = nullptr;
	}
};

void print_cousins(Node *root, int curr_parent, int curr_level){
	if(root == nullptr)
		return;
	if(curr_level == level && curr_parent != parent){
		cout << root->key << " ";
	}
	print_cousins(root->left, root->key, curr_level + 1);
	print_cousins(root->right, root->key, curr_level + 1);
}

void find_details(Node *root, int a, int curr_parent, int curr_level){
	if(root == nullptr)
		return;

	if(root->key == a){
		level = curr_level;
		parent = curr_parent;
	}
	find_details(root->left, a, root->key, curr_level + 1);
	find_details(root->right, a, root->key, curr_level + 1);
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

	int a;
	cin >> a;
	find_details(root, a, -1, 0);
	print_cousins(root, -1, 0);
    return 0;
}