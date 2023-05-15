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

const char * fish[10] = {
  "salmon", "tuna", "cod", "mackerel", "haddock", NULL, "carp", "trout", "whale", "shark"
};

// level 0-10 values sum to 1
// level 11 onwards values sum to 2
const float lv0[7] = {0.1916, 0, 0, 0.3084, 0, 0, 0.5};
const float lv1[7] = {0.1207, 0.4681, 0.2112, 0, 0, 0, 0.2};
const float lv2[7] = {0.2222, 0.4512, 0.1958, 0, 0.0308, 0, 0.1};
const float lv3[7] = {0.0724, 0, 0.3129, 0.2459, 0.1945, 0, 0.2};
const float lv4[7] = {0.0928, 0, 0, 0.596, 0.2112, 0, 0.1};
const float lv5[7] = {0.1149, 0, 0, 0, 0.4968, 0.0883, 0.3};
const float lv6[7] = {0.1686, 0, 0, 0, 0.3441, 0.1873, 0.3};
const float lv7[7] = {0.1854, 0, 0, 0, 0.2985, 0.3161, 0.2};
const float lv8[7] = {0.1996, 0, 0, 0, 0.2453, 0.3465, 0.2086};
const float lv9[7] = {0.2132, 0, 0, 0, 0.2092, 0.3679, 0.2098};
const float lv10[7] = {0.2482, 0, 0, 0, 0.101, 0.4966, 0.1542};
const float lv11[11] = {0.2691, 0, 0, 0, 0, 0.5144, 0.2165, 0.6099, 0.3148, 0.0742, 0.0011};
const float lv12[11] = {0.2919, 0, 0, 0, 0, 0.4871, 0.221, 0.5634, 0.327, 0.1001, 0.0095};
const float lv13[11] = {0.3414, 0, 0, 0, 0, 0.4506, 0.2, 0.5098, 0.3009, 0.154, 0.0345};
const float lv14[11] = {0.399, 0, 0, 0, 0, 0.351, 0.25, 0.5, 0.369, 0.1904, 0.1406};
const float lv15[12] = {0, 0.06, 0.12, 0.17, 0.25, 0.3, 0.1, 0.25, 0.25, 0.25, 0.25};

const float * clump[16] = {lv0, lv1, lv2, lv3, lv4, lv5, lv6, lv7, lv8, lv9, lv10, lv11, lv12, lv13, lv14, lv15};

// for high-value: pre 2.0.4 mechanic
// const int sale[4] = {15, 25, 40, 70};
const int sale[5] = {15, 12, 10, 8, 8};

