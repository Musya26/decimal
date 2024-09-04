#include "s21_decimal.h"

int get_bit(s21_decimal src, int bit) {
  int x = 0;
  int res = 0;
  for (; bit > 31; x++, bit -= 32)
    ;
  if ((src.bits[x] & (1 << (bit))) == 0) {
    res = 0;
  } else
    res = 1;
  return res;
}

char *get_scale(s21_decimal *src) { return (((char *)(&src->bits[3])) + 2); }

void set_scale(s21_decimal *src, int scale) {
  char *sc = (((char *)(&src->bits[3])) + 2);
  *sc = scale;
}

int check_sign(s21_decimal src) {
  int res = 0;
  if ((src.bits[3] & (1 << 31)) == 0) {
    res = 0;
  } else
    res = 1;
  return res;
}

void set_sign(s21_decimal *src) { src->bits[3] |= (1 << 31); }

void clear_sign(s21_decimal *src) { src->bits[3] &= (~(1 << 31)); }
