#include <iostream>
#include "ordenacao.h"

void countingSort( long* A, long maxElem, long minElem, long nElem )
{
    long i, j, B[nElem], range = maxElem - minElem + 1;
    long* C = new long[range];
    for ( i = 0; i < range; i++ ) {
        C[i] = 0;
    }

    for ( j = 0; j < nElem; j++ ) {
        C[A[j]-minElem] += 1;
    }

    for ( i = 1; i < range; i++ ) {
        C[i] += C[i-1];
    }

    for ( j = nElem - 1; j >= 0; j-- ) {
        B[C[A[j]-minElem] - 1] = A[j];
        C[A[j]-minElem]--;
    }

    for ( i = 0; i < nElem; i++ ) {
        A[i] = B[i];
    }
}

void radixSort( long* A, long maxElem, long nElem )
{
    for ( long d = 1; maxElem/d > 0; d*=10 ) {
        radixCount( A, nElem, d);
    }
}

void radixCount( long* A, long nElem, long n )
{
    long B[nElem], C[19] = {0}, i, j;

    for ( j = 0; j < nElem; j++ ) {
        C[ ((A[j] / n) % 10) + 9 ] += 1;
    }

    for ( i = 1; i < 19; i++ ) {
        C[i] += C[i-1];
    }

    for ( j = nElem-1; j >= 0; j-- ) {
        B[C[ ((A[j] / n) % 10) + 9 ] - 1] = A[j];
        C[ ((A[j] / n) % 10) + 9 ]--;
    }

    for ( i = 0; i < nElem; i++ ) {
        A[i] = B[i];
    }
}

void selectionSort( long* A, long nElem )
{
    long i, j;
    for ( i = 0; i < nElem-1; i++ ) {
        long minElem = i;
        for ( j = i+1; j < nElem; j++ ) {
            if ( A[j] < A[minElem] )
                minElem = j;
        }

        if( minElem != i ) {
            long aux = A[i];
            A[i] = A[minElem];
            A[minElem] = aux;
        }
    }
}

void insertionSort( long* A, long nElem )
{
    long i, j, elem;
    for ( i = 1; i < nElem; i++ ) {
        elem = A[i];
        j = i - 1;

        while( j >= 0 && A[j] > elem ) {
            A[j+1] = A[j];
            j--;
        }

        A[j+1] = elem;
    }
}