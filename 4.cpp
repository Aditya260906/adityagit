#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int d){
        data=d;
        next=NULL;
    }
};

Node* head=NULL;

void create(){
    int n,x;
    cout<<"Enter number of nodes: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter value: ";
        cin>>x;
        Node* temp=new Node(x);
        if(head==NULL) head=temp;
        else{
            Node* p=head;
            while(p->next!=NULL) p=p->next;
            p->next=temp;
        }
    }
}

void display(){
    Node* p=head;
    if(!p){ cout<<"List empty\n"; return; }
    while(p){ cout<<p->data<<" "; p=p->next; }
    cout<<endl;
}

void insertNode(){
    int x;
    cout<<"Enter value to insert: ";
    cin>>x;
    Node* temp=new Node(x);
    if(head==NULL) head=temp;
    else{
        Node* p=head;
        while(p->next!=NULL) p=p->next;
        p->next=temp;
    }
}

void searchNode(){
    int x; cout<<"Enter value: "; cin>>x;
    Node* p=head;
    while(p){
        if(p->data==x){ cout<<"Found\n"; return; }
        p=p->next;
    }
    cout<<"Not Found\n";
}

int main(){
    int ch;
    do{
        cout<<"\n1.Create 2.Display 3.Insert 4.Search 5.Exit\nChoice: ";
        cin>>ch;
        if(ch==1) create();
        if(ch==2) display();
        if(ch==3) insertNode();
        if(ch==4) searchNode();
    }while(ch!=5);
}
