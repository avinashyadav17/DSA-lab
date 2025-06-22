//using curcukar queue 
#include <iostream>
using namespace std;

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    if ((front == 0 && rear == SIZE - 1) || (rear + 1 == front)) {
        cout << "Queue is full!\n";
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else if (rear == SIZE - 1 && front != 0) {
        rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }

    queue[rear] = value;
    cout << "Inserted: " << value << endl;
}

void dequeue() {
    if (front == -1) {
        cout << "Queue is empty!\n";
        return;
    }

    cout << "Deleted: " << queue[front] << endl;

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

void display() {
    if (front == -1) {
        cout << "Queue is empty!\n";
        return;
    }

    cout << "Queue: ";
    int i = front;
    while (true) {
        cout << queue[i] << " ";
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    cout << endl;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);  // Queue becomes full here
    display();

    dequeue();
    dequeue();
    display();

    enqueue(60);  // Can insert because of circular behavior
    enqueue(70);
    display();

    return 0;
}

