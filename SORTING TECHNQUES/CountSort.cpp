#include<iostream>
using namespace std;

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

void CountSort(int A[], int n)
{
    int max;
    int *Count;
    max = findMax(A,n);
    Count = new int[max+1];

    for(int i=0;i<max+1;i++)
        Count[i]=0;

    for(int i =0;i<n;i++)
        Count[A[i]]++;
    
    int i=0,j=0;
    while(i<max+1)
    {
        if(Count[i]>0)
        {    
            A[j++]=i;
            Count[i]--;
        }    
        else
            i++;
    }
}

int main()
{
    int A[]={6,3,9,10,15,6,8,12,3,6};int n=10;

    CountSort(A,n);

    for(int i =0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;

}