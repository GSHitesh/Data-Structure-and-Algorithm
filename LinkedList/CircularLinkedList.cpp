#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
} *Head = NULL;


void Create(int A[], int n)
{
    Node* t,*last;
    Head = new Node; // Imp line
    Head->data = A[0];
    Head->next = Head; // head cause can't be NULL
    last = Head;
   
    for(int i=1;i<n;i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        last->next = t; // Stores address of the next node
        last = t;
    }
}

void RDisplay(Node *p)
{
    static int flag = 0;
    if(p!=Head || flag == 0) // NO P != NULL
    {
        flag = 1;
        cout << p->data << " " << flush;
        RDisplay(p->next);
    }
    flag = 0;
}


void Display(Node *p)
{
    do
    {
        cout << p->data <<" " <<flush;
        p = p->next;
    } while (p != Head);
    
    cout << endl;
}

void Insert(Node* p, int index, int value)
{
    Node* t;
    if(index == 0)
    {        
        t = new Node;
        t->data = value;
        t->next = Head;  

        if(Head == NULL)    // If LinkedList is empty
        {
            Head = t;
            Head->next = Head;
        }

        else
        {
            while(p->next != Head)
            {
                p = p->next;
            }

            p->next = t;
            // Head = t;   // If you want to update the head
        }
    }       
    
    else
    {
        for(int i = 0; i < index - 1 && p; i++)
        {            
             p = p->next;
        }
        t = new Node;
        t->data = value;
        t->next = p->next;
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
        q = Head;
        x = Head->data;

    while(p->next != Head)
        {
            p = p->next;
        }

        p->next = Head->next;
        Head = Head->next;
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



int main()
{

    int A[] = {10,20,30,40,50};
    Create(A,5);
    // RDisplay(Head);

    Insert(Head,0,5);
    Insert(Head,4,27);

    Display(Head);

    // ////**********DELETION*************

    // // cout << DeletionLL(Head,0);
    // // cout << DeletionLL(Head,5);
    cout << DeletionLL(Head,7);

    cout << endl; 

    Display(Head);
    


    return 0;
}