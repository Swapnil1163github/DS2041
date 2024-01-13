// INSERTION SORT
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

  for (i = 1; i < n; i++) {
    temp = a[i];
    j = i - 1;
    while (temp < a[j] && j >= 0) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = temp;
  }

  printf("\nYOUR LINKED LIST AFTER SORTING\n");
  for (i = 0; i < n; i++) {
    printf("%d\t", a[i]);
  }
  return 0;
}
