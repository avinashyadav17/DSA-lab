//1. Perform enqueue and dequeue operations in Linear Queue
#include <iostream>
using namespace std;

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == SIZE - 1) {
        cout << "Queue is full!\n";
        return;
    }
    if (front == -1) front = 0;
    rear++;
    queue[rear] = value;
    cout << "Inserted: " << value << endl;
}

void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue is empty!\n";
        return;
    }
    cout << "Deleted: " << queue[front] << endl;
    front++;
}

void display() {
    if (front == -1 || front > rear) {
        cout << "Queue is empty!\n";
        return;
    }
    cout << "Queue: ";
    for (int i = front; i <= rear; i++) {
        cout << queue[i] << " ";
    }
    cout << endl;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    enqueue(40);
    enqueue(50);
    enqueue(60);  // Should show full
    display();
    return 0;
}

