// MOVE EVEN NODES OF THE LINKED LIST AT THE END OF THE LINKED LIST IN REVERSE ORDER
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
} *q, *start = NULL, *start1 = NULL;

typedef struct Node NODE;

void traverse() { // TRAVERSE

  q = start;
  while (q != NULL) {
    printf("--> %d ", q->data);
    q = q->next;
  }
}

void createatstart(int a) { // CREATE AT START
  NODE *func;
  func = (NODE *)malloc(sizeof(NODE));
  func->data = a;
  if (start1 == NULL) {
    start1 = func;
    func->next = NULL;
  } else {
    func->next = start1;
    start1 = func;
  }
}

int main() {
  int ch, i,node;
  NODE *b[60], *p;
  
  printf("BY WHICH WAY YOU WANT TO PERFORM??\n1.Predefined linked "
         "list\n2.Create new linked list\n");
  scanf("%d", &ch);
  b[0] = (NODE *)malloc(sizeof(NODE));
  switch (ch) {

  case 1:
    start = b[0];
    for (i = 0; i < 8; i++) {
      b[i + 1] = (NODE *)malloc(sizeof(NODE));
      b[i]->next = b[i + 1];
      b[i]->data = i * 10;
    }
    b[8]->data = 80;
    b[8]->next = NULL;
    break;

  case 2:
    printf("How many nodes do you want to create:\n");
    scanf("%d", &node);
    printf("Enter data elements:\n");
    b[0] = (NODE *)malloc(sizeof(NODE));
    start = b[0];
    for (i = 0; i < node - 1; i++) {
      b[i + 1] = (NODE *)malloc(sizeof(NODE));
      b[i]->next = b[i + 1];
      scanf("%d", &b[i]->data);
    }
    scanf("%d", &b[i]->data);
    b[i]->next = NULL;
    break;

  default:
    printf("ENTER VALID CHOICE!!");
  }

  printf("\nLINKED LIST CREATED SUCCESSFULLY\nYour linked list:\n");
  traverse();
  printf("\n\nEnter 1 to perform operation OR any other number to EXIT\n");
  scanf("%d", &ch);
  if (ch == 1) {
    q = start;
    while (q->next != NULL) {
      p = q->next;
      createatstart(p->data);
      q->next = p->next;
      free(p);
      if (q->next != NULL)
        q = q->next;
    }
    q->next = start1;
    printf("OPERATION PERFORMED SUCCESSFULLY.\nYour new linked list:\n");
    traverse();
  } else {
    printf("Exited from the code");
  }
  return 0;
}
