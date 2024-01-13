// MERGE SORT
#include <stdio.h>

void merge(int a[], int low, int mid, int high) {
  int i = low, j = mid + 1, k = low;
  int b[high - low + 1];

  while (i <= mid && j <= high) {
    if (a[i] < a[j]) {
      b[k] = a[i];
      i++;
    } else {
      b[k] = a[j];
      j++;
    }
    k++;
  }

  while (i <= mid) {
    b[k] = a[i];
    i++;
    k++;
  }

  while (j <= high) {
    b[k] = a[j];
    j++;
    k++;
  }

  for (k = low; k <= high; k++) {
    a[k] = b[k];
  }
}

void merge_sort(int a[], int low, int high) {
  if (low < high) {
    int mid = (low + high) / 2;

    merge_sort(a, low, mid);
    merge_sort(a, mid + 1, high);
    merge(a, low, mid, high);
  }
}

int main() {
  int i, j, k, n, a[100], low = 0, high, mid;
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

  merge_sort(a, low, high);

  printf("\nYOUR LINKED LIST AFTER SORTING:\n");
  for (i = 0; i < n; i++) {
    printf("%d\t", a[i]);
  }
  return 0;
}
