//
//  main.cpp
//  Estrutura de Dados - 2021
//
//  Created by Taylor Schinvelski on 19/03/21.
//

#include "header.h"

using namespace std;

int main() {
  int number = 2;
  
  cout << number;
  
  List *list = new List();
  
  
  list -> insertTop(number);
  list -> insertTop(1);
  list -> insertTop(3);
  list -> insertTop(4);
  
  list -> show();
  
  delete list;
  
  return 0;
}
