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

void RDisplay(Node *p){
    if(p!= NULL)
    {
        cout << p->data << " ";
        RDisplay(p->next);
    }
}

int Add(Node *p)
{
    int sum = 0;
    while(p)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int count(Node *p)
{
    if(p==0)
        return 0;
    else
        return count(p->next) + 1;
}

int MaxElement(Node *p)
{
    int max = INT_MIN; //p->data 
    while (p!=NULL)
    {
        if(max < p->data)
            max = p->data;
        p = p->next;

    }
    return max;
    
}

Node * Search(Node *p,int key)
{
    Node *q = NULL;
    while (p!=NULL)
    {
        if(p->data == key)
        {
            q->next = p->next;
            p->next = first;
            first = p;   
            return p;         
        }
        q = p;
        p = p->next;
    }
    return NULL;
    
}

int main(int argc, char const *argv[])
{
    int A[] = {1,2,3,4,5};
    Create(A,5);
    RDisplay(first);
    cout << "\nSum: " << Add(first) << "\n";
    cout << "Count: " << count(first) << "\n";
    cout << "Max Element: " << MaxElement(first) << "\n";

    Node* temp;
    temp = Search(first,3);

    if(temp)
        cout << "Found: " << temp->data << endl;
    else
        cout << "Not Found \n";

    RDisplay(first);
    return 0;
}

