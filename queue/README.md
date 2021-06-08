# Implementação Fila - Estrutura de Dados 2021

Taylor Byk Schinvelski

Compilado no MacOS (Unix)
Executado no terminal ZSH

## Funções Especias 

```c
system("clear");
```

Utilizada para limpar o console, caso for preciso rodar em um terminal windows deve ser utilizado:

```c
system("cls");
```



```c
system( "read -r -p \"Pressione uma tecla para continuar...\"" );
```

Utilizada para pausar a execução, caso for preciso rodar em um terminal windows deve ser utilizado:

```c
system("break");
```


```c
void flushIn() {
  while ((flush = fgetc(stdin)) != EOF && flush != '\n') {}
}
```
Utilizada para limpar o buffer

```c
scanf("%[^\n]", value.content); 
```
Com o Buffer limpo é possivel ler strings com espaços EX: "teste teste teste      teste"
