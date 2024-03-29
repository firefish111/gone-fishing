if (argc > 1 && strcmp(argv[1], "/d") == 0) {
  printf("Gone Fishing v%s savefile destructurer. Copyright firefish %d.\n\n", mkver(VER), YEAR);

  savefile = fopen("GONEFISH.SAV", "rb");
  if (!savefile) {
    printf("Savefile does not exist. Cannot destructure.\n");
    return 1;
  }

  tempBuf = calloc(sizeof(size_t), LEN + 4);
  fread(tempBuf, sizeof(size_t), LEN + 4, savefile);
  printf("Save version %s.\nTier %d (%s), $%d in bank, %d bait.\nFish:\n", mkver(tempBuf[0]), tempBuf[1], rodname[tempBuf[1]], tempBuf[2], tempBuf[LEN + 3]);

  for (i = 0; i < LEN; ++i) {
    printf("\t%zu %s,\n", tempBuf[i + 3], fish[i < 5 ? i : i + 1]);
  }

  printf("\n\nText-based save: %01x$%zu[%zu:%zu:%zu:%zu:%zu][%zu:%zu:%zu:%zu]%zu\n", tempBuf[1], tempBuf[2], tempBuf[3], tempBuf[4], tempBuf[5], tempBuf[6], tempBuf[7], tempBuf[8], tempBuf[9], tempBuf[10], tempBuf[11], tempBuf[LEN + 3]);
  return 0;
}
