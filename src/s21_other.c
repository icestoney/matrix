#include "s21_matrix.h"

// Проверка матрицы на корректность
int matrix_is_correct(matrix_t *A) {
  int err = OK;
  if (A->matrix == NULL || A->columns <= 0 || A->rows <= 0) {
    err = INCORRECT_MATRIX;
  }
  return err;
}

// Возвращает минор элемента
matrix_t s21_minor(matrix_t *A, int row, int col) {
  matrix_t result = {0};
  s21_create_matrix(A->rows - 1, A->columns - 1, &result);
  for (int i = 0, x = 0; i < A->rows; i++) {
    if (i == row) {
      continue;
    }
    for (int j = 0, y = 0; j < A->columns; j++) {
      if (j == col) {
        continue;
      }
      result.matrix[x][y] = A->matrix[i][j];
      y++;
    }
    x++;
  }
  return result;
}

// Сложение/вычитание матриц
int s21_arithmetic_matrix(matrix_t *A, matrix_t *B, matrix_t *result,
                          int sign) {
  int err = OK;
  if (matrix_is_correct(A) || matrix_is_correct(B) || result == NULL) {
    err = INCORRECT_MATRIX;
  } else if (A->rows != B->rows || A->columns != B->columns) {
    err = CALCULATION_ERROR;
  } else {
    s21_create_matrix(A->rows, A->columns, result);
    if (sign == MINUS) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
        }
      }
    } else {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
        }
      }
    }
  }
  return err;
}