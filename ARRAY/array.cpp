
#include <iostream>
using namespace std;

class Array
{
private:
    int *A;
    int size;
    int length;
    void swap(int *x, int *y);

public:
    Array()
    {
        A = new int[size];
        size = 10;
        length = 0;
    }

    Array(int sz)
    {
        size = sz;
        length = 0;
        A = new int[sz];
    }

    ~Array()
    {
        delete[] A;
    }

    void Display();
    void Append(int x);
    void Insert(int index, int x);
    int Delete(int index);
    int LinearSearch(int key);
    int BinarySeach(int key);
    int Get(int index);
    void Set(int index, int x);
    int Max();
    int Min();
    int Sum();
    float Avg();
    void Reverse();
    void Reverse2();
    void InsertSort(int x);
    int isSorted();
    void Rearrange();
};

void Array ::Display()
{
    for (int i = 0; i < length; i++)
        cout << A[i] << " ";
}

void Array ::Append(int x)
{
    if (length < size)
        A[length++] = x;
}

void Array ::Insert(int index, int x)
{
    int i;
    if (index >= 0 && index < length)
    {
        for (i = length; i > index; i--)
            A[i] = A[i - 1];
        A[index] = x;
        length++;
    }
}

int Array ::Delete(int index)
{
    int i;
    int x = 0;
    if (index >= 0 && index < length)
    {
        x = A[index];
        for (i = index; i < length - 1; i++)
            A[i] = A[i + 1];
        length--;
    }
    return x;
}

void Array ::swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int Array ::LinearSearch(int key)
{
    int i;
    for (i = 0; i < length; i++)
    {
        if (key == A[i])
        {
            swap(&A[i], &A[0]);
            return i;
        }
    }
    return -1;
}

int Array ::BinarySeach(int key)
{
    int l, mid, h;
    l = 0;
    h = length - 1;

    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == A[mid])
            return mid;
        else if (key < A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int Array ::Get(int index)
{
    if (index >= 0 && index < length)
        return A[index];
    return -1;
}

void Array ::Set(int index, int x)
{
    if (index >= 0 && index < length)
        A[index] = x;
}

int Array ::Max()
{
    int max = A[0];
    int i;
    for (i = 0; i < length; i++)
    {
        if (A[i] > max)
            max = A[i];
    }
    return max;
}

int Array ::Min()
{
    int min = A[0];
    int i;
    for (i = 0; i < length; i++)
    {
        if (A[i] > min)
            min = A[i];
    }
    return min;
}

int Array::Sum()
{
    int sum = 0;
    int i;
    for (i = 0; i < length; i++)
        sum += A[i];

    return sum;
}

float Array::Avg()
{
    return (float)Sum() / length;
}

void Array::Reverse()
{
    int *B;
    int i, j;
    B = new int[length];
    for (i = length - 1, j = 0; i >= 0; i--, j++)
    {
        B[j] = A[i];
    }
    for (i = 0; i < j; i++, j = length - 1, j--)
    {
        A[i] = B[j];
    }
}

void Array ::Reverse2()
{
    int i, j;
    for (i = 0; i < j; i++, j = length - 1, j--)
    {
        swap(&A[i], &A[j]);
    }
}

void Array ::InsertSort(int x)
{
    int i = length - 1;
    if (length == size)
        return;
    while (i >= 0 && A[i] > x)
    {
        A[i + 1] = A[i];
        i--;
        // 1 2 3 5 6 7
        //insert 4
        //i=5->6=7
        //i=5->5=6
        //i=3->4=5
        //i=2-> stop->insert 4 at index 3
    }
    A[i + 1] = x;
    length++;
}

int Array::isSorted()
{
    int i;
    for (i = 0; i < length - 1; i++)
    {
        if (A[i] > A[i + 1])
            return 0;
    }
    return 1;
}

void Array::Rearrange()
{
    int i, j;
    i = 0;
    j = length - 1;

    while (i < j)
    {
        while (A[i] < 0)
            i++;
        while (A[j] > 0)
            j++;
        if (i < j)
            swap(&A[i], &A[j]);
    }
}

int main()
{
    Array *arr1;
    int ch, sz;
    int x, index;

    cout << "enter the size of array:" << endl;
    cin >> sz;
    arr1 = new Array[sz];

    do
    {
        cout << "Menu:" << endl;
        cout << "1.Display" << endl;
        cout << "2.Append" << endl;
        cout << "3.Insert" << endl;
        cout << "4.Delete" << endl;
        cout << "5.LinearSerach" << endl;
        cout << "6.BinarySEarch" << endl;
        cout << "7.Get" << endl;
        cout << "8.Carry on" << endl;
        cout << "9.Set" << endl;
        cout << "10.Max" << endl;
        cout << "11.Min" << endl;
        cout << "12.Sum" << endl;
        cout << "13.Avg" << endl;
        cout << "14.Reverse" << endl;
        cout << "15.Reverse2" << endl;
        cout << "16.InsertSort" << endl;
        cout << "17.isSorted" << endl;
        cout << "18.Rearrange" << endl;
        cout << "19.Exit" << endl;

        cout << "Enter your choice:" << endl;
        cin >> ch;

        switch (ch)
        {
        case 1:
            arr1->Display();
            break;
        case 2:
            cout << "Enter an element to append" << endl;
            cin >> x;
            arr1->Append(x);
            break;
        case 3:
            cout << "Enter an element and index to insert" << endl;
            cin >> x >> index;
            arr1->Insert(index, x);
            break;
        case 4:
            cout << "Enter an index to delete an element " << endl;
            cin >> index;
            arr1->Delete(index);
            break;
        case 5:
            cout << "Enter an element to search" << endl;
            cin >> x;
            arr1->LinearSearch(x);
            break;
        case 6:
            cout << "Enter an element to search" << endl;
            cin >> x;
            arr1->BinarySeach(x);
            break;
        case 7:
            cout << "Enter an index to get an element" << endl;
            cin >> index;
            arr1->Get(index);
            break;
        case 8:
            cout << "Nothing here keep going" << endl;
            break;
        case 9:
            cout << "Enter element and index  to set an element" << endl;
            cin >> x >> index;
            arr1->Set(index, x);
            break;
        case 10:
            arr1->Max();
            break;
        case 11:
            arr1->Min();
            break;
        case 12:
            arr1->Sum();
            break;
        case 13:
            arr1->Avg();
            break;
        case 14:
            arr1->Reverse();
            break;
        case 15:
            arr1->Reverse2();
            break;
        case 16:
            cout << "enter an element to Insert in a sorted array" << endl;
            cin >> x;
            arr1->InsertSort(x);
            break;
        case 17:
            arr1->isSorted();
            break;
        case 18:
            arr1->Rearrange();
        }

    } while (ch < 19);
    return 0;
}
