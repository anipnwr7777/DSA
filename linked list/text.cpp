#include<bits/stdc++.h>
using namespace std;

struct Node{
	int Data;
	Node *Next;
};

Node* newnode(int data){
	Node *node = (Node*)malloc(sizeof(Node));
	node->Data = data;
	node->Next = NULL;
	return node;
}

Node* construct_list(vector<int> list){
	int n = list.size();
	Node *head = NULL, *node= NULL;
	head = newnode(list[0]);
	node =  head;
	for(int i=1 ; i<n ; i++){
		node->Next = newnode(list[i]);
		node = node->Next;
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

int main(){
	vector<int> list = {1,2,3,4,5};
	Node *head = construct_list(list);
	printlist(head);
    return 0;
}