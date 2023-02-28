# Assignment

## selection sort
```
procedure selection sort 
   list  : array of items
   n     : size of list

   for i = 1 to n - 1
   /* set current element as minimum*/
      min = i    
  
      /* check the element to be minimum */

      for j = i+1 to n 
         if list[j] < list[min] then
            min = j;
         end if
      end for

      /* swap the minimum element with the current element*/
      if indexMin != i  then
         swap list[min] and list[i]
      end if
   end for
	
end procedure
```
## Recursive Selection Sort
```
// Recursive C++ program to sort an array
// using selection sort
#include <iostream>
using namespace std;

// Return minimum index
int minIndex(int a[], int i, int j)
{
	if (i == j)
		return i;

	// Find minimum of remaining elements
	int k = minIndex(a, i + 1, j);

	// Return minimum of current and remaining.
	return (a[i] < a[k])? i : k;
}

// Recursive selection sort. n is size of a[] and index
// is index of starting element.
void recurSelectionSort(int a[], int n, int index = 0)
{
	// Return when starting and size are same
	if (index == n)
	return;

	// calling minimum index function for minimum index
	int k = minIndex(a, index, n-1);

	// Swapping when index and minimum index are not same
	if (k != index)
	swap(a[k], a[index]);

	// Recursively calling selection sort function
	recurSelectionSort(a, n, index + 1);
}

// Driver code
int main()
{
	int arr[] = {3, 1, 5, 2, 7, 0};
	int n = sizeof(arr)/sizeof(arr[0]);

	// Calling function
	recurSelectionSort(arr, n);

	//printing sorted array
	for (int i = 0; i<n ; i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}

```

```
t(n) = n+t(n-1) O(N^2)

```

## Insertion sort
<img width="194" alt="image" src="https://user-images.githubusercontent.com/96559286/221920740-548bdc7e-9642-4979-8bc1-0b1d547b4fdb.png">


```
// C++ program for insertion sort

#include <bits/stdc++.h>
using namespace std;

// Function to sort an array using
// insertion sort
void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		// Move elements of arr[0..i-1],
		// that are greater than key, to one
		// position ahead of their
		// current position
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

// A utility function to print an array
// of size n
void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

// Driver code
int main()
{
	int arr[] = { 12, 11, 13, 5, 6 };
	int N = sizeof(arr) / sizeof(arr[0]);

	insertionSort(arr, N);
	printArray(arr, N);

	return 0;
}
// This is code is contributed by rathbhupendra

```

```
// Recursive C++ program for insertion sort
#include <iostream>
using namespace std;

// Recursive function to sort an array using
// insertion sort
void insertionSortRecursive(int arr[], int n)
{
	// Base case
	if (n <= 1)
		return;

	// Sort first n-1 elements
	insertionSortRecursive( arr, n-1 );

	// Insert last element at its correct position
	// in sorted array.
	int last = arr[n-1];
	int j = n-2;

	/* Move elements of arr[0..i-1], that are
	greater than key, to one position ahead
	of their current position */
	while (j >= 0 && arr[j] > last)
	{
		arr[j+1] = arr[j];
		j--;
	}
	arr[j+1] = last;
}

// A utility function to print an array of size n
void printArray(int arr[], int n)
{
	for (int i=0; i < n; i++)
		cout << arr[i] <<" ";
}

/* Driver program to test insertion sort */
int main()
{
	int arr[] = {12, 11, 13, 5, 6};
	int n = sizeof(arr)/sizeof(arr[0]);

	insertionSortRecursive(arr, n);
	printArray(arr, n);

	return 0;
}

```

```
t(n) = (n-1) + t(n-1)  O(N^2)
```

