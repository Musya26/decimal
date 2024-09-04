#include <math.h>

#include "s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int* dst) {
  int res = CONV_OK;
  s21_decimal src1 = {0};
  s21_truncate(src, &src1);
  if (dst == NULL) {  //в случае переполнения выдаст единицу
    res = CONV_ERR;
  } else {
    *dst = 0;

    *dst = src1.bits[0];
    if (get_bit(src1, 127) == 1) {
      (*dst) = -1 * (*dst);
    }
  }
  return res;
}

int s21_from_decimal_to_float(s21_decimal src, float* dst) {
  int res = CONV_OK;
  if (dst == NULL) {  //|| (*dst > powf(10, 38))) {
    res = CONV_ERR;
  } else {
    long int integrate = 0;
    integrate = src.bits[0];
    if (get_bit(src, 127) == 1) {
      (*dst) = -1 * (*dst);
    }

    if (src.bits[1] != 0) {  //если нулевой бит переполнен
      for (int i = 32; i < 64; i++) {
        if (get_bit(src, i) == 1) integrate += pow(2, i);
      }
    }
    if (src.bits[2] != 0) {  //если первый бит переполнен
      for (int i = 64; i < 96; i++) {
        if (get_bit(src, i) == 1) integrate += pow(2.0, i);
      }
    }
    //*dst = integrate;
    int scale = *get_scale(&src);
    *dst = integrate / (pow(10, scale));
    if (check_sign(src)) *dst *= -1;
  }
  return res;
}

int s21_from_int_to_decimal(int src, s21_decimal* dst) {
  dec_zero(dst);
  if (dst == NULL) {
    return CONV_ERR;
  } else {
    if (src < 0) {
      set_sign(dst);
      src *= -1;
    }
    dst->bits[0] = (unsigned int)src;
    return CONV_OK;
  }
}

void from_decimal_to_bigdecimal(s21_decimal src, s21_big_decimal* dst) {
  for (int i = 0; i < 96; i++) {
    if (get_bit(src, i)) big_set_bit(dst, i);
  }
}

void from_bigdecimal_to_decimal(s21_big_decimal src, s21_decimal* dst) {
  dst->bits[0] = src.bits[0];
  dst->bits[1] = src.bits[1];
  dst->bits[2] = src.bits[2];
  // dst->bits[3] = src.bits[3];
}

void convert_number(long long number, s21_decimal* dst, int scale2) {
  int bit;
  if (number > 4294967295) {
    while (number > 4294967295) {
      bit = number % 2;
      number = number / 2;
      dst->bits[1] = dst->bits[1] << 1;
      dst->bits[1] = dst->bits[1] | bit;
    }
  }
  s21_from_int_to_decimal(number, dst);
  if (scale2 < 7) {
    scale2 = 6 - scale2;
  } else
    scale2 = 0;
  set_scale(dst, scale2);
}

int count_int(float src) {
  int count = 0;
  while (src >= 1) {
    count++;
    src = src / 10;
  }
  return count;
}

int s21_from_float_to_decimal(float src, s21_decimal* dst) {
  int res = CONV_OK;
  if (isnan(src) || isinf(src) || fabs(src) > MAX_FLOAT) {
    res = CONV_ERR;
  } else if (fabs(src) < 1e-28 || src == 0.0) {
    res = 0;
    dec_zero(dst);
  } else {
    char buf[50] = {0};
    sprintf(buf, "%.28e", src);
    char* integrate = strtok(buf, ".");
    char* fraction = strtok(NULL, "e");
    char* scale = strtok(NULL, "+");
    if (fraction == NULL) fraction = 0;
    if (scale == NULL) scale = 0;
    char* combined_str = 0;
    combined_str = (char*)malloc(strlen(integrate) + strlen(fraction) + 1);
    if (combined_str != NULL) {
      strcpy(combined_str, integrate);
      strcat(combined_str, fraction);
      char significant_number[20] = {0};  //значимое число
      int extreme_number = 0;  // необходимо для округления
      int stop = 0, k = 0, f = 0, c = 0, d = 0;
      if (count_int(src) < 8)
        d = 7;
      else
        d = count_int(src);
      if (src < 0) d = 8;
      for (; f < 28; f++) {
        if (k < d) {
          significant_number[f] = combined_str[f];
          if (combined_str[f] != '0') {
            stop = 1;
          }
          if (stop == 1) k++;
        } else {
          extreme_number += (combined_str[f] - '0') /
                            pow(10, c);  // c  = счетчик регистров во float
          c++;
        }
      }
      long long number = strtol(significant_number, NULL, 10);
      int round = roundf(extreme_number);
      if (round >= 5) {
        if (number >= 0) {
          number += 1;
        } else
          number -= 1;
      }
      int scale2 = strtol(scale, NULL, 10);
      convert_number(number, dst, scale2);
      free(combined_str);
    } else
      res = CONV_ERR;
  }
  return res;
}
