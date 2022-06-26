#include <iostream>

using namespace std;

class Queue
{
private:
    int size;
    int rear;
    int front;
    int *Q;
public:
    Queue();
    Queue(int size);
    void enqueue(int x);
    int dequeue();
    void display();
    int Front();
    int last();
    ~Queue();
};

Queue::Queue()
{
    front = rear = -1;
    size = 10;
    this->Q = new int[size];
}

Queue::Queue(int size)
{
    front = rear = -1;
    this->Q = new int[this->size];
}

void Queue::enqueue(int x)
{
    if(rear == size-1)
        cout << "Queue is Full" << endl;
    else{
        rear++;
        Q[rear] = x;
    }
}

int Queue::dequeue()
{
    int x = -1;
    if(front == rear)
        cout << "Queue is Empty" << endl;
    else{
        front++;
        x = Q[front];

    }
    return x;
}

void Queue::display()
{
    for(int i = front+1;i<=rear;i++){
        cout << Q[i] << " ";
    }
    cout << endl;
}

int Queue::Front(){
    return Q[front+1];
}

int Queue::last(){
    return Q[rear];
}

Queue::~Queue()
{
}



int main(){

    Queue q(15);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.display();

    cout << q.Front() << " " << q.last() << endl;
    cout << q.dequeue() << " ";
    cout << q.dequeue() << endl;

    

    q.display();
    return 0;
}