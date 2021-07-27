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

void preorder(Node* root)
{
    if (root == nullptr) {
        return;
    }
    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
}

int convertSumTree(Node *root){

	if(root == nullptr){ // tree doesn't exist
		cout << "tree doesn't exist" << endl;
		return 0;
	}
	if(root->left == nullptr && root->right == nullptr) // leaf node
		return root->key;

	int leftsum = 0, rightsum = 0;
	if(root->left)
		leftsum = convertSumTree(root->left);
	if(root->right)
		rightsum = convertSumTree(root->right);

	int old = root->key;
	root->key = leftsum + rightsum;
	return old + root->key;
}

int main(){

	/*
	          1
            /  \
           /    \
          2      3
           \    / \
            4  5   6
              / \
             7   8 
	*/

	Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);

	convertSumTree(root);
	preorder(root);

    return 0;
}