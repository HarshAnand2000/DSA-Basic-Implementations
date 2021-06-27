
#include<iostream>
using namespace std;

class Queue
{
    private :
    int size; int rear; int front; int *Q;
    public:
    Queue(){size = 10; rear =front = 0; Q=new int[size];}
    Queue(int size){this->size = size; rear = front = 0; Q=new int[this->size];}
    void enqueue(int x);
    int dequeue();
    void display();
};

void Queue :: enqueue(int x)
{
    if((rear + 1) % size == front)
        cout<<"queue is full"<<endl;
    else
    {
        rear = (rear+1)%size;
        Q[rear] = x;
    }
}

int Queue :: dequeue()
{
    int x =-1;
    if(front == rear)
        cout<<"queue is empty"<<endl;
    else
    {
        front = (front+1)%size;
        x = Q[front];
    }
    return x;
}

void Queue :: display()
{
    int i =front+1;
    do 
    {
        cout<<Q[i]<<" ";
        i = (i+1)%size;
    }while(i != (rear + 1)%size);

    cout<<endl;
}

int main()
{
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60); 
    q.display();
}