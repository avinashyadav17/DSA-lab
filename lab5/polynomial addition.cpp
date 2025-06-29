// Program: Simple Polynomial Addition using Linked List (easy version)
#include <iostream>
using namespace std;

struct Node {
    int coeff;
    int power;
    Node* next;
};

class Polynomial {
    Node* head;

public:
    Polynomial() {
        head = NULL;
    }

    // Insert term at the end (assumes terms inserted in descending power order)
    void insertTerm(int c, int p) {
        Node* newNode = new Node;
        newNode->coeff = c;
        newNode->power = p;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    void display() {
        if (head == NULL) {
            cout << "0\n";
            return;
        }
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->coeff << "x^" << temp->power;
            temp = temp->next;
            if (temp != NULL)
                cout << " + ";
        }
        cout << "\n";
    }

    // Add two polynomials and return the result
    static Polynomial add(Polynomial &p1, Polynomial &p2) {
        Polynomial result;
        Node* t1 = p1.head;
        Node* t2 = p2.head;

        while (t1 != NULL && t2 != NULL) {
            if (t1->power == t2->power) {
                int sumCoeff = t1->coeff + t2->coeff;
                if (sumCoeff != 0)
                    result.insertTerm(sumCoeff, t1->power);
                t1 = t1->next;
                t2 = t2->next;
            } else if (t1->power > t2->power) {
                result.insertTerm(t1->coeff, t1->power);
                t1 = t1->next;
            } else {
                result.insertTerm(t2->coeff, t2->power);
                t2 = t2->next;
            }
        }

        // Add remaining terms from p1
        while (t1 != NULL) {
            result.insertTerm(t1->coeff, t1->power);
            t1 = t1->next;
        }

        // Add remaining terms from p2
        while (t2 != NULL) {
            result.insertTerm(t2->coeff, t2->power);
            t2 = t2->next;
        }

        return result;
    }
};

int main() {
    Polynomial p1, p2;

    // Polynomial 1: 5x^3 + 4x^2 + 2
    p1.insertTerm(5, 3);
    p1.insertTerm(4, 2);
    p1.insertTerm(2, 0);

    // Polynomial 2: 3x^3 + 1x + 7
    p2.insertTerm(3, 3);
    p2.insertTerm(1, 1);
    p2.insertTerm(7, 0);

    cout << "Polynomial 1: ";
    p1.display();

    cout << "Polynomial 2: ";
    p2.display();

    Polynomial sum = Polynomial::add(p1, p2);
    cout << "Sum: ";
    sum.display();

    return 0;
}

