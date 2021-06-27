
#include <iostream>
using namespace std;

class Array
{
public:
    int A[10]={1,2,3,4,5};
    int B[10]={5,4,3,2,1};
    int size;
    int length;

    void Display();
    Array *Merge(Array arr2);
};

void Array :: Display()
{
    int i;
    for (i = 0; i < length; i++)
        cout << A[i] << "  ";
    cout << endl;
}

Array *Array :: Merge(Array arr2)
{
    int i, j, k;
    i = j = k = 0;
    Array *arr3 = new Array[length + arr2.length];
    while (i < length && j < arr2.length)
    {
        if(A[i]<arr2.A[j])
         arr3->A[k++] = A[i++];
        else
        arr3->A[k++]=arr2.A[j++];
    }
    for(;i<length;i++)
        arr3->A[k++]=A[i];
    for(;j<arr2.length;j++)
        arr3->A[k++]=arr2.A[j++];
    arr3->length = length + arr2.length;

return arr3;
}
int main()
{
    Array arr;
    arr.A;
    Array arr2;
    arr2.B;
    Array *arr3;
    arr3->Merge(arr2);
    arr3->Display();
    
return 0;
}