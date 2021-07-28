#include<bits/stdc++.h>
using namespace std;

struct Node{
	int key;
	Node *left = nullptr, *right = nullptr;
	Node(int key){   // constructor 
		this->key = key;
		this->left = this->right = nullptr;
	}
};

bool ifExist(Node *root, int a){
	if(root == nullptr)
		return false;
	if(root->key == a)
		return true;

	bool left = ifExist(root->left, a);
	bool right = ifExist(root->right, a);
	return left || right;
}

Node *findLCA(Node *root, int a, int b){
	if(root == nullptr)  // if tree is empty then no ancestor
		return nullptr;

	if(root->key == a || root->key == b)  // if root node itself is either a or b
		return root;

	// if it is not then go to left side and right side and search for ancestor there
	Node *left = findLCA(root->left, a, b);
	Node *right = findLCA(root->right, a, b);

	// if both left and right subtree return something that means this node itself is the ancestor(a is on left and b is on right or vice versa)
	if(left && right)
		return root;
	// if right side return null then on left there is something and the one returned earlier is root
	if(left)
		return left;
	if(right)
		return right;

	// if nothing happens on right or left then return null pointer
	return nullptr;
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

	int a,b; 
	cin >> a >> b;
	if(ifExist(root, a) && ifExist(root,b)){  // both of them should exist for lca to exist
		Node *ans = findLCA(root, a, b);
		cout << ans->key << endl;
	}
	else{
		cout << "either or both the values donot exist in the tree" << endl;
	}

    return 0;
}