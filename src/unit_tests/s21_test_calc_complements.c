#include "s21_test.h"

START_TEST(matrix_calc_complements_test_1) {
  static double array[1][1] = {{2}};
  int row = 1;
  int col = 1;
  matrix_t A = {0};
  matrix_t result = {0};
  s21_create_matrix(row, col, &A);
  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++) {
      A.matrix[i][j] = array[i][j];
    }
  ck_assert_int_eq(s21_calc_complements(&A, &result), CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(matrix_calc_complements_test_2) {
  static double array[3][3] = {{1, 2, 3}, {0, 4, 2}, {5, 2, 1}};
  static double array_res[3][3] = {{0, 10, -20}, {4, -14, 8}, {-8, -2, 4}};
  int row = 3;
  int col = 3;
  matrix_t A = {0};
  matrix_t res_check = {0};
  matrix_t result = {0};
  s21_create_matrix(row, col, &A);
  s21_create_matrix(row, col, &res_check);
  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++) {
      A.matrix[i][j] = array[i][j];
      res_check.matrix[i][j] = array_res[i][j];
    }
  ck_assert_int_eq(s21_calc_complements(&A, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&res_check, &result), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res_check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(matrix_calc_complements_test_3) {
  static double array[2][2] = {{2.36, 4.59}, {2.3, 15}};
  static double array_res[2][2] = {{15, -2.3}, {-4.59, 2.36}};
  int row = 2;
  int col = 2;
  matrix_t A = {0};
  matrix_t res_check = {0};
  matrix_t result = {0};
  s21_create_matrix(row, col, &A);
  s21_create_matrix(row, col, &res_check);
  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++) {
      A.matrix[i][j] = array[i][j];
      res_check.matrix[i][j] = array_res[i][j];
    }
  ck_assert_int_eq(s21_calc_complements(&A, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&res_check, &result), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res_check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(matrix_calc_complements_test_4) {
  matrix_t A = {0};
  matrix_t result = {0};
  ck_assert_int_eq(s21_calc_complements(&A, &result), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(matrix_calc_complements_test_5) {
  static double array[3][2] = {{1, 2}, {0, 4}, {5, 2}};
  int row = 3;
  int col = 2;
  matrix_t A = {0};
  matrix_t result = {0};
  s21_create_matrix(row, col, &A);
  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++) {
      A.matrix[i][j] = array[i][j];
    }
  ck_assert_int_eq(s21_calc_complements(&A, &result), CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(matrix_calc_complements_test_6) {
  static double array[2][1] = {{2}, {5}};
  int row = 2;
  int col = 1;
  matrix_t A = {0};
  matrix_t result = {0};
  s21_create_matrix(row, col, &A);
  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++) {
      A.matrix[i][j] = array[i][j];
    }
  ck_assert_int_eq(s21_calc_complements(&A, &result), CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(matrix_calc_complements_test_7) {
  static double array[1][2] = {{2, 5}};
  int row = 1;
  int col = 2;
  matrix_t A = {0};
  matrix_t result = {0};
  s21_create_matrix(row, col, &A);
  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++) {
      A.matrix[i][j] = array[i][j];
    }
  ck_assert_int_eq(s21_calc_complements(&A, &result), CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(matrix_calc_complements_test_8) {
  static double array[3][3] = {{1, 2, 3}, {0, 4, 2}, {5, 2, 1}};
  int row = 3;
  int col = 3;
  matrix_t A = {0};
  s21_create_matrix(row, col, &A);
  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++) {
      A.matrix[i][j] = array[i][j];
    }
  ck_assert_int_eq(s21_calc_complements(&A, NULL), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

Suite *suite_s21_calc_complements(void) {
  Suite *s = suite_create("\033[42mS21_CALC_COMPLEMENTS\033[0m");
  TCase *tcase = tcase_create("create_tc");

  tcase_add_test(tcase, matrix_calc_complements_test_1);
  tcase_add_test(tcase, matrix_calc_complements_test_2);
  tcase_add_test(tcase, matrix_calc_complements_test_3);
  tcase_add_test(tcase, matrix_calc_complements_test_4);
  tcase_add_test(tcase, matrix_calc_complements_test_5);
  tcase_add_test(tcase, matrix_calc_complements_test_6);
  tcase_add_test(tcase, matrix_calc_complements_test_7);
  tcase_add_test(tcase, matrix_calc_complements_test_8);

  suite_add_tcase(s, tcase);
  return s;
}
