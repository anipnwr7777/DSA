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

void findkthLargest(Node *root, int &num, int k){
	if(root == nullptr)
		return;
	findkthLargest(root->left, num, k);
	if(num == k){
		cout << "kth largest element is: " << root->key << endl;
	}
	num++;
	findkthLargest(root->right, num, k);
}

void findkthSmallest(Node *root, int &num, int k){
	if (root == nullptr)
		return;
	findkthSmallest(root->left, num, k);
	if(num == k){
		cout << "kth smallest element is: " << root->key << endl;
	}
	num++;
	findkthSmallest(root->right, num, k);
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

	int k;
	cin >> k;
	int start1, start2;
	start1 = start2 = 1;
	findkthSmallest(root, start1, k);
	findkthLargest(root, start2, n-k+1);
	return 0;
}