#include <iostream>
using namespace std;
 
void printArray(int arr[], int size) 
{
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int partition(int *arr, int low,int high)
{
	int pivot=arr[low];
	int i=low+1;
	int j=high;
	int temp;
	do
	{
		while(arr[i]<=pivot)
		{
			i++;
		}
		while(arr[j]>pivot)
		{
			j--;
		}
		if(i<j)
		{
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}while(i<=j);
	//Swap arr[low] and arr[j]
	temp=arr[low];
	arr[low]=arr[j];
	arr[j]=temp;
	return j;
}
 
void quicksort(int *arr,int low,int high)
{
	int partitionindex; //Index of pivot after patition
	if(low<high)
	{
		partitionindex=	partition(arr,low,high);
		quicksort(arr,low,partitionindex-1); //Sort left subarray 
		quicksort(arr,partitionindex+1,high); //Sort right subarray
	}
}
 
int main()
{
	int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Unsorted array: ";
    printArray(arr, n);
    cout<<"-----------------------------\n";
    quicksort(arr, 0,n-1);
    cout << "Sorted array: ";
    printArray(arr, n);
    return 0;
}