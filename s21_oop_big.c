#include "s21_decimal.h"

int big_get_bit(s21_big_decimal src, int bit) {
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

void big_set_bit(s21_big_decimal *result, int i) {
  int x = 0;
  for (; i > 31; x++, i -= 32)
    ;
  result->bits[x] |= (1 << i);
}

char *big_get_scale(s21_big_decimal *src) {
  return (((char *)(&src->bits[6])) + 2);
}

void big_set_scale(s21_big_decimal *src, int scale) {
  char *sc = (((char *)(&src->bits[6])) + 2);
  *sc = scale;
}

int check_sign_big(s21_big_decimal src) {
  int res = 0;
  if ((src.bits[6] & (1 << 31)) == 0) {
    res = 0;
  } else
    res = 1;
  return res;
}
