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

void mergeSort( long *A, long l, long r )
{
    if ( l >= r )
        return;

    long m = l + ( r - l ) / 2;

    mergeSort( A, l, m );
    mergeSort( A, m+1, r );

    merge( A, l, m, r );
}

void merge( long *A, long l, long m, long r )
{
    long i, j, k;
    long nElemL = m - l + 1;
    long nElemR = r - m;

    long left[nElemL], right[nElemR];

    for ( i = 0; i < nElemL; i++ )
        left[i] = A[l+i];
    for ( j = 0; j < nElemR; j++ )
        right[j] = A[(m+1) + j];

    i = 0; 
    j = 0;
    k = l;
    while ( i < nElemL && j < nElemR ) {
        if ( left[i] <= right[j] ) {
            A[k] = left[i];
            i++;
        } else {
            A[k] = right[j];
            j++;
        }

        k++;
    }

    while ( i < nElemL ) {
        A[k] = left[i];
        i++;
        k++;
    }

    while ( j < nElemR ) {
        A[k] = right[j];
        j++;
        k++;
    }
}

void quickSort( long* A, long low, long high )
{
    if ( low >= high )
        return;

    long pi = partition( A, low, high );

    quickSort( A, low, pi-1 );
    quickSort( A, pi+1, high );
}

int partition( long* A, long low, long high )
{
    long pivot = A[high];
    long i = low-1;

    long aux;
    for ( long j = low; j < high; j++ ) {
        if ( A[j] < pivot ) {
            i++;
            aux = A[i];
            A[i] = A[j];
            A[j] = aux;
        }
    }

    aux = A[i+1];
    A[i+1] = A[high];
    A[high] = aux;

    return ( i + 1 );
}