#include <iostream>
using namespace std;
class Node {
public:
    int data;
    struct Node *next;
    Node(int x)
    {data=x;}
};
Node *front = NULL;
Node *rear = NULL;
void enqueue(int a){
    Node *b = new Node(a);
    if(rear == nullptr){
        rear = b;
        rear->next= nullptr;
        front = b;
    }
    else{
        rear->next = b;
        b->next = nullptr;
        rear = b;
    }
} void dequeue(){
    Node *c = front;
    if(front== nullptr)
        cout<<"Empty"<<endl;
    else{
        if(c->next != nullptr){
            cout<<"Deleted: "<<c->data<<endl;
            c = c->next;
            ::free(front);
            front = c;
        }
        else{
            front= nullptr;
            rear = nullptr;
        }
    }

};
int top(){
    if(front== nullptr)
        cout<<"Queue is empty";
    else
        return front->data;
}
bool isEmpty(){
    Node *tmp = front;
    if(tmp == nullptr)
        return true;
    else{
        return false;
    }

}

int size(){
    int size = 0;
    if(front == nullptr)
        cout<<"Queue is empty "<<endl;
    else{
        Node *temp = front;
        while(temp != nullptr){
            temp = temp->next;
            size++;
        }
    }
    return size;
}

int main(){
    enqueue(5);
    enqueue(8);
    enqueue(9);
    enqueue(11);
    enqueue(21);
    enqueue(55);
    enqueue(35);


    cout<<"Queue before dequeued"<<endl;

    Node *t = front;
    do {
        cout<<t->data<<" ";
        t= t->next;

    }
    while(t != nullptr);
    cout<<endl;

    dequeue();

    cout<<"Queue after dequeued"<<endl;
    Node *l = front;
    do {
        cout<<l->data<<" ";
        l= l->next;

    }
    while(l != nullptr);
    cout<<endl;



    cout<<"top() function"<<endl;
    cout<<top()<<endl;

    cout<<"isEmpty() function"<<endl;
    cout<<isEmpty()<<endl;

    cout<<"size() function"<<endl;
    cout<<size();



}