#include "s21_matrix.h"

// Умножение двух матриц
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int err = OK;
  if (matrix_is_correct(A) || matrix_is_correct(B) || result == NULL) {
    err = INCORRECT_MATRIX;
  } else if (A->columns != B->rows) {
    err = CALCULATION_ERROR;
  } else {
    s21_create_matrix(A->rows, B->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        double sum = 0.0;
        for (int k = 0; k < A->columns; k++) {
          sum = sum + A->matrix[i][k] * B->matrix[k][j];
        }
        result->matrix[i][j] = sum;
      }
    }
  }
  return err;
}
