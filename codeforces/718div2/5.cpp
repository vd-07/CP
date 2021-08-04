#include <iostream>

using namespace std;

struct LinkedList {
	int value;
	LinkedList *next;
};

LinkedList* makeNode(int value) {
	LinkedList *newPointer = new LinkedList;

	newPointer->value = value;
	newPointer->next = NULL;
	
	return newPointer;
}

bool deleteNode(LinkedList* node) {
	if(node == NULL) {
		return false;
	}

	// it frees the memory that pointer node is currently pointing to
	delete node;

	return true;
}

void printLinkedList(LinkedList* curr) {
	// recursive

	if(curr == NULL) {
		cout << "NULL\n";
		return;
	}

	cout << curr->value << "->";

	printLinkedList(curr->next);
}

LinkedList* insertBeginning(int value, LinkedList *head) {
	LinkedList *node = makeNode(value);

	node->next = head;

	return node;
}

void insertEnd(int value, LinkedList *node) {
	if(node->next == NULL) {
		LinkedList *nnode = makeNode(value);
		node->next = nnode;
		return;
	}

	insertEnd(value, node->next);
}

int main() {
	#ifndef ONLINE_JUDGE
	    // for getting input from input.txt
		freopen("input.txt", "r", stdin);
	    // for writing output to output.txt
	    //this can be opted out if you want to print the output to the sublime console
		freopen("output.txt", "w", stdout);
	#endif

	int n;

	cin >> n;

	LinkedList *prev, *head = NULL;

	if(n != 0) {
		int data;

		cin >> data;

		head = makeNode(data);

		prev = head;

		for(int i = 0; i < n - 1; i++) {
			
			cin >> data;
			
			prev->next = makeNode(data);
			
			prev = prev->next;
		}	
	}

	
	printLinkedList(head);

	// insertion
	if(head == NULL) {
		//
		head = makeNode(6);
	} else {
		insertEnd(6, head);	
	}
	
	printLinkedList(head);

	return 0;
}