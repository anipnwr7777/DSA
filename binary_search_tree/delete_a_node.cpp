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

Node *findInorderMax(Node *root){
	while(root->right){
		root = root->right;
	}
	return root;
}

Node *deleteNode(Node *root, int data){ 	// return pointer to the root of the updated tree

	if(root == nullptr)		// tree empty, nothing to delete, return as it is.
		return nullptr;

	if(root->key == data){  	// first case: data found on the node itself

		if(!root->left && !root->right){   // 1.1 : no child
			return nullptr;
		}
		else if(root->left && root->right){    // 1.2 : two child
			Node *dummy = findInorderMax(root->left);
			root->key = dummy->key;
			root->left = deleteNode(root->left, dummy->key);	// always take the changes you do on any side inside a pointer that points to that side, so that you make sure that changes made on that side are not lost.
		}
		else if(root->left){	// 1.3 : single child 
			return root->left;	// skip this node and return it's left to it's parent. it gets ignored.
		}
		else					// 1.3 : single child
			return root->right;
	}

	else if(data > root->key){		// second case: data on right side, go there and delete it
		root->right = deleteNode(root->right, data);
	}

	else{		// third case: data on left side, go there and delete it
		root->left = deleteNode(root->left, data);
	}

	return root;
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

	int nodeToDelete;
	cin >> nodeToDelete;
	deleteNode(root, nodeToDelete);
	printTree(root);
	return 0;
}