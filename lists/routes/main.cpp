//
//  main.cpp
//  routes
//
//  Created by Taylor Schinvelski on 19/04/21.
//

#include "functions.c"

int main() {
  /* O Programa ja inicia com 3 rotas, no menu é possivel adicionar mais */
  
  //Inicializa a rota 1
  route[id].insertEnd("Campo Largo", "Regiao Metropolitana de Curitiba");
  route[id].insertEnd("Irati", "Regiao Sudeste do estado");
  route[id].insertEnd("Laranjeiras do Sul", "Regiao Centro Oeste do estado");
  route[id].insertEnd("Cascavel", "Uma Metropole em Construcao");
  routes.insert(&route[id]);
  id++;
  
  //Inicializa a rota 2
  route[id].insertEnd("Campo Largo", "Regiao Metropolitana de Curitiba");
  route[id].insertEnd("Irati", "Regiao Sudeste do Estado");
  route[id].insertEnd("Corbelia", "Cidade das Flores");
  routes.insert(&route[id]);
  id++;
  
  //Inicializa a rota 3
  route[id].insertEnd("Campo Largo", "Regiao Metropolitana de Curitiba");
  route[id].insertEnd("Irati", "Regiao Sudeste do Estado");
  route[id].insertEnd("Laranjeiras do Sul", "Regiao Centro Oeste do Estado");
  routes.insert(&route[id]);
  id++;
  
  menu();
  
  return 0;
}
