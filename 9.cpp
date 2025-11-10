#include <iostream>
using namespace std;

#define SIZE 5
int q[SIZE];
int front = 0, rear = -1;

bool isFull() {
    return rear == SIZE - 1;
}

bool isEmpty() {
    return front > rear;
}

void insertQ() {
    if(isFull()) {
        cout << "Overflow\n";
        return;
    }
    int x;
    cout << "Enter value: ";
    cin >> x;
    q[++rear] = x;
    cout << "Inserted.\n";
}

void deleteQ() {
    if(isEmpty()) {
        cout << "Underflow\n";
        return;
    }
    cout << "Deleted: " << q[front] << endl;
    front++;
}

void display() {
    if(isEmpty()) {
        cout << "Queue is Empty\n";
        return;
    }
    cout << "Queue: ";
    for(int i = front; i <= rear; i++)
        cout << q[i] << " ";
    cout << endl;
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
