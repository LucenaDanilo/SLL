#ifndef LSA_H
#define LSA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  char value;
  struct Node *next;
} Node;

typedef struct Sll {
  Node *first;
  int size;
} Sll;

void create( Sll* );
int display( Sll* );
int insert( Sll*, char );
int removeElem( Sll*, char );
int find( Sll*, char );
int clearList( Sll* );

int obterElemento( Sll*, int, char* );
int inserirNaPosicao( Sll*, char[], int );

#endif