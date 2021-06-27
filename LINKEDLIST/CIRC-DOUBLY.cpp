
#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} * Head;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    Head = new Node;
    Head->data = A[0];
    Head->prev = Head;
    Head->next = Head;
    last = Head;

    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = Head;
        Head->prev = t;                    
        t->prev = last;    
        last->next = t;    
        last = t;
    }
}

int length(struct Node *p)
{
    int len=0;
    do{
        len ++;
        p=p->next;
    }while(p!=Head);
    return len;
}

void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;

    if (index == 0)
    {
        t = new Node;
        t->data = x;
        if(Head =NULL)
        {
            Head =t;
            Head->next = Head;
            Head->prev = Head;
        }
        else
        {
        t->next = Head;
        t->prev = Head->prev;
        Head->prev = t;
        Head->prev->next = t;

        Head = t;

        }
    }

    else
    {
        t = new Node;
        t->data = x;
        for (i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        t->prev = p;
        if (p->next)
            p->next->prev = t;
        p->next = t;
    }
}

int Delete (struct Node *p, int index)
{
    struct Node *q;
    int i,x;

    if(index<1 || index>length(p))
        return -1;
    if(index == 1)
    {
        x = Head->data;
        if(Head->next = Head)
        {
            Head =  Head ->prev->next = NULL;
            delete p;
        }
        else 
        {
            Head = Head ->next;
            Head ->prev = Head ->prev ->next;
            Head->prev->next = Head;
            delete p;

        }
    }
    else 
    {
        for(i=0;i<index-1;i++)
            p=p->next;
        p->prev->next = p->next;
        if(p->next)
            p->next->prev = p->prev;
        x = p->data;
        delete p;
    }
    return x;
}

void display(struct Node *p)
{
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != Head);
    cout << endl;
}

int main()
{
    int A[] = {10, 20, 30, 40, 50, 60, 70};
    create(A, 7);
    Delete(Head,1);
    
    
    
    display(Head);
    return 0;
}