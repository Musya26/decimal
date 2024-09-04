#include "s21_decimal.h"

int check_less_big(s21_big_decimal value1, s21_big_decimal value2) {
  int res = 0;
  int flag = 0;
  int check = 1;
  for (int n = 5; (n > -1) && (flag != 1); n--) {
    if (value1.bits[n] < value2.bits[n]) {
      flag = 1;
      res = 1;
    }
  }
  for (int n = 5; (n >= 0) && (flag == 0); n--) {
    if (value1.bits[n] != value2.bits[n] && check) {
      check = 0;
    }
    if (check == 0) {
      if (value1.bits[n] > value2.bits[n]) {
        res = 1;
        flag = 1;
      } else if (value1.bits[n] < value2.bits[n]) {
        res = -1;
        flag = 1;
      }
    }
  }

  return res;
}

int s21_is_less_big(s21_big_decimal volume1, s21_big_decimal volume2) {
  int sign1 = check_sign_big(volume1);
  int sign2 = check_sign_big(volume2);
  int res = 0;
  big_normalisation(&volume1, &volume2);
  if (sign1 > sign2) {
    res = 1;
  } else if (sign1 < sign2) {
    res = 0;
  }
  if (sign1 == sign2) {
    if (sign1 == 1) {
      res = check_less_big(volume2, volume1);
    }
    if (sign1 == 0) {
      res = check_less_big(volume1, volume2);
    }
  }
  return res;
}

int s21_is_equal_big(s21_big_decimal value1, s21_big_decimal value2) {
  int res = 1;
  int flag = 0;
  big_normalisation(&value1, &value2);

  for (int i = 0; i < 7 && !flag; i++) {
    if (value1.bits[i] != value2.bits[i]) {
      res = 0;
      flag = 1;
    }
  }
  if (!mant_not_zero_big(value1) && !mant_not_zero_big(value2)) {
    res = 1;
  }
  return res;
}

int check_comp_big(s21_big_decimal value1, s21_big_decimal value2) {
  int res = 0;
  int flag = 0;
  int check = 1;
  for (int n = 5; (n >= 0) && (flag == 0); n--) {
    if ((value1.bits[n] != value2.bits[n]) && check) {
      check = 0;
    }
    if (check == 0) {
      if (value1.bits[n] > value2.bits[n]) {
        res = 1;
        flag = 1;
      } else if (value1.bits[n] < value2.bits[n]) {
        res = -1;
        flag = 1;
      }
    }
  }
  return res;
}

int comprasion_with_big(s21_decimal value1, s21_decimal value2) {
  s21_big_decimal val1, val2;
  big_dec_zero(&val1);
  big_dec_zero(&val2);
  from_decimal_to_bigdecimal(value1, &val1);
  from_decimal_to_bigdecimal(value2, &val2);
  big_set_scale(&val1, (int)*get_scale(&value1));
  big_set_scale(&val2, (int)*get_scale(&value2));
  big_normalisation(&val1, &val2);
  int sign1 = check_sign(value1);
  int sign2 = check_sign(value2);
  int res = 0;
  if (sign1 > sign2) {
    res = -1;
  } else if (sign1 < sign2) {
    res = 1;
  } else if (sign1 == sign2) {
    res = check_comp_big(val1, val2);
    if (sign1 == 1 && res != 0) {
      res *= -1;
    }
  }
  if (!mant_not_zero_big(val1) && !mant_not_zero_big(val2)) {
    res = 0;
  }
  return res;
}

int s21_is_greater_big(s21_big_decimal value1, s21_big_decimal value2) {
  int sign1 = check_sign_big(value1);
  int sign2 = check_sign_big(value2);
  big_normalisation(&value1, &value2);
  int res = 0;
  if (!mant_not_zero_big(value1) && !mant_not_zero_big(value2)) {
    res = 0;
  } else if (sign1 > sign2) {
    res = 0;
  } else if (sign1 < sign2) {
    res = 1;
  }
  if (sign1 == sign2) {
    res = check_great_big(value1, value2);
    if (sign1 == 1 && res != 0) {
      res *= -1;
    }
  }

  return res;
}
int check_great_big(s21_big_decimal value1, s21_big_decimal value2) {
  int res = 0;
  int flag = 0;
  int check = 0;
  for (int n = 5; (n >= 0) && (flag == 0); n--) {
    if (value1.bits[n] != value2.bits[n] && check) {
      check = 0;
    }
    if (check == 0) {
      if (value1.bits[n] > value2.bits[n]) {
        res = 1;
        flag = 1;
      } else if (value1.bits[n] < value2.bits[n]) {
        res = 0;
        flag = 1;
      }
    }
  }
  return res;
}

int mant_not_zero_big(s21_big_decimal volume) {
  int res = 0;
  for (int n = 5; n > -1; n--) {
    if (volume.bits[n] != 0) {
      res = 1;
    }
  }
  return res;
}

int s21_is_greater_or_equal_big(s21_big_decimal value_1,
                                s21_big_decimal value_2) {
  int res = 0;
  if (s21_is_equal_big(value_1, value_2) ||
      s21_is_greater_big(value_1, value_2))
    res = 1;
  return res;
}
