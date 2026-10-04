#include "../include/mywc.h"

#include <stdio.h>

int count_chars(FILE **fp) {
  fseek(*fp, 0, SEEK_SET);

  int ccount = 0;
  char fchar = fgetc(*fp);

  while (fchar != EOF) {
    ccount++;
    fchar = fgetc(*fp);
  }

  return ccount;
}

int count_words(FILE **fp) {
  fseek(*fp, 0, SEEK_SET);

  int wcount = 0;
  char fchar = fgetc(*fp);

  while (fchar != EOF) {
    if (fchar == ' ' || fchar == '\n')
      wcount++;

    fchar = fgetc(*fp);
  }

  return wcount;
}

int count_lines(FILE **fp) {
  fseek(*fp, 0, SEEK_SET);

  int lcount = 0;
  char fchar = fgetc(*fp);

  while (fchar != EOF) {
    if (fchar == '\n')
      lcount++;

    fchar = fgetc(*fp);
  }

  return lcount;
}
