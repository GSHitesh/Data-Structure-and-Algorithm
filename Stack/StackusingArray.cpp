#include <iostream>

using namespace std;

struct stack
{
    int size;
    int top;
    int *s;
};

void create(stack *st)
{
    cout << "Enter the stack size: ";
    cin >> st->size;
    st->s = new int[st->size];
    st->top = -1;
}

void display(stack st)
{
    for(int i=st.top;i>=0;i--)
    {
        cout << st.s[i] << " ";
    }
    cout << endl;
}

void push(stack *st,int x)
{
    if(st->top == st->size-1)
        cout << "Condition Overflow";
    else
    {
        st->top++;
        st->s[st->top] = x;
    }
}

int pop(stack *st)  //ptr -> call by reference, updating the stack
{
    int x=-1;
    if(st->top == -1) 
        cout << "Condition Underflow";
    else
    {
        x = st->s[st->top];
        st->top--;
    }
    return x;
}

bool isEmpty(stack st)
{
    if(st.top == -1)
        return -1;
    else    
        return 0;
}

bool isFull(stack st)
{
    if(st.top == st.size-1)
        return -1;
    else
        return 0;
}

int peek(stack st, int pos)
{
    int x = -1;
    if(pos < 0 || pos > st.size)
        cout << "Invalid Index" << endl;
    else
    {
        x = st.s[st.top-pos+1];
    }
    
    return x;
}

int main()
{
    stack st;

    create(&st);
    
    push(&st,10);
    push(&st,20);
    push(&st,30);
    push(&st,40);
    push(&st,50);

    // cout << pop(&st) << endl;
    // cout << pop(&st) << endl;
    // cout << pop(&st) << endl;
    // cout << pop(&st) << endl;

    cout << "Empty: " << isEmpty(st) << endl;
    cout << "Full: " << isFull(st) << endl;

    cout << peek(st,3) << endl;
     display(st);


    return 0;
}  