// SELECTION SORT
#include <stdio.h>

int main() {
  int i, j, temp, min, n, a[50];
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
    min = i;
    for (j = i + 1; j < n; j++) {
      if (a[j] < a[min]) {
        min = j;
      }
    }
    if (i != min) {
      temp = a[min];
      a[min] = a[i];
      a[i] = temp;
    }
  }

  printf("\nYOUR LINKED LIST AFTER SORTING\n");
  for (i = 0; i < n; i++) {
    printf("%d\t", a[i]);
  }
  return 0;
}
