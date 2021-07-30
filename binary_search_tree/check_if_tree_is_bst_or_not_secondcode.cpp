#include<bits/stdc++.h>
using namespace std;
bool isBST = true;

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

void checkBST(Node *root, int &lastNode){
	if(root == nullptr)
		return;

	checkBST(root->left, lastNode);
	if(root->key <= lastNode){
		isBST = false;
	}
	lastNode = root->key;
	cout << lastNode << endl;
	checkBST(root->right, lastNode);
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

	int lastNode = -1;
	checkBST(root, lastNode);
	cout << (isBST ? "yes it is bst" : "no it is not bst") << endl;
	return 0;
}