#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
 
// function for creating a new node in the linked list
struct Node* create(int x)
{
    Node* temp = new Node();
    temp->data = x;
    temp->next = NULL;
 
    return temp;
}
 
// utility function to append node in the linked list
// here head is passed by reference, to know more about this
// search pass by reference
void insert(Node*& head, int n)
{
    if (head == NULL) {
        head = create(n);
        return;
    }
 
    Node* t = head;
    while (t->next != NULL)
        t = t->next;
    t->next = create(n);
}
 
// utility function to pop an element from front in the list
// for the sake of stability in sorting
int del(Node*& head)
{
    if (head == NULL)
        return 0;
    Node* temp = head;
    // storing the value of head before updating
    int val = head->data;
 
    // updation of head to next node
    head = head->next;
 
    delete temp;
    return val;
}

int findMax(int A[], int n)
{
    int max=A[0];
    int i;
    for(i=0;i<n;i++)
    {
        if(A[i]>max)
            max = A[i];
    }
    return max;
}

void BinSort(int A[], int n)
{
    int max;
    Node **Bin;
    max = findMax(A,n);
    Bin = new Node*[max+1];

    for(int i=0;i<max+1;i++)
        Bin[i]=NULL;

    for(int i =0;i<n;i++)
        insert(Bin[A[i]],A[i]);
    
    int i=0,j=0;
    while(i<max+1)
    {
        while(Bin[i]!=NULL)
        {    
            A[j++]=del(Bin[i]);
        }    
            i++;
    }
}

int main()
{
    int A[]={6,3,9,10,15,6,8,12,3,6};int n=10;

    BinSort(A,n);

    for(int i =0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;

}