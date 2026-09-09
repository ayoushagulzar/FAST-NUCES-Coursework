// A university stores attendance percentages: 55 61 67 72 78 81 80 85 The attendance
// data is nearly sorted Using Modified Bubble Sort, determine:
//     1. After which pass does the array become sorted?
//     2. How many comparisons are performed before the algorithm terminates?
//     3. How many swaps are performed?
//     4. How many passes would standard Bubble Sort perform on the same array?
//     5. How many comparisons would standard Bubble Sort perform?


#include<iostream>
#include<windows.h>
using namespace std;

static int no_of_passes = 0;
static int no_of_comparisons = 0;
static int no_of_swaps = 0;
static int bubble_passes = 0;
static int bubble_comparisons = 0;

void printArray(int arr[] , int n);

void bubble_sort(int arr[] , int n){
    //no: of passes
    for (int i = 0; i < n - 1; i++)
    {
        bubble_passes++;

        //no: of comparisons
        for (int j = 0; j < n - 1 - i; j++)
        {
            bubble_comparisons++;
            if (arr[j] > arr[j + 1])
            {
               int temp = arr[j];
               arr[j] = arr [j+1];
               arr[j+1] = temp;
            }
        }
    }  
}

void modified_bubble_sort(int arr[] , int n){
    //no: of passes
    for (int i = 0; i < n - 1; i++)
    {
        no_of_passes++;
        bool flag = false;

        //no: of comparisons
        for (int j = 0; j < n - 1 - i; j++)
        {
            no_of_comparisons++;
            if (arr[j] > arr[j + 1])
            {
               int temp = arr[j];
               arr[j] = arr [j+1];
               arr[j+1] = temp;
               no_of_swaps++;
               flag = true; 
            }
        }
        if (flag == false)
            break;         
    }
}

void printArray(int arr[] , int n){
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
}

int main(){
    int n = 8;
    int array1[] = {55, 61, 67, 72, 78, 81, 80, 85};
    int array2[] = {55, 61, 67, 72, 78, 81, 80, 85};

    cout << "Original Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << array1[i] << " ";
    }

    bubble_sort(array1 , n);
    modified_bubble_sort(array2 , n);
    cout<<endl;

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << array2[i] << " ";
    }
    cout<<endl;

    cout << "Array become sorted after pass " << no_of_passes << endl;
    cout << "Number of Comparisons: " << no_of_comparisons << endl;
    cout << "Number of Swaps: " << no_of_swaps << endl;
    cout << "Standard bubble sort passses: " << bubble_passes << endl;
    cout << "Standard bubble sort Comparisons: " << bubble_comparisons << endl;
    return 0;
}