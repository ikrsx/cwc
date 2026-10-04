#include "../include/mywc.h"

#include <stdio.h>

int count_chars(FILE **fp) {
  int ccount = 0;
  char fchar = fgetc(*fp);

  while (fchar != EOF) {
    ccount++;
    fchar = fgetc(*fp);
  }

  return ccount;
}
