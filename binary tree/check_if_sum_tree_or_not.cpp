#include<bits/stdc++.h>
using namespace std;
bool isSumTree = true;

struct Node{
	int key;
	Node *left = nullptr, *right = nullptr;
	Node(int key){   // constructor 
		this->key = key;
		this->left = this->right = nullptr;
	}
};

int checkSumTree(Node *root){

	if(root == nullptr){ // tree doesn't exist
		cout << "tree doesn't exist" << endl;
		isSumTree = false;
		return 0;
	}
	if(root->left == nullptr && root->right == nullptr) // leaf node
		return root->key;

	int leftsum = 0, rightsum = 0;
	if(root->left)
		leftsum = checkSumTree(root->left);
	if(root->right)
		rightsum = checkSumTree(root->right);

	if(root->key != (leftsum + rightsum)){
		isSumTree = false;
	}
	return leftsum + rightsum + root->key;
}

int main(){

	/*
	         44
            /  \
           /    \
          9     13
         / \    / \
        4   5  6   7
	*/

	Node* root = new Node(44);
    root->left = new Node(9);
    root->right = new Node(13);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Node *root2 = new Node(10);

	checkSumTree(root);
	cout << (isSumTree? "yes it is a sum tree" : "not a sum tree") << endl;

    return 0;
}