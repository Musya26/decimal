#include <check.h>
#include <stdlib.h>

#include "../s21_decimal.h"

START_TEST(test_21_comparison_s21_is_equal_1) {
  s21_decimal src1, src2;
  int value_res;
  // 7 = 15 FALSE
  src1.bits[0] = 7;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0;
  src2.bits[0] = 15;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_res = s21_is_equal(src1, src2);
  ck_assert_int_eq(value_res, FALSE);
}
END_TEST

START_TEST(test_21_comparison_s21_is_equal_2) {
  s21_decimal src1, src2;
  int value_res;
  // 7 = 1.5 FALSE
  src1.bits[0] = 7;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0;
  src2.bits[0] = 15;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b00000000000000100000000000000000;
  value_res = s21_is_equal(src1, src2);
  ck_assert_int_eq(value_res, FALSE);
}
END_TEST

START_TEST(test_21_comparison_s21_is_equal_3) {
  s21_decimal src1, src2;
  int value_res;
  // 65.5 = 655 FALSE
  src1.bits[0] = 655;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b00000000000000100000000000000000;
  src2.bits[0] = 655;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0;
  value_res = s21_is_equal(src1, src2);
  ck_assert_int_eq(value_res, FALSE);
}
END_TEST

START_TEST(test_21_comparison_s21_is_equal_4) {
  s21_decimal src1, src2;
  int value_res;
  // 655 = 655 TRUE
  src1.bits[0] = 65;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0;
  src2.bits[0] = 65;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0;
  value_res = s21_is_equal(src1, src2);
  ck_assert_int_eq(value_res, TRUE);
}
END_TEST

START_TEST(test_21_comparison_s21_is_equal_5) {
  s21_decimal src1, src2;
  int value_res;
  // ==
  src1.bits[0] = 0;
  src1.bits[1] = 100;
  src1.bits[2] = 45;
  src1.bits[3] = 0;
  src2.bits[0] = 0;
  src2.bits[1] = 100;
  src2.bits[2] = 45;
  src2.bits[3] = 0;
  value_res = s21_is_equal(src1, src2);
  ck_assert_int_eq(value_res, TRUE);
}
END_TEST

START_TEST(test_21_comparison_s21_is_equal_6) {
  s21_decimal src1, src2;
  int value_res;
  //==
  src1.bits[0] = MAXBITS;
  src1.bits[1] = MAXBITS;
  src1.bits[2] = MAXBITS;
  src1.bits[3] = 0;
  src2.bits[0] = MAXBITS;
  src2.bits[1] = MAXBITS;
  src2.bits[2] = MAXBITS;
  src2.bits[3] = 0;
  value_res = s21_is_equal(src1, src2);
  ck_assert_int_eq(value_res, TRUE);
}
END_TEST

START_TEST(test_21_comparison_s21_is_equal_7) {
  s21_decimal src1, src2;
  int value_res;
  // -52 = -52 TRUE
  src1.bits[0] = 52;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 52;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000000000000000000000;
  value_res = s21_is_equal(src1, src2);
  ck_assert_int_eq(value_res, TRUE);
}
END_TEST

START_TEST(test_21_comparison_s21_is_equal_8) {
  s21_decimal src1, src2;
  int value_res;
  // 52 = -52 F
  src1.bits[0] = 52;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 52;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000000000000000000000;
  value_res = s21_is_equal(src1, src2);
  ck_assert_int_eq(value_res, FALSE);
}
END_TEST

START_TEST(test_21_comparison_s21_is_equal_9) {
  s21_decimal src1, src2;
  int value_res;
  // -52 = 52 F
  src1.bits[0] = 52;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 52;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0;
  value_res = s21_is_equal(src1, src2);
  ck_assert_int_eq(value_res, FALSE);
}
END_TEST

START_TEST(test_21_comparison_s21_is_equal_10) {
  s21_decimal src1, src2;
  int value_res;
  // -132 = -52 F
  src1.bits[0] = 132;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 52;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000000000000000000000;
  value_res = s21_is_equal(src1, src2);
  ck_assert_int_eq(value_res, FALSE);
}
END_TEST

START_TEST(test_21_comparison_s21_is_equal_11) {
  s21_decimal src1, src2;
  int value_res;
  // -132 = 52 F
  src1.bits[0] = 132;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 52;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_res = s21_is_equal(src1, src2);
  ck_assert_int_eq(value_res, FALSE);
}
END_TEST

START_TEST(test_21_comparison_s21_is_equal_12) {
  s21_decimal src1, src2;
  int value_res;
  // 132 = -52 F
  src1.bits[0] = 132;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 52;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000000000000000000000;
  value_res = s21_is_equal(src1, src2);
  ck_assert_int_eq(value_res, FALSE);
}
END_TEST

START_TEST(test_21_comparison_s21_is_equal_13) {
  s21_decimal src1, src2;
  int value_res;
  // -13 = -52 F
  src1.bits[0] = 13;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 52;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000000000000000000000;
  value_res = s21_is_equal(src1, src2);
  ck_assert_int_eq(value_res, FALSE);
}
END_TEST

START_TEST(test_21_comparison_s21_is_equal_14) {
  s21_decimal src1, src2;
  int value_res;
  // 13 = -52 F
  src1.bits[0] = 13;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 52;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000000000000000000000;
  value_res = s21_is_equal(src1, src2);
  ck_assert_int_eq(value_res, FALSE);
}
END_TEST

START_TEST(test_21_comparison_s21_is_equal_15) {
  s21_decimal src1, src2;
  int value_res;
  // -13 = 52 F
  src1.bits[0] = 13;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 52;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_res = s21_is_equal(src1, src2);
  ck_assert_int_eq(value_res, FALSE);
}
END_TEST

START_TEST(test_21_comparison_s21_is_not_equal_1) {
  s21_decimal src1, src2;
  int value_res;
  // 7 != 15 TRUE
  src1.bits[0] = 7;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0;
  src2.bits[0] = 15;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_res = s21_is_not_equal(src1, src2);
  ck_assert_int_eq(value_res, TRUE);
}
END_TEST

START_TEST(test_21_comparison_s21_is_not_equal_2) {
  s21_decimal src1, src2;
  int value_res;
  // 7 != 1.5 T
  src1.bits[0] = 7;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0;
  src2.bits[0] = 15;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b00000000000000100000000000000000;
  value_res = s21_is_not_equal(src1, src2);
  ck_assert_int_eq(value_res, TRUE);
}
END_TEST

START_TEST(test_21_comparison_s21_is_not_equal_3) {
  s21_decimal src1, src2;
  int value_res;
  // 65.5 != 655 T
  src1.bits[0] = 655;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b00000000000000100000000000000000;
  src2.bits[0] = 655;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0;
  value_res = s21_is_not_equal(src1, src2);
  ck_assert_int_eq(value_res, TRUE);
}
END_TEST

START_TEST(test_21_comparison_s21_is_not_equal_4) {
  s21_decimal src1, src2;
  int value_res;
  // 655 != 655 F
  src1.bits[0] = 65;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0;
  src2.bits[0] = 65;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0;
  value_res = s21_is_not_equal(src1, src2);
  ck_assert_int_eq(value_res, FALSE);
}
END_TEST

START_TEST(test_21_comparison_s21_is_not_equal_5) {
  s21_decimal src1, src2;
  int value_res;
  // ==
  src1.bits[0] = 0;
  src1.bits[1] = 100;
  src1.bits[2] = 45;
  src1.bits[3] = 0;
  src2.bits[0] = 0;
  src2.bits[1] = 100;
  src2.bits[2] = 45;
  src2.bits[3] = 0;
  value_res = s21_is_not_equal(src1, src2);
  ck_assert_int_eq(value_res, FALSE);
}
END_TEST

START_TEST(test_21_comparison_s21_is_not_equal_6) {
  s21_decimal src1, src2;
  int value_res;
  //==
  src1.bits[0] = MAXBITS;
  src1.bits[1] = MAXBITS;
  src1.bits[2] = MAXBITS;
  src1.bits[3] = 0;
  src2.bits[0] = MAXBITS;
  src2.bits[1] = MAXBITS;
  src2.bits[2] = MAXBITS;
  src2.bits[3] = 0;
  value_res = s21_is_not_equal(src1, src2);
  ck_assert_int_eq(value_res, FALSE);
}
END_TEST

START_TEST(test_21_comparison_s21_is_not_equal_7) {
  s21_decimal src1, src2;
  int value_res;
  // -52 != -52 F
  src1.bits[0] = 52;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 52;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000000000000000000000;
  value_res = s21_is_not_equal(src1, src2);
  ck_assert_int_eq(value_res, FALSE);
}
END_TEST

START_TEST(test_21_comparison_s21_is_not_equal_8) {
  s21_decimal src1, src2;
  int value_res;
  // 52 != -52 T
  src1.bits[0] = 52;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 52;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000000000000000000000;
  value_res = s21_is_not_equal(src1, src2);
  ck_assert_int_eq(value_res, TRUE);
}
END_TEST

START_TEST(test_21_comparison_s21_is_not_equal_9) {
  s21_decimal src1, src2;
  int value_res;
  // -52 != 52 T
  src1.bits[0] = 52;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 52;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0;
  value_res = s21_is_not_equal(src1, src2);
  ck_assert_int_eq(value_res, TRUE);
}
END_TEST

START_TEST(test_21_comparison_s21_is_not_equal_10) {
  s21_decimal src1, src2;
  int value_res;
  // -132 != -52 T
  src1.bits[0] = 132;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 52;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000000000000000000000;
  value_res = s21_is_not_equal(src1, src2);
  ck_assert_int_eq(value_res, TRUE);
}
END_TEST

START_TEST(test_21_comparison_s21_is_not_equal_11) {
  s21_decimal src1, src2;
  int value_res;
  // -132 != 52 T
  src1.bits[0] = 132;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 52;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_res = s21_is_not_equal(src1, src2);
  ck_assert_int_eq(value_res, TRUE);
}
END_TEST

START_TEST(test_21_comparison_s21_is_not_equal_12) {
  s21_decimal src1, src2;
  int value_res;
  // 132 != -52 T
  src1.bits[0] = 132;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 52;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000000000000000000000;
  value_res = s21_is_not_equal(src1, src2);
  ck_assert_int_eq(value_res, TRUE);
}
END_TEST

START_TEST(test_21_comparison_s21_is_not_equal_13) {
  s21_decimal src1, src2;
  int value_res;
  // -13 != -52 T
  src1.bits[0] = 13;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 52;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000000000000000000000;
  value_res = s21_is_not_equal(src1, src2);
  ck_assert_int_eq(value_res, TRUE);
}
END_TEST

START_TEST(test_21_comparison_s21_is_not_equal_14) {
  s21_decimal src1, src2;
  int value_res;
  // 13 != -52 T
  src1.bits[0] = 13;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 52;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000000000000000000000;
  value_res = s21_is_not_equal(src1, src2);
  ck_assert_int_eq(value_res, TRUE);
}
END_TEST

START_TEST(test_21_comparison_s21_is_not_equal_15) {
  s21_decimal src1, src2;
  int value_res;
  // -13 != 52 T
  src1.bits[0] = 13;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 52;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_res = s21_is_not_equal(src1, src2);
  ck_assert_int_eq(value_res, TRUE);
}
END_TEST

START_TEST(test_s21_is_less_1) {
  s21_decimal src1, src2;
  int val;
  // 7 < 15 TRUE
  src1.bits[0] = 7;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0;
  src2.bits[0] = 15;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0;
  val = s21_is_less(src1, src2);
  ck_assert_int_eq(val, TRUE);
}
END_TEST

