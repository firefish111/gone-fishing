/*
struct fish {
  // w h a t
  long int unsigned long salmon;
  long long int unsigned tuna;
  unsigned long int long cod;
  int long unsigned long mackerel;
  long int long unsigned haddock;
  unsigned char next;
};

struct opfish {
  unsigned long long carp;
  long unsigned long trout;
  long long unsigned whale;
  unsigned long long shark;
};
*/
enum type {
  salmon = 1,
  tuna = 2,
  cod = 3,
  mackerel = 4,
  haddock = 5,
  carp = 7,
  trout = 8,
  whale = 9,
  shark = 10
};

const char * tiername[16] = {
  "string", "wood", "bamboo", "ice",
  "brick", "stone", "iron", "copper",
  "silver", "gold", "platinum", "ruby",
  "emerald", "sapphire", "diamonds", "fishing rods"
};

const char * rodname[16] = {
  "stringy", "wooden", "bamboo", "icy",
  "brick", "rocky", "stainless steel", "copper",
  "silver", "golden", "platinum", "ruby",
  "emerald", "sapphire", "diamond", "rod on a"
};

const char * fish[5] = {
  "salmon", "tuna", "cod", "mackerel", "haddock"
};

const float lv0[7] = {0.1916, 0, 0, 0.3084, 0, 0, 0.5};
const float lv1[7] = {0.1207, 0.4681, 0.2112, 0, 0, 0, 0.2};
const float lv2[7] = {0.2222, 0.4512, 0.1958, 0, 0.0308, 0, 0.1};

const float * clump[3] = {lv0, lv1, lv2};