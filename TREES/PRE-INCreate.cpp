
#include<iostream>
using namespace std;

class node
{
    public:
    node *left;
    char data;
    node *right;
};

int search(char arr[], int start, int end, int value)
{
    for(int i=0; i<=end; i++)
    {
        if(arr[i] == value)
            return i;
    }
    return 0;
}

node* newnode(char data)
{
    node* Node = new node;
    Node->data = data;
    Node->left = Node->right = NULL;
    return Node;
}

//initial values of inStart and inEnd should be 0 and len-1
node* buildTree(char in[], char pre[], int inStart, int inEnd)
{
    static int preIndex = 0;

    if(inStart > inEnd)
        return NULL;

     /* Pick current node from Preorder traversal using preIndex
    and increment preIndex */
    node *t = newnode(pre[preIndex++]);

    //if this  node does not have any children
    if(inStart == inEnd)
        return t;
    
    int inIndex = search(in, inStart, inEnd, t->data);
    t->left = buildTree(in, pre, inStart, inIndex-1 );
    t->right = buildTree(in, pre, inIndex+1, inEnd);

    return t;
}

void Inorder (node *p)
{
    if(p)
    {
        Inorder(p->left);
        cout<<p->data<<" ";
        Inorder(p->right);
    }
}

int main()
{
    char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' };
    char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' };
    int len = sizeof(in) / sizeof(in[0]);
    struct node* root = buildTree(in, pre, 0, len - 1);
 
    /* Let us test the built tree by printing Insorder traversal */
    printf("Inorder traversal of the constructed tree is \n");
    Inorder(root);
}