START_TEST(test_s21_is_less_2) {
  s21_decimal src1, src2;
  int val;
  // 15 < 7 FALSE
  src1.bits[0] = 15;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0;
  src2.bits[0] = 7;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0;
  val = s21_is_less(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_less_3) {
  s21_decimal src1, src2;
  int val;
  //-15 < 7 TRUE
  src1.bits[0] = 15;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = MINUS;
  src2.bits[0] = 7;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0;
  val = s21_is_less(src1, src2);
  ck_assert_int_eq(val, TRUE);
}
END_TEST

START_TEST(test_s21_is_less_4) {
  s21_decimal src1, src2;
  int val;
  //-15 < 15 TRUE
  src1.bits[0] = 15;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = MINUS;
  src2.bits[0] = 15;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0;
  val = s21_is_less(src1, src2);
  ck_assert_int_eq(val, TRUE);
}
END_TEST

START_TEST(test_s21_is_less_5) {
  s21_decimal src1, src2;
  int val;
  //-15 < -5 TRUE
  src1.bits[0] = 15;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = MINUS;
  src2.bits[0] = 5;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = MINUS;
  val = s21_is_less(src1, src2);
  ck_assert_int_eq(val, TRUE);
}
END_TEST

START_TEST(test_s21_is_less_6) {
  s21_decimal src1, src2;
  int val;
  //-7 < +1.5 TRUE
  src1.bits[0] = 7;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 15;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b00000000000000100000000000000000;
  val = s21_is_less(src1, src2);
  ck_assert_int_eq(val, TRUE);
}
END_TEST

START_TEST(test_s21_is_less_7) {
  s21_decimal src1, src2;
  int val;
  // 7 < -1.5 FALSE
  src1.bits[0] = 7;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 15;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000100000000000000000;
  val = s21_is_less(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_less_8) {
  s21_decimal src1, src2;
  int val;
  //-0.7 < -1.5 FALSE
  src1.bits[0] = 7;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b10000000000000010000000000000000;
  src2.bits[0] = 15;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000010000000000000000;
  val = s21_is_less(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_less_9) {
  s21_decimal src1, src2;
  int val;
  //== FALSE
  src1.bits[0] = MAXBITS;
  src1.bits[1] = MAXBITS;
  src1.bits[2] = MAXBITS;
  src1.bits[3] = 0;
  src2.bits[0] = MAXBITS;
  src2.bits[1] = MAXBITS;
  src2.bits[2] = MAXBITS;
  src2.bits[3] = 0;
  val = s21_is_less(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_less_10) {
  s21_decimal src1, src2;
  int val;
  //-5 < 5 TRUE
  src1.bits[0] = 5;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 5;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0;
  val = s21_is_less(src1, src2);
  ck_assert_int_eq(val, TRUE);
}
END_TEST

START_TEST(test_s21_is_less_11) {
  s21_decimal src1, src2;
  int val;
  // 6 < 6 FALSE
  src1.bits[0] = 6;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0;
  src2.bits[0] = 6;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0;
  val = s21_is_less(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_less_12) {
  s21_decimal src1, src2;
  int val;
  // 6 < 0.6 FALSE
  src1.bits[0] = 6;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0;
  src2.bits[0] = 6;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000100000000000000000;
  val = s21_is_less(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_less_13) {
  s21_decimal src1, src2;
  int val;
  //-4 < -5 FALSE
  src1.bits[0] = 4;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 5;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000000000000000000000;
  val = s21_is_less(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_less_14) {
  s21_decimal src1, src2;
  int val;
  // 4 < -5 FALSE
  src1.bits[0] = 4;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 5;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000000000000000000000;
  val = s21_is_less(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_less_15) {
  s21_decimal src1, src2;
  int val;
  // 4 < -5 FALSE
  src1.bits[0] = 4;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 5;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000000000000000000000;
  val = s21_is_less(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_less_16) {
  s21_decimal src1, src2;
  int val;
  //-4 < +5 FALSE
  src1.bits[0] = 4;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 5;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b00000000000000000000000000000000;
  val = s21_is_less(src1, src2);
  ck_assert_int_eq(val, TRUE);
}
END_TEST

START_TEST(test_s21_is_less_17) {
  s21_decimal src1, src2;
  int val;
  //-23 < -23 FALSE
  src1.bits[0] = 23;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 23;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000000000000000000000;
  val = s21_is_less(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_less_18) {
  s21_decimal src1, src2;
  int val;
  // 23 < -23 FALSE
  src1.bits[0] = 23;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 23;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000000000000000000000;
  val = s21_is_less(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_less_19) {
  s21_decimal src1, src2;
  int val;
  //-4 < +5 FALSE
  src1.bits[0] = 4;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 5;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b00000000000000000000000000000000;
  val = s21_is_less(src1, src2);
  ck_assert_int_eq(val, TRUE);
}
END_TEST

START_TEST(test_s21_is_less_20) {
  s21_decimal src1, src2;
  int val;
  //-23 < -23 FALSE
  src1.bits[0] = 23;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 23;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000000000000000000000;
  val = s21_is_less(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_less_21) {
  s21_decimal src1, src2;
  int val;
  // 23 < -23 FALSE
  src1.bits[0] = 23;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 23;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000000000000000000000;
  val = s21_is_less(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_less_or_equal_1) {
  s21_decimal src1, src2;
  int val;
  // 7 <= 15 TRUE
  src1.bits[0] = 7;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0;
  src2.bits[0] = 15;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0;
  val = s21_is_less_or_equal(src1, src2);
  ck_assert_int_eq(val, TRUE);
}
END_TEST

START_TEST(test_s21_is_less_or_equal_2) {
  s21_decimal src1, src2;
  int val;
  // 15 <= 7 FALSE
  src1.bits[0] = 15;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0;
  src2.bits[0] = 7;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0;
  val = s21_is_less_or_equal(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_less_or_equal_3) {
  s21_decimal src1, src2;
  int val;
  //-15 <= 7 TRUE
  src1.bits[0] = 15;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = MINUS;
  src2.bits[0] = 7;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0;
  val = s21_is_less_or_equal(src1, src2);
  ck_assert_int_eq(val, TRUE);
}
END_TEST

START_TEST(test_s21_is_less_or_equal_4) {
  s21_decimal src1, src2;
  int val;
  //-15 <= -5 TRUE
  src1.bits[0] = 15;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = MINUS;
  src2.bits[0] = 5;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = MINUS;
  val = s21_is_less_or_equal(src1, src2);
  ck_assert_int_eq(val, TRUE);
}
END_TEST

START_TEST(test_s21_is_less_or_equal_5) {
  s21_decimal src1, src2;
  int val;
  //-7 <= +1.5 TRUE
  src1.bits[0] = 7;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 15;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b00000000000000100000000000000000;
  val = s21_is_less_or_equal(src1, src2);
  ck_assert_int_eq(val, TRUE);
}
END_TEST

START_TEST(test_s21_is_less_or_equal_6) {
  s21_decimal src1, src2;
  int val;
  // 6 <= 6 TRUE
  src1.bits[0] = 6;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0;
  src2.bits[0] = 6;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0;
  val = s21_is_less_or_equal(src1, src2);
  ck_assert_int_eq(val, TRUE);
}
END_TEST

START_TEST(test_s21_is_less_or_equal_7) {
  s21_decimal src1, src2;
  int val;
  // 6 <= 0.6 FALSE
  src1.bits[0] = 6;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0;
  src2.bits[0] = 6;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000100000000000000000;
  val = s21_is_less_or_equal(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_less_or_equal_8) {
  s21_decimal src1, src2;
  int val;
  //-4 <= -5 FALSE
  src1.bits[0] = 4;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 5;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000000000000000000000;
  val = s21_is_less_or_equal(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_less_or_equal_9) {
  s21_decimal src1, src2;
  int val;
  //-15 <= 15 TRUE
  src1.bits[0] = 15;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = MINUS;
  src2.bits[0] = 15;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0;
  val = s21_is_less_or_equal(src1, src2);
  ck_assert_int_eq(val, TRUE);
}
END_TEST

START_TEST(test_s21_is_less_or_equal_10) {
  s21_decimal src1, src2;
  int val;
  //-0.7 <= -1.5 FALSE
  src1.bits[0] = 7;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b10000000000000010000000000000000;
  src2.bits[0] = 15;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000010000000000000000;
  val = s21_is_less_or_equal(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_less_or_equal_11) {
  s21_decimal src1, src2;
  int val;
  // -0.7 <= -0.15 TRUE
  src1.bits[0] = 7;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 1 << 31 | 1 << 16;
  src2.bits[0] = 15;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 1 << 31 | 2 << 16;
  val = s21_is_less_or_equal(src1, src2);
  ck_assert_int_eq(val, TRUE);
}
END_TEST

START_TEST(test_s21_is_less_or_equal_12) {
  s21_decimal src1, src2;
  int val;
  //== TRUE
  src1.bits[0] = MAXBITS;
  src1.bits[1] = MAXBITS;
  src1.bits[2] = MAXBITS;
  src1.bits[3] = 0;
  src2.bits[0] = MAXBITS;
  src2.bits[1] = MAXBITS;
  src2.bits[2] = MAXBITS;
  src2.bits[3] = 0;
  val = s21_is_less_or_equal(src1, src2);
  ck_assert_int_eq(val, TRUE);
}
END_TEST

START_TEST(test_s21_is_less_or_equal_13) {
  s21_decimal src1, src2;
  int val;
  //-5 <= 5 TRUE
  src1.bits[0] = 5;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 5;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0;
  val = s21_is_less_or_equal(src1, src2);
  ck_assert_int_eq(val, TRUE);
}
END_TEST

START_TEST(test_s21_is_less_or_equal_14) {
  s21_decimal src1, src2;
  int val;
  // 4 <= -5 FALSE
  src1.bits[0] = 4;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 5;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000000000000000000000;
  val = s21_is_less_or_equal(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_less_or_equal_15) {
  s21_decimal src1, src2;
  int val;
  //-4 <= +5 FALSE
  src1.bits[0] = 4;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 5;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b00000000000000000000000000000000;
  val = s21_is_less_or_equal(src1, src2);
  ck_assert_int_eq(val, TRUE);
}
END_TEST

START_TEST(test_s21_is_less_or_equal_16) {
  s21_decimal src1, src2;
  int val;
  //-23 <= -23 T
  src1.bits[0] = 23;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 23;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000000000000000000000;
  val = s21_is_less_or_equal(src1, src2);
  ck_assert_int_eq(val, TRUE);
}
END_TEST

START_TEST(test_s21_is_less_or_equal_17) {
  s21_decimal src1, src2;
  int val;
  // 23 <= -23 FALSE
  src1.bits[0] = 23;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 23;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000000000000000000000;
  val = s21_is_less_or_equal(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_less_or_equal_18) {
  s21_decimal src1, src2;
  int val;
  // 23 <= -12 FALSE
  src1.bits[0] = 23;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 12;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000000000000000000000;
  val = s21_is_less_or_equal(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_less_or_equal_19) {
  s21_decimal src1, src2;
  int val;
  // 4 <= -5 FALSE
  src1.bits[0] = 4;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 5;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000000000000000000000;
  val = s21_is_less_or_equal(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_less_or_equal_20) {
  s21_decimal src1, src2;
  int val;
  //-4 <= +5 FALSE
  src1.bits[0] = 4;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 5;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b00000000000000000000000000000000;
  val = s21_is_less_or_equal(src1, src2);
  ck_assert_int_eq(val, TRUE);
}
END_TEST

START_TEST(test_s21_is_less_or_equal_21) {
  s21_decimal src1, src2;
  int val;
  //-23 <= -23 T
  src1.bits[0] = 23;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 23;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000000000000000000000;
  val = s21_is_less_or_equal(src1, src2);
  ck_assert_int_eq(val, TRUE);
}
END_TEST

START_TEST(test_s21_is_less_or_equal_22) {
  s21_decimal src1, src2;
  int val;
  // 23 <= -23 FALSE
  src1.bits[0] = 23;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 23;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000000000000000000000;
  val = s21_is_less_or_equal(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_less_or_equal_23) {
  s21_decimal src1, src2;
  int val;
  // 23 <= -12 FALSE
  src1.bits[0] = 23;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 12;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000000000000000000000;
  val = s21_is_less_or_equal(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_greater_1) {
  s21_decimal src1, src2;
  int val;

  // 7 > 15 FALSE
  src1.bits[0] = 7;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0;
  src2.bits[0] = 15;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0;
  val = s21_is_greater(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_greater_2) {
  s21_decimal src1, src2;
  int val;
  // 15 > 7 TRUE
  src1.bits[0] = 15;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0;
  src2.bits[0] = 7;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0;
  val = s21_is_greater(src1, src2);
  ck_assert_int_eq(val, TRUE);
}
END_TEST

START_TEST(test_s21_is_greater_3) {
  s21_decimal src1, src2;
  int val;
  // -15 > 7 FALSE
  src1.bits[0] = 15;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = MINUS;
  src2.bits[0] = 7;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0;
  val = s21_is_greater(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_greater_4) {
  s21_decimal src1, src2;
  int val;
  //-15 > 15 FALSE
  src1.bits[0] = 15;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = MINUS;
  src2.bits[0] = 15;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0;
  val = s21_is_greater(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_greater_5) {
  s21_decimal src1, src2;
  int val;
  //-15 > -5 FALSE
  src1.bits[0] = 15;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = MINUS;
  src2.bits[0] = 5;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = MINUS;
  val = s21_is_greater(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_greater_6) {
  s21_decimal src1, src2;
  int val;
  //-0.7 > -1.5 TRUE
  src1.bits[0] = 7;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b10000000000000100000000000000000;
  src2.bits[0] = 15;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000100000000000000000;
  val = s21_is_greater(src1, src2);
  ck_assert_int_eq(val, TRUE);
}
END_TEST

START_TEST(test_s21_is_greater_7) {
  s21_decimal src1, src2;
  int val;
  //-7 > +1.5 FALSE
  src1.bits[0] = 7;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 15;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b00000000000000100000000000000000;
  val = s21_is_greater(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_greater_8) {
  s21_decimal src1, src2;
  int val;
  // 0.7 > 1.5 FALSE
  src1.bits[0] = 7;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b10000000000000010000000000000000;
  src2.bits[0] = 15;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000100000000000000000;
  val = s21_is_greater(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_greater_9) {
  s21_decimal src1, src2;
  int val;
  // 6 > 6 FALSE
  src1.bits[0] = 6;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0;
  src2.bits[0] = 6;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0;
  val = s21_is_greater(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_greater_10) {
  s21_decimal src1, src2;
  int val;
  // 6 > 0.6 TRUE
  src1.bits[0] = 6;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0;
  src2.bits[0] = 6;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000100000000000000000;
  val = s21_is_greater(src1, src2);
  ck_assert_int_eq(val, TRUE);
}
END_TEST

START_TEST(test_s21_is_greater_11) {
  s21_decimal src1, src2;
  int val;
  //-4 > -5 TRUE
  src1.bits[0] = 4;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 5;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000000000000000000000;
  val = s21_is_greater(src1, src2);
  ck_assert_int_eq(val, TRUE);
}
END_TEST

START_TEST(test_s21_is_greater_12) {
  s21_decimal src1, src2;
  int val;
  //== FALSE
  src1.bits[0] = MAXBITS;
  src1.bits[1] = MAXBITS;
  src1.bits[2] = MAXBITS;
  src1.bits[3] = 0;
  src2.bits[0] = MAXBITS;
  src2.bits[1] = MAXBITS;
  src2.bits[2] = MAXBITS;
  src2.bits[3] = 0;
  val = s21_is_greater(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_greater_13) {
  s21_decimal src1, src2;
  int val;
  // 4 > -5 T
  src1.bits[0] = 4;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 5;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000000000000000000000;
  val = s21_is_greater(src1, src2);
  ck_assert_int_eq(val, TRUE);
}
END_TEST

START_TEST(test_s21_is_greater_14) {
  s21_decimal src1, src2;
  int val;
  //-4 > +5 FALSE
  src1.bits[0] = 4;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 5;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b00000000000000000000000000000000;
  val = s21_is_greater(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_greater_15) {
  s21_decimal src1, src2;
  int val;
  //-23 > -23 F
  src1.bits[0] = 23;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 23;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000000000000000000000;
  val = s21_is_greater(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_greater_16) {
  s21_decimal src1, src2;
  int val;
  // 23 > -23 T
  src1.bits[0] = 23;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 23;
  src2.bits[1] = 0;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000000000000000000000;
  val = s21_is_greater(src1, src2);
  ck_assert_int_eq(val, TRUE);
}
END_TEST

START_TEST(test_s21_is_greater_17) {
  s21_decimal src1, src2;
  int val;
  // 23 > -12 T
  src1.bits[0] = 23;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 12;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000000000000000000000;
  val = s21_is_greater(src1, src2);
  ck_assert_int_eq(val, TRUE);
}
END_TEST

START_TEST(test_s21_is_greater_18) {
  s21_decimal src1, src2;
  int val;
  //== FALSE
  src1.bits[0] = MAXBITS;
  src1.bits[1] = MAXBITS;
  src1.bits[2] = MAXBITS;
  src1.bits[3] = 0;
  src2.bits[0] = MAXBITS;
  src2.bits[1] = MAXBITS;
  src2.bits[2] = MAXBITS;
  src2.bits[3] = 0;
  val = s21_is_greater(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_greater_19) {
  s21_decimal src1, src2;
  int val;
  // 4 > -5 T
  src1.bits[0] = 4;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 5;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000000000000000000000;
  val = s21_is_greater(src1, src2);
  ck_assert_int_eq(val, TRUE);
}
END_TEST

START_TEST(test_s21_is_greater_20) {
  s21_decimal src1, src2;
  int val;
  //-4 > +5 FALSE
  src1.bits[0] = 4;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 5;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b00000000000000000000000000000000;
  val = s21_is_greater(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_greater_21) {
  s21_decimal src1, src2;
  int val;
  //-23 > -23 F
  src1.bits[0] = 23;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 23;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000000000000000000000;
  val = s21_is_greater(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_greater_22) {
  s21_decimal src1, src2;
  int val;
  // 23 > -23 T
  src1.bits[0] = 23;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 23;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000000000000000000000;
  val = s21_is_greater(src1, src2);
  ck_assert_int_eq(val, TRUE);
}
END_TEST

START_TEST(test_s21_is_greater_23) {
  s21_decimal src1, src2;
  int val;
  // 23 > -12 T
  src1.bits[0] = 23;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 12;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000000000000000000000;
  val = s21_is_greater(src1, src2);
  ck_assert_int_eq(val, TRUE);
}
END_TEST

START_TEST(test_s21_is_greater_24) {
  s21_decimal src1, src2;
  int val;
  // 0 > 0 F
  src1.bits[0] = 0;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b00000000000000000000000000000000;
  val = s21_is_greater(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_greater_25) {
  s21_decimal src1, src2;
  int val;
  // 0 > -0 F
  src1.bits[0] = 0;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000000000000000000000;
  val = s21_is_greater(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_greater_26) {
  s21_decimal src1, src2;
  int val;
  src1.bits[0] = 12637482;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b00000000000000100000000000000000;
  src2.bits[0] = 12637482;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b00000000000000100000000000000000;
  val = s21_is_greater(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_greater_27) {
  s21_decimal src1, src2;
  int val;
  src1.bits[0] = 12637482;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b00000000000000100000000000000000;
  src2.bits[0] = 12637482;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b00000000000000010000000000000000;
  val = s21_is_greater(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_greater_28) {
  s21_decimal src1, src2;
  int val;
  src1.bits[0] = 1000;
  src1.bits[1] = 32;
  src1.bits[2] = 567;
  src1.bits[3] = 0b00000000000000100000000000000000;
  src2.bits[0] = 12637482;
  src2.bits[1] = 12;
  src2.bits[2] = 567;
  src2.bits[3] = 0b00000000000000100000000000000000;
  val = s21_is_greater(src1, src2);
  ck_assert_int_eq(val, TRUE);
}
END_TEST

START_TEST(test_s21_is_greater_29) {
  s21_decimal src1, src2;
  int val;
  src1.bits[0] = 12637482;
  src1.bits[1] = 12;
  src1.bits[2] = 567;
  src1.bits[3] = 0b00000000000000100000000000000000;
  src2.bits[0] = 1000;
  src2.bits[1] = 32;
  src2.bits[2] = 567;
  src2.bits[3] = 0b00000000000000100000000000000000;

  val = s21_is_greater(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_greater_30) {
  s21_decimal src1, src2;
  int val;
  src1.bits[0] = 1000;
  src1.bits[1] = 32;
  src1.bits[2] = 567;
  src1.bits[3] = 0b10000000000000100000000000000000;
  src2.bits[0] = 12637482;
  src2.bits[1] = 12;
  src2.bits[2] = 567;
  src2.bits[3] = 0b00000000000000100000000000000000;
  val = s21_is_greater(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_greater_31) {
  s21_decimal src1, src2;
  int val;
  src1.bits[0] = 1000;
  src1.bits[1] = 32;
  src1.bits[2] = 567;
  src1.bits[3] = 0b10000000000000100000000000000000;
  src2.bits[0] = 12637482;
  src2.bits[1] = 12;
  src2.bits[2] = 567;
  src2.bits[3] = 0b10000000000000100000000000000000;
  val = s21_is_greater(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_greater_32) {
  s21_decimal src1, src2;
  int val;
  src2.bits[0] = 1000;
  src2.bits[1] = 32;
  src2.bits[2] = 567;
  src2.bits[3] = 0b00000000000000100000000000000000;
  src1.bits[0] = 12637482;
  src1.bits[1] = 12;
  src1.bits[2] = 567;
  src1.bits[3] = 0b00000000000000100000000000000000;
  val = s21_is_greater(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_greater_33) {
  s21_decimal src1, src2;
  int val;
  src1.bits[0] = 1000;
  src1.bits[1] = 32;
  src1.bits[2] = 567;
  src1.bits[3] = 0b10000000000000100000000000000000;
  src2.bits[0] = 12637482;
  src2.bits[1] = 12;
  src2.bits[2] = 567;
  src2.bits[3] = 0b00000000000000100000000000000000;
  val = s21_is_greater(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_greater_34) {
  s21_decimal src1, src2;
  int val;
  src1.bits[0] = 1000;
  src1.bits[1] = 32;
  src1.bits[2] = 567;
  src1.bits[3] = 0b10000000000000100000000000000000;
  src2.bits[0] = 12637482;
  src2.bits[1] = 12;
  src2.bits[2] = 567;
  src2.bits[3] = 0b10000000000000100000000000000000;
  val = s21_is_greater(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_greater_35) {
  s21_decimal src1, src2;
  int val;
  src1.bits[0] = 1000;
  src1.bits[1] = 32;
  src1.bits[2] = 567;
  src1.bits[3] = 0b10000000000000100000000000000000;
  src2.bits[0] = 0;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0;
  val = s21_is_greater(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_greater_36) {
  s21_decimal src1, src2;
  int val;
  src1.bits[0] = 0;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 12637482;
  src2.bits[1] = 12;
  src2.bits[2] = 567;
  src2.bits[3] = 0b00000000000000100000000000000000;
  val = s21_is_greater(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_greater_37) {
  s21_decimal src1, src2;
  int val;
  src1.bits[0] = 1000;
  src1.bits[1] = 32;
  src1.bits[2] = 567;
  src1.bits[3] = 0b00000000000000100000000000000000;
  src2.bits[0] = 0;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000000000000000000000;
  val = s21_is_greater(src1, src2);
  ck_assert_int_eq(val, TRUE);
}
END_TEST

START_TEST(test_s21_is_greater_38) {
  s21_decimal src1, src2;
  int val;
  src1.bits[0] = 1000;
  src1.bits[1] = 32;
  src1.bits[2] = 567;
  src1.bits[3] = 0b00000000000000100000000000000000;
  src2.bits[0] = 0;
  src2.bits[1] = 34562234;
  src2.bits[2] = 0;
  src2.bits[3] = 0b00000000000000000000000000000000;
  val = s21_is_greater(src1, src2);
  ck_assert_int_eq(val, TRUE);
}
END_TEST

START_TEST(test_s21_is_greater_39) {
  s21_decimal src1, src2;
  int val;
  src1.bits[0] = 1000;
  src1.bits[1] = 32;
  src1.bits[2] = 567;
  src1.bits[3] = 0b10000000000000100000000000000000;
  src2.bits[0] = 0;
  src2.bits[1] = 34562234;
  src2.bits[2] = 0;
  src2.bits[3] = 0b00000000000000000000000000000000;
  val = s21_is_greater(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_greater_40) {
  s21_decimal src1, src2;
  int val;
  src1.bits[0] = 10;
  src1.bits[1] = 3;
  src1.bits[2] = 0;
  src1.bits[3] = 0b00000000000000100000000000000000;
  src2.bits[0] = 0;
  src2.bits[1] = 34562234;
  src2.bits[2] = 0;
  src2.bits[3] = 0b00000000000000000000000000000000;
  val = s21_is_greater(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_greater_41) {
  s21_decimal src1, src2;
  int val;
  src1.bits[0] = 1000;
  src1.bits[1] = 32;
  src1.bits[2] = 567;
  src1.bits[3] = 0b10000000000000100000000000000000;
  src2.bits[0] = 1000;
  src2.bits[1] = 32;
  src2.bits[2] = 567;
  src2.bits[3] = 0b10000000000000100000000000000000;
  val = s21_is_greater(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_greater_42) {
  s21_decimal src1, src2;
  int val;
  src1.bits[0] = 1000;
  src1.bits[1] = 32;
  src1.bits[2] = 567;
  src1.bits[3] = 0b00000000000000100000000000000000;
  src2.bits[0] = 1000;
  src2.bits[1] = 32;
  src2.bits[2] = 567;
  src2.bits[3] = 0b00000000000000100000000000000000;
  val = s21_is_greater(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_34) {
  s21_decimal src1, src2;
  int val;

  // 7 >= 15 FALSE
  src1.bits[0] = 7;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0;
  src2.bits[0] = 15;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0;
  val = s21_is_greater_or_equal(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_33) {
  s21_decimal src1, src2;
  int val;
  // 15 >= 7 TRUE
  src1.bits[0] = 15;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0;
  src2.bits[0] = 7;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0;
  val = s21_is_greater_or_equal(src1, src2);
  ck_assert_int_eq(val, TRUE);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_32) {
  s21_decimal src1, src2;
  int val;
  // -15 >= 7 FALSE
  src1.bits[0] = 15;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = MINUS;
  src2.bits[0] = 7;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0;
  val = s21_is_greater_or_equal(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_31) {
  s21_decimal src1, src2;
  int val;
  //-15 >= 15 FALSE
  src1.bits[0] = 15;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = MINUS;
  src2.bits[0] = 15;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0;
  val = s21_is_greater_or_equal(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_30) {
  s21_decimal src1, src2;
  int val;
  //    -15 >= -5 FALSE
  src1.bits[0] = 15;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = MINUS;
  src2.bits[0] = 5;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = MINUS;
  val = s21_is_greater_or_equal(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_29) {
  s21_decimal src1, src2;
  int val;
  //-0.7 >= -1.5 TRUE
  src1.bits[0] = 7;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b10000000000000100000000000000000;
  src2.bits[0] = 15;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000100000000000000000;
  val = s21_is_greater_or_equal(src1, src2);
  ck_assert_int_eq(val, TRUE);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_28) {
  s21_decimal src1, src2;
  int val;
  //-7 >= +1.5 FALSE
  src1.bits[0] = 7;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 15;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b00000000000000100000000000000000;
  val = s21_is_greater_or_equal(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_27) {
  s21_decimal src1, src2;
  int val;
  // 0.7 >= 1.5 FALSE
  src1.bits[0] = 7;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b10000000000000010000000000000000;
  src2.bits[0] = 15;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000100000000000000000;
  val = s21_is_greater_or_equal(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_26) {
  s21_decimal src1, src2;
  int val;
  // 6 >= 6 TRUE
  src1.bits[0] = 6;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0;
  src2.bits[0] = 6;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0;
  val = s21_is_greater_or_equal(src1, src2);
  ck_assert_int_eq(val, TRUE);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_25) {
  s21_decimal src1, src2;
  int val;
  //-6 >= -6 TRUE
  src1.bits[0] = 6;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = MINUS;
  src2.bits[0] = 6;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = MINUS;
  val = s21_is_greater_or_equal(src1, src2);
  ck_assert_int_eq(val, TRUE);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_24) {
  s21_decimal src1, src2;
  int val;
  // 6 >= 0.6 TRUE
  src1.bits[0] = 6;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0;
  src2.bits[0] = 6;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000100000000000000000;
  val = s21_is_greater_or_equal(src1, src2);
  ck_assert_int_eq(val, TRUE);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_23) {
  s21_decimal src1, src2;
  int val;
  //-4 >= -5 TRUE
  src1.bits[0] = 4;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 5;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000000000000000000000;
  val = s21_is_greater_or_equal(src1, src2);
  ck_assert_int_eq(val, TRUE);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_22) {
  s21_decimal src1, src2;
  int val;
  //== TRUE
  src1.bits[0] = MAXBITS;
  src1.bits[1] = MAXBITS;
  src1.bits[2] = MAXBITS;
  src1.bits[3] = 0;
  src2.bits[0] = MAXBITS;
  src2.bits[1] = MAXBITS;
  src2.bits[2] = MAXBITS;
  src2.bits[3] = 0;
  val = s21_is_greater_or_equal(src1, src2);
  ck_assert_int_eq(val, TRUE);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_21) {
  s21_decimal src1, src2;
  int val;
  // 4 > -5 T
  src1.bits[0] = 4;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 5;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000000000000000000000;
  val = s21_is_greater_or_equal(src1, src2);
  ck_assert_int_eq(val, TRUE);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_20) {
  s21_decimal src1, src2;
  int val;
  //-4 > +5 FALSE
  src1.bits[0] = 4;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 5;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b00000000000000000000000000000000;
  val = s21_is_greater_or_equal(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_1) {
  s21_decimal src1, src2;
  int val;
  //-23 > -23 T
  src1.bits[0] = 23;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 23;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000000000000000000000;
  val = s21_is_greater_or_equal(src1, src2);
  ck_assert_int_eq(val, TRUE);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_2) {
  s21_decimal src1, src2;
  int val;
  // 23 > -23 T
  src1.bits[0] = 23;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 23;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000000000000000000000;
  val = s21_is_greater_or_equal(src1, src2);
  ck_assert_int_eq(val, TRUE);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_3) {
  s21_decimal src1, src2;
  int val;
  // 23 > -12 T
  src1.bits[0] = 23;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 12;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000000000000000000000;
  val = s21_is_greater_or_equal(src1, src2);
  ck_assert_int_eq(val, TRUE);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_4) {
  s21_decimal src1, src2;
  int val;
  // 0 > 0 F
  src1.bits[0] = 0;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b00000000000000000000000000000000;
  val = s21_is_greater_or_equal(src1, src2);
  ck_assert_int_eq(val, TRUE);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_5) {
  s21_decimal src1, src2;
  int val;
  // 0 > -0 F
  src1.bits[0] = 0;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000000000000000000000;
  val = s21_is_greater_or_equal(src1, src2);
  ck_assert_int_eq(val, TRUE);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_6) {
  s21_decimal src1, src2;
  int val;
  src1.bits[0] = 12637482;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b00000000000000100000000000000000;
  src2.bits[0] = 12637482;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b00000000000000100000000000000000;
  val = s21_is_greater_or_equal(src1, src2);
  ck_assert_int_eq(val, TRUE);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_7) {
  s21_decimal src1, src2;
  int val;
  src1.bits[0] = 12637482;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b00000000000000100000000000000000;
  src2.bits[0] = 12637482;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b00000000000000010000000000000000;
  val = s21_is_greater_or_equal(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_8) {
  s21_decimal src1, src2;
  int val;
  src1.bits[0] = 1000;
  src1.bits[1] = 32;
  src1.bits[2] = 567;
  src1.bits[3] = 0b00000000000000100000000000000000;
  src2.bits[0] = 12637482;
  src2.bits[1] = 12;
  src2.bits[2] = 567;
  src2.bits[3] = 0b00000000000000100000000000000000;
  val = s21_is_greater_or_equal(src1, src2);
  ck_assert_int_eq(val, TRUE);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_9) {
  s21_decimal src1, src2;
  int val;
  src2.bits[0] = 1000;
  src2.bits[1] = 32;
  src2.bits[2] = 567;
  src2.bits[3] = 0b00000000000000100000000000000000;
  src1.bits[0] = 12637482;
  src1.bits[1] = 12;
  src1.bits[2] = 567;
  src1.bits[3] = 0b00000000000000100000000000000000;
  val = s21_is_greater_or_equal(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_10) {
  s21_decimal src1, src2;
  int val;
  src1.bits[0] = 1000;
  src1.bits[1] = 32;
  src1.bits[2] = 567;
  src1.bits[3] = 0b10000000000000100000000000000000;
  src2.bits[0] = 12637482;
  src2.bits[1] = 12;
  src2.bits[2] = 567;
  src2.bits[3] = 0b00000000000000100000000000000000;
  val = s21_is_greater_or_equal(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_11) {
  s21_decimal src1, src2;
  int val;
  src1.bits[0] = 1000;
  src1.bits[1] = 32;
  src1.bits[2] = 567;
  src1.bits[3] = 0b10000000000000100000000000000000;
  src2.bits[0] = 12637482;
  src2.bits[1] = 12;
  src2.bits[2] = 567;
  src2.bits[3] = 0b10000000000000100000000000000000;
  val = s21_is_greater_or_equal(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_12) {
  s21_decimal src1, src2;
  int val;
  src1.bits[0] = 1000;
  src1.bits[1] = 32;
  src1.bits[2] = 567;
  src1.bits[3] = 0b10000000000000100000000000000000;
  src2.bits[0] = 0;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0;
  val = s21_is_greater_or_equal(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_13) {
  s21_decimal src1, src2;
  int val;
  src1.bits[0] = 0;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 12637482;
  src2.bits[1] = 12;
  src2.bits[2] = 567;
  src2.bits[3] = 0b00000000000000100000000000000000;
  val = s21_is_greater_or_equal(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_14) {
  s21_decimal src1, src2;
  int val;
  src1.bits[0] = 1000;
  src1.bits[1] = 32;
  src1.bits[2] = 567;
  src1.bits[3] = 0b00000000000000100000000000000000;
  src2.bits[0] = 0;
  src2.bits[1] = 0;
  src2.bits[2] = 0;
  src2.bits[3] = 0b10000000000000000000000000000000;
  val = s21_is_greater_or_equal(src1, src2);
  ck_assert_int_eq(val, TRUE);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_15) {
  s21_decimal src1, src2;
  int val;
  src1.bits[0] = 1000;
  src1.bits[1] = 32;
  src1.bits[2] = 567;
  src1.bits[3] = 0b00000000000000100000000000000000;
  src2.bits[0] = 0;
  src2.bits[1] = 34562234;
  src2.bits[2] = 0;
  src2.bits[3] = 0b00000000000000000000000000000000;
  val = s21_is_greater_or_equal(src1, src2);
  ck_assert_int_eq(val, TRUE);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_16) {
  s21_decimal src1, src2;
  int val;
  src1.bits[0] = 1000;
  src1.bits[1] = 32;
  src1.bits[2] = 567;
  src1.bits[3] = 0b10000000000000100000000000000000;
  src2.bits[0] = 0;
  src2.bits[1] = 34562234;
  src2.bits[2] = 0;
  src2.bits[3] = 0b00000000000000000000000000000000;
  val = s21_is_greater_or_equal(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_17) {
  s21_decimal src1, src2;
  int val;
  src1.bits[0] = 10;
  src1.bits[1] = 3;
  src1.bits[2] = 0;
  src1.bits[3] = 0b00000000000000100000000000000000;
  src2.bits[0] = 0;
  src2.bits[1] = 34562234;
  src2.bits[2] = 0;
  src2.bits[3] = 0b00000000000000000000000000000000;
  val = s21_is_greater_or_equal(src1, src2);
  ck_assert_int_eq(val, FALSE);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_18) {
  s21_decimal src1, src2;
  int val;
  src1.bits[0] = 1000;
  src1.bits[1] = 32;
  src1.bits[2] = 567;
  src1.bits[3] = 0b10000000000000100000000000000000;
  src2.bits[0] = 1000;
  src2.bits[1] = 32;
  src2.bits[2] = 567;
  src2.bits[3] = 0b10000000000000100000000000000000;
  val = s21_is_greater_or_equal(src1, src2);
  ck_assert_int_eq(val, TRUE);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_19) {
  s21_decimal src1, src2;
  int val;
  src1.bits[0] = 1000;
  src1.bits[1] = 32;
  src1.bits[2] = 567;
  src1.bits[3] = 0b00000000000000100000000000000000;
  src2.bits[0] = 1000;
  src2.bits[1] = 32;
  src2.bits[2] = 567;
  src2.bits[3] = 0b00000000000000100000000000000000;
  val = s21_is_greater_or_equal(src1, src2);
  ck_assert_int_eq(val, TRUE);
}
END_TEST

START_TEST(test_s21_from_int_to_decimal) {
  s21_decimal rez, value;
  int test_1 = -10;
  s21_from_int_to_decimal(test_1, &value);
  rez.bits[0] = 0b00000000000000000000000000001010;
  rez.bits[1] = 0b00000000000000000000000000000000;
  rez.bits[2] = 0b00000000000000000000000000000000;
  rez.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(value.bits[0], rez.bits[0]);
  ck_assert_int_eq(value.bits[1], rez.bits[1]);
  ck_assert_int_eq(value.bits[2], rez.bits[2]);
  ck_assert_int_eq(value.bits[3], rez.bits[3]);

  int test_2 = 10;
  s21_from_int_to_decimal(test_2, &value);
  rez.bits[0] = 0b00000000000000000000000000001010;
  rez.bits[1] = 0b00000000000000000000000000000000;
  rez.bits[2] = 0b00000000000000000000000000000000;
  rez.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(value.bits[0], rez.bits[0]);
  ck_assert_int_eq(value.bits[1], rez.bits[1]);
  ck_assert_int_eq(value.bits[2], rez.bits[2]);
  ck_assert_int_eq(value.bits[3], rez.bits[3]);

  int test_3 = MAX_INT;
  s21_from_int_to_decimal(test_3, &value);
  rez.bits[0] = 0b01111111111111111111111111111111;
  rez.bits[1] = 0b00000000000000000000000000000000;
  rez.bits[2] = 0b00000000000000000000000000000000;
  rez.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(value.bits[0], rez.bits[0]);
  ck_assert_int_eq(value.bits[1], rez.bits[1]);
  ck_assert_int_eq(value.bits[2], rez.bits[2]);
  ck_assert_int_eq(value.bits[3], rez.bits[3]);

  int test_4 = 4535435;
  s21_from_int_to_decimal(test_4, &value);
  rez.bits[0] = 0b00000000010001010011010010001011;
  rez.bits[1] = 0b00000000000000000000000000000000;
  rez.bits[2] = 0b00000000000000000000000000000000;
  rez.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(value.bits[0], rez.bits[0]);
  ck_assert_int_eq(value.bits[1], rez.bits[1]);
  ck_assert_int_eq(value.bits[2], rez.bits[2]);
  ck_assert_int_eq(value.bits[3], rez.bits[3]);

  int test_5 = -4535435;
  s21_from_int_to_decimal(test_5, &value);
  rez.bits[0] = 0b00000000010001010011010010001011;
  rez.bits[1] = 0b00000000000000000000000000000000;
  rez.bits[2] = 0b00000000000000000000000000000000;
  rez.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(value.bits[0], rez.bits[0]);
  ck_assert_int_eq(value.bits[1], rez.bits[1]);
  ck_assert_int_eq(value.bits[2], rez.bits[2]);
  ck_assert_int_eq(value.bits[3], rez.bits[3]);
}
END_TEST

START_TEST(test_s21_from_decimal_to_int_1) {
  s21_decimal value;
  int test_1 = 10, rez = 0;
  value.bits[0] = 0b00000000000000000000000000001010;
  value.bits[1] = 0b00000000000000000000000000000000;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b00000000000000000000000000000000;
  s21_from_decimal_to_int(value, &rez);
  ck_assert_int_eq(test_1, rez);
}
END_TEST

START_TEST(test_s21_from_decimal_to_int_2) {
  s21_decimal value;
  int test_2 = 4535435, rez = 0;
  value.bits[0] = 0b00000000010001010011010010001011;
  value.bits[1] = 0b00000000000000000000000000000000;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b00000000000000000000000000000000;
  s21_from_decimal_to_int(value, &rez);
  ck_assert_int_eq(test_2, rez);
}
END_TEST

START_TEST(test_s21_from_decimal_to_int_3) {
  s21_decimal value;
  int rez = 0;
  int test_3 = -4535435;
  value.bits[0] = 0b00000000010001010011010010001011;
  value.bits[1] = 0b00000000000000000000000000000000;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b10000000000000000000000000000000;
  s21_from_decimal_to_int(value, &rez);
  ck_assert_int_eq(test_3, rez);
}
END_TEST

START_TEST(test_s21_from_decimal_to_int_4) {
  s21_decimal value;
  int rez = 0;
  int test_4 = MAX_INT;
  value.bits[0] = 0b01111111111111111111111111111111;
  value.bits[1] = 0b00000000000000000000000000000000;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b00000000000000000000000000000000;
  s21_from_decimal_to_int(value, &rez);
  ck_assert_int_eq(test_4, rez);
}
END_TEST

START_TEST(test_s21_from_decimal_to_int_5) {
  s21_decimal value;
  int rez = 0;
  int test_5 = 453553;
  value.bits[0] = 0b00000000000001101110101110110001;
  value.bits[1] = 0b00000000000000000000000000000000;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b00000000000000000000000000000000;
  s21_from_decimal_to_int(value, &rez);
  ck_assert_int_eq(test_5, rez);
}
END_TEST

START_TEST(test_s21_from_decimal_to_int_6) {
  s21_decimal value;
  int rez = 0;
  int test_6 = -453;
  value.bits[0] = 0b00000000000000000000000111000101;
  value.bits[1] = 0b00000000000000000000000000000000;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b10000000000000000000000000000000;
  s21_from_decimal_to_int(value, &rez);
  ck_assert_int_eq(test_6, rez);
}
END_TEST

START_TEST(test_s21_from_decimal_to_int_7) {
  s21_decimal value;
  int rez = 0;
  int test_7 = 222;
  value.bits[0] = 0b00000000000000000000100010101110;
  value.bits[1] = 0b00000000000000000000000000000000;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b00000000000000010000000000000000;
  s21_from_decimal_to_int(value, &rez);
  ck_assert_int_eq(test_7, rez);
}
END_TEST

START_TEST(test_s21_from_decimal_to_int_8) {
  s21_decimal value;
  int rez = 0;
  int test_8 = -222;
  value.bits[0] = 0b00000000000000000000100010101110;
  value.bits[1] = 0b00000000000000000000000000000000;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b10000000000000010000000000000000;
  s21_from_decimal_to_int(value, &rez);
  ck_assert_int_eq(test_8, rez);
}
END_TEST

START_TEST(test_s21_from_float_to_decimal_1) {
  s21_decimal value, rez;
  float test_1 = 10.0F;
  s21_from_float_to_decimal(test_1, &value);
  rez.bits[0] = 0b00000000000011110100001001000000;
  rez.bits[1] = 0b00000000000000000000000000000000;
  rez.bits[2] = 0b00000000000000000000000000000000;
  rez.bits[3] = 0b00000000000001010000000000000000;
  ck_assert_int_eq(value.bits[0], rez.bits[0]);
  ck_assert_int_eq(value.bits[1], rez.bits[1]);
  ck_assert_int_eq(value.bits[2], rez.bits[2]);
  ck_assert_int_eq(value.bits[3], rez.bits[3]);
}
END_TEST

START_TEST(test_s21_from_float_to_decimal_2) {
  s21_decimal value, rez;
  float test_2 = -1.254183F;
  s21_from_float_to_decimal(test_2, &value);
  rez.bits[0] = 0b00000000000100110010001100100111;
  rez.bits[1] = 0b00000000000000000000000000000000;
  rez.bits[2] = 0b00000000000000000000000000000000;
  rez.bits[3] = 0b10000000000001100000000000000000;
  ck_assert_int_eq(value.bits[0], rez.bits[0]);
  ck_assert_int_eq(value.bits[1], rez.bits[1]);
  ck_assert_int_eq(value.bits[2], rez.bits[2]);
  ck_assert_int_eq(value.bits[3], rez.bits[3]);
}
END_TEST

START_TEST(test_s21_from_float_to_decimal_3) {
  s21_decimal value, rez;
  float test_3 = -43.765F;
  s21_from_float_to_decimal(test_3, &value);
  rez.bits[0] = 0b00000000010000101100011110110100;
  rez.bits[1] = 0b00000000000000000000000000000000;
  rez.bits[2] = 0b00000000000000000000000000000000;
  rez.bits[3] = 0b10000000000001010000000000000000;
  ck_assert_int_eq(value.bits[0], rez.bits[0]);
  ck_assert_int_eq(value.bits[1], rez.bits[1]);
  ck_assert_int_eq(value.bits[2], rez.bits[2]);
  ck_assert_int_eq(value.bits[3], rez.bits[3]);
}
END_TEST

START_TEST(test_s21_from_float_to_decimal_4) {
  s21_decimal value;
  float test_4 = -1.0F / 0.0F;
  s21_from_float_to_decimal(test_4, &value);
}
END_TEST

START_TEST(test_s21_from_float_to_decimal_5) {
  s21_decimal value;
  float test_5 = 1.0F / 0.0F;
  s21_from_float_to_decimal(test_5, &value);
}
END_TEST

START_TEST(test_s21_from_float_to_decimal_6) {
  s21_decimal value;
  float test_6 = 0.0F;
  s21_from_float_to_decimal(test_6, &value);
}
END_TEST

START_TEST(test_s21_from_decimal_to_float_1) {
  s21_decimal value;
  float test_1 = 10.F;
  float rez = 0;
  value.bits[0] = 10;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0;
  s21_from_decimal_to_float(value, &rez);
  ck_assert_int_eq(test_1, rez);
}
END_TEST

START_TEST(test_s21_from_decimal_to_float_2) {
  s21_decimal value;
  float rez = 0;
  float test_2 = -18.122;
  value.bits[0] = 18122;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0b10000000000000110000000000000000;
  s21_from_decimal_to_float(value, &rez);
  ck_assert_int_eq(test_2, rez);
}
END_TEST

START_TEST(test_s21_from_decimal_to_float_3) {
  s21_decimal value;
  float rez = 0;
  float test_3 = 1234.56789F;
  value.bits[0] = 123456789;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0b00000000000001010000000000000000;
  s21_from_decimal_to_float(value, &rez);
  ck_assert_int_eq(test_3, rez);
}
END_TEST

START_TEST(test_s21_from_decimal_to_float_4) {
  s21_decimal value;
  float rez = 0;
  float test_4 = 12345.6789;
  value.bits[0] = 123456789;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0b00000000000001000000000000000000;
  s21_from_decimal_to_float(value, &rez);
  ck_assert_int_eq(test_4, rez);
}
END_TEST

START_TEST(test_s21_from_decimal_to_float_5) {
  s21_decimal value;
  float rez = 0;
  float test_5 = -4356.765F;
  value.bits[0] = 0b00000000010000100111101010011101;
  value.bits[1] = 0b00000000000000000000000000000000;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b10000000000000110000000000000000;
  s21_from_decimal_to_float(value, &rez);
  ck_assert_int_eq(test_5, rez);
}
END_TEST

START_TEST(test_s21_add_1) {
  s21_decimal value, value2, rez_function, rez_add_in_our_head;
  int result_int;

  // 2946 + 361 = 3307
  value.bits[0] = 2946;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0;
  value2.bits[0] = 361;
  value2.bits[1] = 0;
  value2.bits[2] = 0;
  value2.bits[3] = 0;
  result_int = s21_add(value, value2, &rez_function);

  rez_add_in_our_head.bits[0] = 3307;
  rez_add_in_our_head.bits[1] = 0;
  rez_add_in_our_head.bits[2] = 0;
  rez_add_in_our_head.bits[3] = 0;
  ck_assert_int_eq(rez_function.bits[0], rez_add_in_our_head.bits[0]);
  ck_assert_int_eq(rez_function.bits[1], rez_add_in_our_head.bits[1]);
  ck_assert_int_eq(rez_function.bits[2], rez_add_in_our_head.bits[2]);
  ck_assert_int_eq(rez_function.bits[3], rez_add_in_our_head.bits[3]);
  ck_assert_int_eq(result_int, 0);
}
END_TEST

START_TEST(test_s21_add_2) {
  s21_decimal value, value2, rez_function, rez_add_in_our_head;
  int result_int;
  //-2946 + 361 = - 2585
  value.bits[0] = 2946;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0b10000000000000000000000000000000;
  value2.bits[0] = 361;
  value2.bits[1] = 0;
  value2.bits[2] = 0;
  value2.bits[3] = 0;
  result_int = s21_add(value, value2, &rez_function);

  rez_add_in_our_head.bits[0] = 2585;
  rez_add_in_our_head.bits[1] = 0;
  rez_add_in_our_head.bits[2] = 0;
  rez_add_in_our_head.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(rez_function.bits[0], rez_add_in_our_head.bits[0]);
  ck_assert_int_eq(rez_function.bits[1], rez_add_in_our_head.bits[1]);
  ck_assert_int_eq(rez_function.bits[2], rez_add_in_our_head.bits[2]);
  ck_assert_int_eq(rez_function.bits[3], rez_add_in_our_head.bits[3]);
  ck_assert_int_eq(result_int, 0);
}
END_TEST

START_TEST(test_s21_add_3) {
  s21_decimal value, value2, rez_function, rez_add_in_our_head;
  int result_int;
  // 22 + -10 = 12
  value.bits[0] = 22;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0b00000000000000000000000000000000;
  value2.bits[0] = 10;
  value2.bits[1] = 0;
  value2.bits[2] = 0;
  value2.bits[3] = 0b10000000000000000000000000000000;
  result_int = s21_add(value, value2, &rez_function);

  rez_add_in_our_head.bits[0] = 12;
  rez_add_in_our_head.bits[1] = 0;
  rez_add_in_our_head.bits[2] = 0;
  rez_add_in_our_head.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(rez_function.bits[0], rez_add_in_our_head.bits[0]);
  ck_assert_int_eq(rez_function.bits[1], rez_add_in_our_head.bits[1]);
  ck_assert_int_eq(rez_function.bits[2], rez_add_in_our_head.bits[2]);
  ck_assert_int_eq(rez_function.bits[3], rez_add_in_our_head.bits[3]);
  ck_assert_int_eq(result_int, 0);
}
END_TEST

START_TEST(test_s21_add_4) {
  s21_decimal value, value2, rez_function, rez_add_in_our_head;
  int result_int;
  // -22 + -10 = 32
  value.bits[0] = 22;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0b10000000000000000000000000000000;
  value2.bits[0] = 10;
  value2.bits[1] = 0;
  value2.bits[2] = 0;
  value2.bits[3] = 0b10000000000000000000000000000000;
  result_int = s21_add(value, value2, &rez_function);

  rez_add_in_our_head.bits[0] = 32;
  rez_add_in_our_head.bits[1] = 0;
  rez_add_in_our_head.bits[2] = 0;
  rez_add_in_our_head.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(rez_function.bits[0], rez_add_in_our_head.bits[0]);
  ck_assert_int_eq(rez_function.bits[1], rez_add_in_our_head.bits[1]);
  ck_assert_int_eq(rez_function.bits[2], rez_add_in_our_head.bits[2]);
  ck_assert_int_eq(rez_function.bits[3], rez_add_in_our_head.bits[3]);
  ck_assert_int_eq(result_int, 0);
}
END_TEST

START_TEST(test_s21_add_5) {
  s21_decimal value, value2, rez_function, rez_add_in_our_head;
  int result_int;
  // 0+0=0
  value.bits[0] = 0;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0;
  value2.bits[0] = 0;
  value2.bits[1] = 0;
  value2.bits[2] = 0;
  value2.bits[3] = 0;
  result_int = s21_add(value, value2, &rez_function);

  rez_add_in_our_head.bits[0] = 0;
  rez_add_in_our_head.bits[1] = 0;
  rez_add_in_our_head.bits[2] = 0;
  rez_add_in_our_head.bits[3] = 0;
  ck_assert_int_eq(rez_function.bits[0], rez_add_in_our_head.bits[0]);
  ck_assert_int_eq(rez_function.bits[1], rez_add_in_our_head.bits[1]);
  ck_assert_int_eq(rez_function.bits[2], rez_add_in_our_head.bits[2]);
  ck_assert_int_eq(rez_function.bits[3], rez_add_in_our_head.bits[3]);
  ck_assert_int_eq(result_int, 0);
}
END_TEST

START_TEST(test_s21_add_6) {
  s21_decimal value, value2, rez_function, rez_add_in_our_head;
  int result_int;
  //-4 + -5 = -9
  value.bits[0] = 4;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0b10000000000000000000000000000000;
  value2.bits[0] = 5;
  value2.bits[1] = 0;
  value2.bits[2] = 0;
  value2.bits[3] = 0b10000000000000000000000000000000;
  result_int = s21_add(value, value2, &rez_function);

  rez_add_in_our_head.bits[0] = 9;
  rez_add_in_our_head.bits[1] = 0;
  rez_add_in_our_head.bits[2] = 0;
  rez_add_in_our_head.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(rez_function.bits[0], rez_add_in_our_head.bits[0]);
  ck_assert_int_eq(rez_function.bits[1], rez_add_in_our_head.bits[1]);
  ck_assert_int_eq(rez_function.bits[2], rez_add_in_our_head.bits[2]);
  ck_assert_int_eq(rez_function.bits[3], rez_add_in_our_head.bits[3]);
  ck_assert_int_eq(result_int, 0);
}
END_TEST

START_TEST(test_s21_add_7) {
  s21_decimal value, value2, rez_function, rez_add_in_our_head;
  int result_int;
  // 4 + 5 = 9
  value.bits[0] = 4;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0b00000000000000000000000000000000;
  value2.bits[0] = 5;
  value2.bits[1] = 0;
  value2.bits[2] = 0;
  value2.bits[3] = 0b00000000000000000000000000000000;
  result_int = s21_add(value, value2, &rez_function);

  rez_add_in_our_head.bits[0] = 9;
  rez_add_in_our_head.bits[1] = 0;
  rez_add_in_our_head.bits[2] = 0;
  rez_add_in_our_head.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(rez_function.bits[0], rez_add_in_our_head.bits[0]);
  ck_assert_int_eq(rez_function.bits[1], rez_add_in_our_head.bits[1]);
  ck_assert_int_eq(rez_function.bits[2], rez_add_in_our_head.bits[2]);
  ck_assert_int_eq(rez_function.bits[3], rez_add_in_our_head.bits[3]);
  ck_assert_int_eq(result_int, 0);
}
END_TEST

START_TEST(test_s21_add_8) {
  s21_decimal value, value2, rez_function, rez_add_in_our_head;
  int result_int;
  //-4 + 5 = 1
  value.bits[0] = 4;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0b10000000000000000000000000000000;
  value2.bits[0] = 5;
  value2.bits[1] = 0;
  value2.bits[2] = 0;
  value2.bits[3] = 0b00000000000000000000000000000000;
  result_int = s21_add(value, value2, &rez_function);

  rez_add_in_our_head.bits[0] = 1;
  rez_add_in_our_head.bits[1] = 0;
  rez_add_in_our_head.bits[2] = 0;
  rez_add_in_our_head.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(rez_function.bits[0], rez_add_in_our_head.bits[0]);
  ck_assert_int_eq(rez_function.bits[1], rez_add_in_our_head.bits[1]);
  ck_assert_int_eq(rez_function.bits[2], rez_add_in_our_head.bits[2]);
  ck_assert_int_eq(rez_function.bits[3], rez_add_in_our_head.bits[3]);
  ck_assert_int_eq(result_int, 0);
}
END_TEST

START_TEST(test_s21_add_9) {
  s21_decimal value, value2, rez_function, rez_add_in_our_head;
  int result_int;
  // 22 + -150 = -128
  value.bits[0] = 22;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0b00000000000000000000000000000000;
  value2.bits[0] = 150;
  value2.bits[1] = 0;
  value2.bits[2] = 0;
  value2.bits[3] = 0b10000000000000000000000000000000;
  result_int = s21_add(value, value2, &rez_function);

  rez_add_in_our_head.bits[0] = 128;
  rez_add_in_our_head.bits[1] = 0;
  rez_add_in_our_head.bits[2] = 0;
  rez_add_in_our_head.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(rez_function.bits[0], rez_add_in_our_head.bits[0]);
  ck_assert_int_eq(rez_function.bits[1], rez_add_in_our_head.bits[1]);
  ck_assert_int_eq(rez_function.bits[2], rez_add_in_our_head.bits[2]);
  ck_assert_int_eq(rez_function.bits[3], rez_add_in_our_head.bits[3]);
  ck_assert_int_eq(result_int, 0);
}
END_TEST

START_TEST(test_s21_add_10) {
  s21_decimal value, value2, rez_function, rez_add_in_our_head;
  int result_int;
  // 4 + 4 = 8
  value.bits[0] = 4;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0b00000000000000000000000000000000;
  value2.bits[0] = 4;
  value2.bits[1] = 0;
  value2.bits[2] = 0;
  value2.bits[3] = 0b00000000000000000000000000000000;
  result_int = s21_add(value, value2, &rez_function);

  rez_add_in_our_head.bits[0] = 8;
  rez_add_in_our_head.bits[1] = 0;
  rez_add_in_our_head.bits[2] = 0;
  rez_add_in_our_head.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(rez_function.bits[0], rez_add_in_our_head.bits[0]);
  ck_assert_int_eq(rez_function.bits[1], rez_add_in_our_head.bits[1]);
  ck_assert_int_eq(rez_function.bits[2], rez_add_in_our_head.bits[2]);
  ck_assert_int_eq(rez_function.bits[3], rez_add_in_our_head.bits[3]);
  ck_assert_int_eq(result_int, 0);
}
END_TEST

START_TEST(test_s21_add_11) {
  s21_decimal value, value2, rez_function, rez_add_in_our_head;
  int result_int;
  // -4 + -4 = -8
  value.bits[0] = 4;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0b10000000000000000000000000000000;
  value2.bits[0] = 4;
  value2.bits[1] = 0;
  value2.bits[2] = 0;
  value2.bits[3] = 0b10000000000000000000000000000000;
  result_int = s21_add(value, value2, &rez_function);

  rez_add_in_our_head.bits[0] = 8;
  rez_add_in_our_head.bits[1] = 0;
  rez_add_in_our_head.bits[2] = 0;
  rez_add_in_our_head.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(rez_function.bits[0], rez_add_in_our_head.bits[0]);
  ck_assert_int_eq(rez_function.bits[1], rez_add_in_our_head.bits[1]);
  ck_assert_int_eq(rez_function.bits[2], rez_add_in_our_head.bits[2]);
  ck_assert_int_eq(rez_function.bits[3], rez_add_in_our_head.bits[3]);
  ck_assert_int_eq(result_int, 0);
}
END_TEST

START_TEST(test_s21_add_12) {
  s21_decimal value, value2, rez_function, rez_add_in_our_head;
  int result_int;
  // 4 + -4 = 0
  value.bits[0] = 4;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0b00000000000000000000000000000000;
  value2.bits[0] = 4;
  value2.bits[1] = 0;
  value2.bits[2] = 0;
  value2.bits[3] = 0b10000000000000000000000000000000;
  result_int = s21_add(value, value2, &rez_function);

  rez_add_in_our_head.bits[0] = 0;
  rez_add_in_our_head.bits[1] = 0;
  rez_add_in_our_head.bits[2] = 0;
  rez_add_in_our_head.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(rez_function.bits[0], rez_add_in_our_head.bits[0]);
  ck_assert_int_eq(rez_function.bits[1], rez_add_in_our_head.bits[1]);
  ck_assert_int_eq(rez_function.bits[2], rez_add_in_our_head.bits[2]);
  ck_assert_int_eq(rez_function.bits[3], rez_add_in_our_head.bits[3]);
  ck_assert_int_eq(result_int, 0);
}
END_TEST

START_TEST(test_s21_add_13) {
  s21_decimal value, value2, rez_function, rez_add_in_our_head;
  int result_int;
  //-4 + 4 = 0
  value.bits[0] = 4;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0b10000000000000000000000000000000;
  value2.bits[0] = 4;
  value2.bits[1] = 0;
  value2.bits[2] = 0;
  value2.bits[3] = 0b00000000000000000000000000000000;
  result_int = s21_add(value, value2, &rez_function);

  rez_add_in_our_head.bits[0] = 0;
  rez_add_in_our_head.bits[1] = 0;
  rez_add_in_our_head.bits[2] = 0;
  rez_add_in_our_head.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(rez_function.bits[0], rez_add_in_our_head.bits[0]);
  ck_assert_int_eq(rez_function.bits[1], rez_add_in_our_head.bits[1]);
  ck_assert_int_eq(rez_function.bits[2], rez_add_in_our_head.bits[2]);
  ck_assert_int_eq(rez_function.bits[3], rez_add_in_our_head.bits[3]);
  ck_assert_int_eq(result_int, 0);
}
END_TEST

START_TEST(test_s21_add_14) {
  s21_decimal value, value2, rez_function, rez_add_in_our_head;
  int result_int;
  // MAX_INT + MAX_INT
  value.bits[0] = 0b11111111111111111111111111111111;
  value.bits[1] = 0b00000000000000000000000000000000;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b00000000000000000000000000000000;

  value2.bits[0] = 0b11111111111111111111111111111111;
  value2.bits[1] = 0b00000000000000000000000000000000;
  value2.bits[2] = 0b00000000000000000000000000000000;
  value2.bits[3] = 0b00000000000000000000000000000000;
  result_int = s21_add(value, value2, &rez_function);

  rez_add_in_our_head.bits[0] = 0b11111111111111111111111111111110;
  rez_add_in_our_head.bits[1] = 1;
  rez_add_in_our_head.bits[2] = 0;
  rez_add_in_our_head.bits[3] = 0;

  ck_assert_int_eq(rez_function.bits[0], rez_add_in_our_head.bits[0]);
  ck_assert_int_eq(rez_function.bits[1], rez_add_in_our_head.bits[1]);
  ck_assert_int_eq(rez_function.bits[2], rez_add_in_our_head.bits[2]);
  ck_assert_int_eq(rez_function.bits[3], rez_add_in_our_head.bits[3]);
  ck_assert_int_eq(result_int, 0);
}
END_TEST

START_TEST(test_s21_add_15) {
  s21_decimal value, value2, rez_function;
  int result_int;
  // MAX
  value.bits[0] = 0b11111111111111111111111111111111;
  value.bits[1] = 0b11111111111111111111111111111111;
  value.bits[2] = 0b11111111111111111111111111111111;
  value.bits[3] = 0b00000000000000000000000000000000;

  value2.bits[0] = 0b11111111111111111111111111111111;
  value2.bits[1] = 0b11111111111111111111111111111111;
  value2.bits[2] = 0b11111111111111111111111111111111;
  value2.bits[3] = 0b00000000000000000000000000000000;
  result_int = s21_add(value, value2, &rez_function);
  ck_assert_int_eq(result_int, 1);
}
END_TEST

START_TEST(test_s21_add_16) {
  s21_decimal value, value2, rez_function;
  int result_int;
  // MAX + MAX
  value.bits[0] = 0b11111111111111111111111111111111;
  value.bits[1] = 0b11111111111111111111111111111111;
  value.bits[2] = 0b11111111111111111111111111111111;
  value.bits[3] = 0b10000000000000000000000000000000;

  value2.bits[0] = 0b11111111111111111111111111111111;
  value2.bits[1] = 0b11111111111111111111111111111111;
  value2.bits[2] = 0b11111111111111111111111111111111;
  value2.bits[3] = 0b10000000000000000000000000000000;
  result_int = s21_add(value, value2, &rez_function);
  ck_assert_int_eq(result_int, 2);
}
END_TEST

START_TEST(test_s21_sub_1) {
  s21_decimal value, value2, rez_function, rez_sub_in_our_head;
  int result_int;
  // 2946 - 361 = 2585
  value.bits[0] = 2946;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0;
  value2.bits[0] = 361;
  value2.bits[1] = 0;
  value2.bits[2] = 0;
  value2.bits[3] = 0;
  result_int = s21_sub(value, value2, &rez_function);

  rez_sub_in_our_head.bits[0] = 2585;
  rez_sub_in_our_head.bits[1] = 0;
  rez_sub_in_our_head.bits[2] = 0;
  rez_sub_in_our_head.bits[3] = 0;
  ck_assert_int_eq(rez_function.bits[0], rez_sub_in_our_head.bits[0]);
  ck_assert_int_eq(rez_function.bits[1], rez_sub_in_our_head.bits[1]);
  ck_assert_int_eq(rez_function.bits[2], rez_sub_in_our_head.bits[2]);
  ck_assert_int_eq(rez_function.bits[3], rez_sub_in_our_head.bits[3]);
  ck_assert_int_eq(result_int, 0);
}
END_TEST

START_TEST(test_s21_sub_2) {
  s21_decimal value, value2, rez_function, rez_sub_in_our_head;
  int result_int;
  //-2946 - +361 = - 3307
  value.bits[0] = 2946;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0b10000000000000000000000000000000;
  value2.bits[0] = 361;
  value2.bits[1] = 0;
  value2.bits[2] = 0;
  value2.bits[3] = 0b00000000000000000000000000000000;
  result_int = s21_sub(value, value2, &rez_function);

  rez_sub_in_our_head.bits[0] = 3307;
  rez_sub_in_our_head.bits[1] = 0;
  rez_sub_in_our_head.bits[2] = 0;
  rez_sub_in_our_head.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(rez_function.bits[0], rez_sub_in_our_head.bits[0]);
  ck_assert_int_eq(rez_function.bits[1], rez_sub_in_our_head.bits[1]);
  ck_assert_int_eq(rez_function.bits[2], rez_sub_in_our_head.bits[2]);
  ck_assert_int_eq(rez_function.bits[3], rez_sub_in_our_head.bits[3]);
  ck_assert_int_eq(result_int, 0);
}
END_TEST

START_TEST(test_s21_sub_3) {
  s21_decimal value, value2, rez_function, rez_sub_in_our_head;
  int result_int;
  // 22 - -10 = 32
  value.bits[0] = 22;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0b00000000000000000000000000000000;
  value2.bits[0] = 10;
  value2.bits[1] = 0;
  value2.bits[2] = 0;
  value2.bits[3] = 0b10000000000000000000000000000000;
  result_int = s21_sub(value, value2, &rez_function);

  rez_sub_in_our_head.bits[0] = 32;
  rez_sub_in_our_head.bits[1] = 0;
  rez_sub_in_our_head.bits[2] = 0;
  rez_sub_in_our_head.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(rez_function.bits[0], rez_sub_in_our_head.bits[0]);
  ck_assert_int_eq(rez_function.bits[1], rez_sub_in_our_head.bits[1]);
  ck_assert_int_eq(rez_function.bits[2], rez_sub_in_our_head.bits[2]);
  ck_assert_int_eq(rez_function.bits[3], rez_sub_in_our_head.bits[3]);
  ck_assert_int_eq(result_int, 0);
}
END_TEST

START_TEST(test_s21_sub_4) {
  s21_decimal value, value2, rez_function, rez_sub_in_our_head;
  int result_int;
  // -22 - -10 = -12
  value.bits[0] = 22;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0b10000000000000000000000000000000;
  value2.bits[0] = 10;
  value2.bits[1] = 0;
  value2.bits[2] = 0;
  value2.bits[3] = 0b10000000000000000000000000000000;
  result_int = s21_sub(value, value2, &rez_function);

  rez_sub_in_our_head.bits[0] = 12;
  rez_sub_in_our_head.bits[1] = 0;
  rez_sub_in_our_head.bits[2] = 0;
  rez_sub_in_our_head.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(rez_function.bits[0], rez_sub_in_our_head.bits[0]);
  ck_assert_int_eq(rez_function.bits[1], rez_sub_in_our_head.bits[1]);
  ck_assert_int_eq(rez_function.bits[2], rez_sub_in_our_head.bits[2]);
  ck_assert_int_eq(rez_function.bits[3], rez_sub_in_our_head.bits[3]);
  ck_assert_int_eq(result_int, 0);
}
END_TEST

START_TEST(test_s21_sub_5) {
  s21_decimal value, value2, rez_function, rez_sub_in_our_head;
  int result_int;
  // 0- -0=0
  value.bits[0] = 0;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0;
  value2.bits[0] = 0;
  value2.bits[1] = 0;
  value2.bits[2] = 0;
  value2.bits[3] = 0;
  result_int = s21_sub(value, value2, &rez_function);

  rez_sub_in_our_head.bits[0] = 0;
  rez_sub_in_our_head.bits[1] = 0;
  rez_sub_in_our_head.bits[2] = 0;
  rez_sub_in_our_head.bits[3] = 0;
  ck_assert_int_eq(rez_function.bits[0], rez_sub_in_our_head.bits[0]);
  ck_assert_int_eq(rez_function.bits[1], rez_sub_in_our_head.bits[1]);
  ck_assert_int_eq(rez_function.bits[2], rez_sub_in_our_head.bits[2]);
  ck_assert_int_eq(rez_function.bits[3], rez_sub_in_our_head.bits[3]);
  ck_assert_int_eq(result_int, 0);
}
END_TEST

START_TEST(test_s21_sub_6) {
  s21_decimal value, value2, rez_function, rez_sub_in_our_head;
  int result_int;
  //-4 - -5 = 1
  value.bits[0] = 4;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0b10000000000000000000000000000000;
  value2.bits[0] = 5;
  value2.bits[1] = 0;
  value2.bits[2] = 0;
  value2.bits[3] = 0b10000000000000000000000000000000;
  result_int = s21_sub(value, value2, &rez_function);

  rez_sub_in_our_head.bits[0] = 1;
  rez_sub_in_our_head.bits[1] = 0;
  rez_sub_in_our_head.bits[2] = 0;
  rez_sub_in_our_head.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(rez_function.bits[0], rez_sub_in_our_head.bits[0]);
  ck_assert_int_eq(rez_function.bits[1], rez_sub_in_our_head.bits[1]);
  ck_assert_int_eq(rez_function.bits[2], rez_sub_in_our_head.bits[2]);
  ck_assert_int_eq(rez_function.bits[3], rez_sub_in_our_head.bits[3]);
  ck_assert_int_eq(result_int, 0);
}
END_TEST

START_TEST(test_s21_sub_7) {
  s21_decimal value, value2, rez_function, rez_sub_in_our_head;
  int result_int;
  //+4 - +5 = -1
  value.bits[0] = 4;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0b00000000000000000000000000000000;
  value2.bits[0] = 5;
  value2.bits[1] = 0;
  value2.bits[2] = 0;
  value2.bits[3] = 0b00000000000000000000000000000000;
  result_int = s21_sub(value, value2, &rez_function);

  rez_sub_in_our_head.bits[0] = 1;
  rez_sub_in_our_head.bits[1] = 0;
  rez_sub_in_our_head.bits[2] = 0;
  rez_sub_in_our_head.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(rez_function.bits[0], rez_sub_in_our_head.bits[0]);
  ck_assert_int_eq(rez_function.bits[1], rez_sub_in_our_head.bits[1]);
  ck_assert_int_eq(rez_function.bits[2], rez_sub_in_our_head.bits[2]);
  ck_assert_int_eq(rez_function.bits[3], rez_sub_in_our_head.bits[3]);
  ck_assert_int_eq(result_int, 0);
}
END_TEST

START_TEST(test_s21_sub_8) {
  s21_decimal value, value2, rez_function, rez_sub_in_our_head;
  int result_int;
  //-4 - +5 = -9
  value.bits[0] = 4;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0b10000000000000000000000000000000;
  value2.bits[0] = 5;
  value2.bits[1] = 0;
  value2.bits[2] = 0;
  value2.bits[3] = 0b00000000000000000000000000000000;
  result_int = s21_sub(value, value2, &rez_function);

  rez_sub_in_our_head.bits[0] = 9;
  rez_sub_in_our_head.bits[1] = 0;
  rez_sub_in_our_head.bits[2] = 0;
  rez_sub_in_our_head.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(rez_function.bits[0], rez_sub_in_our_head.bits[0]);
  ck_assert_int_eq(rez_function.bits[1], rez_sub_in_our_head.bits[1]);
  ck_assert_int_eq(rez_function.bits[2], rez_sub_in_our_head.bits[2]);
  ck_assert_int_eq(rez_function.bits[3], rez_sub_in_our_head.bits[3]);
  ck_assert_int_eq(result_int, 0);
}
END_TEST

START_TEST(test_s21_sub_9) {
  s21_decimal value, value2, rez_function, rez_sub_in_our_head;
  int result_int;
  //+4 - -5 = 1
  value.bits[0] = 4;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0b00000000000000000000000000000000;
  value2.bits[0] = 5;
  value2.bits[1] = 0;
  value2.bits[2] = 0;
  value2.bits[3] = 0b10000000000000000000000000000000;
  result_int = s21_sub(value, value2, &rez_function);

  rez_sub_in_our_head.bits[0] = 9;
  rez_sub_in_our_head.bits[1] = 0;
  rez_sub_in_our_head.bits[2] = 0;
  rez_sub_in_our_head.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(rez_function.bits[0], rez_sub_in_our_head.bits[0]);
  ck_assert_int_eq(rez_function.bits[1], rez_sub_in_our_head.bits[1]);
  ck_assert_int_eq(rez_function.bits[2], rez_sub_in_our_head.bits[2]);
  ck_assert_int_eq(rez_function.bits[3], rez_sub_in_our_head.bits[3]);
  ck_assert_int_eq(result_int, 0);
}
END_TEST

START_TEST(test_s21_sub_10) {
  s21_decimal value, value2, rez_function, rez_sub_in_our_head;
  int result_int;
  // 2.2 - 1.5 = 0.7
  value.bits[0] = 22;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0b00000000000000010000000000000000;
  value2.bits[0] = 150;
  value2.bits[1] = 0;
  value2.bits[2] = 0;
  value2.bits[3] = 0b00000000000000010000000000000000;
  result_int = s21_sub(value, value2, &rez_function);

  rez_sub_in_our_head.bits[0] = 128;
  rez_sub_in_our_head.bits[1] = 0;
  rez_sub_in_our_head.bits[2] = 0;
  rez_sub_in_our_head.bits[3] = 0b10000000000000010000000000000000;
  ck_assert_int_eq(rez_function.bits[0], rez_sub_in_our_head.bits[0]);
  ck_assert_int_eq(rez_function.bits[1], rez_sub_in_our_head.bits[1]);
  ck_assert_int_eq(rez_function.bits[2], rez_sub_in_our_head.bits[2]);
  ck_assert_int_eq(rez_function.bits[3], rez_sub_in_our_head.bits[3]);
  ck_assert_int_eq(result_int, 0);
}
END_TEST

START_TEST(test_s21_sub_11) {
  s21_decimal value, value2, rez_function, rez_sub_in_our_head;
  int result_int;
  // 4 - 4 = 0
  value.bits[0] = 4;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0b00000000000000000000000000000000;
  value2.bits[0] = 4;
  value2.bits[1] = 0;
  value2.bits[2] = 0;
  value2.bits[3] = 0b00000000000000000000000000000000;
  result_int = s21_sub(value, value2, &rez_function);
  rez_sub_in_our_head.bits[0] = 0;
  rez_sub_in_our_head.bits[1] = 0;
  rez_sub_in_our_head.bits[2] = 0;
  rez_sub_in_our_head.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(rez_function.bits[0], rez_sub_in_our_head.bits[0]);
  ck_assert_int_eq(rez_function.bits[1], rez_sub_in_our_head.bits[1]);
  ck_assert_int_eq(rez_function.bits[2], rez_sub_in_our_head.bits[2]);
  ck_assert_int_eq(rez_function.bits[3], rez_sub_in_our_head.bits[3]);
  ck_assert_int_eq(result_int, 0);
}
END_TEST

START_TEST(test_s21_sub_12) {
  s21_decimal value, value2, rez_function, rez_sub_in_our_head;
  int result_int;
  //-4 - -4 = 0
  value.bits[0] = 4;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0b10000000000000000000000000000000;
  value2.bits[0] = 4;
  value2.bits[1] = 0;
  value2.bits[2] = 0;
  value2.bits[3] = 0b10000000000000000000000000000000;
  result_int = s21_sub(value, value2, &rez_function);
  rez_sub_in_our_head.bits[0] = 0;
  rez_sub_in_our_head.bits[1] = 0;
  rez_sub_in_our_head.bits[2] = 0;
  rez_sub_in_our_head.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(rez_function.bits[0], rez_sub_in_our_head.bits[0]);
  ck_assert_int_eq(rez_function.bits[1], rez_sub_in_our_head.bits[1]);
  ck_assert_int_eq(rez_function.bits[2], rez_sub_in_our_head.bits[2]);
  ck_assert_int_eq(rez_function.bits[3], rez_sub_in_our_head.bits[3]);
  ck_assert_int_eq(result_int, 0);
}
END_TEST

START_TEST(test_s21_sub_13) {
  s21_decimal value, value2, rez_function, rez_sub_in_our_head;
  int result_int;
  // 4 - -4 = 0
  value.bits[0] = 4;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0b00000000000000000000000000000000;
  value2.bits[0] = 4;
  value2.bits[1] = 0;
  value2.bits[2] = 0;
  value2.bits[3] = 0b10000000000000000000000000000000;
  result_int = s21_sub(value, value2, &rez_function);

  rez_sub_in_our_head.bits[0] = 8;
  rez_sub_in_our_head.bits[1] = 0;
  rez_sub_in_our_head.bits[2] = 0;
  rez_sub_in_our_head.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(rez_function.bits[0], rez_sub_in_our_head.bits[0]);
  ck_assert_int_eq(rez_function.bits[1], rez_sub_in_our_head.bits[1]);
  ck_assert_int_eq(rez_function.bits[2], rez_sub_in_our_head.bits[2]);
  ck_assert_int_eq(rez_function.bits[3], rez_sub_in_our_head.bits[3]);
  ck_assert_int_eq(result_int, 0);
}
END_TEST

START_TEST(test_s21_sub_14) {
  s21_decimal value, value2, rez_function, rez_sub_in_our_head;
  int result_int;
  //-4 - 4 = 0
  value.bits[0] = 4;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0b10000000000000000000000000000000;
  value2.bits[0] = 4;
  value2.bits[1] = 0;
  value2.bits[2] = 0;
  value2.bits[3] = 0b0000000000000000000000000000000;
  result_int = s21_sub(value, value2, &rez_function);

  rez_sub_in_our_head.bits[0] = 8;
  rez_sub_in_our_head.bits[1] = 0;
  rez_sub_in_our_head.bits[2] = 0;
  rez_sub_in_our_head.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(rez_function.bits[0], rez_sub_in_our_head.bits[0]);
  ck_assert_int_eq(rez_function.bits[1], rez_sub_in_our_head.bits[1]);
  ck_assert_int_eq(rez_function.bits[2], rez_sub_in_our_head.bits[2]);
  ck_assert_int_eq(rez_function.bits[3], rez_sub_in_our_head.bits[3]);
  ck_assert_int_eq(result_int, 0);
}
END_TEST

START_TEST(test_s21_sub_15) {
  s21_decimal value, value2, rez_function;
  int result_int;
  // MAX
  value.bits[0] = 0b11111111111111111111111111111111;
  value.bits[1] = 0b11111111111111111111111111111111;
  value.bits[2] = 0b11111111111111111111111111111111;
  value.bits[3] = 0b00000000000000000000000000000000;
  value2.bits[0] = 0b11111111111111111111111111111111;
  value2.bits[1] = 0b11111111111111111111111111111111;
  value2.bits[2] = 0b11111111111111111111111111111111;
  value2.bits[3] = 0b10000000000000000000000000000000;
  result_int = s21_sub(value, value2, &rez_function);
  ck_assert_int_eq(result_int, 1);
}
END_TEST

START_TEST(test_s21_sub_16) {
  s21_decimal value, value2, rez_function;
  int result_int;
  // MAX
  value.bits[0] = 0b11111111111111111111111111111111;
  value.bits[1] = 0b11111111111111111111111111111111;
  value.bits[2] = 0b11111111111111111111111111111111;
  value.bits[3] = 0b10000000000000000000000000000000;
  value2.bits[0] = 0b11111111111111111111111111111111;
  value2.bits[1] = 0b11111111111111111111111111111111;
  value2.bits[2] = 0b11111111111111111111111111111111;
  value2.bits[3] = 0b00000000000000000000000000000000;
  result_int = s21_sub(value, value2, &rez_function);
  ck_assert_int_eq(result_int, 2);
}
END_TEST

START_TEST(test_s21_sub_17) {
  s21_decimal value, value2, rez_function, rez_sub_in_our_head;
  int result_int;
  // MAX_INT - MAX_INT
  value.bits[0] = 0b11111111111111111111111111111111;
  value.bits[1] = 0b00000000000000000000000000000000;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b00000000000000000000000000000000;

  value2.bits[0] = 0b11111111111111111111111111111111;
  value2.bits[1] = 0b00000000000000000000000000000000;
  value2.bits[2] = 0b00000000000000000000000000000000;
  value2.bits[3] = 0b00000000000000000000000000000000;
  result_int = s21_sub(value, value2, &rez_function);

  rez_sub_in_our_head.bits[0] = 0;
  rez_sub_in_our_head.bits[1] = 0;
  rez_sub_in_our_head.bits[2] = 0;
  rez_sub_in_our_head.bits[3] = 0;
  ck_assert_int_eq(rez_function.bits[0], rez_sub_in_our_head.bits[0]);
  ck_assert_int_eq(rez_function.bits[1], rez_sub_in_our_head.bits[1]);
  ck_assert_int_eq(rez_function.bits[2], rez_sub_in_our_head.bits[2]);
  ck_assert_int_eq(rez_function.bits[3], rez_sub_in_our_head.bits[3]);
  ck_assert_int_eq(result_int, 0);
}
END_TEST

START_TEST(test_s21_sub_18) {
  s21_decimal value, value2, rez_function, rez_sub_in_our_head;
  int result_int;
  // MAX_INT - MAX_INT
  value.bits[0] = 0xFFFFFFFF;
  value.bits[1] = 0xFFFFFFFF;
  value.bits[2] = 0xFFFFFFFF;
  value.bits[3] = 0b00000000000000000000000000000000;

  value2.bits[0] = 6;
  value2.bits[1] = 0;
  value2.bits[2] = 0;
  value2.bits[3] = 1 << 16;
  result_int = s21_sub(value, value2, &rez_function);

  rez_sub_in_our_head.bits[0] = 0xFFFFFFFE;
  rez_sub_in_our_head.bits[1] = 0xFFFFFFFF;
  rez_sub_in_our_head.bits[2] = 0xFFFFFFFF;
  rez_sub_in_our_head.bits[3] = 0;
  ck_assert_int_eq(rez_function.bits[0], rez_sub_in_our_head.bits[0]);
  ck_assert_int_eq(rez_function.bits[1], rez_sub_in_our_head.bits[1]);
  ck_assert_int_eq(rez_function.bits[2], rez_sub_in_our_head.bits[2]);
  ck_assert_int_eq(rez_function.bits[3], rez_sub_in_our_head.bits[3]);
  ck_assert_int_eq(result_int, 0);
}
END_TEST

START_TEST(test_s21_negate_1) {
  s21_decimal value, rez_function, rez_negate_in_our_head;
  int result_int;
  //+123456
  value.bits[0] = 123456;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0b00000000000000110000000000000000;
  result_int = s21_negate(value, &rez_function);

  rez_negate_in_our_head.bits[0] = 123456;
  rez_negate_in_our_head.bits[1] = 0;
  rez_negate_in_our_head.bits[2] = 0;
  rez_negate_in_our_head.bits[3] = 0b10000000000000110000000000000000;
  ck_assert_int_eq(rez_negate_in_our_head.bits[0], rez_function.bits[0]);
  ck_assert_int_eq(rez_negate_in_our_head.bits[1], rez_function.bits[1]);
  ck_assert_int_eq(rez_negate_in_our_head.bits[2], rez_function.bits[2]);
  ck_assert_int_eq(rez_negate_in_our_head.bits[3], rez_function.bits[3]);
  ck_assert_int_eq(result_int, 0);
}
END_TEST

START_TEST(test_s21_negate_2) {
  s21_decimal value, rez_function, rez_negate_in_our_head;
  int result_int;
  //-123456
  value.bits[0] = 123456;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0b10000000000000110000000000000000;
  result_int = s21_negate(value, &rez_function);

  rez_negate_in_our_head.bits[0] = 123456;
  rez_negate_in_our_head.bits[1] = 0;
  rez_negate_in_our_head.bits[2] = 0;
  rez_negate_in_our_head.bits[3] = 0b00000000000000110000000000000000;
  ck_assert_int_eq(rez_negate_in_our_head.bits[0], rez_function.bits[0]);
  ck_assert_int_eq(rez_negate_in_our_head.bits[1], rez_function.bits[1]);
  ck_assert_int_eq(rez_negate_in_our_head.bits[2], rez_function.bits[2]);
  ck_assert_int_eq(rez_negate_in_our_head.bits[3], rez_function.bits[3]);
  ck_assert_int_eq(result_int, 0);
}
END_TEST

START_TEST(test_s21_negate_3) {
  s21_decimal value, rez_function, rez_negate_in_our_head;
  int result_int;
  // +2.2
  value.bits[0] = 22;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0b00000000000000010000000000000000;
  result_int = s21_negate(value, &rez_function);

  rez_negate_in_our_head.bits[0] = 22;
  rez_negate_in_our_head.bits[1] = 0;
  rez_negate_in_our_head.bits[2] = 0;
  rez_negate_in_our_head.bits[3] = 0b10000000000000010000000000000000;
  ck_assert_int_eq(rez_function.bits[0], rez_negate_in_our_head.bits[0]);
  ck_assert_int_eq(rez_function.bits[1], rez_negate_in_our_head.bits[1]);
  ck_assert_int_eq(rez_function.bits[2], rez_negate_in_our_head.bits[2]);
  ck_assert_int_eq(rez_function.bits[3], rez_negate_in_our_head.bits[3]);
  ck_assert_int_eq(result_int, 0);
}
END_TEST

START_TEST(test_s21_negate_4) {
  s21_decimal value, rez_function, rez_negate_in_our_head;
  int result_int;
  // -2.2
  value.bits[0] = 22;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0b10000000000000010000000000000000;
  result_int = s21_negate(value, &rez_function);

  rez_negate_in_our_head.bits[0] = 22;
  rez_negate_in_our_head.bits[1] = 0;
  rez_negate_in_our_head.bits[2] = 0;
  rez_negate_in_our_head.bits[3] = 0b00000000000000010000000000000000;
  ck_assert_int_eq(rez_function.bits[0], rez_negate_in_our_head.bits[0]);
  ck_assert_int_eq(rez_function.bits[1], rez_negate_in_our_head.bits[1]);
  ck_assert_int_eq(rez_function.bits[2], rez_negate_in_our_head.bits[2]);
  ck_assert_int_eq(rez_function.bits[3], rez_negate_in_our_head.bits[3]);
  ck_assert_int_eq(result_int, 0);
}
END_TEST

START_TEST(test_s21_negate_5) {
  s21_decimal value, rez_function, rez_negate_in_our_head;
  int result_int;
  // MAXBIT
  value.bits[0] = MAXBITS;
  value.bits[1] = MAXBITS;
  value.bits[2] = MAXBITS;
  value.bits[3] = 0b10000000000000000000000000000000;
  result_int = s21_negate(value, &rez_function);

  rez_negate_in_our_head.bits[0] = MAXBITS;
  rez_negate_in_our_head.bits[1] = MAXBITS;
  rez_negate_in_our_head.bits[2] = MAXBITS;
  rez_negate_in_our_head.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(rez_function.bits[0], rez_negate_in_our_head.bits[0]);
  ck_assert_int_eq(rez_function.bits[1], rez_negate_in_our_head.bits[1]);
  ck_assert_int_eq(rez_function.bits[2], rez_negate_in_our_head.bits[2]);
  ck_assert_int_eq(rez_function.bits[3], rez_negate_in_our_head.bits[3]);
  ck_assert_int_eq(result_int, 0);
}
END_TEST

START_TEST(test_s21_negate_6) {
  s21_decimal value;
  int result_int;
  result_int = s21_negate(value, NULL);
  ck_assert_int_eq(result_int, 1);
}
END_TEST

START_TEST(test_s21_negate_7) {
  s21_decimal value, rez_function, rez_negate_in_our_head;
  int result_int;
  //-123456
  value.bits[0] = 123456;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0b10000000000000000000000000000000;
  result_int = s21_negate(value, &rez_function);

  rez_negate_in_our_head.bits[0] = 123456;
  rez_negate_in_our_head.bits[1] = 0;
  rez_negate_in_our_head.bits[2] = 0;
  rez_negate_in_our_head.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(rez_negate_in_our_head.bits[0], rez_function.bits[0]);
  ck_assert_int_eq(rez_negate_in_our_head.bits[1], rez_function.bits[1]);
  ck_assert_int_eq(rez_negate_in_our_head.bits[2], rez_function.bits[2]);
  ck_assert_int_eq(rez_negate_in_our_head.bits[3], rez_function.bits[3]);
  ck_assert_int_eq(result_int, 0);
}
END_TEST

START_TEST(test_s21_negate_8) {
  s21_decimal value, rez_function, rez_negate_in_our_head;
  int result_int;
  // 123456
  value.bits[0] = 123456;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0b00000000000000000000000000000000;
  result_int = s21_negate(value, &rez_function);

  rez_negate_in_our_head.bits[0] = 123456;
  rez_negate_in_our_head.bits[1] = 0;
  rez_negate_in_our_head.bits[2] = 0;
  rez_negate_in_our_head.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(rez_negate_in_our_head.bits[0], rez_function.bits[0]);
  ck_assert_int_eq(rez_negate_in_our_head.bits[1], rez_function.bits[1]);
  ck_assert_int_eq(rez_negate_in_our_head.bits[2], rez_function.bits[2]);
  ck_assert_int_eq(rez_negate_in_our_head.bits[3], rez_function.bits[3]);
  ck_assert_int_eq(result_int, 0);
}
END_TEST

START_TEST(test_s21_truncate_1) {
  s21_decimal value, rez_function, rez_truncate_in_our_head;
  int result_int;

  //+123.456
  value.bits[0] = 123456;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0b00000000000000110000000000000000;
  result_int = s21_truncate(value, &rez_function);

  rez_truncate_in_our_head.bits[0] = 123;
  rez_truncate_in_our_head.bits[1] = 0;
  rez_truncate_in_our_head.bits[2] = 0;
  rez_truncate_in_our_head.bits[3] = 0;
  ck_assert_int_eq(rez_truncate_in_our_head.bits[0], rez_function.bits[0]);
  ck_assert_int_eq(rez_truncate_in_our_head.bits[1], rez_function.bits[1]);
  ck_assert_int_eq(rez_truncate_in_our_head.bits[2], rez_function.bits[2]);
  ck_assert_int_eq(rez_truncate_in_our_head.bits[3], rez_function.bits[3]);
  ck_assert_int_eq(result_int, 0);
}
END_TEST

START_TEST(test_s21_truncate_2) {
  s21_decimal value, rez_function, rez_truncate_in_our_head;
  int result_int;
  //-8.7734
  value.bits[0] = 87734;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0b10000000000001000000000000000000;
  result_int = s21_truncate(value, &rez_function);

  rez_truncate_in_our_head.bits[0] = 8;
  rez_truncate_in_our_head.bits[1] = 0;
  rez_truncate_in_our_head.bits[2] = 0;
  rez_truncate_in_our_head.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(rez_truncate_in_our_head.bits[0], rez_function.bits[0]);
  ck_assert_int_eq(rez_truncate_in_our_head.bits[1], rez_function.bits[1]);
  ck_assert_int_eq(rez_truncate_in_our_head.bits[2], rez_function.bits[2]);
  ck_assert_int_eq(rez_truncate_in_our_head.bits[3], rez_function.bits[3]);
  ck_assert_int_eq(result_int, 0);
  result_int = s21_truncate(value, NULL);
  ck_assert_int_eq(result_int, 1);
}
END_TEST

START_TEST(test_s21_truncate_3) {
  s21_decimal value, rez_function;
  int result_int;
  // 1
  value.bits[0] = 23;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0b00000000000111110000000000000000;
  result_int = s21_truncate(value, &rez_function);
  ck_assert_int_eq(result_int, 1);
}
END_TEST

START_TEST(test_s21_truncate_4) {
  s21_decimal value, rez_function, rez_truncate_in_our_head;
  int result_int;
  // 12
  value.bits[0] = 12;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0b00000000000000000000000000000000;
  result_int = s21_truncate(value, &rez_function);

  rez_truncate_in_our_head.bits[0] = 12;
  rez_truncate_in_our_head.bits[1] = 0;
  rez_truncate_in_our_head.bits[2] = 0;
  rez_truncate_in_our_head.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(rez_truncate_in_our_head.bits[0], rez_function.bits[0]);
  ck_assert_int_eq(rez_truncate_in_our_head.bits[1], rez_function.bits[1]);
  ck_assert_int_eq(rez_truncate_in_our_head.bits[2], rez_function.bits[2]);
  ck_assert_int_eq(rez_truncate_in_our_head.bits[3], rez_function.bits[3]);
  ck_assert_int_eq(result_int, 0);
}
END_TEST

START_TEST(test_s21_truncate_5) {
  s21_decimal value, rez_function, rez_truncate_in_our_head;
  int result_int;
  //-12
  value.bits[0] = 12;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0b10000000000000000000000000000000;
  result_int = s21_truncate(value, &rez_function);

  rez_truncate_in_our_head.bits[0] = 12;
  rez_truncate_in_our_head.bits[1] = 0;
  rez_truncate_in_our_head.bits[2] = 0;
  rez_truncate_in_our_head.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(rez_truncate_in_our_head.bits[0], rez_function.bits[0]);
  ck_assert_int_eq(rez_truncate_in_our_head.bits[1], rez_function.bits[1]);
  ck_assert_int_eq(rez_truncate_in_our_head.bits[2], rez_function.bits[2]);
  ck_assert_int_eq(rez_truncate_in_our_head.bits[3], rez_function.bits[3]);
  ck_assert_int_eq(result_int, 0);
}
END_TEST

START_TEST(test_s21_round) {
  s21_decimal value = {0}, rez_function = {0}, rez_round_in_our_head = {0};
  int result_int = 0;
  //+123.456
  value.bits[0] = 123456;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0b00000000000000110000000000000000;
  result_int = s21_round(value, &rez_function);

  rez_round_in_our_head.bits[0] = 123;
  rez_round_in_our_head.bits[1] = 0;
  rez_round_in_our_head.bits[2] = 0;
  rez_round_in_our_head.bits[3] = 0;
  ck_assert_int_eq(rez_round_in_our_head.bits[0], rez_function.bits[0]);
  ck_assert_int_eq(rez_round_in_our_head.bits[1], rez_function.bits[1]);
  ck_assert_int_eq(rez_round_in_our_head.bits[2], rez_function.bits[2]);
  ck_assert_int_eq(rez_round_in_our_head.bits[3], rez_function.bits[3]);
  ck_assert_int_eq(result_int, 0);

  //-566.45
  value.bits[0] = 56645;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0b10000000000001000000000000000000;
  result_int = s21_round(value, &rez_function);

  rez_round_in_our_head.bits[0] = 6;
  rez_round_in_our_head.bits[1] = 0;
  rez_round_in_our_head.bits[2] = 0;
  rez_round_in_our_head.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(rez_round_in_our_head.bits[0], rez_function.bits[0]);
  ck_assert_int_eq(rez_round_in_our_head.bits[1], rez_function.bits[1]);
  ck_assert_int_eq(rez_round_in_our_head.bits[2], rez_function.bits[2]);
  ck_assert_int_eq(rez_round_in_our_head.bits[3], rez_function.bits[3]);
  ck_assert_int_eq(result_int, 0);

  // 1.1
  value.bits[0] = 11;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0b10000000000000010000000000000000;
  result_int = s21_round(value, &rez_function);

  rez_round_in_our_head.bits[0] = 1;
  rez_round_in_our_head.bits[1] = 0;
  rez_round_in_our_head.bits[2] = 0;
  rez_round_in_our_head.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(rez_round_in_our_head.bits[0], rez_function.bits[0]);
  ck_assert_int_eq(rez_round_in_our_head.bits[1], rez_function.bits[1]);
  ck_assert_int_eq(rez_round_in_our_head.bits[2], rez_function.bits[2]);
  ck_assert_int_eq(rez_round_in_our_head.bits[3], rez_function.bits[3]);
  ck_assert_int_eq(result_int, 0);

  //-0.14
  value.bits[0] = 14;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0b10000000000000110000000000000000;
  result_int = s21_round(value, &rez_function);

  rez_round_in_our_head.bits[0] = 0;
  rez_round_in_our_head.bits[1] = 0;
  rez_round_in_our_head.bits[2] = 0;
  rez_round_in_our_head.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(rez_round_in_our_head.bits[0], rez_function.bits[0]);
  ck_assert_int_eq(rez_round_in_our_head.bits[1], rez_function.bits[1]);
  ck_assert_int_eq(rez_round_in_our_head.bits[2], rez_function.bits[2]);
  ck_assert_int_eq(rez_round_in_our_head.bits[3], rez_function.bits[3]);
  ck_assert_int_eq(result_int, 0);
  result_int = s21_round(value, NULL);
  ck_assert_int_eq(result_int, 1);

  // 12
  value.bits[0] = 12;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0b00000000000000000000000000000000;
  result_int = s21_round(value, &rez_function);

  rez_round_in_our_head.bits[0] = 12;
  rez_round_in_our_head.bits[1] = 0;
  rez_round_in_our_head.bits[2] = 0;
  rez_round_in_our_head.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(rez_round_in_our_head.bits[0], rez_function.bits[0]);
  ck_assert_int_eq(rez_round_in_our_head.bits[1], rez_function.bits[1]);
  ck_assert_int_eq(rez_round_in_our_head.bits[2], rez_function.bits[2]);
  ck_assert_int_eq(rez_round_in_our_head.bits[3], rez_function.bits[3]);
  ck_assert_int_eq(result_int, 0);

  //-12
  value.bits[0] = 12;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0b10000000000000000000000000000000;
  result_int = s21_round(value, &rez_function);

  rez_round_in_our_head.bits[0] = 12;
  rez_round_in_our_head.bits[1] = 0;
  rez_round_in_our_head.bits[2] = 0;
  rez_round_in_our_head.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(rez_round_in_our_head.bits[0], rez_function.bits[0]);
  ck_assert_int_eq(rez_round_in_our_head.bits[1], rez_function.bits[1]);
  ck_assert_int_eq(rez_round_in_our_head.bits[2], rez_function.bits[2]);
  ck_assert_int_eq(rez_round_in_our_head.bits[3], rez_function.bits[3]);
  ck_assert_int_eq(result_int, 0);

  //тест не понятен
  // 1
  value.bits[0] = 22;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0b00000000000111110000000000000000;
  int d = 0;
  s21_from_decimal_to_int(value, &d);
  float f = 0;
  s21_from_decimal_to_float(value, &f);
  result_int = s21_round(value, &rez_function);
  ck_assert_int_eq(result_int, 1);
}
END_TEST

START_TEST(test_s21_floor) {
  s21_decimal value, rez_function, rez_floor_in_our_head;
  int result_int;

  //+123.456
  value.bits[0] = 123456;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0b00000000000000110000000000000000;
  result_int = s21_floor(value, &rez_function);

  rez_floor_in_our_head.bits[0] = 123;
  rez_floor_in_our_head.bits[1] = 0;
  rez_floor_in_our_head.bits[2] = 0;
  rez_floor_in_our_head.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(rez_floor_in_our_head.bits[0], rez_function.bits[0]);
  ck_assert_int_eq(rez_floor_in_our_head.bits[1], rez_function.bits[1]);
  ck_assert_int_eq(rez_floor_in_our_head.bits[2], rez_function.bits[2]);
  ck_assert_int_eq(rez_floor_in_our_head.bits[3], rez_function.bits[3]);
  ck_assert_int_eq(result_int, 0);

  //-566.45
  value.bits[0] = 56645;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0b10000000000001000000000000000000;
  result_int = s21_floor(value, &rez_function);

  rez_floor_in_our_head.bits[0] = 6;
  rez_floor_in_our_head.bits[1] = 0;
  rez_floor_in_our_head.bits[2] = 0;
  rez_floor_in_our_head.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(rez_floor_in_our_head.bits[0], rez_function.bits[0]);
  ck_assert_int_eq(rez_floor_in_our_head.bits[1], rez_function.bits[1]);
  ck_assert_int_eq(rez_floor_in_our_head.bits[2], rez_function.bits[2]);
  ck_assert_int_eq(rez_floor_in_our_head.bits[3], rez_function.bits[3]);
  ck_assert_int_eq(result_int, 0);

  //-1.1
  value.bits[0] = 11;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0b10000000000000010000000000000000;
  result_int = s21_floor(value, &rez_function);

  rez_floor_in_our_head.bits[0] = 2;
  rez_floor_in_our_head.bits[1] = 0;
  rez_floor_in_our_head.bits[2] = 0;
  rez_floor_in_our_head.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(rez_floor_in_our_head.bits[0], rez_function.bits[0]);
  ck_assert_int_eq(rez_floor_in_our_head.bits[1], rez_function.bits[1]);
  ck_assert_int_eq(rez_floor_in_our_head.bits[2], rez_function.bits[2]);
  ck_assert_int_eq(rez_floor_in_our_head.bits[3], rez_function.bits[3]);
  ck_assert_int_eq(result_int, 0);

  //-0.23
  value.bits[0] = 23;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0b10000000000000100000000000000000;
  result_int = s21_floor(value, &rez_function);

  rez_floor_in_our_head.bits[0] = 1;
  rez_floor_in_our_head.bits[1] = 0;
  rez_floor_in_our_head.bits[2] = 0;
  rez_floor_in_our_head.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(rez_floor_in_our_head.bits[0], rez_function.bits[0]);
  ck_assert_int_eq(rez_floor_in_our_head.bits[1], rez_function.bits[1]);
  ck_assert_int_eq(rez_floor_in_our_head.bits[2], rez_function.bits[2]);
  ck_assert_int_eq(rez_floor_in_our_head.bits[3], rez_function.bits[3]);
  ck_assert_int_eq(result_int, 0);

  //-12
  value.bits[0] = 12;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0b10000000000000000000000000000000;
  result_int = s21_floor(value, &rez_function);

  rez_floor_in_our_head.bits[0] = 12;
  rez_floor_in_our_head.bits[1] = 0;
  rez_floor_in_our_head.bits[2] = 0;
  rez_floor_in_our_head.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(rez_floor_in_our_head.bits[0], rez_function.bits[0]);
  ck_assert_int_eq(rez_floor_in_our_head.bits[1], rez_function.bits[1]);
  ck_assert_int_eq(rez_floor_in_our_head.bits[2], rez_function.bits[2]);
  ck_assert_int_eq(rez_floor_in_our_head.bits[3], rez_function.bits[3]);
  ck_assert_int_eq(result_int, 0);

  // 1
  value.bits[0] = 22;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0b00000000000111110000000000000000;
  result_int = s21_floor(value, &rez_function);
  ck_assert_int_eq(result_int, 1);

  // null
  result_int = s21_floor(value, NULL);
  ck_assert_int_eq(result_int, 1);
}
END_TEST

START_TEST(test_s21_mul_1) {
  s21_decimal test_decimal1, test_decimal2, test_decimal_result,
      test_decimal_result_in_function;
  test_decimal1.bits[0] = 2;
  test_decimal1.bits[1] = 0;
  test_decimal1.bits[2] = 0;
  test_decimal1.bits[3] = 0;
  test_decimal2.bits[0] = 2;
  test_decimal2.bits[1] = 0;
  test_decimal2.bits[2] = 0;
  test_decimal2.bits[3] = 0;
  test_decimal_result_in_function.bits[0] = 4;
  test_decimal_result_in_function.bits[1] = 0;
  test_decimal_result_in_function.bits[2] = 0;
  test_decimal_result_in_function.bits[3] = 0;
  int result_function =
      s21_mul(test_decimal1, test_decimal2, &test_decimal_result);
  ck_assert_int_eq(test_decimal_result_in_function.bits[0],
                   test_decimal_result.bits[0]);
  ck_assert_int_eq(test_decimal_result_in_function.bits[1],
                   test_decimal_result.bits[1]);
  ck_assert_int_eq(test_decimal_result_in_function.bits[2],
                   test_decimal_result.bits[2]);
  ck_assert_int_eq(test_decimal_result_in_function.bits[3],
                   test_decimal_result.bits[3]);
  ck_assert_int_eq(result_function, 0);
}
END_TEST

START_TEST(test_s21_mul_2) {
  s21_decimal test_decimal1, test_decimal2, test_decimal_result,
      test_decimal_result_in_function;
  test_decimal1.bits[0] = 2;
  test_decimal1.bits[1] = 0;
  test_decimal1.bits[2] = 0;
  test_decimal1.bits[3] = 0b10000000000000000000000000000000;
  test_decimal2.bits[0] = 2;
  test_decimal2.bits[1] = 0;
  test_decimal2.bits[2] = 0;
  test_decimal2.bits[3] = 0b00000000000000000000000000000000;
  test_decimal_result_in_function.bits[0] = 4;
  test_decimal_result_in_function.bits[1] = 0;
  test_decimal_result_in_function.bits[2] = 0;
  test_decimal_result_in_function.bits[3] = 0b10000000000000000000000000000000;
  int result_function =
      s21_mul(test_decimal1, test_decimal2, &test_decimal_result);
  ck_assert_int_eq(test_decimal_result_in_function.bits[0],
                   test_decimal_result.bits[0]);
  ck_assert_int_eq(test_decimal_result_in_function.bits[1],
                   test_decimal_result.bits[1]);
  ck_assert_int_eq(test_decimal_result_in_function.bits[2],
                   test_decimal_result.bits[2]);
  ck_assert_int_eq(test_decimal_result_in_function.bits[3],
                   test_decimal_result.bits[3]);
  ck_assert_int_eq(test_decimal_result_in_function.bits[3],
                   test_decimal_result.bits[3]);
  ck_assert_int_eq(result_function, 0);
}
END_TEST

START_TEST(test_s21_mul_3) {
  s21_decimal test_decimal1, test_decimal2, test_decimal_result,
      test_decimal_result_in_function;
  test_decimal1.bits[0] = 2;
  test_decimal1.bits[1] = 0;
  test_decimal1.bits[2] = 0;
  test_decimal1.bits[3] = 0b10000000000000000000000000000000;
  test_decimal2.bits[0] = 2;
  test_decimal2.bits[1] = 0;
  test_decimal2.bits[2] = 0;
  test_decimal2.bits[3] = 0b10000000000000000000000000000000;
  test_decimal_result_in_function.bits[0] = 4;
  test_decimal_result_in_function.bits[1] = 0;
  test_decimal_result_in_function.bits[2] = 0;
  test_decimal_result_in_function.bits[3] = 0b0000000000000000000000000000000;
  int result_function =
      s21_mul(test_decimal1, test_decimal2, &test_decimal_result);
  ck_assert_int_eq(test_decimal_result_in_function.bits[0],
                   test_decimal_result.bits[0]);
  ck_assert_int_eq(test_decimal_result_in_function.bits[1],
                   test_decimal_result.bits[1]);
  ck_assert_int_eq(test_decimal_result_in_function.bits[2],
                   test_decimal_result.bits[2]);
  ck_assert_int_eq(test_decimal_result_in_function.bits[3],
                   test_decimal_result.bits[3]);
  ck_assert_int_eq(result_function, 0);
}
END_TEST
START_TEST(test_s21_mul_4) {
  s21_decimal test_decimal1, test_decimal2, test_decimal_result,
      test_decimal_result_in_function;
  test_decimal1.bits[0] = 0b00000000000000000000000000000010;
  test_decimal1.bits[1] = 0b00000000000000000000000000000000;
  test_decimal1.bits[2] = 0b00000000000000000000000000000000;
  test_decimal1.bits[3] = 0b00000000000000000000000000000000;
  test_decimal2.bits[0] = 0b00000000000000000000000000000010;
  test_decimal2.bits[1] = 0b00000000000000000000000000000000;
  test_decimal2.bits[2] = 0b00000000000000000000000000000000;
  test_decimal2.bits[3] = 0b00000000000000000000000000000000;
  test_decimal_result_in_function.bits[0] = 0b00000000000000000000000000000100;
  test_decimal_result_in_function.bits[1] = 0b00000000000000000000000000000000;
  test_decimal_result_in_function.bits[2] = 0b00000000000000000000000000000000;
  test_decimal_result_in_function.bits[3] = 0b00000000000000000000000000000000;
  int result_function =
      s21_mul(test_decimal1, test_decimal2, &test_decimal_result);
  ck_assert_int_eq(test_decimal_result_in_function.bits[0],
                   test_decimal_result.bits[0]);
  ck_assert_int_eq(test_decimal_result_in_function.bits[1],
                   test_decimal_result.bits[1]);
  ck_assert_int_eq(test_decimal_result_in_function.bits[2],
                   test_decimal_result.bits[2]);
  ck_assert_int_eq(test_decimal_result_in_function.bits[3],
                   test_decimal_result.bits[3]);
  ck_assert_int_eq(test_decimal_result_in_function.bits[3],
                   test_decimal_result.bits[3]);
  ck_assert_int_eq(result_function, 0);
}
END_TEST
START_TEST(test_s21_mul_5) {
  s21_decimal test_decimal1, test_decimal2, test_decimal_result,
      test_decimal_result_in_function;
  test_decimal1.bits[0] = 15;
  test_decimal1.bits[1] = 0;
  test_decimal1.bits[2] = 0;
  test_decimal1.bits[3] = 0;
  test_decimal2.bits[0] = 30;
  test_decimal2.bits[1] = 0;
  test_decimal2.bits[2] = 0;
  test_decimal2.bits[3] = 0;
  test_decimal_result_in_function.bits[0] = 450;
  test_decimal_result_in_function.bits[1] = 0;
  test_decimal_result_in_function.bits[2] = 0;
  test_decimal_result_in_function.bits[3] = 0;
  int result_function =
      s21_mul(test_decimal1, test_decimal2, &test_decimal_result);
  ck_assert_int_eq(test_decimal_result_in_function.bits[0],
                   test_decimal_result.bits[0]);
  ck_assert_int_eq(test_decimal_result_in_function.bits[1],
                   test_decimal_result.bits[1]);
  ck_assert_int_eq(test_decimal_result_in_function.bits[2],
                   test_decimal_result.bits[2]);
  ck_assert_int_eq(test_decimal_result_in_function.bits[3],
                   test_decimal_result.bits[3]);
  ck_assert_int_eq(result_function, 0);
}
END_TEST
START_TEST(test_s21_mul_6) {
  s21_decimal test_decimal1, test_decimal2, test_decimal_result,
      test_decimal_result_in_function;
  test_decimal1.bits[0] = 2100;
  test_decimal1.bits[1] = 0;
  test_decimal1.bits[2] = 0;
  test_decimal1.bits[3] = 0;
  test_decimal2.bits[0] = 234;
  test_decimal2.bits[1] = 0;
  test_decimal2.bits[2] = 0;
  test_decimal2.bits[3] = 0;
  test_decimal_result_in_function.bits[0] = 491400;
  test_decimal_result_in_function.bits[1] = 0;
  test_decimal_result_in_function.bits[2] = 0;
  test_decimal_result_in_function.bits[3] = 0;
  int result_function =
      s21_mul(test_decimal1, test_decimal2, &test_decimal_result);
  ck_assert_int_eq(test_decimal_result_in_function.bits[0],
                   test_decimal_result.bits[0]);
  ck_assert_int_eq(test_decimal_result_in_function.bits[1],
                   test_decimal_result.bits[1]);
  ck_assert_int_eq(test_decimal_result_in_function.bits[2],
                   test_decimal_result.bits[2]);
  ck_assert_int_eq(test_decimal_result_in_function.bits[3],
                   test_decimal_result.bits[3]);
  ck_assert_int_eq(result_function, 0);
}
END_TEST
START_TEST(test_s21_mul_7) {
  s21_decimal test_decimal1, test_decimal2, test_decimal_result,
      test_decimal_result_in_function;
  test_decimal1.bits[0] = 2100;
  test_decimal1.bits[1] = 0;
  test_decimal1.bits[2] = 0;
  test_decimal1.bits[3] = 0;
  test_decimal2.bits[0] = 234;
  test_decimal2.bits[1] = 0;
  test_decimal2.bits[2] = 0;
  test_decimal2.bits[3] = 0;
  test_decimal_result_in_function.bits[0] = 491400;
  test_decimal_result_in_function.bits[1] = 0;
  test_decimal_result_in_function.bits[2] = 0;
  test_decimal_result_in_function.bits[3] = 0;
  int result_function =
      s21_mul(test_decimal1, test_decimal2, &test_decimal_result);
  ck_assert_int_eq(test_decimal_result_in_function.bits[0],
                   test_decimal_result.bits[0]);
  ck_assert_int_eq(test_decimal_result_in_function.bits[1],
                   test_decimal_result.bits[1]);
  ck_assert_int_eq(test_decimal_result_in_function.bits[2],
                   test_decimal_result.bits[2]);
  ck_assert_int_eq(test_decimal_result_in_function.bits[3],
                   test_decimal_result.bits[3]);
  ck_assert_int_eq(result_function, 0);
}
END_TEST
START_TEST(test_s21_mul_8) {
  s21_decimal test_decimal1, test_decimal2, test_decimal_result;
  test_decimal1.bits[0] = MAX_INT;  // 1111111111111111111111111111111
  test_decimal1.bits[1] = MAX_INT;
  test_decimal1.bits[2] = 0;
  test_decimal1.bits[3] = 0;
  test_decimal2.bits[0] = MAX_INT;
  test_decimal2.bits[1] = MAX_INT;
  test_decimal2.bits[2] = 0;
  test_decimal2.bits[3] = 0;
  int result_function =
      s21_mul(test_decimal1, test_decimal2, &test_decimal_result);
  // 1111111111111111111111111111
  // 11111111111111111111111111111111
  // 10000000000000000000000000000000
  // 00000000000000000000000000000001
  ck_assert_int_eq(result_function, 1);
}
END_TEST
START_TEST(test_s21_mul_9) {
  s21_decimal test_decimal1, test_decimal2, test_decimal_result;
  test_decimal1.bits[0] = MAX_INT;  // 1111111111111111111111111111111
  test_decimal1.bits[1] = MAX_INT;
  test_decimal1.bits[2] = 0;
  test_decimal1.bits[3] = 0;
  test_decimal2.bits[0] = MAX_INT;
  test_decimal2.bits[1] = MAX_INT;
  test_decimal2.bits[2] = 0;
  test_decimal2.bits[3] = 0b10000000000000000000000000000000;
  int result_function =
      s21_mul(test_decimal1, test_decimal2, &test_decimal_result);
  // 1111111111111111111111111111
  // 11111111111111111111111111111111
  // 10000000000000000000000000000000
  // 00000000000000000000000000000001
  ck_assert_int_eq(result_function, 2);
}
END_TEST
START_TEST(test_s21_mul_10) {
  s21_decimal test_decimal1, test_decimal2, test_decimal_result;
  test_decimal1.bits[0] = MAX_INT;
  test_decimal1.bits[1] = MAX_INT;
  test_decimal1.bits[2] = 0;
  test_decimal1.bits[3] = 0;
  test_decimal2.bits[0] = MAX_INT;
  test_decimal2.bits[1] = MAX_INT;
  test_decimal2.bits[2] = 0;
  test_decimal2.bits[3] = 0b00000000000000000000000000000000;
  int result_function =
      s21_mul(test_decimal1, test_decimal2, &test_decimal_result);
  ck_assert_int_eq(result_function, 1);
}
END_TEST
START_TEST(test_s21_mul_11) {
  s21_decimal test_decimal1, test_decimal2, test_decimal_result;
  test_decimal1.bits[0] = 0b11111111111111111111111111111111;
  test_decimal1.bits[1] = 0;
  test_decimal1.bits[2] = 0;
  test_decimal1.bits[3] = 0;
  test_decimal2.bits[0] = 2;
  test_decimal2.bits[1] = 0;
  test_decimal2.bits[2] = 0;
  test_decimal2.bits[3] = 0b00000000000000000000000000000000;
  int result_function =
      s21_mul(test_decimal1, test_decimal2, &test_decimal_result);
  ck_assert_int_eq(result_function, 0);
}
END_TEST

START_TEST(test_s21_mul_12) {
  s21_decimal test_decimal1, test_decimal2, test_decimal_result;
  test_decimal1.bits[0] = 0b11111111111111111111111111111111;
  test_decimal1.bits[1] = 0;
  test_decimal1.bits[2] = 0;
  test_decimal1.bits[3] = 0b00000000000111110000000000000000;
  test_decimal2.bits[0] = 2;
  test_decimal2.bits[1] = 0;
  test_decimal2.bits[2] = 0;
  test_decimal2.bits[3] = 0b000000000011111100000000000000000;
  int result_function =
      s21_mul(test_decimal1, test_decimal2, &test_decimal_result);
  ck_assert_int_eq(result_function, 0);
}
END_TEST

START_TEST(test_s21_div) {
  s21_decimal test_decimal_1, test_decimal_2, test_decimal_result,
      test_decimal_result_in_function;
  int result_function;
  (void)result_function;
  test_decimal_1.bits[0] = 4;
  test_decimal_1.bits[1] = 0;
  test_decimal_1.bits[2] = 0;
  test_decimal_1.bits[3] = 0;
  test_decimal_2.bits[0] = 2;
  test_decimal_2.bits[1] = 0;
  test_decimal_2.bits[2] = 0;
  test_decimal_2.bits[3] = 0;
  test_decimal_result_in_function.bits[0] = 2;
  test_decimal_result_in_function.bits[1] = 0;
  test_decimal_result_in_function.bits[2] = 0;
  test_decimal_result_in_function.bits[3] = 0;
  result_function =
      s21_div(test_decimal_1, test_decimal_2, &test_decimal_result);
  ck_assert_int_eq(test_decimal_result.bits[0],
                   test_decimal_result_in_function.bits[0]);
  ck_assert_int_eq(test_decimal_result.bits[1],
                   test_decimal_result_in_function.bits[1]);
  ck_assert_int_eq(test_decimal_result.bits[2],
                   test_decimal_result_in_function.bits[2]);
  ck_assert_int_eq(test_decimal_result.bits[3],
                   test_decimal_result_in_function.bits[3]);

  test_decimal_1.bits[0] = 128;
  test_decimal_1.bits[1] = 0;
  test_decimal_1.bits[2] = 0;
  test_decimal_1.bits[3] = 0;
  test_decimal_2.bits[0] = 2;
  test_decimal_2.bits[1] = 0;
  test_decimal_2.bits[2] = 0;
  test_decimal_2.bits[3] = 0;
  test_decimal_result_in_function.bits[0] = 64;
  test_decimal_result_in_function.bits[1] = 0;
  test_decimal_result_in_function.bits[2] = 0;
  test_decimal_result_in_function.bits[3] = 0;
  result_function =
      s21_div(test_decimal_1, test_decimal_2, &test_decimal_result);
  ck_assert_int_eq(test_decimal_result.bits[0],
                   test_decimal_result_in_function.bits[0]);
  ck_assert_int_eq(test_decimal_result.bits[1],
                   test_decimal_result_in_function.bits[1]);
  ck_assert_int_eq(test_decimal_result.bits[2],
                   test_decimal_result_in_function.bits[2]);
  ck_assert_int_eq(test_decimal_result.bits[3],
                   test_decimal_result_in_function.bits[3]);

  test_decimal_1.bits[0] = 131072;
  test_decimal_1.bits[1] = 0;
  test_decimal_1.bits[2] = 0;
  test_decimal_1.bits[3] = 0;
  test_decimal_2.bits[0] = 16;
  test_decimal_2.bits[1] = 0;
  test_decimal_2.bits[2] = 0;
  test_decimal_2.bits[3] = 0;
  test_decimal_result_in_function.bits[0] = 8192;
  test_decimal_result_in_function.bits[1] = 0;
  test_decimal_result_in_function.bits[2] = 0;
  test_decimal_result_in_function.bits[3] = 0;
  result_function =
      s21_div(test_decimal_1, test_decimal_2, &test_decimal_result);
  ck_assert_int_eq(test_decimal_result.bits[0],
                   test_decimal_result_in_function.bits[0]);
  ck_assert_int_eq(test_decimal_result.bits[1],
                   test_decimal_result_in_function.bits[1]);
  ck_assert_int_eq(test_decimal_result.bits[2],
                   test_decimal_result_in_function.bits[2]);
  ck_assert_int_eq(test_decimal_result.bits[3],
                   test_decimal_result_in_function.bits[3]);

  test_decimal_1.bits[0] = 15;
  test_decimal_1.bits[1] = 0;
  test_decimal_1.bits[2] = 0;
  test_decimal_1.bits[3] = 0;
  test_decimal_2.bits[0] = 15;
  test_decimal_2.bits[1] = 0;
  test_decimal_2.bits[2] = 0;
  test_decimal_2.bits[3] = 0;
  test_decimal_result_in_function.bits[0] = 1;
  test_decimal_result_in_function.bits[1] = 0;
  test_decimal_result_in_function.bits[2] = 0;
  test_decimal_result_in_function.bits[3] = 0;
  result_function =
      s21_div(test_decimal_1, test_decimal_2, &test_decimal_result);
  ck_assert_int_eq(test_decimal_result.bits[0],
                   test_decimal_result_in_function.bits[0]);
  ck_assert_int_eq(test_decimal_result.bits[1],
                   test_decimal_result_in_function.bits[1]);
  ck_assert_int_eq(test_decimal_result.bits[2],
                   test_decimal_result_in_function.bits[2]);
  ck_assert_int_eq(test_decimal_result.bits[3],
                   test_decimal_result_in_function.bits[3]);

  test_decimal_1.bits[0] = 123456789;
  test_decimal_1.bits[1] = 0;
  test_decimal_1.bits[2] = 0;
  test_decimal_1.bits[3] = 0;
  test_decimal_2.bits[0] = 123456789;
  test_decimal_2.bits[1] = 0;
  test_decimal_2.bits[2] = 0;
  test_decimal_2.bits[3] = 0;
  test_decimal_result_in_function.bits[0] = 1;
  test_decimal_result_in_function.bits[1] = 0;
  test_decimal_result_in_function.bits[2] = 0;
  test_decimal_result_in_function.bits[3] = 0;
  result_function =
      s21_div(test_decimal_1, test_decimal_2, &test_decimal_result);
  ck_assert_int_eq(test_decimal_result.bits[0],
                   test_decimal_result_in_function.bits[0]);
  ck_assert_int_eq(test_decimal_result.bits[1],
                   test_decimal_result_in_function.bits[1]);
  ck_assert_int_eq(test_decimal_result.bits[2],
                   test_decimal_result_in_function.bits[2]);
  ck_assert_int_eq(test_decimal_result.bits[3],
                   test_decimal_result_in_function.bits[3]);

  test_decimal_1.bits[0] = 0b00000000000000000000010000000000;
  test_decimal_1.bits[1] = 0;
  test_decimal_1.bits[2] = 0;
  test_decimal_1.bits[3] = 0;
  test_decimal_2.bits[0] = 0b00000000000000000000000000000010;
  test_decimal_2.bits[1] = 0;
  test_decimal_2.bits[2] = 0;
  test_decimal_2.bits[3] = 0;
  test_decimal_result_in_function.bits[0] = 0b00000000000000000000001000000000;
  test_decimal_result_in_function.bits[1] = 0;
  test_decimal_result_in_function.bits[2] = 0;
  test_decimal_result_in_function.bits[3] = 0;
  result_function =
      s21_div(test_decimal_1, test_decimal_2, &test_decimal_result);
  ck_assert_int_eq(test_decimal_result.bits[0],
                   test_decimal_result_in_function.bits[0]);
  ck_assert_int_eq(test_decimal_result.bits[1],
                   test_decimal_result_in_function.bits[1]);
  ck_assert_int_eq(test_decimal_result.bits[2],
                   test_decimal_result_in_function.bits[2]);
  ck_assert_int_eq(test_decimal_result.bits[3],
                   test_decimal_result_in_function.bits[3]);

  test_decimal_1.bits[0] = 0;
  test_decimal_1.bits[1] = 0;
  test_decimal_1.bits[2] = 0b00000000000000000000010000000000;
  test_decimal_1.bits[3] = 0;
  test_decimal_2.bits[0] = 0;
  test_decimal_2.bits[1] = 0;
  test_decimal_2.bits[2] = 0b00000000000000000000010000000000;
  test_decimal_2.bits[3] = 0;
  test_decimal_result_in_function.bits[0] = 1;
  test_decimal_result_in_function.bits[1] = 0;
  test_decimal_result_in_function.bits[2] = 0;
  test_decimal_result_in_function.bits[3] = 0;
  result_function =
      s21_div(test_decimal_1, test_decimal_2, &test_decimal_result);
  ck_assert_int_eq(test_decimal_result.bits[0],
                   test_decimal_result_in_function.bits[0]);
  ck_assert_int_eq(test_decimal_result.bits[1],
                   test_decimal_result_in_function.bits[1]);
  ck_assert_int_eq(test_decimal_result.bits[2],
                   test_decimal_result_in_function.bits[2]);
  ck_assert_int_eq(test_decimal_result.bits[3],
                   test_decimal_result_in_function.bits[3]);
}
END_TEST

START_TEST(test_mul_13) {
  s21_decimal num1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 28 << 16}},
              num2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 28 << 16}},
              num3 = {{0}},
              result = {{158262358, 0x359A3B3E, 0xCAD2F7F5, 27 << 16}};
  int code = s21_mul(num1, num2, &num3);
  ck_assert_int_eq(num3.bits[0], result.bits[0]);
  ck_assert_int_eq(num3.bits[1], result.bits[1]);
  ck_assert_int_eq(num3.bits[2], result.bits[2]);
  ck_assert_int_eq(num3.bits[3], result.bits[3]);
  ck_assert_int_eq(code, 0);
}
END_TEST

int main() {
  Suite *suite = suite_create("TEST");
  TCase *tCase = tcase_create("TEST");
  SRunner *sRunner = srunner_create(suite);

  double FAILED = 0;
  suite_add_tcase(suite, tCase);

  tcase_add_test(tCase, test_mul_13);
  tcase_add_test(tCase, test_21_comparison_s21_is_equal_1);
  tcase_add_test(tCase, test_21_comparison_s21_is_equal_2);
  tcase_add_test(tCase, test_21_comparison_s21_is_equal_3);
  tcase_add_test(tCase, test_21_comparison_s21_is_equal_4);
  tcase_add_test(tCase, test_21_comparison_s21_is_equal_5);
  tcase_add_test(tCase, test_21_comparison_s21_is_equal_6);
  tcase_add_test(tCase, test_21_comparison_s21_is_equal_7);
  tcase_add_test(tCase, test_21_comparison_s21_is_equal_8);
  tcase_add_test(tCase, test_21_comparison_s21_is_equal_9);
  tcase_add_test(tCase, test_21_comparison_s21_is_equal_10);
  tcase_add_test(tCase, test_21_comparison_s21_is_equal_11);
  tcase_add_test(tCase, test_21_comparison_s21_is_equal_12);
  tcase_add_test(tCase, test_21_comparison_s21_is_equal_13);
  tcase_add_test(tCase, test_21_comparison_s21_is_equal_14);
  tcase_add_test(tCase, test_21_comparison_s21_is_equal_15);
  tcase_add_test(tCase, test_21_comparison_s21_is_not_equal_1);
  tcase_add_test(tCase, test_21_comparison_s21_is_not_equal_2);
  tcase_add_test(tCase, test_21_comparison_s21_is_not_equal_3);
  tcase_add_test(tCase, test_21_comparison_s21_is_not_equal_4);
  tcase_add_test(tCase, test_21_comparison_s21_is_not_equal_5);
  tcase_add_test(tCase, test_21_comparison_s21_is_not_equal_6);
  tcase_add_test(tCase, test_21_comparison_s21_is_not_equal_7);
  tcase_add_test(tCase, test_21_comparison_s21_is_not_equal_8);
  tcase_add_test(tCase, test_21_comparison_s21_is_not_equal_9);
  tcase_add_test(tCase, test_21_comparison_s21_is_not_equal_10);
  tcase_add_test(tCase, test_21_comparison_s21_is_not_equal_11);
  tcase_add_test(tCase, test_21_comparison_s21_is_not_equal_12);
  tcase_add_test(tCase, test_21_comparison_s21_is_not_equal_13);
  tcase_add_test(tCase, test_21_comparison_s21_is_not_equal_14);
  tcase_add_test(tCase, test_21_comparison_s21_is_not_equal_15);
  tcase_add_test(tCase, test_s21_is_less_1);
  tcase_add_test(tCase, test_s21_is_less_2);
  tcase_add_test(tCase, test_s21_is_less_3);
  tcase_add_test(tCase, test_s21_is_less_4);
  tcase_add_test(tCase, test_s21_is_less_5);
  tcase_add_test(tCase, test_s21_is_less_6);
  tcase_add_test(tCase, test_s21_is_less_7);
  tcase_add_test(tCase, test_s21_is_less_8);
  tcase_add_test(tCase, test_s21_is_less_9);
  tcase_add_test(tCase, test_s21_is_less_10);
  tcase_add_test(tCase, test_s21_is_less_11);
  tcase_add_test(tCase, test_s21_is_less_12);
  tcase_add_test(tCase, test_s21_is_less_13);
  tcase_add_test(tCase, test_s21_is_less_14);
  tcase_add_test(tCase, test_s21_is_less_15);
  tcase_add_test(tCase, test_s21_is_less_16);
  tcase_add_test(tCase, test_s21_is_less_17);
  tcase_add_test(tCase, test_s21_is_less_18);
  tcase_add_test(tCase, test_s21_is_less_19);
  tcase_add_test(tCase, test_s21_is_less_20);
  tcase_add_test(tCase, test_s21_is_less_21);
  tcase_add_test(tCase, test_s21_is_less_or_equal_1);
  tcase_add_test(tCase, test_s21_is_less_or_equal_2);
  tcase_add_test(tCase, test_s21_is_less_or_equal_3);
  tcase_add_test(tCase, test_s21_is_less_or_equal_4);
  tcase_add_test(tCase, test_s21_is_less_or_equal_5);
  tcase_add_test(tCase, test_s21_is_less_or_equal_6);
  tcase_add_test(tCase, test_s21_is_less_or_equal_7);
  tcase_add_test(tCase, test_s21_is_less_or_equal_8);
  tcase_add_test(tCase, test_s21_is_less_or_equal_9);
  tcase_add_test(tCase, test_s21_is_less_or_equal_10);
  tcase_add_test(tCase, test_s21_is_less_or_equal_11);
  tcase_add_test(tCase, test_s21_is_less_or_equal_12);
  tcase_add_test(tCase, test_s21_is_less_or_equal_13);
  tcase_add_test(tCase, test_s21_is_less_or_equal_14);
  tcase_add_test(tCase, test_s21_is_less_or_equal_15);
  tcase_add_test(tCase, test_s21_is_less_or_equal_16);
  tcase_add_test(tCase, test_s21_is_less_or_equal_17);
  tcase_add_test(tCase, test_s21_is_less_or_equal_18);
  tcase_add_test(tCase, test_s21_is_less_or_equal_19);
  tcase_add_test(tCase, test_s21_is_less_or_equal_20);
  tcase_add_test(tCase, test_s21_is_less_or_equal_21);
  tcase_add_test(tCase, test_s21_is_less_or_equal_22);
  tcase_add_test(tCase, test_s21_is_less_or_equal_23);
  tcase_add_test(tCase, test_s21_is_greater_1);
  tcase_add_test(tCase, test_s21_is_greater_2);
  tcase_add_test(tCase, test_s21_is_greater_3);
  tcase_add_test(tCase, test_s21_is_greater_4);
  tcase_add_test(tCase, test_s21_is_greater_5);
  tcase_add_test(tCase, test_s21_is_greater_6);
  tcase_add_test(tCase, test_s21_is_greater_7);
  tcase_add_test(tCase, test_s21_is_greater_8);
  tcase_add_test(tCase, test_s21_is_greater_9);
  tcase_add_test(tCase, test_s21_is_greater_10);
  tcase_add_test(tCase, test_s21_is_greater_11);
  tcase_add_test(tCase, test_s21_is_greater_12);
  tcase_add_test(tCase, test_s21_is_greater_13);
  tcase_add_test(tCase, test_s21_is_greater_14);
  tcase_add_test(tCase, test_s21_is_greater_15);
  tcase_add_test(tCase, test_s21_is_greater_16);
  tcase_add_test(tCase, test_s21_is_greater_17);
  tcase_add_test(tCase, test_s21_is_greater_18);
  tcase_add_test(tCase, test_s21_is_greater_19);
  tcase_add_test(tCase, test_s21_is_greater_20);
  tcase_add_test(tCase, test_s21_is_greater_21);
  tcase_add_test(tCase, test_s21_is_greater_22);
  tcase_add_test(tCase, test_s21_is_greater_23);
  tcase_add_test(tCase, test_s21_is_greater_24);
  tcase_add_test(tCase, test_s21_is_greater_25);
  tcase_add_test(tCase, test_s21_is_greater_26);
  tcase_add_test(tCase, test_s21_is_greater_27);
  tcase_add_test(tCase, test_s21_is_greater_28);
  tcase_add_test(tCase, test_s21_is_greater_29);
  tcase_add_test(tCase, test_s21_is_greater_30);
  tcase_add_test(tCase, test_s21_is_greater_31);
  tcase_add_test(tCase, test_s21_is_greater_32);
  tcase_add_test(tCase, test_s21_is_greater_33);
  tcase_add_test(tCase, test_s21_is_greater_34);
  tcase_add_test(tCase, test_s21_is_greater_35);
  tcase_add_test(tCase, test_s21_is_greater_36);
  tcase_add_test(tCase, test_s21_is_greater_37);
  tcase_add_test(tCase, test_s21_is_greater_38);
  tcase_add_test(tCase, test_s21_is_greater_39);
  tcase_add_test(tCase, test_s21_is_greater_40);
  tcase_add_test(tCase, test_s21_is_greater_41);
  tcase_add_test(tCase, test_s21_is_greater_42);
  tcase_add_test(tCase, test_s21_is_greater_or_equal_1);
  tcase_add_test(tCase, test_s21_is_greater_or_equal_2);
  tcase_add_test(tCase, test_s21_is_greater_or_equal_3);
  tcase_add_test(tCase, test_s21_is_greater_or_equal_4);
  tcase_add_test(tCase, test_s21_is_greater_or_equal_5);
  tcase_add_test(tCase, test_s21_is_greater_or_equal_6);
  tcase_add_test(tCase, test_s21_is_greater_or_equal_7);
  tcase_add_test(tCase, test_s21_is_greater_or_equal_8);
  tcase_add_test(tCase, test_s21_is_greater_or_equal_9);
  tcase_add_test(tCase, test_s21_is_greater_or_equal_10);
  tcase_add_test(tCase, test_s21_is_greater_or_equal_11);
  tcase_add_test(tCase, test_s21_is_greater_or_equal_12);
  tcase_add_test(tCase, test_s21_is_greater_or_equal_13);
  tcase_add_test(tCase, test_s21_is_greater_or_equal_14);
  tcase_add_test(tCase, test_s21_is_greater_or_equal_15);
  tcase_add_test(tCase, test_s21_is_greater_or_equal_16);
  tcase_add_test(tCase, test_s21_is_greater_or_equal_17);
  tcase_add_test(tCase, test_s21_is_greater_or_equal_18);
  tcase_add_test(tCase, test_s21_is_greater_or_equal_19);
  tcase_add_test(tCase, test_s21_is_greater_or_equal_20);
  tcase_add_test(tCase, test_s21_is_greater_or_equal_21);
  tcase_add_test(tCase, test_s21_is_greater_or_equal_22);
  tcase_add_test(tCase, test_s21_is_greater_or_equal_23);
  tcase_add_test(tCase, test_s21_is_greater_or_equal_24);
  tcase_add_test(tCase, test_s21_is_greater_or_equal_25);
  tcase_add_test(tCase, test_s21_is_greater_or_equal_26);
  tcase_add_test(tCase, test_s21_is_greater_or_equal_27);
  tcase_add_test(tCase, test_s21_is_greater_or_equal_28);
  tcase_add_test(tCase, test_s21_is_greater_or_equal_29);
  tcase_add_test(tCase, test_s21_is_greater_or_equal_30);
  tcase_add_test(tCase, test_s21_is_greater_or_equal_31);
  tcase_add_test(tCase, test_s21_is_greater_or_equal_32);
  tcase_add_test(tCase, test_s21_is_greater_or_equal_33);
  tcase_add_test(tCase, test_s21_is_greater_or_equal_34);

  tcase_add_test(tCase, test_s21_from_int_to_decimal);
  tcase_add_test(tCase, test_s21_from_decimal_to_int_1);
  tcase_add_test(tCase, test_s21_from_decimal_to_int_2);
  tcase_add_test(tCase, test_s21_from_decimal_to_int_3);
  tcase_add_test(tCase, test_s21_from_decimal_to_int_4);
  tcase_add_test(tCase, test_s21_from_decimal_to_int_5);
  tcase_add_test(tCase, test_s21_from_decimal_to_int_6);
  tcase_add_test(tCase, test_s21_from_decimal_to_int_7);
  tcase_add_test(tCase, test_s21_from_decimal_to_int_8);
  tcase_add_test(tCase, test_s21_from_float_to_decimal_1);
  tcase_add_test(tCase, test_s21_from_float_to_decimal_2);
  tcase_add_test(tCase, test_s21_from_float_to_decimal_3);
  tcase_add_test(tCase, test_s21_from_float_to_decimal_4);
  tcase_add_test(tCase, test_s21_from_float_to_decimal_5);
  tcase_add_test(tCase, test_s21_from_float_to_decimal_6);
  tcase_add_test(tCase, test_s21_from_decimal_to_float_1);
  tcase_add_test(tCase, test_s21_from_decimal_to_float_2);
  tcase_add_test(tCase, test_s21_from_decimal_to_float_3);
  tcase_add_test(tCase, test_s21_from_decimal_to_float_4);
  tcase_add_test(tCase, test_s21_from_decimal_to_float_5);

  tcase_add_test(tCase, test_s21_mul_1);
  tcase_add_test(tCase, test_s21_mul_2);
  tcase_add_test(tCase, test_s21_mul_3);
  tcase_add_test(tCase, test_s21_mul_4);
  tcase_add_test(tCase, test_s21_mul_5);
  tcase_add_test(tCase, test_s21_mul_6);
  tcase_add_test(tCase, test_s21_mul_7);
  tcase_add_test(tCase, test_s21_mul_8);
  tcase_add_test(tCase, test_s21_mul_9);
  tcase_add_test(tCase, test_s21_mul_10);
  tcase_add_test(tCase, test_s21_mul_11);
  tcase_add_test(tCase, test_s21_mul_12);

  tcase_add_test(tCase, test_s21_div);
  tcase_add_test(tCase, test_s21_add_1);
  tcase_add_test(tCase, test_s21_add_2);
  tcase_add_test(tCase, test_s21_add_3);
  tcase_add_test(tCase, test_s21_add_4);
  tcase_add_test(tCase, test_s21_add_5);
  tcase_add_test(tCase, test_s21_add_6);
  tcase_add_test(tCase, test_s21_add_7);
  tcase_add_test(tCase, test_s21_add_8);
  tcase_add_test(tCase, test_s21_add_9);
  tcase_add_test(tCase, test_s21_add_10);
  tcase_add_test(tCase, test_s21_add_11);
  tcase_add_test(tCase, test_s21_add_12);
  tcase_add_test(tCase, test_s21_add_13);
  tcase_add_test(tCase, test_s21_add_14);
  tcase_add_test(tCase, test_s21_add_15);
  tcase_add_test(tCase, test_s21_add_16);
  tcase_add_test(tCase, test_s21_sub_1);
  tcase_add_test(tCase, test_s21_sub_2);
  tcase_add_test(tCase, test_s21_sub_3);
  tcase_add_test(tCase, test_s21_sub_4);
  tcase_add_test(tCase, test_s21_sub_5);
  tcase_add_test(tCase, test_s21_sub_6);
  tcase_add_test(tCase, test_s21_sub_7);
  tcase_add_test(tCase, test_s21_sub_8);
  tcase_add_test(tCase, test_s21_sub_9);
  tcase_add_test(tCase, test_s21_sub_10);
  tcase_add_test(tCase, test_s21_sub_11);
  tcase_add_test(tCase, test_s21_sub_12);
  tcase_add_test(tCase, test_s21_sub_13);
  tcase_add_test(tCase, test_s21_sub_14);
  tcase_add_test(tCase, test_s21_sub_15);
  tcase_add_test(tCase, test_s21_sub_16);
  tcase_add_test(tCase, test_s21_sub_17);
  tcase_add_test(tCase, test_s21_sub_18);

  tcase_add_test(tCase, test_s21_negate_1);
  tcase_add_test(tCase, test_s21_negate_2);
  tcase_add_test(tCase, test_s21_negate_3);
  tcase_add_test(tCase, test_s21_negate_4);
  tcase_add_test(tCase, test_s21_negate_5);
  tcase_add_test(tCase, test_s21_negate_6);
  tcase_add_test(tCase, test_s21_negate_7);
  tcase_add_test(tCase, test_s21_negate_8);
  tcase_add_test(tCase, test_s21_truncate_1);
  tcase_add_test(tCase, test_s21_truncate_2);
  tcase_add_test(tCase, test_s21_truncate_3);
  tcase_add_test(tCase, test_s21_truncate_4);
  tcase_add_test(tCase, test_s21_truncate_5);

  tcase_add_test(tCase, test_s21_round);
  tcase_add_test(tCase, test_s21_floor);

  srunner_run_all(sRunner, CK_NORMAL);
  FAILED = srunner_ntests_failed(sRunner);
  srunner_free(sRunner);
  return !FAILED ? EXIT_SUCCESS : EXIT_FAILURE;
}
