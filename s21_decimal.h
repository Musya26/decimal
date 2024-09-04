#ifndef S21DECIMAL_H
#define S21DECIMAL_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CONV_OK 0
#define CONV_ERR 1

#define MAX_FLOAT 79228162514264337593543950335.F

#define S21_NULL (void *)0

#define FALSE 0
#define TRUE 1

#define MAXBITS 0xffffffff
#define MAXBITSEXT 0xffffffffffffffff
#define MAX_INT 2147483647
#define MIN_INT (-2147483648)

#define MINUS 0x80000000

typedef struct {
  int bits[4];
} s21_decimal;

typedef struct {
  unsigned int bits[7];
} s21_big_decimal;
// arithemic
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
void s21_add_big_dec(s21_big_decimal value1, s21_big_decimal value2,
                     s21_big_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
void s21_sub_big_dec(s21_big_decimal value1, s21_big_decimal value2,
                     s21_big_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
void s21_mul_big_dec(s21_big_decimal value1, s21_big_decimal value2,
                     s21_big_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div_big_dec(s21_big_decimal value_1, s21_big_decimal value_2,
                    s21_big_decimal *result);
// convert
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
void from_decimal_to_bigdecimal(s21_decimal src, s21_big_decimal *dst);
void from_bigdecimal_to_decimal(s21_big_decimal src, s21_decimal *dst);
// oop
int get_bit(s21_decimal src, int bit);
char *get_scale(s21_decimal *src);
void set_scale(s21_decimal *src, int scale);
int check_sign(s21_decimal src);
void set_sign(s21_decimal *src);
void clear_sign(s21_decimal *src);
// oop_big
int big_get_bit(s21_big_decimal src, int bit);
void big_set_bit(s21_big_decimal *result, int i);
void big_clear_bit(s21_big_decimal *src, int bit);
char *big_get_scale(s21_big_decimal *src);
void big_set_scale(s21_big_decimal *src, int scale);
int check_sign_big(s21_big_decimal src);
void big_set_sign(s21_big_decimal *src);
// other_func
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);
// help_func
void inverse(s21_big_decimal *val);
void big_shift_left(s21_big_decimal *value, int shift_value);
int big_normalisation(s21_big_decimal *value1, s21_big_decimal *value2);
void scale_normalise(s21_big_decimal *value, int n);
unsigned int s21_divide_by_10(s21_big_decimal *number);
int s21_post_normalization(s21_big_decimal *result, int scale);
void sub_scale_big(s21_big_decimal *dst, int n);
void dec_zero(s21_decimal *src);
void big_dec_zero(s21_big_decimal *src);
void copy_big_dec(s21_big_decimal value, s21_big_decimal *res);
void shift_left(s21_decimal *value, int shift_value);
void shift_right(s21_decimal *value, int shift_value);
unsigned int s21_divide_by_10_non(s21_decimal *number);
unsigned int s21_divide_by_10_smal(s21_decimal *number);
// comparison
int check_less(s21_decimal value1, s21_decimal value2);
int check_less_big(s21_big_decimal value1, s21_big_decimal value2);
int check_great(s21_decimal value1, s21_decimal value2);
int s21_is_less(s21_decimal value1, s21_decimal value2);
int s21_is_less_big(s21_big_decimal volume1, s21_big_decimal volume2);
int s21_is_equal(s21_decimal value1, s21_decimal value2);
int s21_is_equal_big(s21_big_decimal value1, s21_big_decimal value2);
int s21_is_less_or_equal(s21_decimal value1, s21_decimal value2);
int s21_is_less_or_equal_big(s21_big_decimal value1, s21_big_decimal value2);
int s21_is_greater(s21_decimal value1, s21_decimal value2);
int check_comp_big(s21_big_decimal value1, s21_big_decimal value2);
int comprasion_with_big(s21_decimal value1, s21_decimal value2);
int s21_is_greater_big(s21_big_decimal value1, s21_big_decimal value2);
int check_great_big(s21_big_decimal value1, s21_big_decimal value2);
int mant_not_zero(s21_decimal volume);
int mant_not_zero_big(s21_big_decimal volume);
int s21_is_not_equal(s21_decimal value1, s21_decimal value2);
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);
#endif
