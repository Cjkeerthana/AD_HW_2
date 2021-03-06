#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

void nonsq_naive_matrix_multiplication(float **C, float const *const *const A,
                                        float const *const *const B,
                                        const size_t m, const size_t k, const size_t n) 
{
  for (size_t y = 0; y < m; y++){
    for (size_t x = 0; x < n; x++){
      float value = 0.0;
      for (size_t z = 0; z < k; z++){
        value += A[y][z]*B[z][x];
      }
      C[y][x] = value;
    }
  }
  /*printf("naive\n");
    for(size_t x = 0; x < m; x++){
        for(size_t y = 0; y < n; y++){
        printf("%f\t", C[x][y]);
        }
        printf("\n");
  }*/
}

void naive_matrix_multiplication(float **C, float const *const *const A,
                                float const *const *const B,
                                const size_t n) 
{
  for (size_t y = 0; y < n; y++){
    for (size_t x = 0; x < n; x++){
      float value = 0.0;
      for (size_t z = 0; z < n; z++){
        value += A[y][z]*B[z][x];
      }
      C[y][x] = value;
    }
  }
}

int same_matrix(float const *const *const A, float const *const *const B,
                const size_t rows, const size_t cols) {
  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < cols; j++) {
      if (A[i][j] != B[i][j]) {
        return 0;
      }
    }
  }

  return 1;
}

float **allocate_matrix(const size_t rows, const size_t cols) {
  float **M = (float **)malloc(sizeof(float *) * rows);

  for (size_t i = 0; i < rows; i++) {
    M[i] = (float *)malloc(sizeof(float) * cols);
  }

  return M;
}

void deallocate_matrix(float **A, const size_t rows) {
  for (size_t i = 0; i < rows; i++) {
    free(A[i]);
  }

  free(A);
}

float **allocate_random_matrix(const size_t rows, const size_t cols) {
  
  float **A = allocate_matrix(rows, cols);
  
  srand(10);
  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < cols; j++) {
      A[i][j] = (rand() - RAND_MAX / 2) % 5;
    }
  }

  return A;
}

