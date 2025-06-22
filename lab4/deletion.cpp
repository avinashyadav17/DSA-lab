#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* ptr = head;
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = newNode;
        }
    }

    void createInitialList() {
        insertAtEnd(10);
        insertAtEnd(20);
        insertAtEnd(30);
        insertAtEnd(40);
        cout << "Initial list created:\n";
        display();
    }

    void display() {
        Node* ptr = head;
        cout << "List: ";
        while (ptr != NULL) {
            cout << ptr->data << " -> ";
            ptr = ptr->next;
        }
        cout << "NULL\n\n";
    }

    void deleteFromBeginning() {
        if (head == NULL) {
            cout << "List is empty. Nothing to delete at beginning.\n\n";
            return;
        }
        Node* ptr = head;
        head = head->next;
        delete ptr;
        cout << "Deleted node from beginning:\n";
        display();
    }

    void deleteFromEnd() {
        if (head == NULL) {
            cout << "List is empty. Nothing to delete at end.\n\n";
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = NULL;
            cout << "Deleted node from end (only one node):\n";
            display();
            return;
        }
        Node* ptr = head;
        Node* prev = NULL;
        while (ptr->next != NULL) {
            prev = ptr;
            ptr = ptr->next;
        }
        prev->next = NULL;
        delete ptr;
        cout << "Deleted node from end:\n";
        display();
    }

    void deleteAfter(int target) {
        Node* ptr = head;
        while (ptr != NULL && ptr->data != target)
            ptr = ptr->next;

        if (ptr == NULL) {
            cout << "Target node " << target << " not found.\n\n";
            return;
        }
        if (ptr->next == NULL) {
            cout << "No node exists after " << target << " to delete.\n\n";
            return;
        }
        Node* toDelete = ptr->next;
        ptr->next = toDelete->next;
        delete toDelete;
        cout << "Deleted node after " << target << ":\n";
        display();
    }

    void deleteAtPosition(int pos) {
        if (head == NULL) {
            cout << "List is empty. Nothing to delete at position " << pos << ".\n\n";
            return;
        }
        if (pos <= 0) {
            cout << "Invalid position.\n\n";
            return;
        }
        if (pos == 1) {
            deleteFromBeginning();
            return;
        }

        Node* ptr = head;
        Node* prev = NULL;
        for (int i = 1; i < pos && ptr != NULL; i++) {
            prev = ptr;
            ptr = ptr->next;
        }
        if (ptr == NULL) {
            cout << "Position " << pos << " out of range.\n\n";
            return;
        }
        prev->next = ptr->next;
        delete ptr;
        cout << "Deleted node at position " << pos << ":\n";
        display();
    }
};

int main() {
    LinkedList list;

    list.createInitialList();        // 10 -> 20 -> 30 -> 40
    list.deleteFromBeginning();      // Deletes 10
    list.deleteFromEnd();            // Deletes 40
    list.deleteAfter(20);            // Deletes 30
    list.deleteAtPosition(2);        // Invalid: only one node left

    cout << "Press Enter to exit...";
    cin.get();   // Pause to view output

    return 0;
}


 
/*
using namespace std;
struct Node {
    int data;
    Node* next;
};
Node* head = NULL;

// Create list 10->20->30->40
void createList() {
    Node* n1 = new Node{10, NULL};
    Node* n2 = new Node{20, NULL};
    Node* n3 = new Node{30, NULL};
    Node* n4 = new Node{40, NULL};
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
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

void deleteFromBeginning() {
    if (head == NULL) return;
    Node* ptr = head;
    head = head->next;
    delete ptr;
}

void deleteFromEnd() {
    if (head == NULL) return;

    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node* ptr = head;
    // Move to second last node
    while (ptr->next->next != NULL)
        ptr = ptr->next;

    delete ptr->next;
    ptr->next = NULL;
}

void deleteAfter(int target) {
    Node* ptr = head;

    while (ptr != NULL && ptr->data != target)
        ptr = ptr->next;

    if (ptr == NULL || ptr->next == NULL) {
        cout << "No node found after " << target << " to delete.\n";
        return;
    }

    Node* toDelete = ptr->next;
    ptr->next = toDelete->next;
    delete toDelete;
}

void deleteAtPosition(int pos) {
    if (pos <= 0 || head == NULL) return;

    if (pos == 1) {
        Node* ptr = head;
        head = head->next;
        delete ptr;
        return;
    }

    Node* ptr = head;
    int count = 1;
    while (ptr != NULL && count < pos - 1) {
        ptr = ptr->next;
        count++;
    }

    if (ptr == NULL || ptr->next == NULL) {
        cout << "Position " << pos << " does not exist.\n";
        return;
    }

    Node* toDelete = ptr->next;
    ptr->next = toDelete->next;
    delete toDelete;
}

int main() {
    createList();

    cout << "Original list:\n";
    display();

    deleteFromBeginning();
    cout << "\nAfter deleting from beginning:\n";
    display();

    deleteFromEnd();
    cout << "\nAfter deleting from end:\n";
    display();

    deleteAfter(20);
    cout << "\nAfter deleting node after 20:\n";
    display();

    deleteAtPosition(2);
    cout << "\nAfter deleting node at position 2:\n";
    display();

    return 0;
}*/
