#include "s21_test.h"

START_TEST(matrix_detrminant_test_1) {
  static double array[1][1] = {{2}};
  double res_check = 2;
  int row = 1;
  int col = 1;
  matrix_t A = {0};
  double result = 0.0;
  s21_create_matrix(row, col, &A);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      A.matrix[i][j] = array[i][j];
    }
  }
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_int_eq(result, res_check);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(matrix_detrminant_test_2) {
  static double array[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  double res_check = 0;
  int row = 3;
  int col = 3;
  matrix_t A = {0};
  double result = 0.0;
  s21_create_matrix(row, col, &A);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      A.matrix[i][j] = array[i][j];
    }
  }
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_int_eq(result, res_check);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(matrix_detrminant_test_3) {
  static double array[4][4] = {{2.36, 4.59, 4.325, 0.364},
                               {2.3, 532, 45.786, 944.36},
                               {18, -2.36, -31.668, -565.22},
                               {22, 23, 24, 25}};
  double res_check = -13588029;
  int row = 4;
  int col = 4;
  matrix_t A = {0};
  double result = 0.0;
  s21_create_matrix(row, col, &A);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      A.matrix[i][j] = array[i][j];
    }
  }
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_int_eq(result, res_check);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(matrix_detrminant_test_4) {
  static double array[2][3] = {{2, 5, 7}, {6, 3, 4}};
  int row = 2;
  int col = 3;
  matrix_t A = {0};
  double result = 0.0;
  s21_create_matrix(row, col, &A);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      A.matrix[i][j] = array[i][j];
    }
  }
  ck_assert_int_eq(s21_determinant(&A, &result), CALCULATION_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(matrix_detrminant_test_5) {
  matrix_t A = {0};
  double result = 0.0;
  ck_assert_int_eq(s21_determinant(&A, &result), INCORRECT_MATRIX);
}
END_TEST

START_TEST(matrix_detrminant_test_6) {
  static double array[3][3] = {{1, 2, 8}, {0, 4, 9}, {5, 2, 3}};
  int row = 3;
  int col = 2;
  matrix_t A = {0};
  s21_create_matrix(row, col, &A);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      A.matrix[i][j] = array[i][j];
    }
  }
  ck_assert_int_eq(s21_transpose(&A, NULL), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

Suite *suite_s21_detrminant(void) {
  Suite *s = suite_create("\033[42mS21_DETERMINANT\033[0m");
  TCase *tcase = tcase_create("create_tc");

  tcase_add_test(tcase, matrix_detrminant_test_1);
  tcase_add_test(tcase, matrix_detrminant_test_2);
  tcase_add_test(tcase, matrix_detrminant_test_3);
  tcase_add_test(tcase, matrix_detrminant_test_4);
  tcase_add_test(tcase, matrix_detrminant_test_5);
  tcase_add_test(tcase, matrix_detrminant_test_6);

  suite_add_tcase(s, tcase);
  return s;
}
