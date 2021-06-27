
#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
}*front = NULL,*rear =  NULL;

void enqueue(int x)
{
    Node *t;
    t = new Node;
    if(t==NULL)
        cout<<"queue if full"<<endl;
    else
    {
        t->data = x;
        t->next = NULL;
        if(front == NULL)
            front = rear = t;
        else
        {
            rear->next = t;
            rear = t;
        }
    }

}

int dequeue()
{
    int x =-1;
    Node *t;

    if(front == NULL)
        cout<<"queue is empty"<<endl;
    else
    {
        x = front->data;
        t = front;
        front = front->next;
        delete t;
    }
    return x;
}

int isEmpty()
{
    return front ==NULL;
}

