#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int d) {
        data = d;
        next = nullptr;
        prev = nullptr;
    }
};

Node* head = nullptr;

void createList() {
    int n, x;
    cout << "Enter number of nodes: ";
    cin >> n;

    for(int i = 0; i < n; i++){
        cout << "Enter value: ";
        cin >> x;

        Node* newNode = new Node(x);

        if(head == nullptr) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while(temp->next != nullptr) temp = temp->next;

            temp->next = newNode;
            newNode->prev = temp;
        }
    }
    cout << "List Created.\n";
}

void displayList() {
    if(head == nullptr) {
        cout << "List Empty\n";
        return;
    }

    Node* temp = head;
    cout << "List: ";
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void searchNode() {
    if(head == nullptr) {
        cout << "List Empty\n";
        return;
    }

    int x;
    cout << "Enter value to search: ";
    cin >> x;

    Node* temp = head;
    while(temp != nullptr) {
        if(temp->data == x) {
            cout << "Found\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Not Found\n";
}

void deleteNode() {
    if(head == nullptr) {
        cout << "List Empty\n";
        return;
    }

    int x;
    cout << "Enter value to delete: ";
    cin >> x;

    Node* temp = head;
    while(temp != nullptr && temp->data != x)
        temp = temp->next;

    if(temp == nullptr) {
        cout << "Not Found\n";
        return;
    }

    // deleting head
    if(temp->prev == nullptr) {
        head = temp->next;
        if(head != nullptr) head->prev = nullptr;
    }
    // deleting last
    else if(temp->next == nullptr) {
        temp->prev->next = nullptr;
    }
    // deleting middle
    else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    delete temp;
    cout << "Deleted\n";
}

int main() {
    int ch;
    do {
        cout << "\n1.Create 2.Display 3.Delete 4.Search 5.Exit\nChoice: ";
        cin >> ch;

        if(ch==1) createList();
        if(ch==2) displayList();
        if(ch==3) deleteNode();
        if(ch==4) searchNode();

    } while(ch != 5);

    return 0;
}
