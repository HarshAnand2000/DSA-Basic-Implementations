#include<iostream>
#include"tstack.cpp"
using namespace std;
class Tree
{
    public:
    Node *root;
    Tree(){root=NULL;}
    void create();
    void Preorder(Node *);
    void Inorder(Node *);
    void Postorder(Node *);
    void LevelOrder(Node *);
    int Count(Node *);
    int Count1(Node *);
    int Height(Node *);
    int CountLeaf(Node *p);
    int CountDeg2(Node *p);
    int CountDeg12(Node *p);
    int CountDeg1(Node *p);
    int Sum(Node *);
    void IPreorder(Node *);
    void IInorder(Node *);
    void IPostorder(Node *);
};

void Tree :: create()
{
    Node *t,*p;
    int x;
    Queue q(100);

    cout<<"Enter root value"<<endl;
    cin>>x;
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.enqueue(root);

    while(!q.isEmpty())
    {
        p = q.dequeue();
        cout<<"enter lchild of "<<p->data<<endl;
        cin>>x;
        if(x!=-1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild =NULL;
            p->lchild = t;
            q.enqueue(t);
        }
        cout<<"enter right child of "<<p->data<<endl;
        cin>>x;
        if(x!=-1)
        {
            t=new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}

void Tree :: Preorder(Node *p)
{
    if(p)
    {
        cout<<p->data<<" ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
    
}

void Tree :: Inorder(Node *p)
{
    if(p)
    {
        Inorder(p->lchild);
        cout<<p->data<<" ";
        Inorder(p->rchild);
    }
}

void Tree :: Postorder(Node *p)
{
    if(p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout<<p->data<<" ";
    }
}

void Tree :: LevelOrder(Node *root)
{
    Queue q(100);

    cout<<root->data<<" ";
    q.enqueue(root);

    while(!q.isEmpty())
    {
        root = q.dequeue();
        if(root->lchild)
        {
            cout<<root->lchild->data<<" ";
            q.enqueue(root->lchild);
        }
        if(root->rchild)
        {
            cout<<root->rchild->data<<" ";
            q.enqueue(root->rchild);
        }    
    }
}

int Tree :: Count(Node *p)
{
    int x,y;
    if(p!=NULL)
    {
        x = Count(p->lchild);
        y = Count(p->rchild);
        return x+y+1;
    }
    return 0;
}

int Tree ::Count1(Node *p)
{
    if(p==NULL)
        return 0;
    else
        return Count1(p->lchild) + Count1(p->rchild) + 1;
}

int Tree :: Height(Node *root)
{
    int x=0,y=0;
    if(root == 0)
        return 0;
    x= Height(root->lchild);
    y=Height(root->rchild);
    if(x>y)
        return x+1;
    else 
        return y+1;
}

int Tree ::CountLeaf(Node *p)
{
    if(p==NULL)
        return 0;
    else
    {
        if(!p->lchild  && !p->rchild)
            return CountLeaf(p->lchild) + CountLeaf(p->rchild) + 1;
        else
            return CountLeaf(p->lchild) + CountLeaf(p->rchild);
    }
}

int Tree :: CountDeg2(Node *p)
{
    int x,y;
    if(p!=NULL)
    {
        x = CountDeg2(p->lchild);
        y = CountDeg2(p->rchild);
        if(p->lchild!=NULL  && p->rchild!=NULL)
            return x+y+1;
        else
            return x+y;
    }
    return 0;
}

int Tree :: CountDeg12(Node *p)
{
    int x,y;
    if(p!=NULL)
    {
        x = CountDeg12(p->lchild);
        y = CountDeg12(p->rchild);
        if(p->lchild!=NULL  || p->rchild!=NULL)
            return x+y+1;
        else
            return x+y;
    }
    return 0;
}

int Tree :: CountDeg1(Node *p)
{
    int x,y;
    if(p!=NULL)
    {
        x = CountDeg1(p->lchild);
        y = CountDeg1(p->rchild);
        if((p->lchild  && p->rchild==NULL) || (p->lchild == NULL && p->rchild))
            return x+y+1;
        else
            return x+y;
    }
    return 0;
}

int Tree :: Sum(Node *p)
{
    int x,y;
    if(p!=NULL)
    {
        x = Sum(p->lchild);
        y = Sum(p->rchild);
        return x+y+p->data;
    }
    return 0;
}

void Tree :: IPreorder(Node *t)
{
    Stack st(100);
    while(t!=NULL || !st.isEmpty1())
    {
        if(t!=NULL)
        {
            cout<<t->data<<" ";
            st.push(t);
            t = t->lchild;
        }
        else
        {
            t = st.pop();
            t = t->rchild;
        }
    }
}

void Tree :: IInorder(Node *t)
{
    Stack st(100);
    while(t!=NULL || !st.isEmpty1())
    {
        if(t!=NULL)
        {
            st.push(t);
            t = t->lchild;
        }
        else
        {
            t = st.pop();
            cout<<t->data<<" ";
            t = t->rchild;
        }
    }
}


int main()
{
    Tree t;
    t.create();
    cout<<"Preorder ";
    t.Preorder(t.root);
    cout<<endl;
    cout<<"Inorder "; 
    t.Inorder(t.root);
    cout<<endl;
    cout<<"Postorder ";
    t.Postorder(t.root);
    cout<<endl;
    cout<<"LevelOrder ";
    t.LevelOrder(t.root);
    cout<<endl;
    cout<<"Count: "<<t.Count(t.root);
    cout<<endl;
    cout<<"Count1: "<<t.Count1(t.root);
    cout<<endl;
    cout<<"CountLeaf: "<<t.CountLeaf(t.root);
    cout<<endl;
    cout<<"CountDeg2: "<<t.CountDeg2(t.root);
    cout<<endl;
    cout<<"CountDeg12: "<<t.CountDeg12(t.root);
    cout<<endl;
    cout<<"CountDeg1: "<<t.CountDeg1(t.root);
    cout<<endl;
    cout<<"Sum: "<<t.Sum(t.root);
    cout<<endl;

    cout<<"Height: "<<t.Height(t.root);
    cout<<endl;

    cout<<"IPreorder ";
    t.IPreorder(t.root);
    cout<<endl;
    cout<<"IInorder ";
    t.IInorder(t.root);
    cout<<endl;


    return 0;
}


