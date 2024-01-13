// CIRCULAR LINKED LIST
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};
typedef struct node NODE;
NODE *start = NULL, *p, *q, *last = NULL;

int main() {
  int choice, i = 1, loc;
  do {
    printf("\nWHCIH OPERATION DO YOU WANT TO PERFORM?\n1.CREATE AT "
           "START\n2.CREATE AT END\n3.CREATE AT GIVEN LOCATION\n4.DELETE AT "
           "START\n5.DELETE AT END\n6.DELETE AT GIVEN "
           "LOCATION\n7.TRAVERSE\n8.EXIT\n");
    scanf("%d", &choice);

    switch (choice) {
    case 1: // CREATE AT START
      p = (NODE *)malloc(sizeof(NODE));
      printf("ENTER DATA ELEMENT:\n");
      scanf("%d", &p->data);

      if (start == NULL) {
        p->next = p;
        start = p;
        last = p;
      } else {
        p->next = start;
        start = p;
        last->next = p;
      }
      printf("NODE P= %d IS CREATED SUCCESFULLY\n", p->data);
      break;

    case 2: // CREATE AT END
      p = (NODE *)malloc(sizeof(NODE));
      printf("ENTER DATA ELEMENT:\n");
      scanf("%d", &p->data);

      if (start == NULL) {
        p->next = start;
        start = p;
        last = p;
      } else {
        last->next = p;
        p->next = start;
        last = p;
      }
      printf("NODE P= %d IS CREATED SUCCESFULLY\n", p->data);
      break;

    case 3: // CREATE AT GIVEN LOCATION
      p = (NODE *)malloc(sizeof(NODE));
      printf("ENTER LOCATION AT WHICH YOU WANT TO CREATE THE NODE:\n");
      scanf("%d", &loc);
      printf("ENTER DATA ELEMENT:\n");
      scanf("%d", &p->data);

      if (start == NULL) {
        if (loc == 1) {
          p->next = p;
          start = p;
          last = p;
        } else {
          printf("INVALID LOCATION\n");
          free(p);
        }
      } else if (loc == 1) {
        p->next = start;
        start = p;
        last->next = p;
      } else {
        q = start;
        i = 1;

        while (i < loc - 1 && q != last) {
          q = q->next;
          i++;
        }
        if (q != last) {
          p->next = q->next;
          q->next = p;
        } else if (loc == i + 1) {
          p->next = start;
          last->next = p;
          last = p;
        } else {
          printf("LOCATION IS INVALID\n");
          free(p);
        }
      }
      printf("NODE P= %d IS CREATED SUCCESSFULLY\n", p->data);
      break;

    case 4: // DELETE AT START
      if (start == NULL) {
        printf("YOUR LINKED LIST IS EMPTY,DELETE CAN'T PERFORM\n");
      } else if (start->next == start) {
        p = start;
        start = NULL;
        last = NULL;
        printf("%d IS DELETED\n", p->data);
        free(p);
      } else {
        p = start;
        start = start->next;
        last->next = start;
        printf("%d IS DELETED\n", p->data);
        free(p);
      }
      break;

    case 5: // DELETE AT END
      if (start == NULL) {
        printf("YOUR LINKED LIST IS EMPTY,DELETE CAN'T PERFORM\n");
      } else if (start->next == start) {
        p = start;
        start = NULL;
        last = NULL;
        printf("%d IS DELETED\n", p->data);
        free(p);
      } else {
        p = start;
        while (p->next != last) {
          p = p->next;
        }
        q = last;
        last = p;
        last->next = start;
        printf("%d IS DELETED\n", q->data);
        free(q);
      }
      break;

    case 6: // DELETE AT GIVEN LOCATION
      printf("ENTER LOCATION AT WHICH YOU WANT TO DELETE THE NODE:\n");
      scanf("%d", &loc);

      if (start == NULL) {
        printf("YOUR LINKED LIST IS EMPTY,DELETE CAN'T PERFORM\n");
      } else if (loc == 1) {
        p = start;
        if (start == last) {
          start = NULL;
          last = NULL;
        } else {
          start = start->next;
          last->next = start;
        }
        printf("%d IS DELETED\n", p->data);
        free(p);
      } else {
        i = 1;
        p = start;
        while (i < loc && p != last) {
          q = p;
          p = p->next;
          i++;
        }
        if (i != loc) {
          printf("INVALID CHOICE\n");
        } else if (p == last) {
          q->next = start;
          last = q;
          printf("%d IS DELETED\n", p->data);
          free(p);
        } else {
          q->next = p->next;
          printf("%d IS DELETED\n", p->data);
          free(p);
        }
      }
      break;

    case 7: // TRAVERSE
      if (start == NULL) {
        printf("YOUR LINKED LIST IS EMPTY\n");
      } else {
        q = start;
        do {
          printf("--> %d ", q->data);
          q = q->next;
        } while (q != start);
      }
      break;

    case 8: // EXIT
      break;

    default:
      printf("ENTER VALID CHOICE\n");
    }
  } while (choice != 8);

  return 0;
}