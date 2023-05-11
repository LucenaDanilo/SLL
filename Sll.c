#include "Sll.h"

void create(Sll *l) {
  l->first = NULL;
  l->size = 0;
}

int display(Sll *l) {
  printf("\n");
  if (l->size < 1) {
    printf("EMPTY LIST...\n");
    return 0;
  }
  
  Node* aux = l->first;
  for (int i = 0; i < l->size; i++) {
    printf("%c", aux->value);
    aux = aux->next;
  }
  printf("\n");
  return 1;
}

int insert(Sll *l, char c) {
  Node *newElem = (Node*) malloc(sizeof(Node));
  newElem->next = NULL;
  newElem->value = c;

  if (l->first == NULL) {
      l->first = newElem;
  } else {
      Node* aux = l->first;
      while (aux->next != NULL) {
          aux = aux->next;
    }
    aux->next = newElem;
  }

  l->size++;
  return 1;
}

int removeElem( Sll *l, char c) {
  int p = find(l, c);
  if (p == -1) {
    printf(" and will not be removed...\n");
    return -1;
  }
  printf(" And will be removed!\n");

  Node *aux = l->first;
  if (p == 0) {
    l->first = l->first->next;
    free(aux);
  } else {
    for (int i = 0; i < p - 1; i++) {
      aux = aux->next;
    }
    Node *temp = aux->next;
    aux->next = aux->next->next;
    free(temp);
  }
  l->size--;
  return 1;
}

int find(Sll *l, char c) {
  Node *aux = l->first;
  for (int i = 0; i < l->size; i++) {
    if (aux->value == c) {
      printf("\nElement is in %i!", i);
      return i;
    }
    aux = aux->next;
  }
  printf("\nElement isn't in the list");
  return -1;
}

int clearList(Sll *l) {
  Node *aux = l->first;

  int i;
  for (i = 0; i < l->size; i++) {
    Node *temp = aux;
    aux = aux->next;
    free(temp);
  }
  
  l->size = 0;
  l->first = NULL;
  
  return 0;
}

int obterElemento(Sll *l , int p, char *e) {
  if (l->size < 1) {
    printf("\nEMPTY LIST...\n");
    return 0;
  } else if (p > l->size) {
    printf("\nInvalid position\n");
    return 0;
  }
  
  Node *aux = l->first;
  for (int i = 0; i < p-1; i++) {
    aux = aux->next;
  }

  *e = aux->value;
  return 1;
}

int inserirNaPosicao( Sll *l, char c[], int p) {
  Node *newNode = (Node*) malloc(sizeof(Node));
  newNode->next = NULL;
  newNode->value = *c;
  
  Node *aux = l->first;
  Node *temp = aux->next;

  if (p > l->size + 1 || p < 1) {
    printf("\nInvalid position\n");
    return 0;
  } else if (p == l->size + 1) {
    insert(l, *c);
    return 1;
  }

  if (p == 1) {
    temp = l->first;
    l->first = newNode;
    newNode->next = temp;
  } else {
      for (int i = 0; i < p-2; i++) {
        aux = aux->next;
        temp = aux->next;
      }
  
      aux->next = newNode;
      newNode->next = temp; 
  }
  l->size++;
  return 1;
}