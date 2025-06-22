#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int val) {
        data = val;
        next = NULL;
    }
};

class list {
    node* head;
    node* tail;

public:
    list() {
        head = tail = NULL;
    }

    void push_front(int val) {
        node* newnode = new node(val);

        if (head == NULL) {
            head = tail = newnode;
            return;
        }

        newnode->next = head;
        head = newnode;
    }

    void display() {
        node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    list ll;
    ll.push_front(10);
    ll.push_front(20);
    ll.push_front(30);

    ll.display();

    return 0;
}
/*#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int val) {
        data = val;
        next = NULL;
    }
};

class list {
    node* head;
    node* tail;

public:
    list() {
        head = tail = NULL;
    }

    // Add at the front
    void push_front(int val) {
        node* newnode = new node(val);
        if (head == NULL) {
            head = tail = newnode;
        } else {
            newnode->next = head;
            head = newnode;
        }
    }

    // Remove from back
    void pop_back() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        if (head == tail) {
            delete head;
            head = tail = NULL;
            return;
        }

        node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = NULL;
    }

    // Insert after a specific value
    void insert_after(int val, int key) {
        node* temp = head;
        while (temp != NULL && temp->data != key) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Key not found!" << endl;
            return;
        }

        node* newnode = new node(val);
        newnode->next = temp->next;
        temp->next = newnode;

        if (temp == tail) {
            tail = newnode;
        }
    }

    // Search a value
    bool search(int key) {
        node* temp = head;
        while (temp != NULL) {
            if (temp->data == key) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Display the list
    void display() {
        node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    list ll;

    ll.push_front(10);
    ll.push_front(20);
    ll.push_front(30);

    cout << "Initial List: ";
    ll.display();

    cout << "After inserting 25 after 30: ";
    ll.insert_after(25, 30);
    ll.display();

    cout << "After popping from back: ";
    ll.pop_back();
    ll.display();

    int key = 20;
    if (ll.search(key)) {
        cout << "Value " << key << " found in the list." << endl;
    } else {
        cout << "Value " << key << " not found." << endl;
    }

    return 0;
}*/

