if (argc > 1 && strcmp(argv[1], "/d") == 0) {
  printf("Gone Fishing v%zu.%zu.%zu savefile destructurer. Copyright firefish 2022.\n\n", VER / 100, (VER / 10) % 10, VER % 10);

  savefile = fopen("GONEFISH.SAV", "rb");
  if (!savefile) {
    printf("Savefile does not exist. Cannot destructure.\n");
    return 1;
  }

  tempBuf = calloc(sizeof(size_t), LEN + 4);
  fread(tempBuf, sizeof(size_t), LEN + 4, savefile);
  printf("Save version %zu.%zu.%zu.\nTier %d (%s), $%d in bank, %d bait.\nFish:\n", tempBuf[0] / 100, (tempBuf[0] / 10) % 10, tempBuf[0] % 10, tempBuf[1], rodname[tempBuf[1]], tempBuf[2], tempBuf[LEN + 3]);

  for (i = 0; i < 9; ++i) {
    printf("\t%zu %s,\n", tempBuf[i + 3], fish[i < 5 ? i : i + 1]);
  }
  return 0;
}