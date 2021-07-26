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

void spiral_order(Node *root){
	list<Node*> dequeue;  // list is an stl containtor used for implementing doubly ended queue.
	dequeue.push_front(root);
	bool flag = 1;   // just to mark the level and decide for the direction of traversal

	while(!dequeue.empty()){
		int sz = dequeue.size();  // to consider one level at a time
		if(flag == 1){   // odd level
			while(sz--){
				Node *dummy = dequeue.front();
				cout << dummy->key << " ";
				dequeue.pop_front();
				if(dummy->left) dequeue.push_back(dummy->left);
				if(dummy->right) dequeue.push_back(dummy->right);
			}
		}
		else{
			while(sz--){
				Node *dummy = dequeue.back();
				cout << dummy->key << " ";
				dequeue.pop_back();
				if(dummy->right) dequeue.push_front(dummy->right);
				if(dummy->left) dequeue.push_front(dummy->left);
			}
		}
		flag = !flag;  // change direction for next time
		cout << endl;
	}
}

int main(){

	/*
	     root-> 3
			   / \
			  4   5
			 / \ / \
			7  8 10 11   
	*/

	Node *root = new Node(3);
	root->left = new Node(4);
	root->right = new Node(5);
	root->left->left = new Node(7);
	root->left->right = new Node(8);
	root->right->left = new Node(10);
	root->right->right = new Node(11);

	spiral_order(root);

    return 0;
}