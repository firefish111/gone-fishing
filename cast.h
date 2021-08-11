int calc() {
  float d = (float) rand() / (float) RAND_MAX;
  for (int i = 0; i < 7; ++i) {
    d -= clump[tier][i];
    if (d <= 0) {
      return i;
      break;
    }
  }
  return 0;
}

void cast() {
  printf("\nCasting your %s rod...\n\n", rodname[tier]);
  int catch = calc();

  printf("You caught some %s!\n",
    catch == 0 ? tiername[tier+1] :
    catch == 6 ? "junk" : 
    fish[catch]
  );

  if (catch == 0) {
    printf("You can upgrade your rod now, to fish better items. Do it now, or sell the %s? [y/N]\n> ", tiername[tier+1]);
    int ify = getchar();

    if (ify == 'y' || ify == 'Y') {
      printf("You have upgraded your fishing rod to a %s rod!\n", rodname[++tier]);
    } else {
      money += tier + 1;
      printf(
        "You sold the %s for $%d!",
        tiername[tier+1],
        tier + 1
      );
    }
  } else if (catch == 6) {
    int j = (rand() % 5) + 1;
    money += j;
    printf("You sold the junk for $%d!\n", j);
  } else {
    data[catch]++;
  }
}