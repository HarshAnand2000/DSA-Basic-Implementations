#include<iostream>
using namespace std;

void ShellSort(int A[],int n)
{
    int i,j,temp;
    int gap;
    for(gap = n/2;gap>=1;gap/=2)      //gap for evry pass
    {
        for(i=gap;i<n;i++)            //inner loop for accessing elemnts
        {
        temp=A[i];
        j = i-gap;
        while(j>=0 && A[j]>temp)
        {
            A[j+gap]=A[j];
            j= j-gap;
        }
        A[j+gap]=temp;
    }
    }
}

int main()
{
    int A[]={9,3,5,1,2,7};
    int n = sizeof(A)/sizeof(int);

    ShellSort(A,6);

    for(int i = 0;i<6;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}