## Bubble Sort 
![image](https://user-images.githubusercontent.com/96559286/221922083-3cb9a7e1-a0d3-478e-b85b-5eac154d310a.png)

```
// C program for implementation of Bubble sort
#include <stdio.h>

void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)

		// Last i elements are already in place
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}

/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

// Driver program to test above functions
int main()
{
	int arr[] = { 5, 1, 4, 2, 8 };
	int n = sizeof(arr) / sizeof(arr[0]);
	bubbleSort(arr, n);
	printf("Sorted array: \n");
	printArray(arr, n);
	return 0;
}

```

```
Time Complexity: O(N2)
Auxiliary Space: O(1) 
```
```
// C++ program for recursive implementation
// of Bubble sort
#include <bits/stdc++.h>
using namespace std;

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
	// Base case
	if (n == 1)
		return;

	int count = 0;
	// One pass of bubble sort. After
	// this pass, the largest element
	// is moved (or bubbled) to end.
	for (int i=0; i<n-1; i++)
		if (arr[i] > arr[i+1]){
			swap(arr[i], arr[i+1]);
			count++;
		}

	// Check if any recursion happens or not
	// If any recursion is not happen then return
	if (count==0)
		return;

	// Largest element is fixed,
	// recur for remaining array
	bubbleSort(arr, n-1);
}

/* Function to print an array */
void printArray(int arr[], int n)
{
	for (int i=0; i < n; i++)
		cout<<arr[i]<<" ";
	cout<<"\n";
}

// Driver program to test above functions
int main()
{
	int arr[] = {64, 34, 25, 12, 22, 11, 90};
	int n = sizeof(arr)/sizeof(arr[0]);
	bubbleSort(arr, n);
	cout<<"Sorted array : \n";
	printArray(arr, n);
	return 0;
}

// Code improved by Susobhan Akhuli

```

## Merge Sort

```
step 1: start

step 2: declare array and left, right, mid variable

step 3: perform merge function.
    if left > right
        return
    mid= (left+right)/2
    mergesort(array, left, mid)
    mergesort(array, mid+1, right)
    merge(array, left, mid, right)

step 4: Stop
```
```
// C++ program for Merge Sort
#include <iostream>
using namespace std;

// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(int array[], int const left, int const mid,
		int const right)
{
	auto const subArrayOne = mid - left + 1;
	auto const subArrayTwo = right - mid;

	// Create temp arrays
	auto *leftArray = new int[subArrayOne],
		*rightArray = new int[subArrayTwo];

	// Copy data to temp arrays leftArray[] and rightArray[]
	for (auto i = 0; i < subArrayOne; i++)
		leftArray[i] = array[left + i];
	for (auto j = 0; j < subArrayTwo; j++)
		rightArray[j] = array[mid + 1 + j];

	auto indexOfSubArrayOne
		= 0, // Initial index of first sub-array
		indexOfSubArrayTwo
		= 0; // Initial index of second sub-array
	int indexOfMergedArray
		= left; // Initial index of merged array

	// Merge the temp arrays back into array[left..right]
	while (indexOfSubArrayOne < subArrayOne
		&& indexOfSubArrayTwo < subArrayTwo) {
		if (leftArray[indexOfSubArrayOne]
			<= rightArray[indexOfSubArrayTwo]) {
			array[indexOfMergedArray]
				= leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else {
			array[indexOfMergedArray]
				= rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}
	// Copy the remaining elements of
	// left[], if there are any
	while (indexOfSubArrayOne < subArrayOne) {
		array[indexOfMergedArray]
			= leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}
	// Copy the remaining elements of
	// right[], if there are any
	while (indexOfSubArrayTwo < subArrayTwo) {
		array[indexOfMergedArray]
			= rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
	delete[] leftArray;
	delete[] rightArray;
}

// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int array[], int const begin, int const end)
{
	if (begin >= end)
		return; // Returns recursively

	auto mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid);
	mergeSort(array, mid + 1, end);
	merge(array, begin, mid, end);
}

// UTILITY FUNCTIONS
// Function to print an array
void printArray(int A[], int size)
{
	for (auto i = 0; i < size; i++)
		cout << A[i] << " ";
}

// Driver code
int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	auto arr_size = sizeof(arr) / sizeof(arr[0]);

	cout << "Given array is \n";
	printArray(arr, arr_size);

	mergeSort(arr, 0, arr_size - 1);

	cout << "\nSorted array is \n";
	printArray(arr, arr_size);
	return 0;
}

// This code is contributed by Mayank Tyagi
// This code was revised by Joshua Estes

```
```
t(n) = 2t(n/2) + n ==>2^jt(n/2^j) + jn
◦ Two subproblems of size n/2
◦ Merging solutions requires time O(n/2 + n/2) = O(n)
= O(n log n)


```
### Merge Sort – Shortcomings

```
Merging A and B creates a new array C
◦ No obvious way to efficiently merge in place
• Extra storage can be costly
• Inherently recursive
◦ Recursive call and return are expensive
```
## Quicksort

```
Choose a pivot element
◦ Typically the first value in the array
• Partition A into lower and upper parts with respect to pivot
• Move pivot between lower and upper partition
• Recursively sort the two partitions
```
<img width="455" alt="image" src="https://user-images.githubusercontent.com/96559286/221924458-a4a555f8-4f47-451c-99ee-ddb85dbbb39a.png">

## Pseudo Code for recursive QuickSort function:
```
/* low  –> Starting index,  high  –> Ending index */

quickSort(arr[], low, high) {

    if (low < high) {

        /* pi is partitioning index, arr[pi] is now at right place */

        pi = partition(arr, low, high);

        quickSort(arr, low, pi – 1);  // Before pi

        quickSort(arr, pi + 1, high); // After pi

    }

}
```
## Pseudo code for partition() 
```
/* This function takes last element as pivot, places the pivot element at its correct position in sorted array, and places all smaller (smaller than pivot) to left of pivot and all greater elements to right of pivot */

partition (arr[], low, high)
{
    // pivot (Element to be placed at right position)
    pivot = arr[high];  

    i = (low – 1)  // Index of smaller element and indicates the 
    // right position of pivot found so far

    for (j = low; j <= high- 1; j++){

        // If current element is smaller than the pivot
        if (arr[j] < pivot){
            i++;    // increment index of smaller element
            swap arr[i] and arr[j]
        }
    }
    swap arr[i + 1] and arr[high])
    return (i + 1)
}

```

```
/* C++ implementation of QuickSort */
#include <bits/stdc++.h>
using namespace std;

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition(int arr[], int low, int high)
{
	int pivot = arr[high]; // pivot
	int i
		= (low
		- 1); // Index of smaller element and indicates
				// the right position of pivot found so far

	for (int j = low; j <= high - 1; j++) {
		// If current element is smaller than the pivot
		if (arr[j] < pivot) {
			i++; // increment index of smaller element
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
	if (low < high) {
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

// Driver Code
int main()
{
	int arr[] = { 10, 7, 8, 9, 1, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, n - 1);
	cout << "Sorted array: \n";
	printArray(arr, n);
	return 0;
}




```

```
◦ t(n) = 2t(n/2) + n = O(n log n) O(N^2)
```

## Recursion Tree Method
```
1. Recursion Tree Method is a pictorial representation of an iteration method which is in the form of a tree where at each level nodes are expanded.

2. In general, we consider the second term in recurrence as root.

3. It is useful when the divide & Conquer algorithm is used.

4. It is sometimes difficult to come up with a good guess. In Recursion tree, each root and child represents the cost of a single subproblem.

```
```
eg:Consider T (n) = 2TDAA Recurrence Relation + n2
```
<img width="422" alt="image" src="https://user-images.githubusercontent.com/96559286/221926085-102c2414-6123-4723-9eef-59ecdde10f8f.png">
```
https://www.javatpoint.com/daa-recursion-tree-method
```
