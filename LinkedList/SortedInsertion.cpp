#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next; 
}*first=NULL;


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

void Display(Node *p)
{
    while (p!=NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    
}

void SortedInsertion(Node *p, int value)
{
    Node *q,*t;
    t = new Node;
    t->data = value;
    t->next = NULL;

    if(first == NULL)
    {
        first = t;  //if no element is there in LL, then element will be stored in first ptr
    }

    else
    {
        q = NULL;
        while(p && p->data < value)
        {
            q = p;
            p = p->next;
        }

        if (first == p)     //Checking where p stopped is the first element, if yes then insertion on left side
        {
            t->next = first;     // t will store address of first not q
            first = t;            
        }
        
        else
        {
        t->next = q->next;      // t stores the address of the next node
        q->next = t;            // q will store the address of t
        }

    }
}

int main(int argc, char const *argv[])
{
    // int A [] = {10,20,30,40,50};

    // Create(A,5);
    SortedInsertion(first,25);
    SortedInsertion(first,15);
    SortedInsertion(first,35);
    SortedInsertion(first,5);

    Display(first);


    return 0;
}
