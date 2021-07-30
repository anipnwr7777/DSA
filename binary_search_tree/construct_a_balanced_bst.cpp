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

void printTree(Node *root){  // inorder printing
	if(root == nullptr)
		return;
	printTree(root->left);
	cout << root->key << " ";
	printTree(root->right);
}

void CreateBalancedTree(Node* &root, int low, int high, vector<int> values){
	if(low > high)
		return;
	int mid = (low + high)/2;
	root = new Node(values[mid]);

	CreateBalancedTree(root->left, low, mid -1 , values);
	CreateBalancedTree(root->right, mid+1, high, values);
}

int height(Node *root){
	if(root == nullptr)
		return 0;
	int left = 0, right = 0;
	if(root->right)
		right = height(root->right);
	if(root->left)
		left = height(root->left);

	return max(left, right) + 1;
}

int main(){
	vector<int> values; 
	int n;
	cin >> n;
	values.resize(n);

	for(int i=0 ; i<n ; i++)
		cin >> values[i];

	sort(values.begin(), values.end());
	Node *root = nullptr;
	
	CreateBalancedTree(root, 0, n-1, values);
	cout << "the height of the tree: " <<  height(root) << endl;
	cout << "inorder traversal is: " << endl;
	printTree(root);
	return 0;
}