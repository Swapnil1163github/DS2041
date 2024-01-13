// BABBLE SORT
#include <stdio.h>

int main() {
  int i, a[50], j, temp, n;
  printf("ENTER THE NUMBER OF ELEMENTS:");
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    printf("ENTER ELEMENT %d:", i + 1);
    scanf("%d", &a[i]);
  }

  printf("YOUR LINKED LIST BEFORE SORTING:\n");
  for (i = 0; i < n; i++) {
    printf("%d\t", a[i]);
  }

  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (a[j] > a[j + 1]) {
        temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
      }
    }
  }

  printf("\nYOUR LINKED LIST AFTER SORTING\n");
  for (i = 0; i < n; i++) {
    printf("%d\t", a[i]);
  }
  return 0;
}
