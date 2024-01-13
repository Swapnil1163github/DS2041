//SINGLY LINKED LIST WITH ONE EXTERNAL REFERENCE POINTER
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};
typedef struct node NODE;
NODE *start = NULL, *p, *q;

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
        p->next = NULL;
        start = p;
      } else {
        p->next = start;
        start = p;
      }

      printf("NODE P= %d IS CREATED SUCCESFULLY\n", p->data);
      break;

    case 2: // CREATE AT END
      p = (NODE *)malloc(sizeof(NODE));
      printf("ENTER DATA ELEMENT:\n");
      scanf("%d", &p->data);

      if (start == NULL) {
        p->next = NULL;
        start = p;
      } else {
        q = start;
        while (q->next != NULL)
          q = q->next;
        q->next = p;
        p->next = NULL;
      }
      printf("NODE P= %d IS CREATED SUCCESFULLY\n", p->data);
      break;

    case 3: // CREATE AT GIVEN LOCATION
      p = (NODE *)malloc(sizeof(NODE));
      printf("ENTER LOCATION AT WHICH YOU WANT TO CREATE THE NODE:\n");
      scanf("%d", &loc);
      printf("ENTER DATA ELEMENT\n");
      scanf("%d", &p->data);

      if (start == NULL) {
        if (loc == 1) {
          p->next = NULL;
          start = p;
        } else {
          printf("INVALID LOCATION\n");
          free(p);
        }
      } else if (loc == 1) {
          p->next = start;
          start = p;
        
      } else {
        q = start;
        i = 1;

        while (i < loc - 1 && q != NULL) {
          q = q->next;
          i++;
        }
        if (q != NULL) {
          p->next = q->next;
          q->next = p;
        } else {
          printf("LOCATION IS INVALID\n");
          free(p);
        }
      }
      printf("NODE P= %d IS CREATED SUCCESFULLY\n", p->data);
      break;

    case 4: // DELETE AT START
      if (start == NULL)
        printf("YOUR LINKED LIST IS EMPTY\n");
      else {
        p = start;
        start = start->next;
        printf("%d IS DELETED\n", p->data);
        free(p);
      }
      break;

    case 5: // DELETE AT END
      if (start == NULL)
        printf("YOUR LINKED LIST IS EMPTY\n");
      else if (start->next == NULL) {
        p = start;
        start = NULL;
        printf("%d IS DELETED", p->data);
        free(p);
      } else {
        p = start;
        while (p->next != NULL) {
          q = p;
          p = p->next;
        }
        q->next = NULL;
        printf("%d IS DELETED\n", p->data);
        free(p);
      }
      break;

    case 6: // DELETE AT GIVEN LOCATION
      printf("ENTER LOCATION AT WHICH YOU WANT TO DELETE THE NODE:\n ");
      scanf("%d",&loc);
      if (start == NULL) {
        printf("LINKED LIST IS EMPTY , DELETE CAN'T PREFORM\n");
      } else {
        if (loc == 1) {
          p = start;
          start = start->next;
          printf("%d IS DELETED\n", p->data);
          free(p);
        } else {
          i = 1;
          p = start;
          while (i < loc && p != NULL) {
            q = p;
            p = p->next;
            i++;
          }
          if (p != NULL) {
            q->next = p->next;
            printf("%d IS DELETED\n", p->data);
            free(p);
          } else {
            printf("INVALID LOCATION\n");
          }
        }
      }
      break;

    case 7: // TRAVERSE
      if (start == NULL) {
        printf("LINKED LIST IS EMPTY\n");
      } else {
        q = start;
        while (q != NULL) {
          printf("--> %d ", q->data);
          q = q->next;
        }
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
