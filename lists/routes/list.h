//
//  list.h
//  Define a lista das rotas, uma lista encadeada.
//
//  Created by Taylor Schinvelski on 19/04/21.
//

#ifndef list_h
#define list_h

#include <iostream>
#include "route.h"

using namespace std;

class List {
  private:
    typedef struct node {
      Route route;
      node *next;
    } Node;
  
    Node *head;
    Node *tail;
    int size;
  
  public:

    List() {
      head = nullptr;
      tail = nullptr;
      size = 0;
    };
    
    ~List() {
      while(head != nullptr) {
        if(head->next != nullptr) {
          Node *temp = head -> next;

          head->next = nullptr;
          free((Node *) head);

          head = temp;
        } else {
          head = nullptr;
        }
      }
    };
  
    int numberOfRoutes(){
      return size;
    }
    
    bool empty(void) {
      if(size == 0 && this->head == nullptr){
        return true;
      } else {
        return false;
      }
    };

    void insert(Route *newRoute) {
      Node *newNode = (Node *)malloc(sizeof(Node));
      
      newNode->route = *newRoute;
      newNode->next = nullptr;

      if(empty()) {
        head = newNode;
        
      } else {
        Node *oldTail = tail;
        oldTail->next = newNode;
      }
      
      tail = newNode;
      size++;
    }

    void remove(int n) {
      Node *removeNode = (Node *)malloc(sizeof(Node));
      
      if(n == 1){
        removeNode = head;
        head = removeNode->next;
      } else {
        Node *antRemoveNode = (Node *)malloc(sizeof(Node));

        antRemoveNode = head;
        while(n > 2) { //Busca pelo no antecessor 
          antRemoveNode = antRemoveNode->next;
          n--;
        }
        
        removeNode = antRemoveNode->next;
        if(n == size) {
          tail = antRemoveNode;
          antRemoveNode->next = nullptr;
        } else {
          antRemoveNode->next = removeNode->next;
        }
      }

      free(removeNode);
      size--;
    }
  
    Route *find(int n) {
      Node *current = head;
      
      while(n > 1) {
        current = current->next;
        n--;
      }
      
      return &current->route;
    }

    void show() {
      cout << "\t Rotas:" << endl;
      if(!empty()) {
        Node *current = head;
        cout << "\t" << "0 - Voltar" << endl;
        for(int i = 1; current != nullptr; i++) {
          cout << "\t" << i << " - " << current->route.name() << endl;
          current = current->next;
        }
      } else {
        cout << "\t" << "Não existe nenhuma rota cadastrada" << endl << "\t" << "0 - Voltar" << endl;
      }
    }
};

#endif /* list_h */
