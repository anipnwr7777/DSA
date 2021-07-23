#include<bits/stdc++.h>
using namespace std;

struct Node {
	int Data;
	Node* Next;
};

Node *head = NULL;

void Push(int data){
	Node *node = (Node*)malloc(sizeof(Node));
	node->Data = data;
	node->Next = head;
	head = node;
}

void construct_list(vector<int> values) {
	for (int i = values.size() - 1 ; i >= 0 ; i--) {
		Push(values[i]);
	}
}

void printlist(){
	while(head != NULL){
		cout << head->Data << " ";
		head = head->Next;
	}
	cout << endl;
}

int main() {
	vector<int> values = {1, 2, 3, 4, 5};
	construct_list(values);
	printlist();
	return 0;
}