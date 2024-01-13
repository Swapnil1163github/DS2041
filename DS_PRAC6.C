// CODE TO INSERT THE VALUE IN SORTED WAY.
#include <stdio.h>
#include <stdlib.h>
struct Node {
  int data;
  struct Node *next;
};
typedef struct Node NODE;
NODE *start = NULL, *p, *q;

int main() {
  int data, ch;

  do {
    printf("\nWHCIH OPERATION DO YOU WANT TO PERFORM?\n1.ENTER DATA "
           "ELEMENT\n2.TRAVERSE\n3.EXIT\n:");
    scanf("%d", &ch);

    switch (ch) {
    case 1:
      printf("\nENTER ANY NUMBER:");
      scanf("%d", &data);

      p = (NODE *)malloc(sizeof(NODE));
      p->data = data;
      p->next = NULL;

      if (start == NULL || data < start->data) {
        p->next = start;
        start = p;
      } else {
        q = start;
        while (q->next != NULL && data > q->next->data) {
          q = q->next;
        }
        p->next = q->next;
        q->next = p;
      }
      break;

    case 2: // TRAVERSE
      printf("\nYOUR LINKED LIST IS:\n\n");
      q = start;
      while (q != NULL) {
        printf(" --> %d ", q->data);
        q = q->next;
      }
      printf("\n");
      break;

    case 3: // EXIT
      break;

    default:
      printf("ENTER VALID CHOICE\n");
    }
  } while (ch != 3);

  return 0;
}
