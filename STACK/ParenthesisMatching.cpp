
#include <iostream>
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
    Stack() { top = NULL; }
    void push(int x);
    int pop();
    void display();
    int peek(int index);
    int isEmpty();
    int isFull();
    int StackTop();
    int isBalanced(char *exp);
    int isBalanced2(char *expr);
};

void Stack ::push(int x)
{
    Node *t = new Node;
    if (t == NULL)
        cout << "Stack is Full" << endl;
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int Stack ::pop()
{
    int x = -1;
    if (top == NULL)
        cout << "Stack is Empty:" << endl;
    else
    {
        x = top->data;
        Node *t = new Node;
        t = top;
        top = top->next;
        delete t;
    }
    return x;
}

int Stack ::peek(int index)
{
    Node *p = top;
    for (int i = 0; p != NULL && i < index - 1; i++)
    {
        p = p->next;
    }
    if (p != NULL)
        return p->data;
    else
        return -1;
}

void Stack ::display()
{
    Node *p = top;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int Stack ::StackTop()
{
    if (top)
        return top->data;
    return -1;
}

int Stack ::isEmpty()
{
    return top ? 0 : 1;
}

int Stack ::isFull()
{
    Node *t = new Node;
    int r = t ? 0 : 1;
    delete t;
    return r;
}

int Stack ::isBalanced(char *exp)
{
    int i;
    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
            push(exp[i]);
        else if (exp[i] == ')')
        {
            if (isEmpty())
                return 0;
            pop();
        }
    }

    if (top == NULL)
        return 1;
    return 0;
}

int Stack ::isBalanced2(char *expr)
{
    int i;
    char ch;
    for (i = 0; expr[i]!=NULL; i++)
    {
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
        {
            push(expr[i]);
        }

        if (isEmpty())
            return 0;
        else
        {
            switch (expr[i])
            {
            case ')':
                ch = StackTop();
                pop(); 
                if (ch == '{' || ch == '[')
                    return 0;
                    cout<<ch<<endl;
                break;
            case ']':
                ch = StackTop();
                pop();
                if(ch == '(' || ch == '{')
                    return 0;
                    cout<<ch<<endl;
                break;
            case '}':
                ch =StackTop();
                pop();
                if(ch == '[' || ch =='(')
                    return 0;
                    cout<<ch<<endl;
                break;
            }
        }
    }
    return  isEmpty();
}

int main()
{
    Stack s;
    char *exp = "{[()]}";
    cout << s.isBalanced2(exp) << endl;

    return 0;
}