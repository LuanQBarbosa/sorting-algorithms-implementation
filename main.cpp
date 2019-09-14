#include <iostream>
#include <fstream>
#include <cstdlib>
#include "ordenacao.h"

int main( int argc, char** argv )
{
    std::fstream file;
    file.open( argv[2] );

    int nElem;
    file >> nElem;

    long A[nElem], i = 0, maxElem = 0, minElem = 0;
    while ( file >> A[i] ) {
        if ( maxElem < A[i] )
            maxElem = A[i];
        if ( minElem > A[i] )
            minElem = A[i];

        i++;
    }

    switch ( atoi( argv[1] ) )
    {
    case 1:
        countingSort( A, maxElem, minElem, nElem );
        break;
    
    case 2:
        radixSort( A, maxElem - minElem, nElem );
        break;
    case 3:
        selectionSort( A, nElem );
        break;
    case 4:
        insertionSort( A, nElem );
        break;
    case 5:
        mergeSort( A, 0, nElem-1 );
        break;
    }

    std::cout << A[0];
    for ( i = 1; i < nElem; i++ )
        std::cout << " << " << A[i];
    std::cout << std::endl;
}