#include "s21_test.h"

START_TEST(matrix_sub_test_1) {
  static double array[3][3] = {{2, 5, 7}, {6, 3, 4}, {5, -2, -3}};
  static double array_res[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  int row = 3;
  int col = 3;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  matrix_t res_check = {0};
  s21_create_matrix(row, col, &A);
  s21_create_matrix(row, col, &B);
  s21_create_matrix(row, col, &res_check);
  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++) {
      A.matrix[i][j] = array[i][j];
      B.matrix[i][j] = array[i][j];
      res_check.matrix[i][j] = array_res[i][j];
    }
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&res_check, &result), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&res_check);
}
END_TEST

START_TEST(matrix_sub_test_2) {
  static double array_a[3][3] = {{2, 5, 7}, {6, 3, 4}, {5, -2, -3}};
  static double array_b[2][3] = {{2, 5, 7}, {6, 3, 4}};
  int row_a = 3;
  int col_a = 3;
  int row_b = 2;
  int col_b = 3;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  s21_create_matrix(row_a, col_a, &A);
  s21_create_matrix(row_b, col_b, &B);
  for (int i = 0; i < row_a; i++)
    for (int j = 0; j < col_a; j++) {
      A.matrix[i][j] = array_a[i][j];
    }
  for (int i = 0; i < row_b; i++) {
    for (int j = 0; j < col_b; j++) {
      B.matrix[i][j] = array_b[i][j];
    }
  }
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(matrix_sub_test_3) {
  static double array_b[3][3] = {{2, 5, 7}, {6, 3, 4}, {5, -2, -3}};
  static double array_a[2][3] = {{2, 5, 7}, {6, 3, 4}};
  int row_b = 3;
  int col_b = 3;
  int row_a = 2;
  int col_a = 3;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  s21_create_matrix(row_a, col_a, &A);
  s21_create_matrix(row_b, col_b, &B);
  for (int i = 0; i < row_a; i++)
    for (int j = 0; j < col_a; j++) {
      A.matrix[i][j] = array_a[i][j];
    }
  for (int i = 0; i < row_b; i++) {
    for (int j = 0; j < col_b; j++) {
      B.matrix[i][j] = array_b[i][j];
    }
  }
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(matrix_sub_test_4) {
  static double array_a[3][3] = {{2, 5, 7}, {6, 3, 4}, {5, -2, -3}};
  static double array_b[3][2] = {{2, 5}, {6, 3}, {5, -2}};
  int row_a = 3;
  int col_a = 3;
  int row_b = 3;
  int col_b = 2;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  s21_create_matrix(row_a, col_a, &A);
  s21_create_matrix(row_b, col_b, &B);
  for (int i = 0; i < row_a; i++)
    for (int j = 0; j < col_a; j++) {
      A.matrix[i][j] = array_a[i][j];
    }
  for (int i = 0; i < row_b; i++) {
    for (int j = 0; j < col_b; j++) {
      B.matrix[i][j] = array_b[i][j];
    }
  }
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(matrix_sub_test_5) {
  static double array_a[2][3] = {{2, 5, 7}, {6, 3, 4}};
  int row_a = 2;
  int col_a = 3;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  s21_create_matrix(row_a, col_a, &A);
  for (int i = 0; i < row_a; i++)
    for (int j = 0; j < col_a; j++) {
      A.matrix[i][j] = array_a[i][j];
    }
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(matrix_sub_test_6) {
  static double array_b[3][3] = {{2, 5, 7}, {6, 3, 4}, {5, -2, -3}};
  int row_b = 3;
  int col_b = 3;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  s21_create_matrix(row_b, col_b, &B);
  for (int i = 0; i < row_b; i++) {
    for (int j = 0; j < col_b; j++) {
      B.matrix[i][j] = array_b[i][j];
    }
  }
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(matrix_sub_test_7) {
  static double array_b[3][3] = {{2, 5, 7}, {6, 3, 4}, {5, -2, -3}};
  static double array_a[2][3] = {{2, 5, 7}, {6, 3, 4}};
  int row_b = 3;
  int col_b = 3;
  int row_a = 2;
  int col_a = 3;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  s21_create_matrix(row_a, col_a, &A);
  s21_create_matrix(row_b, col_b, &B);
  for (int i = 0; i < row_a; i++)
    for (int j = 0; j < col_a; j++) {
      A.matrix[i][j] = array_a[i][j];
    }
  for (int i = 0; i < row_b; i++) {
    for (int j = 0; j < col_b; j++) {
      B.matrix[i][j] = array_b[i][j];
    }
  }
  ck_assert_int_eq(s21_sub_matrix(&A, &B, NULL), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(matrix_sub_test_8) {
  static double array_a[3][3] = {{2.000000002, 5.000000002, 7.000000002},
                                 {6.000000002, 3.000000002, 4.000000002},
                                 {5.000000002, -2.000000002, -3.000000002}};
  static double array_b[3][3] = {{1.000000001, 1.000000001, 1.000000001},
                                 {1.000000001, 1.000000001, 1.000000001},
                                 {1.000000001, -1.000000001, -1.000000001}};
  static double array_res[3][3] = {{1.000000001, 4.000000001, 6.000000001},
                                   {5.000000001, 2.000000001, 3.000000001},
                                   {4.000000001, -1.000000001, -2.000000001}};
  int row = 3;
  int col = 3;
  matrix_t A;
  matrix_t B;
  matrix_t result;
  matrix_t result_chek;
  s21_create_matrix(row, col, &A);
  s21_create_matrix(row, col, &B);
  s21_create_matrix(row, col, &result_chek);
  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++) {
      A.matrix[i][j] = array_a[i][j];
      B.matrix[i][j] = array_b[i][j];
      result_chek.matrix[i][j] = array_res[i][j];
    }
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result_chek, &result), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&result_chek);
}
END_TEST

START_TEST(matrix_sub_test_9) {
  static double array_a[3][3] = {{2.0000002, 5.0000002, 7.0000002},
                                 {6.0000002, 3.0000002, 4.0000002},
                                 {5.0000002, -2.0000002, -3.0000002}};
  static double array_b[3][3] = {{1.0000001, 1.0000001, 1.0000001},
                                 {1.0000001, 1.0000001, 1.0000001},
                                 {1.0000001, -1.0000001, -1.0000001}};
  static double array_res[3][3] = {{1.0000001, 4.0000001, 6.0000001},
                                   {5.0000001, 2.0000001, 3.0000001},
                                   {4.0000001, -1.0000001, -2.0000001}};
  int row = 3;
  int col = 3;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  matrix_t result_chek = {0};
  s21_create_matrix(row, col, &A);
  s21_create_matrix(row, col, &B);
  s21_create_matrix(row, col, &result_chek);
  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++) {
      A.matrix[i][j] = array_a[i][j];
      B.matrix[i][j] = array_b[i][j];
      result_chek.matrix[i][j] = array_res[i][j];
    }
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result_chek, &result), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&result_chek);
}
END_TEST

Suite *suite_s21_sub_matrix(void) {
  Suite *s = suite_create("\033[42mS21_SUB_MATRIX\033[0m");
  TCase *tcase = tcase_create("create_tc");

  tcase_add_test(tcase, matrix_sub_test_1);
  tcase_add_test(tcase, matrix_sub_test_2);
  tcase_add_test(tcase, matrix_sub_test_3);
  tcase_add_test(tcase, matrix_sub_test_4);
  tcase_add_test(tcase, matrix_sub_test_5);
  tcase_add_test(tcase, matrix_sub_test_6);
  tcase_add_test(tcase, matrix_sub_test_7);
  tcase_add_test(tcase, matrix_sub_test_8);
  tcase_add_test(tcase, matrix_sub_test_9);

  suite_add_tcase(s, tcase);
  return s;
}
