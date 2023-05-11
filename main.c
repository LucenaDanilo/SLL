#include "Sll.h"

char receiveChar() {
  char c;
  int ch;
  printf("\nPlease, type the character: ");
  
  // Cleaning the buffer before get the char
  while ((ch = getchar()) != '\n' && ch != EOF) {}
  
  scanf("%c", &c);
  
  // cleaning after too
  while ((ch = getchar()) != '\n' && ch != EOF) {}

  return c;
}

int main(void) {
  Sll l;
  create(&l);

  int ch;
  int input, pos;
  char c, answer, r = -1;
  do {
    printf("\n\nList editor\n");
    printf("---------------------------------\n");
    printf("1 – Display list\n");
    printf("2 – Insert\n");
    printf("3 – Remove \n");
    printf("4 – Display position\n");
    printf("5 – Empty list\n");
    printf("6 – Exit\n");
    printf("7 - Get element\n");
    printf("8 - Insert in position\n\n");
    printf("Choose a option:\n\n");
    
    scanf("%d", &input);
    switch(input) {
      case 1:
        display(&l);
        break;
      case 2:
        c = receiveChar();  
        insert(&l, c);
        break;
      case 3:
        c = receiveChar();
        removeElem(&l, c);
        break;
      case 4:
        c = receiveChar();
        find(&l, c);
        break;
      case 5:
        if (l.size > 0) {         
          printf("\nAre you sure in that? (S/N) ");
          while ((ch = getchar()) != '\n' && ch != EOF) {}
          scanf("%c", &answer);
          while ((ch = getchar()) != '\n' && ch != EOF) {}
  
          if (answer == 'S') {
            clearList(&l);
          } 
        } else {
          printf("\nList is already empty\n");
        }
        break;
      case 6:
        exit(0);
        break;
      case 7:
        printf("\nChoose one position: ");
        scanf("%d", &pos);
        if (obterElemento(&l, pos, &r))
          printf("\n%c\n", r);
        break;
      case 8:
        c = receiveChar();
        printf("\nChoose one position: ");
        scanf("%d", &pos);
        inserirNaPosicao(&l, &c, pos);
        break;
    }
  } while (1);
}