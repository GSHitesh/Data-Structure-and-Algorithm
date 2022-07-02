#include <iostream>

using namespace std;
 
class Node{
public:
    int data;
    Node* next;
};
 
class Queue{
private:
    Node* front;    // Linked list pointers
    Node* rear;
public:
    Queue();
    ~Queue();
    void enqueue(int x);
    int dequeue();
    bool isEmpty();
    void display();
};
 
Queue::Queue() {
    front = nullptr;
    rear = nullptr;
}
 
void Queue::enqueue(int x) {
    Node* t = new Node; // Creating a new node for insertion
    if (t == nullptr){
        cout << "Queue Overflow" << endl;
    } else {    // check if first is empty
        t->data = x;
        t->next = nullptr;
        if (front == nullptr){
            front = t;
            rear = t;
        } else {    // no end limit till the heap is full
            rear->next = t;
            rear = t;
        }
    }
}
 
int Queue::dequeue() {
    int x = -1;
    Node* p;
    if (isEmpty()){
        cout << "Queue Underflow" << endl;
    } else {
        p = front;  // Deletion is done from the beginning
        front = front->next;
        x = p->data;
        delete p;
    }
    return x;
}
 
bool Queue::isEmpty() {
    if (front == nullptr){
        return true;
    }
    return false;
}
 
Queue::~Queue() {   // When the object is executed then its deleted
    Node* p = front;
    while (front){
        front = front->next;
        delete p;
        p = front;
    }
}
 
void Queue::display() {
    Node* p = front;
    while (p){
        cout << p->data << flush;
        p = p->next;
        if (p != nullptr){
            cout << " <- " << flush;
        }
    }
    cout << endl;
}
 
int main() {
 
    int A[] = {1, 3, 5, 7, 9};
 
    Queue q;
 
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        q.enqueue(A[i]);
    }
 
    q.display();
 
    for (int i=0; i<sizeof(A)/sizeof(A[0]) -1; i++){
        q.dequeue();
    }
    q.dequeue();

    q.display();

    q.enqueue(5);
    q.display();
 
    return 0;
}