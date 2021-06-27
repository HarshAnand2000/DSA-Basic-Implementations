#include<iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a=*b;
    *b = temp;
}

int partition(int A[], int l, int h)
{
    int pivot = A[l];       //we can aslo select mid element as pivot
    int i=l,j=h;
    do
    {
        do {i++;}while(A[i]<=pivot);
        do {j--;}while(A[j]>pivot);

        if(i<j)
            swap(&A[i],&A[j]);
    } while (i<j);
    
    swap(&A[l],&A[j]);

    return j;               //j is where partition is done.
}

void QuickSort(int A[], int l, int h)
{
    int j;
    if(l<h)
    {
        j = partition(A,l,h);
        QuickSort(A,l,j);          //it should be (j-1),but we took jth(pivot) element as infinity for this list
        QuickSort(A,j+1,h);
    }
}

int main()
{
    int A[]={50,40,30,20,10,INT32_MAX}, n=6, i;

    QuickSort(A,0,n-1);

    for(i=0;i<5;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;

    return 0;
}