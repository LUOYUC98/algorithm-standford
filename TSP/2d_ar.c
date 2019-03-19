#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "common.h"

void print_int_arr(int len, int*A){
  puts("buffer: ");
  for(int i = 0; i < len; i++){
    printf("%d ", A[i]);
  }
  puts("\n");
  
}


float_matrix_t* float_matrix_init(int ho, long ve){
  float_matrix_t* float_matrix = (float_matrix_t*)malloc(sizeof(float_matrix_t));
  float_matrix->arr = (float**)malloc(sizeof(float*)*ve);
  for(int i = 0; i<ve; i++){
    float_matrix->arr[i] = (float*)malloc(sizeof(float)*ho);
  }
  float_matrix->ho = ho;
  float_matrix->ve = ve;
  return float_matrix;
}

int_matrix_t* int_matrix_init(int ho, long ve){
  int_matrix_t* int_matrix = (int_matrix_t*)malloc(sizeof(int_matrix_t));
  int_matrix->arr = (int**)malloc(sizeof(int*)*ve);
  for(int i = 0; i<ve; i++){
    int_matrix->arr[i] = (int*)malloc(sizeof(int)*ho);
  }
  int_matrix->ho = ho;
  int_matrix->ve = ve;
  return int_matrix;
}


void float_matrix_cpy(float_matrix_t* A, float_matrix_t* B){
  for(long i = 0; i<B->ve; i++){
    for(int j = 0; j<B->ho; j++){
      A->arr[i][j] = B->arr[i][j];
    }
  }
}


void free_float_matrix(float_matrix_t* A){
  for(long i = 0; i < A->ve; i++){
      free(A->arr[i]);
  }
  free(A->arr);
  free(A);
}

void free_int_matrix(int_matrix_t* A){
  for(long i = 0; i < A->ve; i++){
    free(A->arr[i]);
  }
  free(A->arr);
  free(A);
}



void print_float_matrix(float_matrix_t* matrix){
  puts("matrix:\n");
  for(long i = 0; i<matrix->ve; i++){
    printf("%-2li: ", i);
    for(int j = 0; j<matrix->ho; j++){
      printf("%f | ", matrix->arr[i][j]);
    }
    putchar('\n');
  }
}


void print_int_matrix(int_matrix_t* matrix){
  puts("matrix:\n");
  //printf("hops = %llu, ve = %llu\n", matrix->hops, matrix->ve);
  for(long i = 0; i<matrix->ve; i++){
    printf("%-2li: ", i+1);
    for(unsigned long long j = 0; j<matrix->ho; j++){
      printf("%d | ", matrix->arr[i][j]);
    }
    putchar('\n');
  }
}

float_matrix_t* resize(float_matrix_t* prev, int cities){
  int ho = prev->ho+1;
  long ve = combination(cities, prev->ho+1);
  float_matrix_t* new_matrix = float_matrix_init(ho, ve);
  free_float_matrix(prev);
  return new_matrix;
}
