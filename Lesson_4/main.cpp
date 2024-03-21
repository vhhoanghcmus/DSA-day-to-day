#include "quick_sort.h"
#include "interchange_Sort.h"
#include <bits/stdc++.h>

void Time_run_interchange_sort(int arr[]){
    cout << "start loop. Processing!!" << endl;
    time_t start, end;  

        /* You can call it like this : start = time(NULL); 
    in both the way start contain total time in seconds 
    since the Epoch. */

    time(&start); 
 
    InterchangeSort(arr, 1000000);
 
   // Recording end time. 
    time(&end);
    // Calculating total time taken by the program. 
    double time_taken = double(end - start); 
    cout << "Time taken by Interchange sort is : " << fixed << time_taken << setprecision(10); 
    cout << " sec " << endl;
}


void Time_run_quick_sort(int arr[]){
    time_t start, end;  

        /* You can call it like this : start = time(NULL); 
    in both the way start contain total time in seconds 
    since the Epoch. */

    time(&start); 
 
    quickSort(arr, 0, 1000000-1);
 
   // Recording end time. 
    time(&end);
    // Calculating total time taken by the program. 
    double time_taken = double(end - start); 
    cout << "Time taken by Quick sort is : " << fixed << time_taken << setprecision(10); 
    cout << " sec " << endl; 
}



using namespace std; 

int main() 
{  
    int temp;
    int* arr = new int[1000000];
    for (int i = 0; i < 1000000; i++) {
        temp = rand();
        arr[i] = temp;
    }
    int* arr2 = new int[1000000];
    for(int i = 0; i < 1000000; i++) {
        arr2[i] = arr[i];
    }

    Time_run_quick_sort(arr2);

    delete[] arr;
    delete[] arr2;
    return 0; 
} 