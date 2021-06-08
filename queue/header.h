//
//  header.h
//  Estrutura de Dados - 2021
//
//  Created by Taylor Schinvelski on 13/03/21.
//

#ifndef header_h
#define header_h

#define MAXFILA 100
#define STRINGSIZE 40
#define QUIT 0
#define ENQUEUE 1
#define DEQUEUE 2
#define CLEAR 3
#define SHOW 4

typedef struct {
  char content[STRINGSIZE];
} string;

struct {
  string content[MAXFILA];
  int size;
} queue;

string aux, value;

int option, flush;

int empty(int size);

int overflow(int size);

void flushIn(void);

void clearQueue(void);
  
int enQueue(string value);
  
int deQueue(void);
  
int show(void);

void menu(void);

#endif
