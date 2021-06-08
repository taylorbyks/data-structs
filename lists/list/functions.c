//
//  functions.c
//  datastructs
//
//  Created by Taylor Schinvelski on 10/04/21.
//

#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int empty(List *list){
  if(list->front == NULL){
    return 1;
  } else {
    return 0;
  }
}

int addFront(List *list, int value){
  Node *newNode = (Node*)malloc(sizeof(Node)); // Aloca a memoria para um novo node
  newNode->content = value; // Recebe o valor

  // Insere na lista
  if(empty(list)){
    newNode->next = NULL;
    list->front = newNode;
    list->end = newNode;
  } else {
    newNode->next = list->front;
    list->front = newNode;
  }

  list->size ++;

  return 1;
}

int addEnd(List *list, int value){
  Node *newNode = (Node*)malloc(sizeof(Node)); // Aloca a memoria para um novo node
  newNode->content = value; // Recebe o valor
  newNode->next = NULL;

  // Insere na lista
  if(empty(list)){
    newNode->next = NULL;
    list->front = newNode;
    list->end = newNode;
  } else {
    list->end->next = newNode;
    list->end = newNode;
  }

  list->size ++;

  return 1;
}

int addPosition(List *list, int value, int position){
  if(list->size == position + 2){
    return 0;
  }
  else if (position == 1){
    return addFront(list, value);
  }
  else if (list->size == position){
    return addEnd(list, value);
  } else {
    Node *newNode = (Node*)malloc(sizeof(Node));
    Node *aux = (Node*)malloc(sizeof(Node));
    aux = list->front;

    for(int i = 0; position == i; i++){
      aux = aux->next;
    }

    newNode->content = value;
    newNode->next = aux->next;
    aux->next = newNode;

    list->size++;
    return 1;
  }
}

int removeFront(List *list){
  if(empty(list)){
    return 0;
  } else {
    printf("\n\t [ %i ] foi removido\n", list->front->content);
    Node *aux = list->front->next;
    free(list->front);
    list->front = aux;

    if(list->front == NULL){ // Se o primeiro elemento é nulo significa que a lista esta vazia
      list->end = NULL;
    }

    list->size--;

    return 1;
  }
}

int removeEnd(List *list){
  if(empty(list)){
    return 0;
  } else {
    printf("\n\t [ %i ] foi removido\n", list->front->content);
    Node *aux = list->end->next;
    free(list->end);
    list->end = aux;

    if(list->end == NULL){ // Se o ultimo elemento é nulo significa que a lista esta vazia
      list->front = NULL;
    }

    list->size--;

    return 1;
  }
}

int show(List *list){
  if(empty(list)){
    return 0;
  } else {
    int position = 0;
    Node *start = list->front;
    printf("\nA lista possui %i elementos\n", list->size);
    while (start != NULL) {
      printf("\n\t %i | [ %i ]\n\t\t ↓ \n", position, start->content);
      start = start->next;
      position++;
    }
    printf("\n\t\tNULL (fim da lista) \n");
    return 1;
  }
}

void menu(List *list){
  printf("===== Selecione uma opção: =====\n");
  printf("\t %d - Adicionar no Inicio \n", ADDFRONT);
  printf("\t %d - Adicionar no Fim \n", ADDEND);
  printf("\t %d - Adicionar na Posição \n", ADDPOSITION);
  printf("\t %d - Remover no Inicio \n", REMOVEFRONT);
  printf("\t %d - Remover no Fim \n", REMOVEEND);
  printf("\t %d - Limpar\n", CLEAR);
  printf("\t %d - Mostrar\n", SHOW);
  printf("\t %d - Sair\n\t ", QUIT);
  scanf("%d", &option);

  while (option != QUIT){
    switch (option){
      case ADDFRONT:
        printf("\n\t Insira o valor para inserir: ");
        scanf("%i", &value);
        if (addFront(list, value)){
          printf("\n\t [ %i ] foi inserido\n\n", value);
          system("read -r -p \"Pressione uma tecla para continuar...\"");
          system("clear");
          menu(list);
        } else {
          printf("\n\t ERRO - Overflow na fila\n\n");
          system("read -r -p \"Pressione uma tecla para continuar...\"");
          system("clear");
          menu(list);
        }
      break;
      case ADDEND:
        printf("\n\t Insira o valor para inserir: ");
        scanf("%i", &value);
        if (addEnd(list, value)){
          printf("\n\t [ %i ] foi inserido\n\n", value);
          system("read -r -p \"Pressione uma tecla para continuar...\"");
          system("clear");
          menu(list);
        } else {
          printf("\n\t ERRO - Overflow na fila\n\n");
          system("read -r -p \"Pressione uma tecla para continuar...\"");
          system("clear");
          menu(list);
        }
      break;
      case ADDPOSITION:
        printf("\n\t Insira a posição para inserir: ");
        scanf("%i", &position);
        printf("\n\t Insira o valor para inserir: ");
        scanf("%i", &value);
        if (addPosition(list, value, position)){
          printf("\n\t [ %i ] foi inserido na posição [ %i ]\n\n", value, position);
          system("read -r -p \"Pressione uma tecla para continuar...\"");
          system("clear");
          menu(list);
        } else {
          printf("\n\t ERRO - Overflow na fila\n\n");
          system("read -r -p \"Pressione uma tecla para continuar...\"");
          system("clear");
          menu(list);
        }
      break;
      case REMOVEFRONT:
        if (removeFront(list)){
          system("read -r -p \"Pressione uma tecla para continuar...\"");
          system("clear");
          menu(list);
        } else {
          printf("\n\t ERRO - Fila vazia\n\n");
          system("read -r -p \"Pressione uma tecla para continuar...\"");
          system("clear");
          menu(list);
        }
      break;
      case CLEAR:
        //clearList();
        printf("\n\t Fila esvaziada\n\n");
        system("read -r -p \"Pressione uma tecla para continuar...\"");
        system("clear");
        menu(list);
      break;
      case SHOW:
        if (show(list)){
          system("read -r -p \"Pressione uma tecla para continuar...\"");
          system("clear");
          menu(list);
        } else {
          printf("\n\t ERRO - Fila vazia\n\n");
          system("read -r -p \"Pressione uma tecla para continuar...\"");
          system("clear");
          menu(list);
        }
      break;
      default:
        printf("\n\t ERRO - Opção inválida\n\n");
        system("read -r -p \"Pressione uma tecla para continuar...\"");
        system("clear");
        menu(list);
      break;
    }
  }
}
