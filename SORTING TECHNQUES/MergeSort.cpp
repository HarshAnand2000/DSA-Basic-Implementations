#include<iostream>
using namespace std;



void Merge(int A[], int low, int mid, int high)
{
    int i,j,k;
    i = low;
    j = mid+1;
    k = low;

    int B[high+1];
    while(i<=mid && j<=high)
    {
        if(A[i]<A[j])
            B[k++]=A[i++];
        else
            B[k++]=A[j++]; 
    }

    for(;i<=mid;i++)
        B[k++]=A[i];
    
    for(;j<=high;j++)
        B[k++]=A[j];

    for(i=low;i<=high;i++)
        A[i]=B[i];
}

void IMergeSort(int A[],int n)
{
    int p,l,h,mid,i;

    for(p=2;p<=n;p=p*2)
    {
        for(i=0;i+p-1<n;i = i+p)
        {
            l = i;
            h = i+p-1;
            mid = (l+h)/2;
            Merge(A,l,mid,h);
        }
    }

    if(p/2<n)
        Merge(A,0,p/2-1,n);

}

void RMergeSort(int A[], int l, int h)
{
    int mid;
    if(l<h)     //must be more than 1 elemnt
    {
        mid = (l+h)/2;

        RMergeSort(A,l,mid);
        RMergeSort(A,mid+1,h);

        Merge(A,l,mid,h);
    }
}

int main()
{
    int A[]={2,5,8,12,7,9,0,10,11};

    IMergeSort(A,9);
    //RMergeSort(A,0,9);

    for(int i=0;i<9; i++)
        cout<<A[i]<<" ";

    return 0;
}