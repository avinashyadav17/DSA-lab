//3. Perform operations in Deque( Double ended queue) for:
//a. Add at beginning
#include <iostream>
using namespace std;

#define SIZE 5

class Deque {
    int arr[SIZE];
    int front, rear;

public:
    Deque() {
        front = -1; rear = -1;
    }

    void insertFront(int value) {
        if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
            cout << "Deque is full, can't insert at front\n";
            return;
        }
        if (front == -1) {
            front = rear = 0;
        } else if (front == 0) {
            front = SIZE - 1;
        } else {
            front--;
        }
        arr[front] = value;
        cout << "Inserted at front: " << value << endl;
    }

    void display() {
        if (front == -1) {
            cout << "Deque is empty\n";
            return;
        }
        cout << "Deque: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    Deque dq;

    dq.insertFront(10);
    dq.insertFront(20);
    dq.insertFront(30);
    dq.display();

    return 0;
}

