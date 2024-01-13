// IMPLEMENT QUEUE OPERATION USING LINKED LIST
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
    printf("\nWHICH OPERATION DO YOU WANT TO PERFORM?: "
           "\n1.ENQUEUE\n2.DEQUEUE\n3.TREVERSE\n4.EXIT\n");
    scanf("%d", &choice);
    switch (choice) {
      // ENQUEUE
    case 1:
      p = (NODE *)malloc(sizeof(NODE));
      printf("ENTER THE DATA: \n");
      scanf("%d", &p->data);
      if (start == NULL) {
        p->next = NULL;
        start = p;
      } else {
        q = start;
        while (q->next != NULL) {
          q = q->next;
        }
        q->next = p;
        p->next = NULL;
      }
      printf("NODE %d IS ENQUEUEED SUCCESSFULLY\n", p->data);
      break;

      // DEQUEUE
    case 2:
      if (start == NULL) {
        printf("QUEUE UNDERFLOW\n");
      } else {
        p = start;
        start = p->next;
        printf("NODE %d IS DEQUEUEED SUCCESSFULLY\n", p->data);
        free(p);
      }
      break;

      // TRAVERSE
    case 3:
      if (start == NULL) {
        printf("QUEUE UNDERFLOW\n");
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