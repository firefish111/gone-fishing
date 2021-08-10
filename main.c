#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "table.h"

unsigned char tier = 0x0;

#include "cast.h"

int main(void) {
  srand(time(NULL));
  printf("Do you have a save? [y/N] ");
  int save = getchar();
  const int LEN = 11;

  size_t * data = calloc(sizeof(size_t), LEN);

  if (save == 'y' || save == 'Y') {
    printf("Please paste your save here. (to paste in a terminal use Shift-Insert)\n> ");
    scanf("%01x$%zu[%zu:%zu:%zu:%zu:%zu][%zu:%zu:%zu:%zu]%zu", &tier, &data[0], &data[1], &data[2], &data[3], &data[4], &data[5], &data[6], &data[7], &data[8], &data[9], &data[10]);
  }

  printf("\x1b[H\x1b[2J");
  
  do {
    printf("");
    //int choice = getchar();
    cast();
  } while (0);
  
//#include "test.h"

  free(data); // it's only 44/88 bytes but it matters
  return 0;
}