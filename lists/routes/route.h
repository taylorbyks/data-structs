//
//  route.h
//  Define a classe Route, que é uma lista duplamente encadeada.
//
//  Created by Taylor Schinvelski on 19/04/21.
//

#ifndef route_h
#define route_h

#include <iostream>
#include <curses.h>

using namespace std;

class Route {
  private:
    typedef struct node{
      string name;
      string description;
      node *next;
      node *prev;
    } Node;
    
    Node *head;
    Node *tail;
    int size;
    
  public:
    Route() {
      head = nullptr;
      tail = nullptr;
      size = 0;
      insertFront("Curitiba", "Capital do Paraná");
    };
    
    ~Route() {
      while (head != nullptr) {
        if(head->next != nullptr) {
          Node *temp = head -> next;

          head->prev = head->next = nullptr;
          free((Node *) head);

          head = temp;
        } else {
          head = nullptr;
        }
      }
    };
  
    string name() {
      Node *Tail = tail;
      return Tail->name;
    }
  
    bool empty(void){
      if(size == 0 && this->head == nullptr && this->tail == nullptr){
        return true;
      } else {
        return false;
      }
    };
  
    bool insertFront(string name, string description) {
      Node *newNode = (Node *)malloc(sizeof(Node));
      
      newNode->name = name;
      newNode->description = description;
      newNode->prev = nullptr;
      
      if(empty()){
        newNode->next = nullptr;
        tail = newNode;
      } else {
        Node *oldHead = head;
        oldHead->prev = newNode;
        newNode->next = head;
      }
      
      head = newNode;
      size++;
      
      return true;
    }
  
    bool insertEnd(string name, string description) {
      Node *newNode = (Node *)malloc(sizeof(Node));
      
      newNode->name = name;
      newNode->description = description;
      newNode->next = nullptr;
      
      if(empty()){
        newNode->prev = nullptr;
        head = newNode;
      } else {
        struct node *oldTail = tail;
        newNode->prev = tail;
        oldTail->next = newNode;
      }
      
      tail = newNode;
      size++;
      
      return true;
    }
  
    void showFromHead() {
      cout << "Ida -> ";
      if(head != nullptr) {
        Node *current = head;
        while(current != nullptr) {
          cout << "[ " << current->name << " | " << current->description << " ] -> ";
          current = current->next;
        }
      }
      cout << "Chegou no Destino" << endl;
    }
  
  void showFromTail() {
    cout << "Volta -> ";
    if(tail != nullptr) {
      Node *current = tail;
      while(current != nullptr) {
        cout << "[ " << current->name << " | " << current->description << " ] -> ";
        current = current->prev;
      }
    }
    cout << "Voltou na Origem" << endl;
  }
  
  void trip() {
    int ch;
    if(head != nullptr) {
      Node *current = head;
      do {
        string name = current->name;
        string description = current->description;
        
        initscr(); //Inicializa uma 'tela' para poder usar o ncurses
          erase();
          refresh(); //Atualiza a tela
          keypad(stdscr, TRUE); //Habilita a ultilizaçao de teclas especias como KEY_LEFT e KEY_RIGHT
          
          if(current->next == nullptr) {
            printw("\t Você chegou ao seu destino\n\t %s | %s \n\n", name.data(), description.data());
            printw("\t Para voltar tecle <-\n\n\t Para sair tecle ENTER");
          }
          else if(current->prev == nullptr) {
            printw("\t Você esta na origem\n\t %s | %s \n\n", name.data(), description.data());
            printw("\t Para avançar tecle ->\n\n\t Para sair tecle ENTER");
          } else {
            printw("\n\t %s | %s \n\n", name.data(), description.data());
            printw("\t Para avançar tecle ->\n\t Para voltar tecle <-\n\n\t Para sair tecle ENTER");
          }

          ch = getch();
    
          switch(ch){
            case KEY_RIGHT:
              if (!(current->next == nullptr)){
                current = current->next;
              }
              break;
            case KEY_LEFT:
              if (!(current->prev == nullptr)){
                current = current->prev;
              }
              break;
          }
        endwin(); //Encerra a 'Tela'
      } while(ch != 10); // Aguarda a tecla ENTER (10) ser pressionada
    }
  }
  
};

#endif /* route_h */
