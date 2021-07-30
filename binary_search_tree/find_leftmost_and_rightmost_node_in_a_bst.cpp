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

void findExtremes(Node *root){
	Node *dummy = root;
	while(dummy->left)
		dummy = dummy->left;
	cout << "left most node is: " << dummy->key << endl;
	dummy = root;
	while(dummy->right)
		dummy = dummy->right;
	cout << "right most node is: " << dummy->key << endl;
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

	findExtremes(root);
	return 0;
}