#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
#include <conio.h> // needs this for getch() which is used instead of getchar()
#include "table.h"

// semver version; insert dots after each nybble; max 15.15.15.rc6
// last digit is subversion - f is none, 0-3 is alpha, 4-7 is beta, 8-14 is rc1-6
const unsigned short VER = 0x2205;

unsigned char tier = 0x0;
const int LEN = 9;
const int COST = 21;
const int YEAR = 2023;
int choice;
int i;
size_t money = 0;
size_t bait = 0;
size_t * data;
size_t * tempBuf;
FILE * savefile;

#include "cast.h"
#include "market.h"

char* verBuf;
#define VER_LEN 20

char* mkver(unsigned short ver) {
  memset(verBuf, '\0', VER_LEN);
  sprintf(verBuf, "%hu.%hu.%hu", (ver >> 12) & 0x000f, (ver >> 8) & 0x000f, (ver >> 4) & 0x000f);
  switch ((ver & 0x000f)) {
  case 15:
    break;
  case 0:
  case 1:
  case 2:
  case 3:
    sprintf(verBuf + strlen(verBuf), "-alpha.%d", (ver & 0x000f) + 1);
    break;
  case 4:
  case 5:
  case 6:
  case 7:
    sprintf(verBuf + strlen(verBuf), "-beta.%d", (ver & 0x000f) - 3);
    break;
  default:
    sprintf(verBuf + strlen(verBuf), "-rc.%d", (ver & 0x000f) - 7);
    break;
  }
  return verBuf;
}

int main(int argc, char** argv) {
  verBuf = calloc(VER_LEN, sizeof(char));

  // save destructuror
  #include "destruct.h"

  srand(time(NULL));

  printf("Gone Fishing v%s. Copyright @firefish %d.\nRun with /d flag to destructure the save file.\n\n", mkver(VER), YEAR);

  i = access("GONEFISH.SAV", 0); // F_OK ain't defined, so we use good ol' fashioned 0
  start:
  printf("Save loading options:\n\t[f] Load save from file %s\n\t[t] Type/Paste save in\n\t[c] Create new save %s\n", i != -1 ? "(default)" : "", i == -1 ? "(default)" : "");

  fflush(stdout);
  choice = getch();
  fflush(stdin);

  data = (size_t *) calloc(sizeof(size_t), LEN);

  printf("\n");

  if (choice == 't' || choice == 'T') {
    printf("Please type your save here.\n> ");
    scanf("%01x$%zu[%zu:%zu:%zu:%zu:%zu][%zu:%zu:%zu:%zu]%zu", &tier, &money, &data[0], &data[1], &data[2], &data[3], &data[4], &data[5], &data[6], &data[7], &data[8], &bait);
  } else if (choice == 'c' || choice == 'C') {
    // haha get fooled
  } else if ((choice == 'f' || choice == 'F') || (i != -1)) {
    savefile = fopen("GONEFISH.SAV", "rb");
    if (!savefile) {
      printf("Savefile does not exist. Returning to menu.\n");
      fclose(savefile);
      goto start;
    }

    // read from file: the format is just a binary file including all the numbers in the save string, in that order, as size_t.
    // this makes this incompatible between 16-bit and 32-bit systems, but do I care? no
    // on second thought it actually is compatible
    tempBuf = calloc(sizeof(size_t), LEN + 4);
    fread(tempBuf, sizeof(size_t), LEN + 4, savefile);

    // file format understander
    if (tempBuf[0] > VER) {
      printf("You're trying to import a save from a newer version of Gone Fishing (%s).\n\tAre you sure you want to import? (y/N)\n", mkver(tempBuf[0]));

      fflush(stdout);
      choice = getch();
      fflush(stdin);

      if (!(choice == 'y' || choice == 'Y')) {
        printf("Returning to menu.\n");
        goto start;
      }
    } else if (tempBuf[0] < VER) {
      printf("Updating save from v%s.\n\n", mkver(tempBuf[0]), mkver(VER));
    }

    tier = (unsigned char) tempBuf[1];
    money = tempBuf[2];
    bait = tempBuf[LEN + 3];
    for (i = 0; i < LEN; ++i) {
      data[i] = tempBuf[i + 3];
    }
    free(tempBuf);
    fclose(savefile);
  }

  printf("You start with a %s rod!\n", rodname[tier]);
  do {
    printf("Press [enter] to fish, [m] to go to the market, or [x] to save and exit. ");
    fflush(stdout);
    choice = getch();
    fflush(stdin);

    printf("\n");
    switch (choice) {
    case 'm':
    case 'M':
      market();
      break;
    case 'x':
    case 'X':
      i = access("GONEFISH.SAV", 0); // F_OK isn't here either :(
      printf("Where would you like your save?\n\t[f] to save to file (default) %s\n\t[t] to return save string as text.\n", i != -1 ? "(THIS OVERRIDES YOUR CURRENT SAVE)" : "");

      fflush(stdout);
      choice = getch();
      fflush(stdin);

      if (choice == 't' || choice == 'T'){
        printf("\n\nHere is your save:\n\n\n%01x$%zu[%zu:%zu:%zu:%zu:%zu][%zu:%zu:%zu:%zu]%zu\n", tier, money, data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7], data[8], bait);
        return 0;
      }

      savefile = fopen("GONEFISH.SAV", "wb");
      tempBuf = calloc(sizeof(size_t), LEN + 4);

      tempBuf[0] = VER;
      tempBuf[1] = (size_t) tier;
      tempBuf[2] = money;
      tempBuf[LEN + 3] = bait;

      for (i = 0; i < LEN; ++i) {
        tempBuf[i + 3] = data[i];
      }

      fwrite(tempBuf, sizeof(size_t), LEN + 4, savefile);

      free(tempBuf);
      free(data); // it's only 18 bytes but it matters
      free(verBuf);
      return 0;
    default:
      cast();
    }
  } while (1);

  // how the hell did you get here
  return 0;
}
