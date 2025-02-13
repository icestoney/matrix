#include "s21_matrix.h"

// Определитель матрицы
int s21_determinant(matrix_t *A, double *result) {
  int err = OK;
  if (matrix_is_correct(A) || result == NULL) {
    err = INCORRECT_MATRIX;
  } else if (A->rows != A->columns) {
    err = CALCULATION_ERROR;
  } else {
    if (A->rows == 1) {
      *result = A->matrix[0][0];
    } else if (A->rows == 2) {
      *result =
          A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
    } else {
      *result = 0.0;
      for (int j = 0; j < A->columns; j++) {
        matrix_t temp = s21_minor(A, 0, j);
        double temp_res = 0.0;
        s21_determinant(&temp, &temp_res);
        *result += pow(-1, 0 + j) * A->matrix[0][j] * temp_res;
        s21_remove_matrix(&temp);
      }
    }
  }
  return err;
}