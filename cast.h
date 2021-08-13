#include <stdbool.h>

int catch, i, j, choice;
float d;
bool baited = false;

int calc(bool bait) {
  d = (float) rand() / (float) RAND_MAX;
  for (i = bait ? 7 : 0; i < bait ? 11 : 7; ++i) {
    d -= clump[tier][i];
    if (d <= 0) {
      return i;
      break;
    }
  }
  return 0;
}


void cast() {
 /*
   let caught,
    baityn = false; // yesn't
  if (rod > 10) {
    baityn = rl.keyInYN("Use some bait to catch better fish?\n\t(You can't catch rod upgrades when using bait)");

    if (baityn) {
      if (bait > 0) {
        caught = load.calculate(tbl.bait);
        bait--;
      } else {
        console.log("You don't have any bait. You can buy bait at the market for $21 per piece.");
        return;
      }
    } else {
      caught = load.calculate(tbl.norm);
    }
  } else {
    caught = load.calculate(tbl);
  }
  */

  if (tier >= 11) {
    printf("Use some bait to catch better fish?\n\t(You can't catch rod upgrades when using bait) (y/N) ");
    choice = getchar();

    baited = choice == 'y' || choice == 'Y';
    if (baited) {
      if (bait > 0) {
        bait--;
      } else {
        baited = false;
        printf("You don't have any bait. You can buy bait at the market for $%d per piece.\n", COST);
        return;
      }
    }
  }

  printf("\nCasting your %s rod...\n\n", rodname[tier]);
  catch = calc(baited);

  printf("You caught some %s (a.k.a %d)!\n",
    catch == 0 ? tiername[tier+1] :
    catch == 6 ? (
      tier == 15 ? "money" : "junk"
    ) :
    fish[catch-1],
    catch
  );

  if (catch == 0) {
    printf("You can upgrade your rod now, to fish better items. Do it now, or sell the %s? [y/N]\n> ", tiername[tier+1]);
    choice = getchar();

    if (choice == 'y' || choice == 'Y') {
      printf("You have upgraded your fishing rod to a %s rod!\n", rodname[++tier]);
    } else {
      money += tier + 1;
      printf(
        "You sold the %s for $%d!\n",
        tiername[tier+1],
        tier + 1
      );
    }

  } else if (catch == 6) {
    if (tier == 15) {
      j = (rand() % 10) * 10;
      money += j;
      printf("You take the $%d.\n", j);
    } else {
      j = (rand() % 5) + 1;
      money += j;
      printf("You sold the junk for $%d!\n", j);
    }
  } else {
    data[catch-(catch > 6 ? 2 : 1)]++;
  }
}