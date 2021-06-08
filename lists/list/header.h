//
//  header.h
//  datastructs
//
//  Created by Taylor Schinvelski on 10/04/21.
//

#ifndef header_h
#define header_h

#define QUIT 0
#define ADDFRONT 1
#define ADDEND 2
#define ADDPOSITION 3
#define REMOVEFRONT 4
#define REMOVEEND 5
#define CLEAR 6
#define SHOW 7

typedef struct {
  struct Node *next;
  int content;
} Node;

typedef struct {
  Node *front, *end;
  int size;
} List;

int option, value, position;

int empty(List *list);

int addFront(List *list, int value);

int addEnd(List *list, int value);

int addPosition(List *list, int value, int position);

int removeFront(List *list);

int removeEnd(List *list);

int show(List *list);

void menu(List *list);

#endif
