#include<bits/stdc++.h>
using namespace std;
map<int,vector<int>> diagonals;

struct Node{
	int key;
	Node *left = nullptr, *right = nullptr;
	Node(int key){   // constructor 
		this->key = key;
		this->left = this->right = nullptr;
	}
};

void printDiagonalTraversal(){
	for(auto ele: diagonals){
		for(auto z: ele.second)
			cout << z << " ";
		cout << endl;
	}
}

void fillDiagonal(Node *root, int level){
	if(root == nullptr)
		return;

	diagonals[level].push_back(root->key);
	fillDiagonal(root->left, level + 1);  // go to left and fill on level + 1
	fillDiagonal(root->right, level);	  // go to the right and fill on the same level
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
	fillDiagonal(root, 0);
	printDiagonalTraversal();

    return 0;
}