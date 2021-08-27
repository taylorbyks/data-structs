//
//  functions.cpp
//  data-structs
//
//  Created by Taylor Schinvelski on 26/08/21.
//

#include "header.h"

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

void selectionSort(int array[], int size) {
  clock_t start = clock();
   
  for (int i = 0; i < size; i++) {
    int minimum = i;
    
    for (int j = i+1; j < size; j++){
      if (array[j] < array[minimum]){
        minimum = j;
      }
    }
      
    swap(array[minimum], array[i]);
  }
  
  cout << "Finalizado - Duração: " << (clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl << endl;
}

void bubbleSort(int array[], int size) {
  clock_t start = clock();
  
  for (int i = 0; i < size; i++){
    for (int j = 0; j < size-i; j++){
      if (array[j] > array[j+1]){
        swap(array[j], array[j+1]);
      }
    }
  }
  
  cout << "Finalizado - Duração: " << (clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl << endl;
}

void quickSort(int array[], int size) {
  clock_t start = clock();
  
  // code
  
  cout << "Finalizado - Duração: " << (clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl << endl;
}

void mergeSort(int array[], int size) {
  clock_t start = clock();
  
  // code
  
  cout << "Finalizado - Duração: " << (clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl << endl;
}

void shellSort(int array[], int size) {
  clock_t start = clock();
  
  // code
  
  cout << "Finalizado - Duração: " << (clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl << endl;
}

void menu() {
  int option;
  int array[] = {1, 6, 5, 3, 2, 8, 12, 2, 1, 8, 9, 11, 4, 15, 19, 20, 40, 45, 6, 7, 13, 16};
  int arraySize = sizeof(array)/sizeof(array[0]);
  
  printArray(array, arraySize);
  
  cout << "Escolha um algoritmo para ordenar o vetor:" << endl;
  cout << "0 - Sair" << endl;
  cout << "1 - Insertion Sort" << endl;
  cout << "2 - Selection Sort" << endl;
  cout << "3 - Bubble Sort" << endl;
  cout << "4 - Quick Sort" << endl;
  cout << "5 - Merge Sort" << endl;
  cout << "6 - Shell Sort" << endl;
  
  cin >> option;
  
  if (option != 0){
    switch (option) {
      case 1:
        cout << "Usando Insertion Sort: " << endl;
        insertionSort(array, arraySize);
        printArray(array, arraySize);
        break;
        
      case 2:
        cout << "Usando Selection Sort: " << endl;
        selectionSort(array, arraySize);
        printArray(array, arraySize);
        break;
        
      case 3:
        cout << "Usando Bubble Sort: " << endl;
        bubbleSort(array, arraySize);
        printArray(array, arraySize);
        break;
        
      case 4:
        cout << "Usando Quick Sort: " << endl;
        quickSort(array, arraySize);
        printArray(array, arraySize);
        break;
      
      case 5:
        cout << "Usando Merge Sort: " << endl;
        mergeSort(array, arraySize);
        printArray(array, arraySize);
        break;
        
      case 6:
        cout << "Usando Shell Sort: " << endl;
        shellSort(array, arraySize);
        printArray(array, arraySize);
        break;
        
      default:
        cout << "Selecione uma opção válida " << endl;
        break;
    }
    
    system("read -r -p \"Pressione uma tecla para continuar...\"");
    system("clear");
    menu();
  }
}
