#include<bits/stdc++.h>
using namespace std;

struct Node {
	int Data;
	Node* Next;
};

Node* newnode(int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->Data = data;
	node->Next = NULL;
	return node;
}

Node* construct_list(vector<int> list){
	Node *head = NULL, *tail = NULL;
	head = newnode(list[0]);
	tail = head;
	for(int i=1 ; i<list.size() ; i++){
		tail->Next = newnode(list[i]);
		tail = tail->Next;
	}
	return head;
}

void printlist(Node *head){
	while(head != NULL){
		cout << head->Data << " -> ";
		head = head->Next;
	}
	cout << "null" << endl;
}

int main(){
	vector<int> list = {1, 2, 3, 4, 5};
	Node *head = construct_list(list);
	printlist(head);
    return 0;
}