#include<iostream>
using namespace std;
#define SIZE 10;

int hash1(int key)
{
    return key%SIZE;
}

int probe(int H[], int key)
{
    int index = hash1(key);
    int i =0;
    while(H[(index+i)%10]!=0)
        i++;
    return (index + i)%SIZE;
}

int probe1(int H[], int key)
{
    int index = hash1(key);
    int i =0;
    while(H[(index+i)%10]!=key)
        i++;
    return (index + i)%SIZE;
}

void Insert(int H[],int key)
{
    int index;
    index =hash1(key);

    if(H[index]!=0)
        index =probe(H,key);
    
    H[index]=key;
}

int Search(int H[], int key)
{
    int index = hash1(key);
    
    if(H[index]!=key)
        index = probe1(H,key);

    return index;
}

int main()
{
    int HT[10]={0};
    
    Insert(HT,12);
    Insert(HT,25);
    Insert(HT,35);

    cout<<"Key found at "<<Search(HT,35)<<endl;

    return 0;
}