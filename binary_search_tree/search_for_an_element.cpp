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

Node *findElement(Node *root, int element){
	if(root == nullptr)
		return nullptr;

	if(root->key == element)
		return root;

	if(element < root->key){
		return findElement(root->left, element);
	}
	else
		return findElement(root->right, element);
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
	int element;
	cin >> element;
	Node *ans = findElement(root, element);
	if(ans == nullptr)
		cout << "element not found" << endl;
	else
		cout << "element found" << endl;
	return 0;
}