
#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*first = NULL;

void create(int A[],int n)
{
    int i;
    struct Node *t,*last;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(i=1;i<n;i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p)
{
    if(p)
    {
        cout<<p->data<<" ";
        Display(p->next);
        cout<<endl;
    }
}

int count(struct Node *p)
{
    if(p==0)
        return 0;
    else 
        return count(p->next) + 1;
}

int count1(struct Node *p)
{
    int x=0;
    if(p)
    {
        x= count(p->next);
        return x+1;
    }
    else {return x;}
}

int sum(struct Node *p)
{
    if(p)
    {
        return sum(p->next) + p->data;
    }
    else return 0;
}

int Max(struct Node *p)
{
    int max = 0;
    if(p==0)
        return INT32_MIN;
    max = Max(p->next);
    if(max>p->data)
        return max;
    return p->data;
}

Node  *Search(Node *p,int key)
{
    if(p==NULL)
        return NULL;
    if(key == p->data)
        return p;
    return Search(p->next,key);
}

void Reverse(struct Node *q,struct Node *p)
{
    if(p)
    {
        Reverse(p,p->next);
        p->next = q;
    }
    else
        first = q;
}

int main()
{
    int A[]={1,2,3,4,5};
    create(A,5);

    Display(first);
    cout<<count(first)<<endl;
    cout<<count1(first)<<endl;
    cout<<sum(first)<<endl;
    cout<<Max(first)<<endl;
    cout<<Search(first,4)<<endl;
    Reverse(NULL,first);
    Display(first);
}