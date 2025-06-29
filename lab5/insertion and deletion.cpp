#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev, *next;
};

Node* head = NULL;

// Insert at beginning
void insertAtBeginning(int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL)
        head->prev = newNode;
    head = newNode;
}

// Insert at end
void insertAtEnd(int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* ptr = head;
    while (ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = newNode;
    newNode->prev = ptr;
}

// Insert after specific node
void insertAfter(int val, int sp_val) {
    Node* ptr = head;
    while (ptr != NULL && ptr->data != sp_val)
        ptr = ptr->next;

    if (ptr == NULL) {
        cout << "Value not found.\n";
        return;
    }

    Node* newNode = new Node;
    newNode->data = val;
    newNode->prev = ptr;
    newNode->next = ptr->next;

    if (ptr->next != NULL)
        ptr->next->prev = newNode;

    ptr->next = newNode;
}

// Insert before specific node
void insertBefore(int val, int sp_val) {
    Node* ptr = head;
    while (ptr != NULL && ptr->data != sp_val)
        ptr = ptr->next;

    if (ptr == NULL) {
        cout << "Value not found.\n";
        return;
    }

    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = ptr;
    newNode->prev = ptr->prev;

    if (ptr->prev != NULL)
        ptr->prev->next = newNode;
    else
        head = newNode;

    ptr->prev = newNode;
}

// Delete from beginning
void deleteFromBeginning() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    delete temp;
}

// Delete from end
void deleteFromEnd() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* ptr = head;
    while (ptr->next != NULL)
        ptr = ptr->next;

    if (ptr->prev != NULL)
        ptr->prev->next = NULL;
    else
        head = NULL;

    delete ptr;
}

// Delete after specific node
void deleteAfter(int sp_val) {
    Node* ptr = head;
    while (ptr != NULL && ptr->data != sp_val)
        ptr = ptr->next;

    if (ptr == NULL || ptr->next == NULL) {
        cout << "Cannot delete after given node.\n";
        return;
    }

    Node* temp = ptr->next;
    ptr->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = ptr;

    delete temp;
}

// Delete before specific node
void deleteBefore(int sp_val) {
    Node* ptr = head;
    while (ptr != NULL && ptr->data != sp_val)
        ptr = ptr->next;

    if (ptr == NULL || ptr->prev == NULL) {
        cout << "Cannot delete before given node.\n";
        return;
    }

    Node* temp = ptr->prev;

    if (temp->prev != NULL)
        temp->prev->next = ptr;
    else
        head = ptr;

    ptr->prev = temp->prev;

    delete temp;
}

// Display in arrow format
void display() {
    Node* ptr = head;

    if (ptr == NULL) {
        cout << "List is empty.\n";
        return;
    }

    cout << "List: NULL";
    while (ptr != NULL) {
        cout << " <- " << ptr->data;
        if (ptr->next != NULL)
            cout << " <->";
        ptr = ptr->next;
    }
    cout << " -> NULL\n";
}

// Main menu
int main() {
    int choice, val, sp_val;

    do {
        cout << "\n--- Doubly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After a Specific Node\n";
        cout << "4. Insert Before a Specific Node\n";
        cout << "5. Delete from Beginning\n";
        cout << "6. Delete from End\n";
        cout << "7. Delete After a Specific Node\n";
        cout << "8. Delete Before a Specific Node\n";
        cout << "9. Display List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                insertAtBeginning(val);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> val;
                insertAtEnd(val);
                break;

            case 3:
                cout << "Enter value to insert: ";
                cin >> val;
                cout << "Insert after which specific value? ";
                cin >> sp_val;
                insertAfter(val, sp_val);
                break;

            case 4:
                cout << "Enter value to insert: ";
                cin >> val;
                cout << "Insert before which specific value? ";
                cin >> sp_val;
                insertBefore(val, sp_val);
                break;

            case 5:
                deleteFromBeginning();
                break;

            case 6:
                deleteFromEnd();
                break;

            case 7:
                cout << "Delete node after which specific value? ";
                cin >> sp_val;
                deleteAfter(sp_val);
                break;

            case 8:
                cout << "Delete node before which specific value? ";
                cin >> sp_val;
                deleteBefore(sp_val);
                break;

            case 9:
                display();
                break;

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}

