#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
};

void SortedInsert( Node **H, int x)
{
    Node *t,*q=NULL,*p=*H;

    t = new Node;
    t->data = x;
    t->next = NULL;

    if(*H==NULL)
        *H = t;
    else
    {
        while(p && p->data < x)
        {
            q = p;
            p =p->next;
        }
        if(p == *H)
        {
            t->next = *H;
            *H =t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

Node *Search(struct Node *p,int key)
{
    while(p!=NULL)
    {
        if(key==p->data)
            return p;
        p = p->next;
    }
    return NULL;
}

int hash1(int key)
{
    return key%10;
}

void Insert(Node *H[], int key)
{
    int index = hash1(key);
    SortedInsert(&H[index],key);
}

int main()
{
    Node *HT[10];
    for(int i = 0;i<10;i++)
        HT[i]=NULL;
    
    Insert(HT,12);
    Insert(HT,22);
    Insert(HT,2);

    Node * temp;
    temp = Search(HT[hash1(12)],12);
    cout<<temp->data<<endl;

}