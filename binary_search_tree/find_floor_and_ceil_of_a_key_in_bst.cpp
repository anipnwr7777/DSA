#include<bits/stdc++.h>
using namespace std;
bool flag = false;  // flag to mark whether ceil and floor are found or not

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

void findFloorCeil(Node *root, int data, int &previous, int n, int curr){
	if(root == nullptr){		// no tree
		return;
	}

	// inorder traversal
	// left
	findFloorCeil(root->left, data, previous, n, curr+1);		


	// root
	if(curr == n && !flag && root->key < data){  	// last node exceeded
		cout << "the floor is: " << root->key << endl;
		cout << "the ceil doesnot exist" <<endl;
		flag = true;
	}
	else if(root->key == data && !flag){	// element found itself
		cout << "the ceil and floor are both same: " << root->key << endl;
		flag = true;
	}
	else if(root->key > data && !flag){		
		if(previous == -1)
			cout << "no floor" << endl;		// first node exceeded
		else
			cout << "the floor is: " << previous << endl;		// node not found, print just smaller and just bigger
		cout << "the ceil is : " << root->key << endl;
		flag = true;
	}
	previous = root->key;  		// set the previous here, not in the function call


	// right
	findFloorCeil(root->right, data, previous, n, curr+1);
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

	int data;
	cin >> data;
	int previous = -1;
	findFloorCeil(root, data, previous, n, 1);
	return 0;
}