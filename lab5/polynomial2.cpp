#include <iostream>
using namespace std;

struct Node {
    int coeff, exp;
    Node* next;
};

// Function to create new node
Node* newnode(int c, int e) {
    Node* temp = new Node;
    temp->coeff = c;
    temp->exp = e;
    temp->next = NULL;
    return temp;
}

// Function to display a polynomial
void display(Node* head) {
    while (head != NULL) {
        cout << head->coeff << "x^" << head->exp;
        if (head->next != NULL)
            cout << " + ";
        head = head->next;
    }
    cout << endl;
}

// Function to add two polynomials
Node* poly_add(Node* poly1, Node* poly2) {
    Node *ptr1 = poly1, *ptr2 = poly2;
    Node *poly = NULL, *ptr = NULL;

    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->exp > ptr2->exp) {
            Node* temp = newnode(ptr1->coeff, ptr1->exp);
            if (poly == NULL) {
                poly = ptr = temp;
            } else {
                ptr->next = temp;
                ptr = ptr->next;
            }
            ptr1 = ptr1->next;
        } else if (ptr1->exp < ptr2->exp) {
            Node* temp = newnode(ptr2->coeff, ptr2->exp);
            if (poly == NULL) {
                poly = ptr = temp;
            } else {
                ptr->next = temp;
                ptr = ptr->next;
            }
            ptr2 = ptr2->next;
        } else {
            int sum = ptr1->coeff + ptr2->coeff;
            Node* temp = newnode(sum, ptr1->exp);
            if (poly == NULL) {
                poly = ptr = temp;
            } else {
                ptr->next = temp;
                ptr = ptr->next;
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }

    // If any terms left in poly1
    while (ptr1 != NULL) {
        Node* temp = newnode(ptr1->coeff, ptr1->exp);
        ptr->next = temp;
        ptr = ptr->next;
        ptr1 = ptr1->next;
    }

    // If any terms left in poly2
    while (ptr2 != NULL) {
        Node* temp = newnode(ptr2->coeff, ptr2->exp);
        ptr->next = temp;
        ptr = ptr->next;
        ptr2 = ptr2->next;
    }

    return poly;
}

// Main
int main() {
    // Creating first polynomial: 5x^3 + 4x^2 + 2
    Node *poly1 = newnode(5, 3);
    poly1->next = newnode(4, 2);
    poly1->next->next = newnode(2, 0);

    // Creating second polynomial: 3x^3 + 2x^1 + 1
    Node *poly2 = newnode(3, 3);
    poly2->next = newnode(2, 1);
    poly2->next->next = newnode(1, 0);

    cout << "Polynomial 1: ";
    display(poly1);
    cout << "Polynomial 2: ";
    display(poly2);

    Node* result = poly_add(poly1, poly2);
    cout << "Resultant Polynomial: ";
    display(result);

    return 0;
}

