#include <iostream>
using namespace std;

#define SIZE 5

class Deque {
    int arr[SIZE];
    int front, rear;

public:
    Deque() {
        front = -1;
        rear = -1;
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

    void insertRear(int value) {
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
        cout << "Inserted at rear: " << value << endl;
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

    void deleteRear() {
        if (front == -1) {
            cout << "Deque is empty, can't delete from rear\n";
            return;
        }
        cout << "Deleted from rear: " << arr[rear] << endl;
        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = SIZE - 1;
        } else {
            rear--;
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
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    Deque dq;

    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(5);
    dq.insertFront(2);
    dq.display();

    dq.deleteFront();
    dq.deleteRear();
    dq.display();

    dq.insertRear(30);
    dq.insertFront(1);
    dq.display();

    return 0;
}

