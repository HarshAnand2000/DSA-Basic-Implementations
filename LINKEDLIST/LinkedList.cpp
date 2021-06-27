
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LL
{
private:
    Node *first;
    Node *Second;

public:
    LL() { first = NULL; Second = NULL; }
    LL(int A[], int n);
    void create(int B[], int n);
    ~LL();

    void Display();
    int length();
    int Sum();
    int Max();
    int Min();
    Node * LinearSearch(int key);
    Node * LinearSearch2(int key);
    void Insert(int index,int x);
    void InsertLast(int x);
    void SortedInsert(int x);
    int Delete(int index);
    int isSorted();
    void RemoveDuplicate();
    void Reverse1();
    void Reverse2();
    int isLoop();
    void Concat();
};

LL ::LL(int A[], int n)
{
    int i = 0;
    Node *last, *t;

    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

LL ::~LL()
{
    Node *p = first;
    while (first)
    {
        first = first->next;
        delete p;
        p = first;
    }
}

void LL ::Display()
{
    Node *p=NULL;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int LL ::length()
{
    int count = 0;
    Node *p = first;
    while (p)
    {
        count++;
        p = p->next;
    }
    return count;
}

int LL ::Sum()
{
    int sum = 0;
    Node *p = first;
    while (p)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int LL ::Max()
{
    Node *p = first;
    int max = INT32_MIN;
    while (p)
    {
        if (p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}


int LL :: Min()
{
    Node *p = first;
    int min = INT32_MAX;

    while(p)
    {
        if(p->data<min)
            min = p->data;
        p = p->next;
    }
    return min;
}

Node * LL :: LinearSearch(int key)
{
    Node *p=first;
    while(p)
    {
        if(key == p->data)
            return p;
        p=p->next;
    }
    return NULL;
}

Node *LL ::  LinearSearch2(int key)
{
    Node *p=first;
    Node *q=NULL;

    while(p)
    {
        if(key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
}

void LL:: Insert(int index,int x)
{
    Node *p =first;
    Node *t=NULL;

    if(index <0 || index>length())
        return;
    t=new Node;
    t->data = x;
    t->next = NULL;

    if(index==0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for(int i =0; i<index-1;i++)
        {
            p=p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

void LL :: InsertLast(int x)
{
    Node *t = new Node;
    Node *last;
    t->data = x;
    t->next = NULL;

    if(first == NULL)
        first = last = t;
    else 
        last->next = t;
        last = t;
}

void LL :: SortedInsert(int x)
{
    Node *p =first;
    Node *t,*q;
    t = new Node;
    t->data = x;
    t->next = NULL;

    if(first == NULL)
        first = t;
    else
    {
        while(p && p->data<x)
        {
            q=p;
            p=p->next;
        }

        if(p == first) //means x is less than the first element,that's why p stayed om first
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int LL  :: Delete(int index)
{
    Node *p=first;
    Node *q=NULL;
    int x=0;
    int i;

    if(index<1 || index>length())
        return x;
    if(index == 1)
    {
        x=first->data;
        p=first;
        first = first->next;
        delete p;
        return x;
    }
    else
    {
        for(i=0;i<index-1;i++)
        {
            q=p;
            p=p->next;
        }
        if(p)
        {
            q->next = p->next;
            x=p->next->data;
            delete p;
            return x;
        }
    }
    return x;
}

int LL :: isSorted()
{
    Node *p=first;
    int x = INT32_MIN;
    while(p)
    {
        if(p->data<x)
            return 0;
        x=p->data;
        p=p->next;
    }
    return 1;
}

void LL :: RemoveDuplicate()
{
    Node *p=first;
    Node*q;
    q=first->next;
    while(q)
    {
        if(p->data != q->data)
        {
            p=q;
            q=q->next;
        }
        else 
        {
            p->next = q->next;
            delete q;
            q=p->next;
        }
    }
}

void LL :: Reverse1()
{
    int *A,i=0;
    Node *p = first;
    A= new int [length()];

    while(p)
    {
        A[i]=p->data;
        p=p->next;
        i++;
    }
    p=first;
    i--;

    while(p)
    {
        p->data=A[i];
        p=p->next;
        i--;
    }
}

void LL :: Reverse2()
{
    Node *p=first;
    Node*q,*r;
    q=r=NULL;
    while(p)
    {
        r=q;
        q=p;
        p=p->next;
        q->next = r;
    }
    first = q;
}

int LL :: isLoop()
{
    Node *p = first;
    Node *q = first;

    do
    {
    p = p->next;
    q= q->next;
    q=q  ? q->next :q;
    }while(p && q && p!=q);

    return p==q ? 1 : 0;
}

void LL :: Concat()
{
    Node *p=first;
    Node *q= Second;
    Node *third =p;

    while(p->next)
        p=p->next;
    p->next = q;
}


int main()
{
    int A[] = {1, 2, 3, 4, 5};
    int B[] = {6,7,8,9,10};
    LL l(A, 5);
    /*
    l.Display();
    cout << "length is "<<l.length() << endl;

    cout << "sum is "<<l.Sum() << endl;

    cout<< "max is "<<l.Max()<<endl;

    cout<< "min is "<<l.Min()<<endl;

    cout<<"key is present at address "<<l.LinearSearch(5)<<" and key is "<<l.LinearSearch(5)->data <<endl;
    
    Node *temp;
    temp=l.LinearSearch2(5);
    cout<<"key is present at address "<<temp<<" and key is "<<temp->data<<endl;
    
    l.Insert(0,0);
    l.Insert(4,9);
    l.Display();
    
    l.InsertLast(6);
    l.InsertLast(7);
    l.InsertLast(8);
    l.Display();
    
    l.SortedInsert(2);
    l.SortedInsert(4);
    l.SortedInsert(6);
    l.SortedInsert(8);
    l.Display();

    l.Delete(0);
    l.Delete(2);
    l.Display();

    cout<<l.isSorted()<<endl;
    
    l.Display();
    l.RemoveDuplicate();
    l.Display();
    
    l.Display();
    l.Reverse1();
    l.Reverse2();
    l.Display();
    */

   



    return 0;
}