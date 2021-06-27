
#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
}*first;

void create(int A[],int n)
{
    struct Node *t,*last;
    int i;

    first = new Node;
    first->data = A[0];
    first->next = NULL;
    first->prev = NULL;
    last = first;

    for(i=1;i<n;i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

int length(struct Node *p)
{
    int len;
    while(p)
    {
        len++;
        p = p->next;
    }
    return len;
}

void Insert(struct Node *p,int index,int x)
{
    struct Node *t;
    int i;
    
    if(index<0 || index>length(p))
        return;
    
    if(index ==0)
    {
        t = new Node;
        t->data = x;
        t->prev =NULL;
        t->next = first;
        first->prev = t;
        first = t; 
    }
    else
    {
        for(i=0;i<index-1;i++)
            p=p->next;
        t = new Node;
        t->data = x;
        t->next = p->next;
        t->prev = p;
        p->next = t;
        if(p->next)
            p->next->prev = t;
            
    }
}

int Delete (struct Node *p,int index)
{
    struct Node *q;
    int i,x;

    if(index<1 || index>length(p))
        return -1;
    
    if(index == 1)
    {
        first = first->next;
        if(first)
            first->prev = NULL;
        x = first->data;
        delete p;
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

void Reverse(struct Node *p)
{
    struct Node *temp;

    while(p!=NULL)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p=p->prev;  //****moving to next node*****

        if(p!=NULL && p->next == NULL)
            first = p;
    }
}

void display(struct Node *p)
{
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

int main()
{
    int A[]={1,2,3,4,5};
    create(A,5);
    display(first);
    Reverse(first);
    display(first);
}