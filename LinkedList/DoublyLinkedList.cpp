#include <iostream>

using namespace std;

struct Node{
    Node* prev;
    int data;
    Node * next;
}*first = NULL;


void Create(int A[],int n)
{
    Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->prev = first->next = NULL;   // prev ptr
    last = first;

    for(int i=1;i<n;i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = last->next;   // changes
        last->next = t;
        last = t;

    }
}

void Display(Node *p)
{
    while (p!=NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int count(Node *p)
{
    if(p==0)
        return 0;
    else
        return count(p->next) + 1;
}

void Insert(Node* p, int index, int value)
{
    Node* t;
    if(index == 0)
    {
        t = new Node;
        t->data = value;
        t->prev = NULL; // Making the first Node prev NULL
        t->next = first;
        first->prev = t;
        first = t;
    }

    else
    {
        for(int i = 0; i < index - 1 && p; i++)
        {
            if(p!=NULL)
                p = p->next;
        }
        t = new Node;
        t->data = value;
        t->prev = p;
        t->next = p->next;
        if(p->next) // Checking if its the last Node
            p->next->prev = t;  
        p->next = t;

    }
}

int DeletionLL(Node *p, int index)
{
    int x = -1;
    Node *q = NULL;

    // if(index < 1 || index > count(p)) // count function to find length of LL
    //     return -1;

    if(index == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        delete q;
        if(first)
            first->prev = NULL;
        return x;
    }

    else
    {
        for(int i=0;i<index-1 && p;i++)
        {
            q = p;
            p = p->next;
        }
        x = p->data;
        q->next = p->next;
        if(p->next)
            p->next->prev = q;
        else
            p->next = NULL;
        delete p;
        return x;
    }

    return x;
}

int main()
{
    int A[] = {1,2,3,4,5};
    Create(A,5);
    Display(first);

    // Insert(first,7,10);
    cout << DeletionLL(first,5) << endl;

    Display(first);


    return  0;
}