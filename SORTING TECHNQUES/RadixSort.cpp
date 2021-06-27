
// implementation of radix sort using bin/bucket sort
#include <bits/stdc++.h>
using namespace std;

// structure for a single linked list to help further in the
// sorting
struct node {
	int data;
	node* next;
};

// function for creating a new node in the linked list
struct node* create(int x)
{
	node* temp = new node();
	temp->data = x;
	temp->next = NULL;

	return temp;
}

// utility function to append node in the linked list
// here head is passed by reference, to know more about this
// search pass by reference
void insert(node*& head, int n)
{
	if (head == NULL) {
		head = create(n);
		return;
	}

	node* t = head;
	while (t->next != NULL)
		t = t->next;
	t->next = create(n);
}

// utility function to pop an element from front in the list
// for the sake of stability in sorting
int del(node*& head)
{
	if (head == NULL)
		return 0;
	node* temp = head;
	// storing the value of head before updating
	int val = head->data;

	// updation of head to next node
	head = head->next;

	delete temp;
	return val;
}

int findMax(int arr[], int n)
{
    int max =arr[0];
    for( int i =0; i<n; i++)
    {
        if(arr[i]>max)
            max = arr[i];
    }
    return max;
}

// utility function to get the number of digits in the
// max_element
int digits(int n)
{
	int i = 0;
	while(n!=0)
    {
        n =n/10;
        i++;
    }
	return i;
}

void radix_sort(int arr[],int size)
{

	// getting the maximum element in the array
	int max = findMax(arr, size);

	// getting digits in the maximum element
	int d = digits(max);

	// creating buckets to store the pointers
	node** bins;

	// array of pointers to linked list of size 10 as
	// integers are decimal numbers so they can hold numbers
	// from 0-9 only, that's why size of 10

	bins = new node*[10];

	// intializing the hash array with null to all
	for (int i = 0; i < 10; i++)
		bins[i] = NULL;

	// first loop working for a constan time only and inner
	// loop is iterating through the array to store elements
	// of array in the linked list by their digits value
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < size; j++) // bins updation
			insert(bins[(arr[j] / (int)pow(10, i)) % 10],
				arr[j]);

		int x = 0, y = 0;
		// write back to the array after each pass

		while (x < 10) {
			while (bins[x] != NULL)
				arr[y++] = del(bins[x]);
			x++;
		}
	}
}

// a utility function to print the sorted array
void print(int arr[], int size)
{
	for (int i = 0; i <size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	int arr[] = { 573, 25, 415, 12, 161, 6 };
    int size = 6;

	// function call
	radix_sort(arr, size);
	print(arr, size);

	return 0;
}
