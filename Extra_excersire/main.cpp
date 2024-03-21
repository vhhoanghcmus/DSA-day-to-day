#include "bubble_short.h"
#include "heap_sort.h"
#include "insertion_sort.h"
#include "interchange_Sort.h"
#include "merge_sort.h"
#include "natural_merge_sort.h"
#include "quick_sort.h"
#include "radix_sort.h"
#include "radix_sort.h"
#include "selection_sort.h"
#include "selection_sort_Max.h"
#include "selection_sort.h"
#include "shell_sort.h"

#include <bits/stdc++.h>


int flag = 0;
void table_choice(){
        std :: cout << "================================\n";
        std :: cout << "1  ->  Inter Change sort \n";
        std :: cout << "2  ->  Selection sort \n";
        std :: cout << "3  ->  Intertion sort \n";
        std :: cout << "4  ->  Bubble sort \n";
        std :: cout << "5  ->  Quick sort \n";
        std :: cout << "6  ->  Heap sort \n";
        std :: cout << "7  ->  Shell sort \n";
        std :: cout << "8  ->  Merge sort \n";
        std :: cout << "9  ->  Nature Merge \n";
        std :: cout << "10 ->  Radix sort \n";
        std :: cout << "11 ->  Selection sort max \n";
        std :: cout << "99 ->  Quick \n";
        std :: cout << "=================================\n";
        std :: cout << "Input your option: ";
}

int main() {
    int arr[12];
    int n = sizeof(arr) / sizeof(arr[0]);

    table_choice();

    std :: cin >> flag;

    switch (flag)
    {
    case 1 :
        InterchangeSort(arr, n);
        break;
    case 2 :
        selectionSort(arr, n);
        break;
    case 3 :
        break;
    case 4 :
        bubble_sort(arr, n);
        break;
    case 5 :
        quickSort(arr, 0, n-1);
        break;
    case 6 :
        heapSort(arr, n);
        break;
    case 7 :
        shellSort(arr, n);
        break;
    case 8 :
        mergeSort(arr, 0, n-1);
        break;
    case 9 :
        /* code */
        break;
    case 10 :
        radixsort(arr, n);
        break;
    case 11 :
        
        break;
    case 99 :
        break;
    default:
        break;
    }

}