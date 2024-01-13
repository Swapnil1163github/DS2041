#include <stdio.h>

void inc(int *largptr, int *valuptr, int *prevptr) {
  *largptr += *valuptr;
  *prevptr = *largptr;
  printf("%d", *largptr);
}

int main() {
  int i = 0, j = 0, next_dec = 1, prev_num = 1, large_num = 1;
  char seq[10];
  printf("ENTER ANY SEQUENCE IN CAPITAL LATTER(IN CHARACTERS 'I' & 'D'): ");
  scanf("%s", seq);
  printf("YOUR SHORTEST NUMBER FOR THIS SEQUESNCE IS: ");
  if (seq[i] == 'I') {
    printf("1");
  } else {
    while (seq[j] == 'D') {
      j++;
    }
    printf("%d", j + 1);
  }
  while (seq[i] != '\0') {
    next_dec = 1;
    if (seq[i] == 'I') {
      j = i + 1;
      while (1) {
        if (seq[j] == 'D')
          next_dec++;
        else
          break;
        j++;
      }
      inc(&large_num, &next_dec, &prev_num);
    } else {
      if (prev_num > 1)
        printf("%d", --prev_num);
      else {
        j = i + 1;
        next_dec++;
        while (1) {
          if (seq[j] == 'D')
            next_dec++;
          else
            break;
          j++;
        }
        large_num = prev_num = next_dec;
        printf("%d", --prev_num);
      }
    }
    i++;
  }
  return 0;
}