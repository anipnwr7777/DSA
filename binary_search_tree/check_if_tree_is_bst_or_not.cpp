#include<bits/stdc++.h>
using namespace std;

struct Node{
	int key;
	Node *left = nullptr, *right = nullptr;
	Node(int key){
		this->key = key;
		this->left = this->right = nullptr;
	}
};

Node *insert(Node *root, int data){  // insert the new node and return the final pointer of the final tree
	if(root == nullptr){
		return new Node(data);  // create the first node with the data that is given as input and return the pointer to the data
	}
	if(data < root->key){
		root->left = insert(root->left, data);
	}
	else if(data > root->key){		// make changes and join the new node to the previously made tree by equating to the pointer.
		root->right = insert(root->right, data);
	}
	else{  // already exist donot do anything just return the root
		return root;
	}

	return root;  // return the final pointer.
}

void printTree(Node *root){  // inorder printing
	if(root == nullptr)
		return;
	printTree(root->left);
	cout << root->key << " ";
	printTree(root->right);
}

bool checkBST(Node *root){		// function to tell whether the given tree is bst or not

	if(root == nullptr) 	// empty tree
		return true;
	if(!root->left && !root->right)		// leaf node is always bst in itself
		return true;

	bool left = true, right = true, cond1 = true, cond2 = true;  // all the conditions and their default values.
	if(root->left){
		left = checkBST(root->left); 	// check if left subtree is bst or not
		if(root->left->key >= root->key)		// left subtree is in itself a bst but, it should have value less than root for root to be a bst
			cond1 = false;
	}
	if(root->right){
		right = checkBST(root->right);  	// check if right subtree is bst or not
		if(root->right->key <= root->key)		// right subtree is in itself a bst but, it should have value more than root for root to be a bst
			cond2 = false;
	}

	if(left && right && cond1 && cond2)		// the subtree under root node is bst only if the given conditions are met
		return true;
	else
		return false;

}

int main(){
	vector<int> values; 
	int n;
	cin >> n;
	values.resize(n);

	for(int i=0 ; i<n ; i++)
		cin >> values[i];

	Node *root = nullptr;
	for(int i=0 ; i<n ; i++){
		root = insert(root, values[i]);
	}

	cout << (checkBST(root) ? "yes, the given tree is a bst" : "not it is not a bst" ) << endl;
	return 0;
}