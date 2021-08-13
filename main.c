#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "table.h"

unsigned char tier = 0x0;
const int LEN = 9;
const int COST = 21;
int choice;
size_t money = 0;
size_t bait = 0;
size_t * data;

#include "cast.h"
#include "market.h" // Is there a reason it's down here? - dark
// yes, it will otherwise complain that money and data don't exist


int main(void) {
  srand(time(NULL));
  printf("Do you have a save? [y/N] ");

  choice = getchar();
  data = (size_t *) calloc(sizeof(size_t), LEN);

  if (choice == 'y' || choice == 'Y') {
    printf("Please paste your save here. (to paste in a terminal use Shift-Insert)\n> ");
    scanf("%01x$%zu[%zu:%zu:%zu:%zu:%zu][%zu:%zu:%zu:%zu]%zu", &tier, &money, &data[0], &data[1], &data[2], &data[3], &data[4], &data[5], &data[6], &data[7], &data[8], &bait);
  }

  printf("\x1b[H\x1b[2J");

  printf("You start with a %s rod!\n", rodname[tier]);
  do {
    printf("Press enter to fish, m to go to the market, or x to save and exit. ");
    choice = getchar();

    switch (choice) {
    case 'm':
      market();
      break;
    case 'x':
      printf("%01x$%zu[%zu:%zu:%zu:%zu:%zu][%zu:%zu:%zu:%zu]%zu\n", tier, money, data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7], data[8], bait);
      free(data); // it's only 18/36/72 bytes but it matters
      return 0;
    default:
      cast();
    }
  } while (1);

  // how the hell did you get here
  return 1;
}
