#include <stdio.h>
#include <stdlib.h>

int main(void) {
  printf("Do you have a save? [y/N] ");
  int save = getchar();

  unsigned char tier = 0x0;
  size_t * data = calloc(sizeof(size_t), 11);

  if (save == 'y' || save == 'Y') {
    printf("Please paste your save here. (to paste in a terminal use Shift-Insert)\n> ");
    scanf("%01x$%zu[%zu:%zu:%zu:%zu:%zu][%zu:%zu:%zu:%zu]%zu", &tier, &data[0], &data[1], &data[2], &data[3], &data[4], &data[5], &data[6], &data[7], &data[8], &data[9], &data[10]);
  }
  
  free(data); // it's only 44/88 bytes but it matters
  return 0;
}