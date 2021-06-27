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
    Node *s1;
    Node *s2;
    Node *top;
    public:
    Stack(){s1=s2=top=NULL;}
    void push(Node *top,int x);
    int pop(Node *top);
    void display();
    void enqueue(int x);
    int dequeue();
    
};


void Stack :: enqueue(int x)
{
    push(s1,x);
}

int Stack :: dequeue()
{
    int x =-1;
    if(s1 == NULL)
    {
        if(s2 == NULL)
        {
        cout<<"stack is empty:"<<endl;
        return x;
        }
    }
    else
    {
        while(s1!= NULL)
        {
            push(s2,pop(s1));
        }
    }    return pop(s2);
}

void Stack :: push(Node *top, int x)
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

int Stack :: pop(Node *top)
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

void Stack :: display()
{
    Node *p=top;
    while(p)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

int main()
{
    Stack st;
    cout << "Enqueuing..7";
    cout << endl;
   st.enqueue( 7);
   cout << "Enqueuing..6";
   cout << endl;
   st.enqueue( 6);
   cout << "Enqueuing..2";
   cout << endl;
   st.enqueue( 2);
   cout << "Enqueuing..3";
   cout << endl;
   st.enqueue( 3);

   cout << "Dequeuing...";
   cout << st.dequeue() << " ";
   cout << endl;
   cout << "Dequeuing...";
   cout << st.dequeue() << " ";
   cout << endl;
   cout << "Dequeuing...";
   cout << st.dequeue() << " ";
   cout << endl;
}




