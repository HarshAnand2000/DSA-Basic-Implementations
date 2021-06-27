
#include<iostream>
using namespace std;

class Node
{
    public:
    
    Node*left;
    int data;
    int height;             //for every node height is maintained
    Node *right;

}* root=NULL;

int NodeHeight(Node *p)         //gives maximum height which ever tree has. 
{
    
    int hl, hr;
    hl = p && p->left ? p->left->height : 0;
    hr = p && p->right ? p->right->height : 0;

    return hl>hr ? hl+1 : hr+1;  //whichever is greater in that add one,and set the height of p
}

int BalanceFactor(Node *p)
{
    int hl,hr ;

    if(p && p->left)
        hl = p->left->height;
    else 
        hl = 0;

    hr = p && p->right ? p->right->height : 0;

    return hl - hr;
}

Node* LLrotation(Node* p)
{
    Node *pl = p->left;
    Node* plr = pl->right;

    pl->right = p;
    p->left = plr;
    p->height = NodeHeight(p);
    pl->height= NodeHeight(pl);

    if(root == p)
        root = pl;

    return pl;
}

Node *LRrotation(Node *p)
{
    Node *pl = p->left;
    Node *plr = pl->right;

    pl->right = plr->left;
    p->left = plr->right;

    plr->left = pl;
    plr->right = p;

    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);

    if(root ==p)
        root = plr;

    return plr;
}

Node *RRrotation(Node *p)
{
    Node *pr = p->right;
    Node* prl = pr->left;

    pr->left = p;
    p->right = prl;
    p->height = NodeHeight(p);
    pr->height= NodeHeight(pr);

    if(root == p)
        root = pr;

    return pr;
}

Node *RLrotation(Node *p)
{
    Node *pr = p->right;
    Node *prl = pr->left;

    pr->left = prl->right;
    p->right = prl->left;

    prl->left = p;
    prl->right = pr;

    pr->height = NodeHeight(pr);
    p->height = NodeHeight(p);
    prl->height = NodeHeight(prl);

    if(root = p)
        root = prl;

    return prl;
}

Node* RInsert(Node *p, int key)
{
    Node *t=NULL;

    if(p==NULL)
    {
        t = new Node;
        t->data = key;
        t->height = 1;  //In BST element is always inserted in a  leaf node,so height for that node will be one,for single node height will be 1
        t->left = t->right = NULL;
        return t;
    }
    if(key < p->data)
        p->left = RInsert(p->left, key);
    else if(key > p->data)
        p->right = RInsert(p->right, key);

    p->height = NodeHeight(p);      //at the returning time, we should update the height of every nod     //maximum height of left subtree or right, whicever is greater we shoukd take that one

    if(BalanceFactor(p)==2 && BalanceFactor(p->left)==1)  //then we shoukd perform ll rotation
        return LLrotation(p);
    else if(BalanceFactor(p)==2 && BalanceFactor(p->left)==-1)  //then we should perform LR rotation
        return LRrotation(p);
    else if (BalanceFactor(p)==-2 && BalanceFactor(p->right)==-1)   //then we should perform RR rotation
        return RRrotation(p);
    else if (BalanceFactor(p)==-2 && BalanceFactor(p->right)==1)    //then we should perform RL rotation
        return RLrotation(p);

    return p;
}

int main()
{
   

    root = RInsert(root,10);
    RInsert(root,20);
    RInsert(root,15);

    return 0;
}