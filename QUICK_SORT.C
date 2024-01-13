// QUICK SORT
#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void quick_sort(int a[], int low, int high) {
  if (low < high) {

    int pivot = a[low];
    int i = low, j = high;

    while (i <= j) {
      while (a[i] < pivot) {
        i++;
      }
      while (a[j] > pivot) {
        j--;
      }
      if (i <= j) {
        swap(&a[i], &a[j]);
        i++;
        j--;
      }
    }
    if (low < j) {
      quick_sort(a, low, j);
    }
    if (i < high) {
      quick_sort(a, i, high);
    }
  }
}

int main() {
  int i, n, a[100], low = 0, high;
  printf("ENTER THE NUMBER OF ELEMENTS:");
  scanf("%d", &n);
  high = n - 1;

  for (i = 0; i < n; i++) {
    printf("ENTER ELEMENT %d:", i + 1);
    scanf("%d", &a[i]);
  }

  printf("YOUR LINKED LIST BEFORE SORTING:\n");
  for (i = 0; i < n; i++) {
    printf("%d\t", a[i]);
  }

  quick_sort(a, low, high);

  printf("\nYOUR LINKED LIST AFTER SORTING:\n");
  for (i = 0; i < n; i++) {
    printf("%d\t", a[i]);
  }
  return 0;
}