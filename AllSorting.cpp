// SELECTION SORT


// #include <iostream>
// using namespace std;

// void selectionsort(int arr[], int n)
// {
//     for (int i = 0; i < n - 1; i++)
//     {
//         int minindex = i;
//         for (int j = i + 1; j < n; j++)
//         {
//             if (arr[j] < arr[minindex])
//             {
//                 minindex = j;
//             }
//         }
//         if (minindex != i)
//         {
//             int temp = arr[i];
//             arr[i] = arr[minindex];
//             arr[minindex] = temp;
//         }
//     }
// }

// int main()
// {
//     int n;
//     cout << "Enter size of array: ";
//     cin >> n;

//     int* array = new int[n];

//     cout << "Enter the elements of the array: " << endl;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> array[i];
//     }

//     selectionsort(array, n);

//     cout << "Sorted array: " << endl;
//     for (int i = 0; i < n; i++)
//     {
//         cout << array[i] << " ";
//     }
//     cout << endl;

//     delete[] array;

//     return 0;
// }


// INSERTION SORT

// #include <iostream>
// using namespace std;

// void insertionSort(int arr[], int n)
// {
//     for (int i = 1; i < n; i++)
//     {
//         for (int j = i; j > 0; j--)
//         {
//             if (arr[j] < arr[j - 1])
//             {
//                 int temp = arr[j];
//                 arr[j] = arr[j - 1];
//                 arr[j - 1] = temp;
//             }
//             else
//             {
//                 break;
//             }
//         }
//     }
// }

// int main()
// {
//     int n;
//     cout << "Enter the size of the array: ";
//     cin >> n;

//     int arr[n];
//     cout << "Enter the elements of the array: ";
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }

//     insertionSort(arr, n);

//     cout << "Sorted array: ";
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }


//QUICK SORT


