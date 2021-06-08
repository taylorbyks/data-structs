//
//  header.h
//  Define variaveis e funções globais
//
//  Created by Taylor Schinvelski on 19/04/21.
//

#ifndef header_h
  #define header_h

  #include <iostream>
  #include "list.h"
  #include "route.h"

  #define MAXROUTES 30
  #define QUIT 0
  #define CREATE 1
  #define DELETE 2
  #define TRAVEL 3
  #define DIRECTTRAVEL 4

  using namespace std;

  int option, choice, id;
  string cityDescription, cityName;
  char insertAnother;
  List routes;
  Route route[MAXROUTES];

  void menu(void);

#endif