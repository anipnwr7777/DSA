#include<bits/stdc++.h>
using namespace std;
int final_level = -1, flag = 0;

struct Node{
	int key;
	Node *left = nullptr, *right = nullptr;
	Node(int key){   // constructor 
		this->key = key;
		this->left = this->right = nullptr;
	}
};

void preorder(Node *root, int node, int level){
	if(root == nullptr)
		return;

	if(level == final_level && flag == 0){
		cout << root->key << endl;
		flag = 1;
	}
	if(root->key == node){
		final_level = level;
	}
	preorder(root->left, node, level + 1);
	preorder(root->right, node, level + 1);
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
	int node;
	cin >> node;
	preorder(root, node, 0);

    return 0;
}