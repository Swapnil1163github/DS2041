#include <stdio.h>
int main() {
  int a[50], b, i, n, flag = 0, start, end = 0;
  printf("ENTER NUMBER OF ELEMENTS YOU WANT?: ");
  scanf("%d", &n);
  printf("ENTER THE VALUES WITH SPACE SEPERATED VALUES: ");
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  printf("ENTER THE SIZE OF WINDOW: ");
  scanf("%d", &b);

  end = end + (b - 1);
  for (start = 0; start < n - b + 1; start++) {
    for (i = start; i < start + b; i++) {
      if (a[i] < 0) {
        printf("%d ", a[i]);
        end++;
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      printf("0 ");
    }
    flag = 0;
  }
  return 0;
}
