
#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;
};

class Stack
{
    private:
    Node *top;
    public:
    Stack(){top = NULL;}
    void push(int x);
    int pop();
    void display();
    int peek(int index);
    int isEmpty();
    int isFull();
    int StackTop();
};

void Stack :: push(int x)
{
    Node *t = new Node;
    if(t == NULL)
        cout<<"Stack is Full"<<endl;
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int Stack :: pop()
{
    int x = -1;
    if(top == NULL)
        cout<<"Stack is Empty:"<<endl;
    else
    {
        x = top->data;
        Node *t = new Node;
        t= top;
        top = top->next;
        delete t;
    }
    return x;
}

int Stack :: peek(int index)
{
    Node *p = top;
    for(int i=0; p!= NULL && i<index-1; i++)
    {
        p = p->next;
    }
    if(p!=NULL)
        return p->data;
    else
        return -1;
}

void Stack :: display()
{
    Node *p =top;
    while(p)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

int Stack :: StackTop()
{
    if(top)
        return top->data;
    return -1;
}

int Stack :: isEmpty()
{
    return top?0:1;
}

int Stack :: isFull()
{
    Node *t = new Node;
    int r = t?0:1;
    delete t;
    return r;
}

int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.display();
    cout<<st.isEmpty()<<endl;
    cout<<st.isFull()<<endl;
}




