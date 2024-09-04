#include "s21_decimal.h"

// 0 означает положительный, а 1 означает отрицательный.

// 0 - OK
// 1 - число слишком велико или равно бесконечности
// 2 - число слишком мало или равно отрицательной бесконечности
// 3 - деление на 0

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int code = 0;
  dec_zero(result);
  int sign_1 = check_sign(value_1);
  int sign_2 = check_sign(value_2);
  int scale1 = *get_scale(&value_1), scale2 = *get_scale(&value_2);

  s21_big_decimal v1 = {0}, v2 = {0}, res = {0};
  s21_decimal zero = {0};
  big_dec_zero(&v1);
  big_dec_zero(&v2);
  big_dec_zero(&res);
  dec_zero(&zero);
  from_decimal_to_bigdecimal(value_1, &v1);
  from_decimal_to_bigdecimal(value_2, &v2);

  big_set_scale(&v1, scale1);
  big_set_scale(&v2, scale2);

  if (scale1 != scale2) {
    big_normalisation(&v1, &v2);
  }

  if (sign_1 == sign_2) {
    s21_add_big_dec(v1, v2, &res);
    if (sign_1) set_sign(result);
  } else {
    if (s21_is_equal_big(v1, v2)) {
      s21_sub_big_dec(v2, v1, &res);
    } else if (s21_is_greater_big(v1, v2)) {
      s21_sub_big_dec(v1, v2, &res);
      if (sign_1) set_sign(result);
    } else {
      s21_sub_big_dec(v2, v1, &res);
      if (sign_2) set_sign(result);
    }
  }

  char *ddd = big_get_scale(&v1);
  int s = (int)*ddd;

  int scale = s21_post_normalization(&res, s);

  if (scale >= 0) {
    from_bigdecimal_to_decimal(res, result);
    set_scale(result, scale);

  } else {
    code = 1;
  }

  if (code == 1 && check_sign(*result)) code = 2;
  if (code || (code == 0 && (s21_is_equal(*result, zero)))) dec_zero(result);

  return code;
}

void s21_add_big_dec(s21_big_decimal value1, s21_big_decimal value2,
                     s21_big_decimal *result) {
  big_dec_zero(result);
  unsigned memo = 0;
  for (int i = 0; i < 32 * 6; i++) {
    unsigned result_bit =
        big_get_bit(value1, i) + big_get_bit(value2, i) + memo;
    memo = result_bit / 2;
    result_bit %= 2;
    if (result_bit == 1) {
      big_set_bit(result, i);
    }
  }
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_negate(value_2, &value_2);
  return s21_add(value_1, value_2, result);
}

void s21_sub_big_dec(s21_big_decimal value1, s21_big_decimal value2,
                     s21_big_decimal *result) {
  inverse(&value1);
  s21_add_big_dec(value1, value2, result);
  inverse(result);
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int code = 0;
  dec_zero(result);
  int sign1 = check_sign(value_1);
  int sign2 = check_sign(value_2);
  char *scale1 = get_scale(&value_1);
  char *scale2 = get_scale(&value_2);
  int res_scale = (int)*scale1 + (int)*scale2;
  s21_decimal zero = {0};
  dec_zero(&zero);

  if (!s21_is_equal(value_1, zero) && !s21_is_equal(value_2, zero)) {
    s21_big_decimal v1 = {0}, v2 = {0}, res = {0};
    big_dec_zero(&v1);
    big_dec_zero(&v2);
    big_dec_zero(&res);

    from_decimal_to_bigdecimal(value_1, &v1);
    from_decimal_to_bigdecimal(value_2, &v2);
    if (s21_is_greater_big(v1, v2)) {
      s21_mul_big_dec(v1, v2, &res);
    } else {
      s21_mul_big_dec(v2, v1, &res);
    }
    int scale = s21_post_normalization(&res, res_scale);
    if (scale >= 0) {
      from_bigdecimal_to_decimal(res, result);
      set_scale(result, scale);
    } else {
      code = 1;
    }
    int res_sign = 1;
    if (sign1 == sign2) res_sign = 0;
    if (res_sign) set_sign(result);
    if (code == 1 && check_sign(*result)) code = 2;
    if (code) dec_zero(result);
  }

  return code;
}

