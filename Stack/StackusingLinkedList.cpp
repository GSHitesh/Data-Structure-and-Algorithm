#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
}*top=NULL;

void push(int value)
{
    Node *t;
    t = new Node;
    if(t == NULL)   // Cheching if heap memory is full
        cout << "Stack is full" << endl;
    else
    {
        t->data = value;
        t->next = top;
        top = t;
    }

}

int pop()
{
    int x = -1;
    Node *t = nullptr;
    if(top) // checing top is not null
    {
        t = top;
        top = top->next;
        x = t->data;
        delete t;
    }
    else
        cout << "Underflow Condition" << endl;
    
    return x;   // returning the deleted value
}

void display()
{
    Node *t = top;
    while(t!=NULL)  // same as linked list
    {
        cout << t->data << " ";
        t = t->next;
    }

    cout << endl;
}

void peek(int pos)
{
    Node *t = top;
        for(int i=0;t!=NULL && i<pos-1;i++)
        {
            t = t->next;
        }
        if(t!=NULL)
        cout << t->data << endl;
        else    
        cout << -1 << endl;        
    
}

int main()
{

    push(10);
    push(20);
    push(30);

    // cout<< pop() << " " << pop() << endl;

    display();

    peek(47);



    return 0;
}