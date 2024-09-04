#include "s21_decimal.h"

void inverse(s21_big_decimal *val) {
  for (int i = 0; i < 6; i++) {
    val->bits[i] = ~val->bits[i];
  }
}

void big_shift_left(s21_big_decimal *value, int shift_value) {
  unsigned memory = 0;
  for (int i = 0; i < 6; i++) {
    unsigned temp = value->bits[i];
    value->bits[i] <<= shift_value;
    value->bits[i] |= memory;
    memory = temp >> (32 - shift_value);
  }
}

int big_normalisation(s21_big_decimal *value1, s21_big_decimal *value2) {
  char *scale1 = big_get_scale(value1);
  char *scale2 = big_get_scale(value2);
  int diff_scale = (int)*scale1 - (int)*scale2;

  if (diff_scale > 0) {
    scale_normalise(value2, diff_scale);
    big_set_scale(value2, (int)*scale1);
  } else {
    scale_normalise(value1, -diff_scale);
    big_set_scale(value1, (int)*scale2);
  }
  return 0;
}

void scale_normalise(s21_big_decimal *value, int n) {
  s21_big_decimal ten = {{10, 0, 0, 0, 0, 0, 0}}, memo = {0};
  for (int i = 0; i < n; i++) {
    s21_mul_big_dec(*value, ten, &memo);
    *value = memo;
    big_dec_zero(&memo);
  }
}

unsigned int s21_divide_by_10(s21_big_decimal *number) {
  int high_index = 0, check = 1;
  for (int i = 5; i >= 0 && check; i--) {
    if (number->bits[i] != 0) {
      high_index = i;
      check = 0;
    }
  }
  unsigned long int rem = 0;
  for (int i = high_index; i >= 0; i--) {
    rem = (rem << 32) | number->bits[i];
    number->bits[i] = rem / 10;
    rem = rem % 10;
  }
  return rem;
}

int s21_post_normalization(s21_big_decimal *result, int scale) {
  while ((result->bits[3] || result->bits[4] || result->bits[5]) && scale > 0) {
    sub_scale_big(result, 1);
    scale--;
  }
  if (result->bits[3] || result->bits[4] || result->bits[5]) {
    scale = -1;
  }
  return scale;
}

void sub_scale_big(s21_big_decimal *dst, int n) {
  s21_big_decimal one = {{1, 0, 0, 0, 0, 0, 0}};

  unsigned int rem = 0;
  for (int i = 0; i < n; i++) {
    rem = s21_divide_by_10(dst);
    int last_bit = big_get_bit(*dst, 0);
    if (rem == (unsigned int)5) {
      if (last_bit != 0) {
        s21_add_big_dec(*dst, one, dst);
      }
    } else if (rem > (unsigned int)5) {
      s21_add_big_dec(*dst, one, dst);
    }
  }
}

void dec_zero(s21_decimal *src) {
  src->bits[0] = 0;
  src->bits[1] = 0;
  src->bits[2] = 0;
  src->bits[3] = 0;
}
void big_dec_zero(s21_big_decimal *src) {
  src->bits[0] = 0;
  src->bits[1] = 0;
  src->bits[2] = 0;
  src->bits[3] = 0;
  src->bits[4] = 0;
  src->bits[5] = 0;
  src->bits[6] = 0;
}

void shift_left(s21_decimal *value, int shift_value) {
  unsigned memory = 0;
  for (int i = 0; i < (int)(sizeof(s21_decimal) / sizeof(int) - 1); i++) {
    unsigned temp = value->bits[i];
    value->bits[i] <<= shift_value;
    value->bits[i] |= memory;
    memory = temp >> (32 - shift_value);
  }
}

unsigned int s21_divide_by_10_smal(s21_decimal *number) {
  int high_index = 0, check = 1;
  for (int i = 2; i >= 0 && check; i--) {
    if ((unsigned int)number->bits[i] != 0) {
      high_index = i;
      check = 0;
    }
  }
  unsigned long int rem = 0;
  for (int i = high_index; i >= 0; i--) {
    rem = (rem << 32) | (unsigned int)number->bits[i];
    number->bits[i] = rem / 10;
    rem = rem % 10;
  }
  return rem;
}
