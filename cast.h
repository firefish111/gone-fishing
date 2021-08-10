int calc() {
  /*
    let d = Math.random();
    for (itm in table) {
      d -= table[itm];
      if (d <= 0) {
        return itmi;
        break;
      }
    }
  */
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
}