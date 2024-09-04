#include "s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  int res = 0;
  int scale = *get_scale(&value);
  if (result != NULL && scale < 29 && scale >= 0) {
    s21_decimal one = {{1, 0, 0, 0}};
    s21_decimal trunc_num = {{0, 0, 0, 0}};
    int sign = check_sign(value);
    s21_truncate(value, &trunc_num);
    if (sign == 1 && scale > 0) {
      s21_sub(trunc_num, one, result);
    } else {
      *result = trunc_num;
    }
  } else {
    res = 1;
  }
  return res;
}

int s21_round(s21_decimal value, s21_decimal *result) {
  int res = 0;
  int scale = *get_scale(&value);
  if (result != NULL && scale < 29 && scale >= 0) {
    s21_decimal one = {{1, 0, 0, 0}};
    s21_decimal trunc_num = {{0, 0, 0, 0}};
    s21_decimal remainder = {{0, 0, 0, 0}};
    s21_decimal half = {{5, 0, 0, 0}};
    set_scale(&half, 1);

    s21_truncate(value, &trunc_num);
    s21_sub(value, trunc_num, &remainder);
    clear_sign(&remainder);

    int sign = check_sign(trunc_num);
    if (s21_is_less(remainder, half)) {
      *result = trunc_num;
    } else {
      if (sign == 0) {
        s21_add(trunc_num, one, result);
      } else {
        s21_sub(trunc_num, one, result);
      }
    }
  } else {
    res = 1;
  }
  return res;
}

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int res = 0;
  int scale = (int)*get_scale(&value);
  if (result != NULL && scale < 29 && scale >= 0) {
    while (scale > 0) {
      s21_divide_by_10_smal(&value);
      scale--;
    }
    set_scale(&value, 0);
    *result = value;
  } else {
    res = 1;
  }
  return res;
}

int s21_negate(s21_decimal value, s21_decimal *result) {
  int res = 0;
  if (result != NULL) {
    if (check_sign(value)) {
      clear_sign(&value);
      *result = value;
    } else
      set_sign(&value);
    *result = value;
  } else {
    res = 1;
  }
  return res;
}
