#pragma once
#include <bits/stdc++.h> 

void bubble_sort(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 1; j < n - 1; j++) {
            if(arr[j] < arr[i]){
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}
