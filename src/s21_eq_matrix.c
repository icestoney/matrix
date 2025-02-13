#include "s21_matrix.h"

// Сравнение матриц
int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int err = SUCCESS;
  if (matrix_is_correct(A) || matrix_is_correct(B)) {
    err = FAILURE;
  } else if (A->rows != B->rows || A->columns != B->columns) {
    err = FAILURE;
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-7) {
          err = FAILURE;
          i = A->rows;
          j = A->columns;
        }
      }
    }
  }
  return err;
}