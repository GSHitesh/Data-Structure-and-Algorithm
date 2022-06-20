#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next; 
}*first=NULL,*second = NULL, *third = NULL;


void Create(int A[],int n)
{
    Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(int i=1;i<n;i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;

    }
}

void Create2(int A[],int n) // new function is required to create a new LL
{
    Node *t, *last;
    second = new Node;
    second->data = A[0];
    second->next = NULL;
    last = second;

    for(int i=1;i<n;i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;

    }
}

void display(Node *p)
{
    while(p!=NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout <<  endl;
}


void Concatenate(Node *p,Node *r)   // two arguments or one argument parameter can be implemented
{
    Node *q = NULL;
    while(p!= NULL)
    {
        q = p;
        p = p->next;
    }
    q->next = r;
    
}

// Merges two sorted linked list
Node* Merge(Node *p, Node *q)
{
    Node * last;
    if(p->data < q->data)
    {
        third = last =  p;
        p = p->next;
        last->next = NULL;
    }
    else
    {
        third = last =  q;
        q = q->next;
        last->next = NULL;
    }
 
    while(p && q) //p!= NULL && q!= NULL
    {
        if(p->data < q->data)
        {
            last->next = p; // Null Address is replaced with p
            last = p;   //last points to p
            p = p->next;
            last->next = NULL;

        }

        else
        {
            last->next = q; // Null Address is replaced with q
            last = q;   //last points to q
            q = q->next;
            last->next = NULL;
        }
    }

    if(p) last->next = p;
    if(q) last->next = q;

    return third;
}


int main(int argc, char const *argv[])
{
    int A [] = {10,30,50,50,50};
    int B [] = {20,40,70,70,70,78,79,80};

    Create(A,5);    // Mention correct length of LL, for correct results
    Create2(B,8);
    
    // display(first);

    // Concatenate(first,second);

    Node *C = Merge(first,second);
    display(C);

    // display(first);
   

    return 0;
}
