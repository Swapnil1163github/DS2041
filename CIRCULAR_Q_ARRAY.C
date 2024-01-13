// IMPLEMENT CIRCULAR QUEUE OPERATION USING ARRAY
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
      if (front == (rear + 1) % 5)
        printf("CIRCULAR QUEUE OVERFLOW\n");
      else {
        printf("ENTER THE DATA: \n");
        if (front == -1) {
          front = 0;
          rear = 0;
        } else {
          rear = (rear + 1) % 5;
        }
        scanf("%d", &a[rear]);
        printf("%d IS ENQUEUEED SUCCESSFULLY\n", a[rear]);
      }
      break;

    // DEQUEUE
    case 2:
      if (front == -1 && rear == -1) {
        printf("CIRCULAR QUEUE UNDERFLOW\n");
      } else {
        printf("%d IS DEQUEUEED SUCCESSFULLY\n", a[front]);
        front = (front + 1) % 5;
        if (front == (rear + 1) % 5) {
          rear = -1;
          front = -1;
        }
      }
      break;

    // TRAVERSE
    case 3:
      if (front == -1) {
        printf("CIRCULAR QUEUE UNDERFLOW\n");
      } else {
        for (i = front; i != rear; i = (i + 1) % 5) {
          printf("-->%d ", a[i]);
        }
        printf("-->%d ", a[rear]);
      }
      break;

    case 4: // EXIT
      break;

    default:
      printf("ENTER VALID CHOICE\n");
    }
  } while (choice != 4);
  return 0;
}