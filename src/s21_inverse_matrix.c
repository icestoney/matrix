#include "s21_matrix.h"

// Обратная матрица
int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int err = OK;
  double det = 0.0;
  err = s21_determinant(A, &det);
  if ((matrix_is_correct(A) || result == NULL)) {
    err = INCORRECT_MATRIX;
  } else if (err == CALCULATION_ERROR || det == 0) {
    err = CALCULATION_ERROR;
  } else {
    double one_div_det = 1 / det;
    matrix_t comp_mtx = {0};
    err = s21_calc_complements(A, &comp_mtx);
    if (err == 0) {
      matrix_t comp_mtx_T = {0};
      s21_transpose(&comp_mtx, &comp_mtx_T);
      err = s21_mult_number(&comp_mtx_T, one_div_det, result);
      s21_remove_matrix(&comp_mtx_T);
    }
    s21_remove_matrix(&comp_mtx);
  }
  return err;
}
