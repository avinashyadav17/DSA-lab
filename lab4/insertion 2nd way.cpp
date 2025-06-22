#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Create initial list 10 -> 20 -> 30
void createList() {
    Node* n1 = new Node{10, NULL};
    Node* n2 = new Node{20, NULL};
    Node* n3 = new Node{30, NULL};
    n1->next = n2;
    n2->next = n3;
    head = n1;
}

void display() {
    Node* ptr = head;
    while (ptr != NULL) {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
    cout << "NULL\n";
}

void insertAtBeginning(int val) {
    Node* ptr = new Node{val, head};
    head = ptr;
}

void insertAtEnd(int val) {
    Node* ptr = head;
    while (ptr->next != NULL)
        ptr = ptr->next;
    Node* newNode = new Node{val, NULL};
    ptr->next = newNode;
}

void insertAfter(int target, int val) {
    Node* ptr = head;
    while (ptr != NULL && ptr->data != target)
        ptr = ptr->next;
    if (ptr == NULL) {
        cout << "Target " << target << " not found.\n";
        return;
    }
    Node* newNode = new Node{val, ptr->next};
    ptr->next = newNode;
}

void insertBefore(int target, int val) {
    if (head == NULL) return;
    if (head->data == target) {
        insertAtBeginning(val);
        return;
    }
    Node* ptr = head;
    while (ptr->next != NULL && ptr->next->data != target)
        ptr = ptr->next;
    if (ptr->next == NULL) {
        cout << "Target " << target << " not found.\n";
        return;
    }
    Node* newNode = new Node{val, ptr->next};
    ptr->next = newNode;
}

void insertAtPosition(int pos, int val) {
    if (pos <= 0) {
        cout << "Invalid position\n";
        return;
    }
    if (pos == 1) {
        insertAtBeginning(val);
        return;
    }
    Node* ptr = head;
    for (int i = 1; i < pos - 1 && ptr != NULL; i++)
        ptr = ptr->next;
    if (ptr == NULL) {
        cout << "Position " << pos << " out of range\n";
        return;
    }
    Node* newNode = new Node{val, ptr->next};
    ptr->next = newNode;
}

int main() {
    createList();

    cout << "Initial list:\n";
    display();

    insertAtBeginning(5);
    cout << "\nAfter insertion at beginning (5):\n";
    display();

    insertAtEnd(40);
    cout << "\nAfter insertion at end (40):\n";
    display();

    insertAfter(20, 25);
    cout << "\nAfter insertion of 25 after 20:\n";
    display();

    insertBefore(10, 7);
    cout << "\nAfter insertion of 7 before 10:\n";
    display();

    insertAtPosition(4, 15);
    cout << "\nAfter insertion of 15 at position 4:\n";
    display();

    return 0;
}

