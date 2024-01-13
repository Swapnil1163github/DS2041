// PRIORITY QUEUE
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct {
  int data;
  int priority;
} Element;

typedef struct {
  Element elements[MAX_SIZE];
  int front, rear;
  int priorityType;
} PriorityQueue;

void InitializeQueue(PriorityQueue *queue) {
  queue->front = -1;
  queue->rear = -1;
}

int Empty(PriorityQueue *queue) {
  return (queue->front == -1 && queue->rear == -1);
}

int Full(PriorityQueue *queue) { return (queue->rear == MAX_SIZE - 1); }

void Enqueue(PriorityQueue *queue, int data, int priority) {
  if (Full(queue)) {
    printf("QUEUE IS FULL. CANNOT ENQUEUE.\n");
    return;
  }

  Element newElement;
  newElement.data = data;
  newElement.priority = priority;

  if (Empty(queue)) {
    queue->front = 0;
    queue->rear = 0;
    queue->elements[0] = newElement;
  } else {
    int i;
    for (i = queue->rear; i >= 0; i--) {
      if ((queue->priorityType == 1 &&
           newElement.priority > queue->elements[i].priority) ||
          (queue->priorityType == 2 &&
           newElement.priority < queue->elements[i].priority)) {
        queue->elements[i + 1] = queue->elements[i];
      } else {
        break;
      }
    }
    queue->elements[i + 1] = newElement;
    queue->rear++;
  }

  printf("ENQUEUED: %d WITH PRIORITY: %d\n", data, priority);
}

void Dequeue(PriorityQueue *queue) {
  if (Empty(queue)) {
    printf("QUEUE IS EMPTY. CANNOT DEQUEUE.\n");
    return;
  }

  Element dequeuedElement = queue->elements[queue->front];

  if (queue->front == queue->rear) {
    queue->front = -1;
    queue->rear = -1;
  } else {
    queue->front++;
  }

  printf("DEQUEUED: %d WITH PRIORITY: %d\n", dequeuedElement.data,
         dequeuedElement.priority);
}

void Traverse(PriorityQueue *queue) {
  if (Empty(queue)) {
    printf("QUEUE IS EMPTY.\n");
    return;
  }

  printf("QUEUE ELEMENTS: ");
  for (int i = queue->front; i <= queue->rear; i++) {
    printf("(%d, %d) ", queue->elements[i].data, queue->elements[i].priority);
  }
  printf("\n");
}

int main() {
  PriorityQueue queue;
  InitializeQueue(&queue);

  printf("SELECT PRIORITY TYPE:\n");
  printf("1. HIGHEST NUMBER HIGHEST PRIORITY\n");
  printf("2. LOWEST NUMBER HIGHEST PRIORITY\n");
  printf("ENTER YOUR CHOICE: ");
  scanf("%d", &queue.priorityType);

  int choice;
  do {
    printf("\nOPERATIONS:\n");
    printf("1. ENQUEUE\n");
    printf("2. DEQUEUE\n");
    printf("3. TRAVERSE\n");
    printf("4. EXIT\n");
    printf("ENTER YOUR CHOICE: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1: {
      int data, priority;
      printf("ENTER DATA AND PRIORITY: ");
      scanf("%d %d", &data, &priority);
      Enqueue(&queue, data, priority);
      break;
    }
    case 2:
      Dequeue(&queue);
      break;
    case 3:
      Traverse(&queue);
      break;
    case 4:
      printf("EXITING THE PROGRAM.\n");
      break;
    default:
      printf("INVALID CHOICE. PLEASE ENTER A VALID OPTION.\n");
    }

  } while (choice != 4);

  return 0;
}
