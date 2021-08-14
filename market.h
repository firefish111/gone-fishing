double total;
int to_buy, to_sell, i;
bool has_some = false;

void market() {
  printf("You have $%zu. You have %zu bait.\n\n\n", money, bait);

  total = floor((double) money / (double) COST);

  if (money >= COST) {
    printf("\n\n\nYou can buy %g bait.\nHow much bait would you like to buy? ", total);
    scanf("%d", &to_buy);

    if (to_buy <= total) {
      money -= to_buy * COST;
      bait += to_buy;
    } else {
      printf("Unfortunately, you can't afford that much bait.\n\tEither try buying less, or try selling some of your fish.\n");
    }
  } else {
    printf("You can't afford any bait. Bait costs $21 per piece. You currently have $%zu.\n", money);
  }

  for (i = 5, has_some = false; i < 9; ++i) {
    if (data[i] != 0) {
      has_some = true;
    }
  }

  if (has_some) {
    printf("\n\n\n\nIt seems as if you have some big fish to sell. Here is what you have:\n");

    for (i = 7; i < 11; ++i) {
      printf("You have %zu %s, which you can sell for $%d per piece.\n", data[i-2], fish[i-1], sale[i-7]);
    }

    printf("What would you like to sell?\n");

    for (i = 7; i < 11; ++i) {
      printf("\tPress %d to sell %s,\n", i - 6, fish[i-1]);
    }
    printf("Or press 0 to not sell anything.\n> ");

    scanf("%d", &choice);
    if (choice > 0 && choice < 5) {
      printf("How much %s would you like to sell? (you currently have %zu) ", fish[choice + 5], data[choice + 4]);
      scanf("%d", &to_sell);

      if (to_sell > data[choice + 4]) {
        printf("You don't have that much $s!", fish[choice + 5]);
        return;
      } else {
        data[choice + 4] -= to_sell;
        money += sale[choice - 1] * to_sell;
      }
    } else {
      printf("Not selling anything.\n");
    }
  }
}