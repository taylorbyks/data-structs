//
//  functions.c
//  Cria a função menu.
//
//  Created by Taylor Schinvelski on 19/04/21.
//

#include "header.h"

void menu(){
  cout << "\t" << QUIT << " - Sair" << endl;
  cout << "\t" << CREATE << " - Criar uma nova rota" << endl;
  cout << "\t" << DELETE << " - Excluir uma rota" << endl;
  cout << "\t" << TRAVEL << " - Viajar" << endl;
  cout << "\t" << DIRECTTRAVEL << " - Viajem Direta" << endl;
  cin >> option;
  while (option != QUIT){
    switch (option) {
      case CREATE:
        while(insertAnother != 'n'){
          system("clear");
          cout << "\t" << "Insira o nome da cidade: ";
          cin.ignore();
          getline( cin, cityName );
          cout << "\n\t" << "Insira a descrição da cidade: ";
          getline( cin, cityDescription );

          route[id].insertEnd(cityName, cityDescription);

          cout << "\t" << "Deseja inserir mais uma cidade? (s/n): ";
          cin >> insertAnother;
        }

        routes.insert(&route[id]);
        id++;
        insertAnother = ' ';
        system("clear");
        menu();
        break;
        
      case DELETE:
        routes.show();
        cout << "\t" << "Selecione uma rota: ";
        cin >> choice;
        if(choice > routes.numberOfRoutes()) {
          cout << "\t" << "ERRO - Opção inválida" << endl;
          system("read -r -p \"Pressione uma tecla para continuar...\"");
        } else if(choice == 0){
          system("clear");
          menu();
        } else {
          routes.remove(choice);
          cout << "\t" << "Rota excluida" << endl;
          system("read -r -p \"Pressione uma tecla para continuar...\"");
          system("clear");
          menu();
        }
        break;

      case TRAVEL:
        system("clear");
        routes.show();
        cout << "\t" << "Selecione uma rota: ";
        cin >> choice;
        if(choice > routes.numberOfRoutes()) {
          cout << "\t" << "ERRO - Opção inválida" << endl;
          system("read -r -p \"Pressione uma tecla para continuar...\"");
        } else if(choice == 0){
          system("clear");
          menu();
        } else {
          Route *choicedRoute;
          choicedRoute = routes.find(choice);
          choicedRoute->trip();
        }
        break;
        
      case DIRECTTRAVEL:
        system("clear");
        routes.show();
        cout << "\t" << "Selecione uma rota: ";
        cin >> choice;
        if(choice > routes.numberOfRoutes()) {
          cout << "\t" << "ERRO - Opção inválida" << endl;
          system("read -r -p \"Pressione uma tecla para continuar...\"");
        } else if(choice == 0){
          system("clear");
          menu();
        } else {
          Route *choicedRoute;
          choicedRoute = routes.find(choice);
          choicedRoute->showFromHead();
          system("read -r -p \"Pressione uma tecla para fazer o caminho de volta...\"");
          choicedRoute->showFromTail();
          system("read -r -p \"Pressione uma tecla para voltar...\"");
        }
        break;
        
      default:
        cout << "\t" << "ERRO - Opção inválida" << endl;
        system("read -r -p \"Pressione uma tecla para continuar...\"");
        system("clear");
        menu();
        break;
    }
  }
}