//
//  functions.cpp
//  Estrutura de Dados - 2021
//
//  Created by Taylor Schinvelski on 20/03/21.
//

#include <iostream>

#include "header.h"

using namespace std;

List *node = new List();

content data;

bool empty(){
  if(head.next == NULL){
    return true;
  } else {
    cout << "ERRO - Lista Vazia" << endl;
    return false;
  }
}

bool overflow(){
  return true;
}

bool addFront(content data){
  List node;
  node.data = data;
  node.next = NULL;
  //head.next = &node;
  return true;
}

bool addEnd(content data){
  return true;
}

bool addPosition(content data, int position){
  return true;
}

bool removeFront(){
  return true;
}

bool removeEnd(){
  return true;
}

bool removePosition(int position){
  return true;
}

bool show(){
  return true;
}

bool clear(){
  return true;
}

void menu(){
  printf("===== Selecione uma opção: =====\n");
  printf("\t %d - Adiciona no inicio\n", ADDFRONT);
  printf("\t %d - Adiciona no fim\n", ADDEND);
  printf("\t %d - Adiciona na posição\n", ADDPOSITION);
  printf("\t %d - Remove no inicio\n", REMOVEFRONT);
  printf("\t %d - Remove no fim\n", REMOVEEND);
  printf("\t %d - Remove na posição\n", REMOVEPOSITION);
  printf("\t %d - Limpar\n", CLEAR);
  printf("\t %d - Mostrar\n", SHOW);
  printf("\t %d - Sair\n\t ", QUIT);
  scanf("%d", &option);
  
  while (option != QUIT){
    switch (option){
      case ADDFRONT:
        cout << "\n\t Insira o valor para inserir:" << endl;
        cin >> data.value;
        if (addFront(data)){
          cout << data.value << " foi inserido" << endl;
          system("read -r -p \"Pressione uma tecla para continuar...\"");
          system("clear");
          menu();
        } else {
          cout << "ERRO - Overflow na lista" << endl;
          system("read -r -p \"Pressione uma tecla para continuar...\"");
          system("clear");
          menu();
        }
      break;
      case ADDEND:
        cout << "\n\t Insira o valor para inserir: " << endl;
        cin >> data.value;
        if (addEnd(data)){
          cout << data.value << " foi inserido" << endl;
          system("read -r -p \"Pressione uma tecla para continuar...\"");
          system("clear");
          menu();
        } else {
          cout << "\n\t ERRO - Overflow na lista\n\n" << endl;
          system("read -r -p \"Pressione uma tecla para continuar...\"");
          system("clear");
          menu();
        }
      break;
      case ADDPOSITION:
        cout << "\n\t Insira o valor para inserir: " << endl;
        cin >> data.value;
        cout << "\n\t Insira a posição para inserir: " << endl;
        cin >> position;
        if (addPosition(data, position)){
          cout << data.value << "foi inserido na " <<  position << endl;
          system("read -r -p \"Pressione uma tecla para continuar...\"");
          system("clear");
          menu();
        } else {
          cout << "ERRO - Overflow na lista" << endl;
          system("read -r -p \"Pressione uma tecla para continuar...\"");
          system("clear");
          menu();
        }
      break;
      case REMOVEFRONT:
        if (removeFront()){
          system("read -r -p \"Pressione uma tecla para continuar...\"");
          system("clear");
          menu();
        } else {
          system("read -r -p \"Pressione uma tecla para continuar...\"");
          system("clear");
          menu();
        }
      break;
      case REMOVEEND:
        if (removeEnd()){
          system("read -r -p \"Pressione uma tecla para continuar...\"");
          system("clear");
          menu();
        } else {
          system("read -r -p \"Pressione uma tecla para continuar...\"");
          system("clear");
          menu();
        }
      break;
      case REMOVEPOSITION:
        cout << "\n\t Insira a posição para remover: " << endl;
        cin >> position;
        if (removePosition(position)){
          system("read -r -p \"Pressione uma tecla para continuar...\"");
          system("clear");
          menu();
        } else {
          system("read -r -p \"Pressione uma tecla para continuar...\"");
          system("clear");
          menu();
        }
      break;
      case CLEAR:
        clear();
        cout << "Fila esvaziada" << endl;
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
          system("read -r -p \"Pressione uma tecla para continuar...\"");
          system("clear");
          menu();
        }
      break;
      default:
        cout << "\n\t ERRO - Opção inválida" << endl;
        system("read -r -p \"Pressione uma tecla para continuar...\"");
        system("clear");
        menu();
      break;
    }
  }
}
