
#include<iostream>
using namespace std;

void Swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(int A[], int n)
{
    int flag = 0;
    int i,j;
    for(i=0;i<n-1;i++)
    {
        flag = 0;
        for(j=0;j<n-1-i;j++)
        {
            if(A[j]>A[j+1])
                Swap(&A[j],&A[j+1]);
                flag=1;
        }
        if(flag==0)
            break;
    }
}

int main()
{
    int A[]={1,2,3,4,5,6,7,8};
    int n = sizeof(A)/sizeof(int);
    
    BubbleSort(A,n);

    for(int i =0;i<n;i++)
        cout<<A[i]<<" ";
    cout<<endl;

    return 0;
    
}