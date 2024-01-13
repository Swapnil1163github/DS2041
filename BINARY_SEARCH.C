// BINARY SEARCH
#include <stdio.h>

int main() {
  int i, mid, flag = 0, a[30], n, low = 0, high, key;

  printf("ENTER NUMBER OF ELEMENTS YOU WANT:\n");
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    printf("ENTER ELEMENT %d:", i + 1);
    scanf("%d", &a[i]);
  }

  printf("ENTER KEY WORD:\n");
  scanf("%d", &key);

  high = n;
  while (low <= high) {
    mid = (low + high) / 2;
    if (key == a[mid]) {
      flag = 1;
      break;
    } else if (key < a[mid]) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  if (flag == 0) {
    printf("UNCCESSFUL TO FIND THE ELEMENT\n");
  } else
    printf("ELEMENT FOUND SUCCESFULLY AT %d\n", mid + 1);

  return 0;
}
