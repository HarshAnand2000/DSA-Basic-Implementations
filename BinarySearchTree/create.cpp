
#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    Node *root;

    Node *left;
    int data;
    Node *right;

    Node(){root = NULL;}

    Node *Insert(Node *t, int key);
    Node *RInsert(Node *t, int key);
    void Inorder(Node *);

    Node* RSearch(Node *,int);
    Node* Search(Node *,int);

    Node* Predecessor(Node *);
    Node* Successor(Node *);
    int Height(Node *);
    Node* RDelete(Node *,int);

};

Node* Node :: Insert(Node *t,int key)
{
    Node *r,*p;
    if(t ==NULL)                    //thif if part will only execute once
    {
        p= new Node;
        p->data = key;
        p->left = p->right = NULL;
        root = p;
        return NULL;
    }
    while(t!=NULL)
    {
        r=t;
        if(key == t->data)
            return NULL;
        else if(key<t->data)
            t = t->left;
        else
            t = t->right;
    }
    p = new Node;
    p->data = key;
    p->left = p->right = NULL;
    

    if(p->data < r->data)                   //p->data = key
        r->left = p;
    else
        r->right = p;

    return NULL;
}

Node* Node ::RInsert(Node *p,int key)
{
    Node *t=NULL;
    if(p==NULL)
    {
        t = new Node;
        t->data = key;
        t->left = t->right = NULL;
        return t;
    }
    if(key < p->data)
        p->left = RInsert(p->left,key);
    if(key > p->data)
        p->right = RInsert(p->right,key);

    return p;
}

void Node :: Inorder(Node *p)
{
    if(p)
    {
    Inorder(p->left);
    cout<<p->data<<" ";
    Inorder(p->right);
    }
}

Node* Node :: RSearch(Node *p, int key)
{
    if(p==NULL)
        return NULL;
    if(key==p->data)
        return p;
    else if(key < p->data)
       return RSearch(p->left,key);
    else 
        return RSearch(p->right,key);
}

Node* Node :: Search(Node *p, int key)
{
    while(p!=NULL)
    {
        if(key == p->data)
            return p;
        else if(key < p->data)
            p = p->left;
        else
            p = p->right;
    }
    return NULL;
}

Node* Node :: Predecessor(Node *p)
{
    while(p && p->right != NULL)
        p=p->right;
    
    return p;
}

Node* Node :: Successor(Node *p)
{
    while(p && p->left != NULL)
        p=p->left;
    
    return p;
}

int Node :: Height(Node *p)
{
    if(p)
    {
        int x,y;
        x = Height(p->left);
        y= Height(p->right);
        return x>y?x+1:y+1;
    }
    return 0;
}

Node* Node :: RDelete(Node *p, int key)
{
    Node *q;

    if(p==NULL)
        return NULL;
    if(p->left == NULL && p->right == NULL)
    {
        if(p==root)
            root = NULL;
        delete p;
        return NULL;
    }

    if(key < p->data)
        p->left = RDelete(p->left,key);
    if(key > p->data)
        p->right = RDelete(p->right,key);
    else
    {
        if(Height(p->left) > Height(p->right))
        {
            q = Predecessor(p->left);
            p->data = q->data;
            p->left = RDelete(p->left,q->data);
        }
        else
        {
            q = Successor(p->right);
            p->data = q->data;
            p->right = RDelete(p->left,q->data);

        }
    }return p;
}


int main()
{
    Node n;
    
    n.Insert(n.root,30);
    n.Insert(n.root,20);
    n.Insert(n.root,40);
    n.Insert(n.root,10);
    n.Insert(n.root,25);
    n.Insert(n.root,35);
    n.Insert(n.root,45);
      
      
    

    n.Inorder(n.root);
    cout<<endl;

    Node *temp = n.Search(n.root,3);
    if(temp!=NULL)
        cout<<temp->data<<" is found "<<endl;
    else
        cout<<"not found"<<endl;

    cout<<n.Height(n.root)<<endl;
    cout<<n.RDelete(n.root,20);
    n.Inorder(n.root);
    return 0;
}
