// LINEAR SEARCH
#include <stdio.h>

int main() {
  int i, key, flag = 0, a[30], n;
  printf("ENTER NUMBER OF ELEMENTS YOU WANT:\n");
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    printf("ENTER ELEMENT %d:", i + 1);
    scanf("%d", &a[i]);
  }

  printf("ENTER KEY WORD:\n");
  scanf("%d", &key);

  for (i = 0; i < 5; i++) {
    if (key == a[i]) {
      flag = 1;
      break;
    }
  }
  if (flag == 1) {
    printf("ELEMENT FOUND SUCCESFULLY AT %d\n", i + 1);
  } else
    printf("UNSCCESSFUL TO FIND THE ELEMENT\n");

  return 0;
}
