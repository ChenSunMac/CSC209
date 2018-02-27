#include<stdio.h>
#include <stdlib.h>

const int NUM = 50;
const int LIMIT = 10;

// exchange the values of array by given indexes
void exch_by_index(int* arr, int index1, int index2){ 
  int temp = arr[index1];
  arr[index1] = arr[index2];
  arr[index2] = temp;
}

// insert element in the back and move everything back one index
void insert_element(int* arr, int element_index, int dest_index){
  int temp = arr[element_index];
  for (int i = element_index; i > dest_index; i--){
    arr[i] = arr[i - 1];
  }
  arr[dest_index] = temp;
}


// insertion sort
void InsertSort(int* s,int low,int up){  
        for(int i=low+1;i<=up;i++)  
        {  
                for(int j=low;j<i;j++)  
                {  
                        if(s[i]<s[j])  
                                insert_element(s,i,j);  
                }  
        }  
}  
// quick sort 
int QSort(int* s,int low,int up)//快速排序  
{  
        if(up <= low+LIMIT)//是小数组时采用插入排序  
        {  
            InsertSort(s,low,up);  
            return 0;  
        }  
        else  
        {  
                int key=s[low];  
                int i=low;  
                int j=up;  
                up++;  
                while(low<up)  
                {  
                        low++;  
                        while(low<up&&s[low]<=key)  
                                low++;  
                        up--;  
                        while(low<=up&&s[up]>=key)  
                                up--;  
                        if(low<up)  
                                exch_by_index(s,low,up);  
                }  
                exch_by_index(s,i,up);  
                QSort(s,i,up-1);  
                QSort(s,up+1,j);  
                return 0;
        }  
}  


void sort(int *arr_ptr, int arr_sz){
  QSort(arr_ptr,0,arr_sz - 1);
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
        int array[NUM];  
        srand(2);//initialize  random number   
        for(int i=0;i<NUM;i++)//from 1 - 100
        {  
                array[i]=rand() % 101;  
        }  
        for(int i=0;i<NUM;i++)//output number array
        {  
                printf("%d ",array[i]);  
        }  
        sort(array,NUM);  
        printf("\n");  
        for(int i=0;i<NUM;i++)  
        {  
                printf("%d ",array[i]);  
        }  
    return 0;  
}