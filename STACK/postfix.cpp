
#include <iostream>
#include <string.h>
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
    int precedence(char x);
    int isOperand(char x);
    char *InToPost(char *infix);
    int Eval(char *postfix);
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

int Stack ::precedence(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    else if (x == 'a' || x == 'b' || x == 'c' || x == 'd' || x == 'e')
        return 3;
    else
        return 0;
}

int Stack ::isOperand(char x)

{
    if (x == '+' || x == '-' || x == '/' || x == '*')
        return 0;
    return 1;
}

char *Stack ::InToPost(char *infix)
{
    int i = 0, j = 0;
    char *postfix;
    int len = strlen(infix);
    postfix = new char[len + 2];

    while (infix[i] != NULL)
    {
        if (isOperand(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else
        {
            if (precedence(infix[i]) > precedence(top->data))
                push(infix[i++]);
            else
            {
                postfix[j++] = pop();
            }
        }
    }

    while (top != NULL)
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    return postfix;
}



int Stack ::Eval(char *postfix)
{
    int i = 0;
    int x1, x2, r = 0;
    for (i = 0; postfix[i] != 0; i++)
    {
        if (isOperand(postfix[i]))
        {
            push(postfix[i] - '0');
        }
        else
        {
            x2 = pop();
            x1 = pop();

            switch (postfix[i])
            {
            case '+':
                r = x1 + x2;
                break;
            case '-':
                r = x1 - x2;
                break;
            case '/':
                r = x1 / x2;
                break;
            case '*':
                r = x1 * x2;
            }
            push(r);
        }
    }
    return top->data;
}

int main()
{
    //char *postfix = "35*62/+4-";
    Stack s;
    //cout<<s.Eval(postfix)<<endl;
    char *infix = "a+b*c-d/e";
    s.push('#');
    char *postfix = s.InToPost(infix);
    cout << postfix << endl;
}