//
//  functions.c
//  Estrutura de Dados - 2021
//
//  Created by Taylor Schinvelski on 04/03/21.
//

#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int empty(int top){
  if(top == -1){
    return 1;
  } else {
    return 0;
  }
}

int overflow(int top){
  if(top == MAXPILHA-1){
    return 1;
  } else {
    return 0;
  }
}

void clearStack(){
  for(int i = -1; i <= MAXPILHA; i++){
    stack.content[i] = 0;
    stack.top --;
  }
}
  
int push(int value){
  if (overflow(stack.top)){
    return 0;
  }
  else {
    stack.top++;
    stack.content[stack.top] = value;
    return 1;
  }
}
  
int pop(){
  int aux;
  if (empty(stack.top)){
    return 0;
  }
  else{
    aux = stack.content[stack.top];
    stack.content[stack.top] = 0;
    stack.top--;
    printf("\n\t [ %d ] foi desempilhado\n\n", aux);
    return 1;
  }
}
  
int show(){
  if (empty(stack.top)){
    return 0;
  } else {
    for(int i = stack.top; i >= 0; i--){
      printf("\n\t %02d | [ %d ]\n", i, stack.content[i]);
    }
    printf("\n");
    return 1;
  }
}

void menu() {
  printf("===== Selecione uma opção: =====\n");
  printf("\t %d - Empilhar (Push)\n", PUSH);
  printf("\t %d - Desempilhar (Pop)\n", POP);
  printf("\t %d - Limpar\n", CLEAR);
  printf("\t %d - Mostrar\n", SHOW);
  printf("\t %d - Sair\n\t ", QUIT);
  scanf("%d", &option);

  while (option != QUIT){
    switch (option){
      case PUSH:
        printf("\n\t Insira o valor para empilhar: ");
        scanf("%d", &value);
        if (push(value)){
          printf("\n\t [ %d ] foi empilhado\n\n", value);
          system( "read -n 1 -s -p \"Pressione uma tecla para continuar...\"" );
          system("clear");
          menu();
        } else {
          printf("\n\t ERRO - Overflow na pilha\n\n");
          system( "read -n 1 -s -p \"Pressione uma tecla para continuar...\"" );
          system("clear");
          menu();
        }
      break;
      case POP:
        if (pop()){
          system( "read -n 1 -s -p \"Pressione uma tecla para continuar...\"" );
          system("clear");
          menu();
        } else {
          printf("\n\t ERRO - Pilha vazia\n\n");
          system( "read -n 1 -s -p \"Pressione uma tecla para continuar...\"" );
          system("clear");
          menu();
        }
      break;
      case CLEAR:
        clearStack();
        printf("\n\t Pilha esvaziada\n\n");
        system( "read -n 1 -s -p \"Pressione uma tecla para continuar...\"" );
        system("clear");
        menu();
      break;
      case SHOW:
        if (show()){
          system( "read -n 1 -s -p \"Pressione uma tecla para continuar...\"" );
          system("clear");
          menu();
        } else {
          printf("\n\t ERRO - Pilha vazia\n\n");
          system( "read -n 1 -s -p \"Pressione uma tecla para continuar...\"" );
          system("clear");
          menu();
        }
      break;
      default:
        printf("\n\t ERRO - Opção inválida\n\n");
        system( "read -n 1 -s -p \"Pressione uma tecla para continuar...\"" );
        system("clear");
        menu();
      break;
    }
  }
}
