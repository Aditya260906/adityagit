#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;
    Node(int d){
        data=d;
        next=NULL;
        prev=NULL;
    }
};

Node* head=NULL;

void create(){
    int n,x; cout<<"Enter nodes: "; cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        Node* temp=new Node(x);
        if(head==NULL) head=temp;
        else{
            Node* p=head;
            while(p->next) p=p->next;
            p->next=temp;
            temp->prev=p;
        }
    }
}

void display(){
    if(!head){ cout<<"Empty\n"; return;}
    Node* p=head;
    while(p){ cout<<p->data<<" "; p=p->next; }
    cout<<endl;
}

void insertNode(){
    int x; cin>>x;
    Node* temp=new Node(x);
    if(head==NULL) head=temp;
    else{
        Node* p=head;
        while(p->next) p=p->next;
        p->next=temp;
        temp->prev=p;
    }
}

void searchNode(){
    int x; cin>>x;
    Node* p=head;
    while(p){
        if(p->data==x){ cout<<"Found\n"; return;}
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
