double total;
int to_buy;

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
}

/*
if (!(Object.values(opfish).every(ky => ky === 0))) {
  console.log("\n\n\n\nIt seems as if you have some big fish to sell. Here is what you have:");

  for (const bigfish in opfish) {
    console.log(`You have ${opfish[bigfish]} ${bigfish}, which you can sell for \$${sellprice[bigfish]} per piece`);
  }

  console.log("What would you like to sell?");

  Object.keys(opfish).forEach((itm, ix) => {
    console.log(`\tPress ${ix+1} to sell ${itm},`);
  });
  console.log("Or press enter to not sell anything.");

  let ip = rl.question("> ");
  try {
    if (ip === "") throw "e";
    ip = Number(ip) - 1;
    const inq = Object.keys(opfish)[ip];

    if (ip >= inq.length) throw ip;

    const amnt = Number(rl.question(`How much ${inq} would you like to sell? (you currently have ${opfish[inq]})`));

    if (amnt > opfish[inq]) {
      console.log(`You don't have that much ${inq}!`);
      throw ammt;
    } else {
      opfish[inq] -= amnt;
      money += sellprice[inq] * amnt;
    }
  } catch (e) {
    console.log("\x1b[38;5;1mDEBUG: Not selling anything.\x1b[0m", e);
  }
}
*/