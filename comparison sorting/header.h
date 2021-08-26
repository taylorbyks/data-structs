//
//  header.h
//  data-structs
//
//  Created by Taylor Schinvelski on 26/08/21.
//

#ifndef header_h
#define header_h

#include <iostream>
#include <chrono>

using namespace std;

void printArray(int array[], int size);

void swap(int &a, int &b);

void insertionSort(int array[], int size);

void selectionSort(int array[], int size);

void bubbleSort(int array[], int size);

void quickSort(int array[], int size);

void mergeSort(int array[], int size);

void shellSort(int array[], int size);

void menu();

#endif /* header_h */
