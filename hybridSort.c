#include<stdio.h>


void insertionSort(int arr[], int low, int high)
{
	for (int x = low + 1; x < high ; x ++){
		int val = arr[x];
		int j = x - 1;
		while (j>=0 && val < arr[j]){
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = val;
	}
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 
/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quicksort(int * tab, int l, int r)
{
   int q;
   while(l < r - 10)
   {
      q = partition(tab, l, r);
      if(q - l < r - q) //recurse into the smaller half
      {
         quicksort(tab, l, q - 1);
         l = q + 1;
      } else
      {
         quicksort(tab, q + 1, r);
         r = q - 1;
      }
   }
}


/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("n");
}
 
// Driver program to test above functions
int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5,1,3,4,4,6,7,8,9,13,22,34,12,24,12,3,512,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    qsort4(arr, 0, n-1);
    printf("Sorted array: n");
    printArray(arr, n);
    return 0;
}