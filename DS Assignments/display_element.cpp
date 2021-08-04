#include <iostream>
using namespace std;

struct LinkedList {
    int val;
    LinkedList *next;
};

int iterativeFind(LinkedList *root, int pos) {
    while(--pos) {
        root = root->next;
    }
    return root->val;
}

int recursiveFind(LinkedList *root, int pos) {
    if(pos == 1) {
        return root->val;
    }
    return recursiveFind(root->next, pos - 1);
}

void displayElementAt(LinkedList *root, int pos) {
    // recursive approach
    cout << recursiveFind(root, pos) << "\n";
    // iterative approach
    cout << iterativeFind(root, pos);
}

// make new node
LinkedList *makeNode(int data) {
    LinkedList *root = new LinkedList();
    root->val = data;
    root->next = NULL;
    return root;
}

// create the LinkedList
LinkedList *createLinkedList() {
    int n;
    cout << "Enter the size of Linked List (>0):\n";
    cin >> n;
    cout << "Enter the values of nodes :\n";
    int node;
    LinkedList *root, *curr;
    // creating the root
    cin >> node;
    root = makeNode(node);
    curr = root;
    // rest nodes
    for(int i = 1; i < n; i++) {
        cin >> node;
        curr->next = makeNode(node);
        
        curr = curr->next;
    }
    return root;
}


int main() {
    // create linkedlist
    LinkedList *root = createLinkedList();
    int k;
    cout << "Enter position of element to display :\n";
    cin >> k;
    displayElementAt(root, k);
    return 0;
}