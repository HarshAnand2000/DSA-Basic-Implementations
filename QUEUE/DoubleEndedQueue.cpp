
#include<iostream>
using namespace std;
class DEQueue
{
private:
    int size;
    int rear;
    int front;
    int *Q;
public:
    DEQueue(){size = 10;rear = front = -1; Q=new int[size];}
    DEQueue(int size) {this->size = size; rear=front = -1;Q= new int[this->size];}
    void insert_at_beg(int );
    void insert_at_end(int x);
    int Delete_fr_front();
    int Delete_fr_end();
    void Display();
};

void DEQueue :: insert_at_end(int x)
{
    if(rear >= size-1)
        cout<<"Queue is full"<<endl;
    else
    {
        if(front == -1)
        {
            front++;
            rear++;
        }
        else
        {
            rear++;
        }
        Q[rear] = x;
    }
}

void DEQueue ::insert_at_beg(int x)
{
    if(front == -1)
    {
        front = 0;
        Q[++rear] = x;
    }
    else if(front != 0)
    {
        Q[--front] = x;
    }   
    else
        cout<<"Queue is full"<<endl; 
}

int DEQueue :: Delete_fr_front()
{
    int x=-1;
    if(front == -1)
        cout<<"Queue is Empty"<<endl;
    else
    {
        if(front == rear)
        {
            front = rear = -1;
            return x; 
        }
        else
            front++;
            x = Q[front];
    }
    return x;
}

int DEQueue ::Delete_fr_end()
{
    int x =-1;
    if(front == rear)
        cout<<"Queue is empty"<<endl;
    else
    {
        if(front == rear)
        {
            front = rear = -1;
        }
        else
        {
            rear--;
            x = Q[rear];
        }
        return rear;
    }
}

void DEQueue :: Display()
{
    for(int i = front; i<=rear;i++)
        cout<<Q[i]<<" ";
}

int main()
{
    DEQueue q;
    //q.Delete_fr_front();
    //q.Delete_fr_end();
    q.insert_at_beg(10);
    q.insert_at_end(20);
    q.insert_at_end(10);
    q.Delete_fr_end();
    q.Display();



return 0;
}