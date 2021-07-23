#include<bits/stdc++.h>
using namespace std;

struct Node {
	int Data;
	Node* Next;
};

void Push(int data, Node **headref){
	Node *node = (Node*)malloc(sizeof(Node));
	node->Data = data;
	node->Next = *headref;
	*headref = node;
}

Node* construct_list(vector<int> values) {
	Node *head = NULL;
	for (int i = values.size() - 1 ; i >= 0 ; i--) {
		Push(values[i], &head);
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