#include "s21_matrix.h"

// Создание матриц
int s21_create_matrix(int row, int col, matrix_t *result) {
  int err = OK;
  if (row <= 0 || col <= 0 || result == NULL) {
    err = INCORRECT_MATRIX;
  } else {
    result->rows = row;
    result->columns = col;
    result->matrix = (double **)calloc(result->rows, sizeof(double *));
    for (int i = 0; i < result->rows; i++) {
      result->matrix[i] = (double *)calloc(result->columns, sizeof(double));
    }
  }
  return err;
}