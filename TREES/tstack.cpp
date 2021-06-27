
#include<iostream>
#include"tqueue.cpp"
using namespace std;

class Stack
{
private:
    int size;
    int top;
    Node **S;
public:
    Stack(){size =10;top=-1;S = new Node*[size];}
    Stack(int size){this->size = size; top =-1;S=new Node* [this->size];}
    void push(Node *);
    Node* pop();
    int isEmpty1();
    Node *StackTop();
};

void Stack :: push(Node *p)
{
    if(top==size-1)
        cout<<"stack is full"<<endl;
    else
        top++;
        S[top]=p;
}

Node* Stack :: pop()
{
    Node *x=NULL;
    if(top == -1)
    {
        cout<<"Stack is empty"<<endl;
    }
    else
    {
        x = S[top--];
    }
return x;
}

Node* Stack :: StackTop()
{
    if(top)
        return S[top];
    else
        return NULL;
}

int Stack :: isEmpty1()
{
    return top == -1;
}

