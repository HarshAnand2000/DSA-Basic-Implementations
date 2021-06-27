#include<iostream>
using namespace std;

void Swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void SelectionSort(int A[], int n)
{
    int i,j,k;

    for(i=0;i<n-1;i++)
    {
        for(j=k=i;j<n;j++)
        {
            if(A[j]<A[k])
                k=j;
        }
        Swap(&A[i],&A[k]);
    }
}

int main()
{
    int A[]={8,7,6,5,4,3,2,1};
    int n = sizeof(A)/sizeof(int);
    
    SelectionSort(A,n);

    for(int i =0;i<n;i++)
        cout<<A[i]<<" ";
    cout<<endl;

    return 0;
    
}