//
//  header.h
//  Estrutura de Dados - 2021
//
//  Created by Taylor Schinvelski on 20/03/21.
//

#ifndef header_h
#define header_h
#include <stddef.h>
#include <stdlib.h>
#include <iostream>

#define QUIT 0
#define ADDEND 1
#define ADDFRONT 2
#define ADDPOSITION 3
#define REMOVEEND 4
#define REMOVEFRONT 5
#define REMOVEPOSITION 6
#define CLEAR 7
#define SHOW 8

using namespace std;

typedef struct node{
  int content;
  node* next;
  node* prev;
} Node;

class List {
  private:
    Node *head;
    int size;
  
  public:
  
  List(){
    head = nullptr;
    size = 0;
  };
  
  ~List(){
    while (head != nullptr) {
      if(head->next != nullptr) {
        struct node *temp = head -> next;

        head->prev = head->next = nullptr;
        free((struct node *) head);

        head = temp;
      } else {
        head = nullptr;
      }
    }
  };
  
  bool empty(void){
    if(size == 0){
      return true;
    } else {
      return false;
    }
  };
  
  bool insertTop(int value){
    Node *newNode = (struct node *)malloc(sizeof(struct node));
      
    newNode -> content = value;
    newNode -> prev = nullptr;

    if(empty()) {
        head = newNode;
        head -> next = nullptr;
    } else {
      head -> next = head;
      head = newNode;
    }
    
    size++;
    return true;
  }


  bool insertEnd(int value){
    Node *newNode = (struct node *)malloc(sizeof(struct node));
    
    newNode -> content = value;
    newNode -> next = nullptr;

    if(empty()) {
      head = newNode;
      newNode -> prev = nullptr;
    } else {
      newNode -> prev = head;
    }
    
    size++;
    return true;
  }

  void show(){
        cout << "Head -> ";
        if(!empty()) {

            struct node *current = head;
            cout << "[" << current->content << "] -> ";
            while(current->next != NULL) {

                current = current->next;
                cout << "[" << current->content << "] -> ";
            }
        }

      cout << "NULL" << endl;
    }
};

int option, position;

#endif /* header_h */
