// IMPLEMENT QUEUE OPERATION USING ARRAY
#include <stdio.h>

int main() {
  int a[5], front = -1, rear = -1, choice, i;
  do {
    printf("\nWHICH OPERATION DO YOU WANT TO PERFORM?: "
           "\n1.ENQUEUE\n2.DEQUEUE\n3.TREVERSE\n4.EXIT\n");
    scanf("%d", &choice);
    switch (choice) {
    // ENQUEUE
    case 1:
      if (rear == 4) {
        printf("QUEUE OVERFLOW\n");
      } else {
        printf("ENTER THE DATA: \n");
        if (front == -1) {
          front = 0;
          rear = 0;
        } else {
          rear = rear + 1;
        }
        scanf("%d", &a[rear]);
        printf("%d IS ENQUEUEED SUCCESSFULLY\n", a[rear]);
      }
      break;

    // DEQUEUE
    case 2:
      if (front == -1) {
        printf("QUEUE UNDERFLOW\n");
      } else {
        printf("%d IS DEQUEUEED SUCCESSFULLY\n", a[front]);
        front = front + 1;
        if (front > rear) {
          front = -1;
          rear = -1;
        }
      }
      break;

    // TRAVERSE
    case 3:
      if (front == -1) {
        printf("QUEUE UNDERFLOW\n");
      } else {
        for (i = front; i <= rear; i++)
          printf("-->%d ", a[i]);
      }
      break;

    // EXIT
    case 4:
      break;

    default:
      printf("ENTER VALID CHOICE");
    }

  } while (choice != 4);
  return 0;
}