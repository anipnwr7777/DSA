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

bool areMirrorImage(Node *root1, Node *root2){
	if(root1 == nullptr && root2 == nullptr)
		return true;
	if(root1 == nullptr || root2 == nullptr)
		return false;

	if ((root1->key == root2->key) && (areMirrorImage(root1->left, root2->right)) && (areMirrorImage(root1->right, root2->left)))
		return true;
	else 
		return false;
}

bool isSymmetric(Node *root){
	return areMirrorImage(root->left, root->right);
}

int main(){

	Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);

    isSymmetric(root) ? cout << "yes they are symmetric" : cout << "no they are not symmetric" ;
    cout << endl;

    return 0;
}