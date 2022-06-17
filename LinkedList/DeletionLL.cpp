#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

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
        delete p;
        return x;
    }

    return x;
}

void Display(Node *p)
{
    while (p!=NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    
}



int main(int argc, char const *argv[])
{
    int A [] = {10,20,30,40,50};

    Create(A,5);
    cout << "Before Deletion: ";
    Display(first);

    cout << "\nDeleted Value: " << DeletionLL(first,1) << "\n";

    cout << "After Deletion: ";
    Display(first);

    cout << "\nDeleted Value: " << DeletionLL(first,3) << "\n";

    cout << "After Deletion: ";
    Display(first);

    return 0;
}
