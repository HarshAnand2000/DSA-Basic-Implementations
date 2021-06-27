
#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
}*Head;

void create(int A[],int n)
{
    struct Node *t,*last;
    int i;
    Head = new Node;
    Head->data = A[0];
    Head->next = Head;
    last = Head;

    for(i=1;i<n;i++)
    {
        t=new Node;
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

int length(struct Node *p)
{
    int len=0;
    do 
    {
        len++;
        p=p->next;
    }while(p!=Head);
return len;

}

void Insert(struct Node *p,int index, int x)
{
    struct Node *t;
    int i;
    if(index<0 || index>length(Head))
        return ;  
    if(index == 0)
    {
        t= new Node;
        t->data = x;
        if(Head == NULL)
        {
            Head = t;
            Head->next =Head;
        }
        else
        {
            while(p->next !=Head)
            {p=p->next;}
            p->next = t;
            t->next = Head;
            Head = t;    //******important condition******
        }
    }  
    else
    {
        for(i=0;i<index - 1;i++)
        {
            p=p->next;
        }
            t=new Node;
            t->data = x;
            t->next = p->next;
            p->next = t;
    }
}

int Delete(struct Node *p,int index)
{
    struct Node *q;
    int i,x;

    if(index<1 || index>length(p))
        {return -1;}
    if(index == 1)
    {
        while(p->next != Head) p= p->next;
        x = Head->data;
        if(Head == p)
        {
            delete Head;
            Head = NULL;
        }
        else
        {
            p->next = Head->next;
            delete Head;
            Head = p->next;
        }
    }
    else
    {
        for(i=0;i<index-2;i++)
        {
            p=p->next;
        }
        q=p->next;
        p->next = q->next;
        x= q->data;
        delete q;
    }
    return x;
}

void display(struct Node *p)
{
    do 
    {
        cout<<p->data<<" ";
        p=p->next;
    }while(p!= Head);
    cout<<endl;
}

int main()
{
    int A[]={1,2,3,4,5};
    create(A,5);
    
    Insert(Head,0,8);
    display(Head);
    Delete(Head,1);
    display(Head);
}