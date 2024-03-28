#pragma once
#include <iostream>



void InterchangeSort( int a[], int N) {
    int i, j;
    for( i = 0; i < N; i++ ) {
        for ( j = i + 1; j < N; j++) {
            if ( a[ j ] < a[ i ] ) {
                std :: swap(a[ i ], a[ j ]);
            }
        }
    }
}