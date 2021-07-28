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

int main(){

	Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->left->left = new Node(3);
 
    Node *root2 = new Node(1);
    root2->right = new Node(2);
    root2->right->right = new Node(3);

    areMirrorImage(root1, root2) ? cout << "yes they are" : cout << "no they are not" ;
    cout << endl;

    return 0;
}