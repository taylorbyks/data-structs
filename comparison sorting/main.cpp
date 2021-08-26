//
//  main.cpp
//  comparison sorting
//
//  Created by Taylor Schinvelski on 26/08/21.
//

#include <iostream>
#include <chrono>

using namespace std;

void printArray(int array[], int size) {
  cout << "Tamanho: " << size << endl;
  cout << "Vetor:";
  
  for(int i = 0; i < size; i++){
    cout << " " << array[i];
  };
  
  cout << endl << endl;
}

void swap(int &a, int &b) {
  int aux = a;
  a = b;
  b = aux;
}

void insertionSort(int array[], int size) {
  clock_t start = clock();
  
  for (int i = 1; i < size; i++) {
    int value = array[i];
    int j = i - 1;
    
    while (j >= 0 && array[j] > value) {
      array[j + 1] = array[j];
      j--;
    }
    
    array[j + 1] = value;
  }
  
  cout << "Finalizado - Duração: " << (clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl << endl;
}


int main() {
  int array[] = {1, 6, 5, 3, 2, 8, 12, 2, 1, 8, 9, 11, 4, 15, 19, 20, 40, 45, 6, 7, 13, 16};
  int arraySize = sizeof(array)/sizeof(array[0]);
  
  printArray(array, arraySize);
  
  cout << "Usando isertion sort: " << endl;
  insertionSort(array, arraySize);
  
  printArray(array, arraySize);
  
  return 0;
}
