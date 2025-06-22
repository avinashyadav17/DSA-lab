 //3.c . Delete from Front (Remove from beginning)
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

    void insertRear(int value) {  // helper to insert so we can delete
        if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
            cout << "Deque is full, can't insert at rear\n";
            return;
        }
        if (front == -1) {
            front = rear = 0;
        } else if (rear == SIZE - 1) {
            rear = 0;
        } else {
            rear++;
        }
        arr[rear] = value;
    }

    void deleteFront() {
        if (front == -1) {
            cout << "Deque is empty, can't delete from front\n";
            return;
        }
        cout << "Deleted from front: " << arr[front] << endl;
        if (front == rear) {
            front = rear = -1;
        } else if (front == SIZE - 1) {
            front = 0;
        } else {
            front++;
        }
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

    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertRear(30);
    dq.display();

    dq.deleteFront();
    dq.display();

    dq.deleteFront();
    dq.display();

    return 0;
}

