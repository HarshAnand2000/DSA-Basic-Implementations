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
node* constructTree ( int post[], int size ) {
   stack<node*> stk;
   node* root = getNode( post[size-1] );
   stk.push(root);
   int i = size-1;
   node* t;
   for ( i = size - 2; i >= 0 ; --i ) {
      t = NULL;
      while ( !stk.empty() && post[i] < stk.top()->data ) {
         t = stk.top();
         stk.pop();
      }
      if ( t != NULL) {
        t->left = getNode(post[i]);
        stk.push(t->left);
      } else {
          node *t = new node;
         stk.top()->right = getNode( post[i] );
         stk.push(stk.top()->right);
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
   int post[] = {1, 7, 5, 50, 40, 10};
   int size = sizeof( post ) / sizeof( int );
   node *root = constructTree(post, size);
   cout << "Inorder traversal: ";
   inord(root);
   cout<<endl;
}