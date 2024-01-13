#include <stdio.h>
int main() {
  int a[50];
  int i, top = -1, ch;
  do {
    printf("ENTER YOUR CHOICE:\n1.PUSH \n2.POP \n3.TRAVERSE\n4.TOP OF "
           "STACK\n5.EXIT\n: ");
    scanf("%d", &ch);
    switch (ch) {
    case 1:
      if (top == 4) {
        printf("STACK OVERFLOW");
      } else {
        top = top + 1;
        printf("ENTER DATA ELEMENT:");
        scanf("%d", &a[top]);
      }
      break;
    case 2:
      if (top == -1) {
        printf("STACK UNDERFLOW");
      } else {
        printf("%d IS POPPED", a[top]);
        top = top - 1;
      }
      break;
    case 3:
      if (top == -1) {
        printf("STACK IS EMPTY");
      } else {
        for (i = 0; i <= top; i++) {
          printf(" %d", a[i]);
        }
      }
      break;
    case 4:
      if (top == -1) {
        printf("STACK IS EMPTY");
      } else {
        printf("%d", a[top]);
      }
    case 5:
      break;
    default:
      printf("ENTER VALID CHOICE");
    }
  } while (ch != 5);
}
