#include<bits/stdc++.h>
using namespace std;

struct Node {
	int Data;
	Node* Next;
};

Node* newnode(int data, Node* nextnode) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->Data = data;
	node->Next = nextnode;
	return node;
}

Node* construct_list(vector<int> values) {
	Node *head = NULL, *node = NULL;
	for (int i = values.size() - 1 ; i >= 0 ; i--) {
		node = newnode(values[i], node);
		head = node;
	}
	return head;
}

void printlist(Node *head){
	while(head != NULL){
		cout << head->Data << " ";
		head = head->Next;
	}
	cout << endl;
}

int main() {
	vector<int> values = {1, 2, 3, 4, 5};
	Node *head = construct_list(values);
	printlist(head);
	return 0;
}