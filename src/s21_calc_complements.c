#include "s21_matrix.h"

// Матрица алгебраических дополнений
int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int err = OK;
  if (matrix_is_correct(A) || result == NULL) {
    err = INCORRECT_MATRIX;
  } else if ((A->rows == 1 || A->columns == 1) || A->rows != A->columns) {
    err = CALCULATION_ERROR;
  } else {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        double minor_res = 0;
        matrix_t minor = s21_minor(A, i, j);
        err = s21_determinant(&minor, &minor_res);
        result->matrix[i][j] = pow(-1, i + j) * minor_res;
        s21_remove_matrix(&minor);
      }
    }
  }
  return err;
}