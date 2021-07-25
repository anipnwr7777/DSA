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

void delete_tree(Node **root){ // pointer to pointer has been used to take reference to a pointer so that changes made is subsequent reucrsive calls can be traced back.
	// since we don't have the pointer and have a reference to the pointer so we do derefrencing
	// this is a post order traversal because we can't delete a parent before it's child.
	if(*root == nullptr)
		return;
	delete_tree(&((*root)->left));
	delete_tree(&((*root)->right));

	delete *root;  // delete the node pointed by *root and deallocate the memory and point it to null
	*root = nullptr;
}

int main(){

	Node *root = new Node(3);
	root->left = new Node(4);
	root->right = new Node(5);
	root->left->left = new Node(7);
	root->left->right = new Node(8);
	root->right->left = new Node(10);
	root->right->right = new Node(11);

	cout << "before deleting root points to: " << root << " and the height is: " << height(root) << endl; 
	delete_tree(&root);
	cout << "after deleting root points to: " << root << " and the height is: " << height(root) << endl;
    return 0;
}