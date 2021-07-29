#include<bits/stdc++.h>
using namespace std;
vector<int> path, finalPath;
int sum = 0, mxSum = -1;

struct Node{
	int key;
	Node *left = nullptr, *right = nullptr;
	Node(int key){   // constructor 
		this->key = key;
		this->left = this->right = nullptr;
	}
};

void printPath(){
	for(auto x:finalPath)
		cout << x << " --> ";
	cout << "null" << endl;
}

void findPath(Node *root){
	if(root == nullptr)
		return;

	path.push_back(root->key);  // do this while entering the node
	sum += root->key;

	if(root->left == nullptr && root->right == nullptr && (sum>mxSum)){
		mxSum = sum;
		finalPath.clear();
		for(auto x:path)
			finalPath.push_back(x);
	}
	findPath(root->left);  // call left
	findPath(root->right);  // call right

	path.pop_back();  // do this while exiting the node
	sum -= root->key;

}

int main(){

	/*
	     root-> 3
			   / \
			  4   5
			 / \ / \
			7  8 10 11   
			    \
			     12
			      \
			      20
	*/

	Node *root = new Node(3);
	root->left = new Node(4);
	root->right = new Node(5);
	root->left->left = new Node(7);
	root->left->right = new Node(8);
	root->right->left = new Node(10);
	root->right->right = new Node(11);
	root->left->right->right = new Node(12);
	root->left->right->right->right = new Node(20);
	findPath(root);
	printPath();

    return 0;
}