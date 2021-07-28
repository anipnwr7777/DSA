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

void preorder(Node *root){
	if(root == nullptr)
		return;

	cout << root->key << " ";
	preorder(root->left);
	preorder(root->right);
}

Node* mirrorImage(Node *root){
	if(root == nullptr) // empty tree
		return root;
	if(root->left == nullptr && root->right == nullptr) // leaf node
		return root;

	if(root->left) // if left side exists then get it's mirror image
		root->left = mirrorImage(root->left);
	if(root->right)  // if right side exists then get it's mirror image
		root->right = mirrorImage(root->right);

	swap(root->left, root->right); 
	/*
		now we have:
		root-left and it's subtree is sorted in itself, root->right and it's subtree is sorted in itself 
		but the root->left and root->right are not in their right places, so we swap them

		now as soon as we do this the root(their parent) becomes entirely sorted
	*/
	return root;  // return pointer to the root node of the subtree who has been converted to it's mirror image.
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

	mirrorImage(root);

	preorder(root);
    return 0;
}