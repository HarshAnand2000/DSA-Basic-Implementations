
#include<iostream>
using namespace std;

void InsertionSort(int A[],int n)
{
    int i,j,k;
    int x;
    for(i=1;i<n;i++)
    {
        j=i-1;
        x=A[i];
        
        while(j>-1 && A[j]>x)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=x;
    }
}

int main()
{
    int A[]={9,3,5,1,2,7};
    int n = sizeof(A)/sizeof(int);

    InsertionSort(A,n);

    for(int i = 0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}