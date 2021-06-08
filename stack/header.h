//
//  header.h
//  Estrutura de Dados - 2021
//
//  Created by Taylor Schinvelski on 04/03/21.
//

#ifndef header_h
#define header_h

#define MAXPILHA 30
#define QUIT 0
#define PUSH 1
#define POP 2
#define CLEAR 3
#define SHOW 4

struct {
  int content[MAXPILHA];
  int top;
} stack;

int option, value;

int empty(int top);

int overflow(int top);

void clearStack(void);
  
int push(int value);
  
int pop(void);
  
int show(void);

void menu(void);

#endif
