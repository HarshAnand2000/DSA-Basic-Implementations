
#include<iostream>
#include<math.h>
using namespace std;

struct Node
{
    int coeff;
    int exp;
    int num;
    struct Node *next;
}*poly1=NULL,*poly2=NULL;

void create(struct Node *t)
{
    struct Node *last;
    int num1,num2;
    cout<<"enter the number of terms"<<endl;
    cin>>t->num;

    cout<<"enter each term with coeff and exp:"<<endl;
    for(int i=0;i<t->num;i++)
    {
        t =new Node;
        cin>>t->coeff>>t->exp;
        t->next = NULL;
        if(poly1 == NULL)
        {
            poly1 = last = t;
        }
        else
        {
            last->next = t;
            last = t;
        }
    }
   
}

long Eval(struct Node *p,int x)
{
    long val;
    while(p)
    {
        val += p->coeff * pow(x,p->exp);
        p=p->next;
    }
    return val;
}

void display(struct Node *p)
{
    while(p)
    {
        cout<<p->coeff<<"x"<<p->exp<<" + ";
        p=p->next;
    }
    cout<<endl;
}

struct Node *add(struct Node *p1, struct Node *p2)
{
    struct Node *sum;
    sum = new Node;
    if(p1->exp < p2->exp)
    {
        sum->coeff = p1->coeff;
        sum->exp ; p1->exp;
    }
    else if(p2->exp < p1->exp)
    {
        sum->coeff = p2->coeff;
        sum->exp = p2->exp;
    }
    else 
    {
        sum->coeff = (p1->coeff + p2->coeff);
        sum->exp = p1->exp;
    }

    return sum;
}



int main()
{
    create(poly1);
    create(poly2);
    display(poly1);
    display(poly2);
    struct Node *p3=add(poly1,poly2);
    display(p3);
}