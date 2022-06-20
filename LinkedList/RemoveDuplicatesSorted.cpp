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

void display(Node *p)
{
    while(p!=NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout <<  endl;
}

void RemoveDuplicates(Node *p)
{
    Node *q = p->next;

    while (q!= NULL)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            delete q;
            q = p->next;    // stores the address the of the next node of the equal node
            //we have deleted the node not the entire LL 
            // q = p is wrong
        }
        
    }
    
}


int main(int argc, char const *argv[])
{
    int A [] = {10,30,30,40,50,50};

    Create(A,5);
    display(first);
    RemoveDuplicates(first);
    display(first);
   

    return 0;
}
