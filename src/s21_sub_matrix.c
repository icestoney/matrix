#include "s21_matrix.h"

// Вычитание матриц
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  return s21_arithmetic_matrix(A, B, result, MINUS);
}