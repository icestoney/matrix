#include "s21_matrix.h"

// Транспонирование матрицы
int s21_transpose(matrix_t *A, matrix_t *result) {
  int err = OK;
  if (matrix_is_correct(A) || result == NULL) {
    err = INCORRECT_MATRIX;
  } else {
    s21_create_matrix(A->columns, A->rows, result);
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        result->matrix[i][j] = A->matrix[j][i];
      }
    }
  }
  return err;
}