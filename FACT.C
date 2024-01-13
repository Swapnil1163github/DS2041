//FACTORIAL 
#include <stdio.h>

int fact(int n) {
  if (n <= 1)
    return 1;
  else
    return n * fact(n - 1);
}

int main() {
  int num;
  printf("ENTER ANY POSITIVE NUMBER:\n");
  scanf("%d", &num);

  if (num < 0)
    printf("FACTORIAL IS NOT DEFINED FOR NEGATIVE NUMBER\n");
  else
    printf("FACTORIAL OF %d IS %d", num, fact(num));
  return 0;
}
