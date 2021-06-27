#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    Node *left;
    int data;
    Node *right;
    Node *newNode(int);
    void IPostorder(Node *);
};

Node *  Node ::  newNode(int data)
{
    Node *node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void Node :: IPostorder(Node *root)
{
    if(root ==NULL)
        return;

    stack<Node*> s1,s2;

    s1.push(root);
    Node *node;

    while(!s1.empty())
    {
        node = s1.top();
        s1.pop();
        s2.push(node);
        
        if(node->left)
            s1.push(node->left);
        if(node->right)
            s1.push(node->right);
    }

    while(!s2.empty())
    {
        node = s2.top();
        s2.pop();
        cout<<node->data<<" ";
    }

}

int main()
{
    Node n;
    Node *root = NULL;
    root = n.newNode(1);
    root->left = n.newNode(2);
    root->right = n.newNode(3);
    root->left->left = n.newNode(4);
    root->left->right = n.newNode(5);
    root->right->left = n.newNode(6);
    root->right->right = n.newNode(7);

    n.IPostorder(root);
    cout<<endl;

    return 0;
}