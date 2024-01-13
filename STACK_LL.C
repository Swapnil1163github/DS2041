// IMPLEMENT STACK OPERATION USING LINKED LIST
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};
typedef struct node NODE;
NODE *start = NULL, *p, *q;

int main() {
  int choice;
  do {
    printf("\nWHICH OPERATION DO YOU WANT TO "
           "PERFORM?:\n1.PUSH\n2.POP\n3.TRAVERSE\n4.EXIT\n");
    scanf("%d", &choice);
    switch (choice) {
    // PUSH
    case 1:
      p = (NODE *)malloc(sizeof(NODE));
      printf("ENTER THE DATA: ");
      scanf("%d", &p->data);
      if (start == NULL) {
        start = p;
        p->next = NULL;
      } else {
        p->next = start;
        start = p;
      }
      printf("NODE %d IS PUSHED SUCCESSFULLY\n", p->data);
      break;

    // POP
    case 2:
      if (start == NULL) {
        printf("STACK UNDERFLOW\n");
      } else {
        p = start;
        start = p->next;
        printf("NODE %d IS POPED SUCCESSFULLY\n", p->data);
        free(p);
      }
      break;

    case 3: // TRAVERSE
      if (start == NULL) {
        printf("STACK UNDERFLOW\n");
      } else {
        q = start;
        while (q != NULL) {
          printf("--> %d ", q->data);
          q = q->next;
        }
      }
      break;

    case 4: // EXIT
      break;

    default:
      printf("ENTER VALID CHOICE\n");
      break;
    }
  } while (choice != 4);
  return 0;
}