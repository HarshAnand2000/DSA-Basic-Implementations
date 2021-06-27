
#include<iostream>
using namespace std;

void Insert(int A[], int n)
{
    int temp,i=n;
    temp = A[n];
    while(i>1 && temp > A[i/2])
    {
        A[i] = A[i/2];
        i= i/2;
    }
    A[i] = temp;
}

void create(int A[])
{
    for(int i=2;i<=7;i++)
        Insert(A,i);
}

int Delete(int A[],int n)
{
    int temp;
    int i,j,x;
    int val = A[1];      //to store delted value
    x = A[n];
    A[1]=A[n];
    A[n]=val;           //storing value at next empty space
    i=1,j=i*2;

    while(j<n-1){           //because size is decreased by 1 after eleteing element    
        if(A[j+1]>A[j])
            j = j+1;
        if(A[i]<A[j])
        {
            temp = A[i];
            A[i]=A[j];
            A[j]=temp;
            i=j;
            j=j*2;
        }
        else
            break;
    }
    return val;
}

int main()
{
    int A[]={0, 10, 20, 30, 25, 5, 40, 35};
    int i;
    create(A);

    for(i=7;i>=1;i--)
        cout<<"deleted value is : "<<Delete(A,i)<<endl;
    
    cout<<"sorted elements are:  ";
    
    for(i=1;i<=7;i++)
        cout<<A[i]<<" ";
    cout<<endl;

    return 0;


}