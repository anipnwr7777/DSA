#include<bits/stdc++.h>
using namespace std;
int parent = -1;
int level = -1;
bool cousin = false;

struct Node{
	int key;
	Node *left = nullptr, *right = nullptr;
	Node(int key){   // constructor 
		this->key = key;
		this->left = this->right = nullptr;
	}
};

void isCousin(Node *root, int a, int b, int curr_parent, int curr_level){
	if(root == nullptr)
		return;

	if(root->key == a){
		level = curr_level;
		parent = curr_parent;
	}
	if(root->key == b && curr_level == level && curr_parent != parent){
		cousin = true;
	}
	isCousin(root->left, a, b, root->key, curr_level + 1);
	isCousin(root->right, a, b, root->key, curr_level + 1);

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

	int a,b;
	cin >> a >> b;
	isCousin(root, a, b, -1, 0);
	cout << (cousin? "is cousin" : "not cousin") << endl;
    return 0;
}