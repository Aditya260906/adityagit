#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = nullptr;
    }
};

Node* last = nullptr; //vvvimp

void create() {
    int n, x;
    cout << "Enter number of nodes: ";
    cin >> n;

    for(int i=0; i<n; i++) {
        cout << "Enter value: ";
        cin >> x;

        Node* temp = new Node(x);

        if(last == nullptr) {              // first node
            last = temp;
            last->next = last;
        } else {                           // insert at end
            temp->next = last->next;
            last->next = temp;
            last = temp;
        }
    }
    cout << "List Created.\n";
}

void display() {
    if(last == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    Node* p = last->next;
    cout << "List: ";
    do {
        cout << p->data << " ";
        p = p->next;
    } while(p != last->next);
    cout << endl;
}

void insertNode() {
    int x;
    cout << "Enter value to insert: ";
    cin >> x;

    Node* temp = new Node(x);

    if(last == nullptr) {
        last = temp;
        last->next = last;
    } else {
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
    cout << "Inserted.\n";
}

void search() {
    if(last == nullptr) {
        cout << "List Empty.\n";
        return;
    }

    int x;
    cout << "Enter value to search: ";
    cin >> x;

    Node* p = last->next;
    do {
        if(p->data == x) {
            cout << "Found.\n";
            return;
        }
        p = p->next;
    } while(p != last->next);

    cout << "Not Found.\n";
}

int main() {
    int ch;
    do {
        cout << "\n1.Create 2.Display 3.Insert 4.Search 5.Exit\nChoice: ";
        cin >> ch;

        if(ch == 1) create();
        if(ch == 2) display();
        if(ch == 3) insertNode();
        if(ch == 4) search();

    } while(ch != 5);

    return 0;
}
