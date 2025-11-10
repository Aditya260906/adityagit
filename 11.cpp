#include <iostream>
using namespace std;

//used char array
#define SIZE 5
char cq[SIZE];
int front = -1, rear = -1;

bool isFull() {
    return ((front == 0 && rear == SIZE-1) || (rear + 1 == front));
}

bool isEmpty() {
    return (front == -1);
}

void insertQ() {
    if(isFull()) {
        cout << "Overflow\n";
        return;
    }
    char x;
    cout << "Enter character: ";
    cin >> x;

    if(front == -1) front = rear = 0;
    else if(rear == SIZE-1) rear = 0;
    else rear++;

    cq[rear] = x;
    cout << "Inserted.\n";
}

void deleteQ() {
    if(isEmpty()) {
        cout << "Underflow\n";
        return;
    }

    cout << "Deleted: " << cq[front] << endl;

    if(front == rear) front = rear = -1;
    else if(front == SIZE-1) front = 0;
    else front++;
}

void display() {
    if(isEmpty()) {
        cout << "Queue is Empty\n";
        return;
    }

    cout << "Queue: ";
    int i = front;
    while(i != rear) {
        cout << cq[i] << " ";
        i = (i + 1) % SIZE; // vvvvimp 
        // i = (i + 1) % size;
        // i = (i + 1) % size;
        // i = (i + 1) % size;
        // i = (i + 1) % size;
    }
    cout << cq[rear] << endl;
}

int main() {
    int ch;
    do {
        cout << "\n1.Insert 2.Delete 3.Display 4.Exit\nChoice: ";
        cin >> ch;

        if(ch == 1) insertQ();
        if(ch == 2) deleteQ();
        if(ch == 3) display();

    } while(ch != 4);

    return 0;
}
