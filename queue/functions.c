//
//  functions.c
//  Estrutura de Dados - 2021
//
//  Created by Taylor Schinvelski on 13/03/21.
//

#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int empty(int size){
  if(size == 0){
    return 1;
  } else {
    return 0;
  }
}

int overflow(int size){
  if(size == MAXFILA-1){
    return 1;
  } else {
    return 0;
  }
}

void flushIn() { // Utilizada para limpar o buffer
  while ((flush = fgetc(stdin)) != EOF && flush != '\n') {}
}

void clearQueue(){
  while (queue.size != 0){
    for(int i = 0; i < STRINGSIZE; i++){
      queue.content[queue.size].content[i] = ' ';
    }
    queue.size--;
  }
}
  
int enQueue(string value){
  if (overflow(queue.size)) {
      return 0;
    } else {
      queue.content[queue.size] = value;
      queue.size++;
      return 1;
    }
}
  
int deQueue(){
  if (empty(queue.size)){
    return 0;
  } else {
    aux = queue.content[0];
    for (int i = 0; i < queue.size; i++) {
      queue.content[i] = queue.content[i + 1];
    }
    queue.size--;
    printf("\n\t [ %s ] Foi removido\n", aux.content);
    return 1;
  }
}
  
int show(){
  if (empty(queue.size)){
    return 0;
  } else {
    for (int i = 0; i < queue.size; i++) {
        printf("\n\t %i | [ %s ]\n",i , queue.content[i].content);
      }
    printf("\n");
    return 1;
  }
}

void menu(){
  printf("===== Selecione uma opção: =====\n");
  printf("\t %d - Enfileirar (Enqueue)\n", ENQUEUE);
  printf("\t %d - Desenfilerar (Dequeue)\n", DEQUEUE);
  printf("\t %d - Limpar\n", CLEAR);
  printf("\t %d - Mostrar\n", SHOW);
  printf("\t %d - Sair\n\t ", QUIT);
  scanf("%d", &option);
  
  while (option != QUIT){
    switch (option){
      case ENQUEUE:
        printf("\n\t Insira o valor para enfileirar: ");
        flushIn();
        scanf("%[^\n]", value.content); // Consegue ler strings com espaços
        if (enQueue(value)){
          printf("\n\t [ %s ] foi enfileirado\n\n", value.content);
          system("read -r -p \"Pressione uma tecla para continuar...\"");
          system("clear");
          menu();
        } else {
          printf("\n\t ERRO - Overflow na fila\n\n");
          system("read -r -p \"Pressione uma tecla para continuar...\"");
          system("clear");
          menu();
        }
      break;
      case DEQUEUE:
        if (deQueue()){
          system("read -r -p \"Pressione uma tecla para continuar...\"");
          system("clear");
          menu();
        } else {
          printf("\n\t ERRO - Fila vazia\n\n");
          system("read -r -p \"Pressione uma tecla para continuar...\"");
          system("clear");
          menu();
        }
      break;
      case CLEAR:
        clearQueue();
        printf("\n\t Fila esvaziada\n\n");
        system("read -r -p \"Pressione uma tecla para continuar...\"");
        system("clear");
        menu();
      break;
      case SHOW:
        if (show()){
          system("read -r -p \"Pressione uma tecla para continuar...\"");
          system("clear");
          menu();
        } else {
          printf("\n\t ERRO - Fila vazia\n\n");
          system("read -r -p \"Pressione uma tecla para continuar...\"");
          system("clear");
          menu();
        }
      break;
      default:
        printf("\n\t ERRO - Opção inválida\n\n");
        system("read -r -p \"Pressione uma tecla para continuar...\"");
        system("clear");
        menu();
      break;
    }
  }
}
