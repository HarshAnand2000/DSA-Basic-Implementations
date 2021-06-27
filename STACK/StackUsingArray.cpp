
#include<iostream>
using namespace std;

class Stack
{
    private:
    int size;
    int top;
    int *st;

    public:
    Stack(){size = 10; top = -1; st = new int[size];}
    Stack(int size)
    {
        this->size = size;
        top = -1;
        st = new int[this->size];
    }

    void push(int x);
    int pop();
    int peek(int index);
    int StackTop();
    int isEmpty();
    int isFull();
    void Dispaly();
};

void Stack :: push(int x)
{
    if(isFull())
        cout<<"Stack Overflow"<<endl;
    else
    {
        top++;
        st[top] = x;
    }
}

int Stack :: pop()
{
    int x=-1;
    if(isEmpty())
        cout<<"Stack Underflow"<<endl;
    else
    {
        x = st[top--];
    }
    return x;
}

int Stack :: peek(int index)
{
    int x = -1;
    if(top - index + 1 < 0)
        cout<<"Invalid Index"<<endl;
    else
        x = st[top - index + 1];
    
    return x;
}

int Stack :: StackTop()
{
    if(top == -1)
        return -1;
    else
        return st[top];
}

int Stack :: isEmpty()
{
    return top == -1;
}

int Stack :: isFull()
{
    return top == size -1;
}

void Stack :: Dispaly()
{
    for(int i = top; i>=0 ; i--)
        cout<<st[i]<<" ";
    cout<<endl;
}

int main()
{
    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    
    
    cout<<s.peek(1)<<endl;
    s.Dispaly();
    cout<<s.isEmpty()<<endl;
    cout<<s.isFull()<<endl;

}

