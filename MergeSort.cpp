#include <iostream>
using namespace std;
void combine(int *,int, int , int );
void merge_sort(int *arr, int p, int r);


int main()
{
    //int A[]={2,4,5,7,1,2,3,6};
    int A[]={2,8,0,6,23,3,47,1};
    int p=0; 
	int r=7;		// r=7 instead of 8
    cout<<"Initial Array"<<endl;
    for (int i = 0; i <= r; i++)
    {
        cout<<A[i]<<"\t";
    }


    merge_sort(A, p, r);
    
    cout<<endl<<"Sorted array"<<endl;
    for (int i = 0; i <= r; i++)
    {
        cout<<A[i]<<"\t";
    }
}

void merge_sort(int *arr, int p, int r)
{
    int q;
    if (p < r)
	{
        q=(p+r)/2;
        merge_sort(arr,p,q);
        merge_sort(arr,q+1,r);
        combine(arr,p,r,q);
    }
}


// Combination Segment in Merge sort 
void combine(int *arr, int p, int r, int q)
{
    int i, j, k, c[10];
 
    // c is auxillary or temporary array
    i = p;
    j = q + 1;
	k = p;
    
    // i starts from p and goes till q
    // j starts with q+1 and goes till r
    while (i <= q && j <= r) 
	{
        if (arr[i] < arr[j]) 
		{
            c[k] = arr[i];
            k++;
            i++;
        }
        else  // means arr[i] >= arr[j] 
		{
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    	// If the condition j<=r reaches earlier
    while (i <= q) 
	{
        c[k] = arr[i];
        k++;
        i++;
    }

      	// If the condition i<=q reaches earlier
    while (j <= r) 
	{
        c[k] = arr[j];
        k++;
        j++;
    }
    
	for (i = p; i <= r; i++)  
	{
        arr[i] = c[i];
    }
}

