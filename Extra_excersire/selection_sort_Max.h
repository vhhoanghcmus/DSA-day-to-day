#pragma once
#include <iostream>

void minMaxSelectionSort(int arr[], int n) 
{ 
    for (int i = 0, j = n - 1; i < j; i++, j--) { 
        int min = arr[i], max = arr[i]; 
        int min_i = i, max_i = i; 
        for (int k = i; k <= j; k++)  { 
            if (arr[k] > max) { 
                max = arr[k]; 
                max_i = k; 
            } else if (arr[k] < min) { 
                min = arr[k]; 
                min_i = k; 
            } 
        } 
  
        // shifting the min. 
        std :: swap(arr[i], arr[min_i]); 
  
        // Shifting the max. The equal condition 
        // happens if we shifted the max to arr[min_i]  
        // in the previous std :: swap. 
        if (arr[min_i] == max)  
            std :: swap(arr[j], arr[min_i]); 
        else
            std :: swap(arr[j], arr[max_i]); 
    } 
} 