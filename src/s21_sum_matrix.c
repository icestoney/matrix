#include "s21_matrix.h"

// Сложение матриц
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  return s21_arithmetic_matrix(A, B, result, PLUS);
}