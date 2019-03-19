#include<stdio.h>
#include<stdlib.h>
#include "common.h"

float_matrix_t* read_file(const char* fn){
  FILE* fp = fopen(fn, "r");
  int len;
  fscanf(fp, "%d", &len);
  float_matrix_t* matrix = float_matrix_init(len, 2);
  for(int i = 0; i < matrix->ho; i++){
    fscanf(fp, " %f %f", &matrix->arr[0][i], &matrix->arr[1][i]);
  }
  return matrix;
}

