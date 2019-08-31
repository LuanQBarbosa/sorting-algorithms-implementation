#ifndef ORDENACAO_H
#define ORDENACAO_H

void countingSort( long* A, long maxElem, long minElem, long nElem );

void radixSort( long* A, long maxElem, long nElem );
void radixCount( long* A, long nElem, long n );

void selectionSort( long* A, long nElem );

void insertionSort( long* A, long nElem );

#endif // ORDENACAO_H