void s21_mul_big_dec(s21_big_decimal value1, s21_big_decimal value2,
                     s21_big_decimal *result) {
  int check = 1;  // пропуск начальных нулей
  big_dec_zero(result);
  for (int i = 32 * 6 - 1; i >= 0; i--) {
    if (big_get_bit(value2, i) != 0 && check) {
      check = 0;
    }
    if (check == 0) {
      if (big_get_bit(value2, i) == 1) {
        s21_add_big_dec(value1, *result, result);
      }
      if (i != 0) big_shift_left(result, 1);
    }
  }
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int code = 0;
  dec_zero(result);
  int sign1 = check_sign(value_1);
  int sign2 = check_sign(value_2);
  char *scale1 = get_scale(&value_1);
  char *scale2 = get_scale(&value_2);
  s21_decimal zero = {0};
  dec_zero(&zero);
  if (!s21_is_equal(value_2, zero)) {
    s21_big_decimal v1 = {0}, v2 = {0}, res = {0};
    big_dec_zero(&v1);
    big_dec_zero(&v2);
    big_dec_zero(&res);
    from_decimal_to_bigdecimal(value_1, &v1);
    from_decimal_to_bigdecimal(value_2, &v2);
    if ((int)*scale1 != (int)*scale2) {
      big_normalisation(&v1, &v2);
    }
    s21_div_big_dec(v1, v2, &res);

    char *ddd = big_get_scale(&v1);
    int s = (int)*ddd;
    int scale = s21_post_normalization(&res, s);
    if (scale >= 0) {
      from_bigdecimal_to_decimal(res, result);
      set_scale(result, scale);
    } else {
      code = 1;
    }
    int res_sign = 1;
    if (sign1 == sign2) res_sign = 0;
    if (res_sign) set_sign(result);
    if (code == 1 && check_sign(*result)) code = 2;
    if (code) dec_zero(result);
  } else {
    code = 3;
  }
  return code;
}

int s21_div_big_dec(s21_big_decimal value_1, s21_big_decimal value_2,
                    s21_big_decimal *result) {
  s21_big_decimal buf, mod = {{0, 0, 0, 0, 0, 0, 0}}, nul = {0};
  big_dec_zero(&buf);
  big_dec_zero(result);
  int check = 0, is_less = 0, first_number = 0;
  for (int i = 192; i >= -1; i--) {
    if (check == 1) {
      is_less = s21_is_less_big(buf, value_2);
      if (is_less == 0) {  ///если буф не меньше делителя
        first_number = 1;
        big_shift_left(result, 1);
        big_set_bit(result, 0);  // result =1;
        s21_sub_big_dec(buf, value_2, &mod);
        buf = mod;
        big_shift_left(&buf, 1);
        if (big_get_bit(value_1, i) == 1) big_set_bit(&buf, 0);
      } else {  //важно чтобы начало выполняться после первого!!!!!!!!!!!
        if (first_number == 1) big_shift_left(result, 1);
        big_shift_left(&buf, 1);
        if (big_get_bit(value_1, i) == 1) big_set_bit(&buf, 0);
      }
    }
    if (big_get_bit(value_1, i) == 1 &&
        check == 0) {  //берет первый символ ненулевой
      big_set_bit(&buf, 0);
      check = 1;  //значит что первый символ найден
      is_less = s21_is_less_big(buf, value_2);
    }
  }
  big_dec_zero(&nul);
  int is_equal = s21_is_equal_big(buf, nul);
  if (is_less == 1 && is_equal) {
    int count = 0, scale = 0;
    while (!is_equal && count < 7) {
      if (is_less) {
        big_shift_left(&buf, 1);  //добавляем символ в буфер
        big_shift_left(result, 1);  //добавляем ноль в результатß
        scale = (int)*big_get_scale(result) + 1;
        big_set_scale(result, scale);  //увеличиваем scale на один
        count++;
      } else {
        s21_sub_big_dec(buf, value_2, &mod);  // tut oshibki net
        buf = mod;
        big_set_bit(result, 0);
        is_equal = s21_is_equal_big(buf, nul);
      }
      is_less = s21_is_less_big(buf, value_2);
    }
  }
  return 0;
}
