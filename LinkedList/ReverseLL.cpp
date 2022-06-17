#include <stdio.h>
#include <iostream>
#include <stdlib.h>
struct Node
{
 int data;
 struct Node *next;
}*first=NULL,*second=NULL,*third=NULL;
void Display(struct Node *p)
{
 while(p!=NULL)
 {
 printf("%d ",p->data);
 p=p->next;
 }
}
void create(int A[],int n)
{
 int i;
 struct Node *t,*last;
 first=new Node;
 first->data=A[0];
 first->next=NULL;
 last=first;

 for(i=1;i<n;i++)
 {
 t=new Node;
 t->data=A[i];
 t->next=NULL;
 last->next=t;
 last=t;
 }
}
void Reverse1(struct Node *p)
{
    Node *q =NULL,*r =NULL;
        
        while(p!=NULL)
        {
            r=q;
            q=p;
            p = p->next;
            q->next = r;
        }
        first = q;
            
}

int main(){
    
    int A [] = {10,30,30,40,50,50};

    create(A,5);
    Display(first);
    std::cout << std::endl;
    Reverse1(first);
    Display(first);


    return 0;
}