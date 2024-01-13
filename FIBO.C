//FIBONACCI SERIES 
#include <stdio.h>

int fibonacci(int a) {
  if (a <= 0)
    return 0;
  else if (a == 1)
    return 1;
  else
    return fibonacci(a - 1) + fibonacci(a - 2);
}

int main() {
  int n, i;
  printf("ENTER THE NUMBER OF TERMS\n");
  scanf("%d", &n);
  fibonacci(n);
  printf("FIBONACCI SERIES UP TO %d TREMS:\n", n);
  for (i = 0; i < n; i++) {
    printf("%d\t", fibonacci(i));
  }
  return 0;
}