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

Node* clone_list(Node *head){
	Node *newhead = NULL , *newtail = NULL, *node = head;
	while(node != NULL){
		if(newhead == NULL){
			newhead = newnode(node->Data);
			newtail = newhead;
		}
		else{
			newtail->Next = newnode(node->Data);
			newtail = newtail->Next;
		}
		node = node->Next;
	}
	return newhead;
}

int main(){
	vector<int> list = {1, 2, 3, 4, 5};
	Node *head = construct_list(list);
	printlist(head);

	Node *newhead = clone_list(head);
	printlist(newhead);
    return 0;
}