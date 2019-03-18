#include<stdio.h>
#include<stdlib.h>
#include "common.h"



int** bi_arr_init(long ho, long ve){
  int** arr = (int**)malloc(sizeof(int*)*ve);
  for(long i = 0; i<ho; i++){
    arr[i] = (int*)malloc(sizeof(int)*ho);
  }
  return arr;
}

void bi_arr_cpy(long ho, long ve, int** A, int** B){
  for(long i = 0; i<ve; i++){
    for(long j = 0; j<ho; j++){
      A[i][j] = B[i][j];
    }
  }
}

int bi_arr_min(long ho, long ve, int** A){
  int min = INFINITY;
  for(long i = 0; i<ve; i++){
    for(long j = 0; j<ho; j++){
      if(A[i][j]<min&&j!=i){
        min = A[i][j];
      }
    }
  }
  return min;
}