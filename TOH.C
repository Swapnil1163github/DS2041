//TOWER OF HANOI
#include <stdio.h>

void toh(int n, char source, char desti, char tempo);

int main() {
  int n;
  printf("ENTER THE NUMBER OF DISKS\n");
  scanf("%d", &n);
  toh(n, 'A', 'C', 'B');
  return 0;
}

void toh(int n, char source, char desti, char tempo) {
  if (n > 0) {
    toh(n - 1, source, tempo, desti);
    printf("\nMOVE %d FROM TOWER %c TO TOWER %c", n, source, desti);
    toh(n - 1, tempo, desti, source);
  }
}