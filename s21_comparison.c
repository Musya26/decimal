#include <stdio.h>

#include "s21_decimal.h"

int s21_is_greater(s21_decimal value1, s21_decimal value2) {
  int res = 0;
  if (comprasion_with_big(value1, value2) == 1) {
    res = 1;
  }
  return res;
}

int s21_is_less_or_equal(s21_decimal value1, s21_decimal value2) {
  int res = 0;
  if (s21_is_equal(value1, value2) || s21_is_less(value1, value2)) res = 1;
  return res;
}

int s21_is_equal(s21_decimal value1, s21_decimal value2) {
  int res = 0;
  if (comprasion_with_big(value1, value2) == 0) {
    res = 1;
  }
  return res;
}

int s21_is_less(s21_decimal value1, s21_decimal value2) {
  int res = 0;
  if (comprasion_with_big(value1, value2) == -1) {
    res = 1;
  }
  return res;
}
int s21_is_not_equal(s21_decimal value1, s21_decimal value2) {
  return !s21_is_equal(value1, value2);
}

int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2) {
  int res = 0;
  if (s21_is_equal(value_1, value_2) || s21_is_greater(value_1, value_2))
    res = 1;
  return res;
}
