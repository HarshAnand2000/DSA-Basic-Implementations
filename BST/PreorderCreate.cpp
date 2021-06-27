
#include <iostream>
#include <stack>
using namespace std;
class node {
   public:
   int data;
   node *left;
   node *right;
};
node* getNode (int data) {
   node* p = new node();
   p->data = data;
   p->left = p->right = NULL;
   return p;
}

int Height(node *p)
{
   int x,y;
   if(p)
   {
      x = Height(p->left);
      y = Height(p->right);
      return x>y?x+1:y+1;
   }
   return 0;
}

node* constructTree ( int pre[], int size ) {
   stack<node*> stk;
   node* root = getNode( pre[0] );
   stk.push(root);
   int i;
   node* t;
   for ( i = 1; i < size; ++i ) {
      t = NULL;
      while ( !stk.empty() && pre[i] > stk.top()->data ) {
         t = stk.top();
         stk.pop();
      }
      if ( t != NULL) {
         t->right = getNode( pre[i] );
         stk.push(t->right);
      } else {
          t= stk.top();
         t->left = getNode( pre[i] );
         stk.push(t->left);
      }
   }
   return root;
}
void inord (node* node) {
   if (node == NULL)
      return;
   inord(node->left);
   cout << node->data << " ";
   inord(node->right);
}
int main () {
   int pre[] = {10, 5, 1, 7, 40, 50};
   int size = sizeof( pre ) / sizeof( pre[0] );
   node *root = constructTree(pre, size);
   cout << "Inorder traversal: ";
   inord(root);
   cout<<endl;
   cout<<Height(root);
   cout<<endl;
}