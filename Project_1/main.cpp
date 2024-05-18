#include "bubble_short.h"
#include "heap_sort.h"
#include "insertion_sort.h"
#include "inter_change_Sort.h"
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

using namespace std;
void show_input(int arr[],int n) {
    for( int i = 0; i < n; i++ ) {
        cout << arr[i] << " ";
    }
        cout << endl;
}

void create_array(int arr[], int n) {
    for ( int i = 0; i < n; i++) {
        arr[i] = rand();
    }
}

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
}

void Choice(int arr[], int n) {
    table_choice();
    do {
    std :: cout << "Input your option: ";
    std :: cin >> flag;
    if(flag < 99 && flag > 0) {
        if(flag > 11) {
            cout << "Option must be 1 to 11 or 99, please enter a legit value: ";
        } else {
            if(flag == 99)  continue;
            else   cout << "Option must be 1 to 11 or 99, please enter a legit value: ";
        }
    }
    switch (flag)
    {
    case 1 :
    cout << "Interchange sort: " << endl;
        create_array(arr, n - 1);
        InterchangeSort(arr, n-1);
        show_input(arr, n-1);
        break;
    case 2 :
        cout << "Selection sort: " << endl;
        create_array(arr, n - 1);
        selectionSort(arr, n-1);
        show_input(arr, n - 1);
        break;
    case 3 :
        cout << "Insertion sort: " << endl;
        create_array(arr, n - 1);
        insertionSort(arr, n - 1);
        show_input(arr, n - 1 );
        break;
    case 4 :
        cout << "Bubble sort: " << endl;
        create_array(arr, n - 1);
        bubble_sort(arr, n - 1);
        show_input(arr, n-1);
        break;
    case 5 :
        cout << "Quick sort: " << endl;
        create_array(arr, n - 1);
        quickSort(arr, 0, n - 1 );
        show_input(arr, n - 1);
        break;
    case 6 :
        cout << "Heap sort: " << endl;
        create_array(arr, n - 1 );
        heapSort(arr, n - 1);
        show_input(arr, n - 1 );
        break;
    case 7 :
        cout << "Shell sort: " << endl;
        create_array(arr, n - 1);
        shellSort(arr, n - 1 );
        show_input(arr, n - 1 );
        break;
    case 8 :
        cout << "Merge sort: " << endl;
        create_array(arr, n - 1 );
        mergeSort(arr, 0, n - 1 );
        show_input(arr, n - 1 );
        break;
    case 9 :
        cout << "Nature Merge sort: " << endl;
        create_array(arr, n - 1 );
        naturalMergeSort(arr, n -1 );
        show_input(arr, n - 1 );
        break;
    case 10 :
        cout << "Radix sort: " << endl;
        create_array(arr, n - 1 );
        radixsort(arr, n - 1 );
        show_input(arr, n - 1 );
        break;
    case 11 :
        cout << "Selection sort max: " << endl;
        create_array(arr, n - 1 );
        minMaxSelectionSort(arr, n - 1 );
        show_input(arr, n - 1 );
        break;
    case 99 :
        break;
    default:
        break;
    }
} while (flag !=99);
}

int main() {
    int arr[12];
    int n = sizeof(arr) / sizeof(arr[0]);
    create_array(arr, n);
    show_input(arr, n);
    Choice(arr, n);
}