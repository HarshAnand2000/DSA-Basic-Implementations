// C++ implementation of the algorithm
/* A binary tree node has data,
pointer to left child and a pointer
to right child */
#include<bits/stdc++.h>
using namespace std;

// Class Node has data and references
// to the left and the right child.
class Node
{
	public:
	int data;
	Node* left, *right;

	Node(int data)
	{
		this->data = data;
		left = right = NULL;
	}
};

// Function that creates the tree
Node* constructTreeUtil(int post[], int n)
{
	// Last node is root
	Node* root = new Node(post[n - 1]);
	stack<Node*> s;
	s.push(root);

	// Traverse from second last node
	for (int i = n - 2; i >= 0; --i)
	{
		Node* x = new Node(post[i]);

		// Keep popping nodes while top()
		// of stack is greater.
		Node* temp = NULL;
		while (s.size() && post[i] < s.top()->data)
			temp = s.top(), s.pop();	

		// Make x as left child of temp
		if (temp != NULL)
			temp->left = x;	

		// Else make x as right of top	
		else
			s.top()->right = x;
		s.push(x);
	}
	return root;
}

// Function that calls the method
// which contructs the tree
Node* constructTree(int post[], int size)
{
	return constructTreeUtil(post, size);
}

// A utility function to print
// inorder traversal of a Binary Tree
void printInorder(Node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	cout << node->data << " ";
	printInorder(node->right);
}

// Driver Code
int main()
{
	int post[] = { 1, 7, 5, 50, 40, 10 };
	int size = sizeof(post)/sizeof(int);

	Node* root = constructTree(post, size);

	cout << "Inorder traversal of "
		<< "the constructed tree:\n";
	printInorder(root);
}

// This code is contributed by Arnab Kundu
