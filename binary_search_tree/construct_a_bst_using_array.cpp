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

Node *insert(Node *root, int data){
	if(root == nullptr){
		return new Node(data);
	}
	if(data < root->key){
		root->left = insert(root->left, data);
	}
	else if(data > root->key){
		root->right = insert(root->right, data);
	}
	else{
		return root;
	}

	return root;
}

void printTree(Node *root){
	if(root == nullptr)
		return;
	printTree(root->left);
	cout << root->key << " ";
	printTree(root->right);
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
	printTree(root);
	return 0;
}