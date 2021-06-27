
#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

void display(struct Node *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
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

void create2(int B[], int n)
{
    int i;
    struct Node *t, *last;
    second = new Node;
    second->data = B[0];
    second->next = NULL;
    last = second;

    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = B[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void concat(struct Node *p, struct Node *q)
{
    third = p;

    while (p->next)
    {
        p = p->next;
    }
    p->next = q;
}

void Merge(struct Node *p, struct Node *q)
{
    struct Node *last;
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        third->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }

    while (p && q)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }

    if (p)
        last->next = p;
    if (q)
        last->next = q;
}

int main()
{
    int A[] = {1, 3, 5, 2, 4};
    int B[] = {6, 8, 10, 9, 7};
    create(A, 5);
    create2(B, 5);
    display(first);
    display(second);
    Merge(first, second);
    display(third);
}