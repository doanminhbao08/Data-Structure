#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;

struct Node{
	Node* pre;
	int data;
	Node* next;
};

Node* create_node(int data_in){
	Node* node = new Node();
	node -> data = data_in;
	node -> pre = NULL;
	node -> next = NULL;
	return node;	
}

int main(){
	Node* a = create_node(1);
	Node* b = create_node(2);
	Node* c = create_node(3);
	Node* d = create_node(4);
	Node* e = create_node(5);
	a -> pre = b;
	b -> next = c;
	c -> pre = d;
	d -> pre = e; 
	return 0;
}

