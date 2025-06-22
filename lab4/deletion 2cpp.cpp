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
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
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
    list.deleteAtPosition(2);        // No node at position 2

    cout << "Press Enter to exit...";
    cin.get();   // Wait for keypress so output stays visible

    return 0;
}

