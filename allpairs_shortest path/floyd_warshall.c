#include<stdio.h>
#include<stdlib.h>
#include "common.h"

floyd_t* init_floyd(matrix_t* matrix){
  floyd_t* floyd = (floyd_t*)malloc(sizeof(floyd_t));
  floyd->cache = bi_arr_init(matrix->vertex_num, matrix->vertex_num);
  floyd->buffer = bi_arr_init(matrix->vertex_num, matrix->vertex_num);
  floyd->capacity = matrix->vertex_num;
  bi_arr_cpy(matrix->vertex_num, matrix->vertex_num, floyd->cache, matrix->arr);
  return floyd;
}


int floyd_warshall(matrix_t* matrix){
  floyd_t* floyd = init_floyd(matrix);
  for(long i = 0; i < floyd->capacity; i++){
    for(long j = 0; j < floyd->capacity; j++){
      for(long k = 0; k< floyd->capacity; k++){
        int old = floyd->cache[j][k];
        int prefix = floyd->cache[j][i];
        int suffix = floyd->cache[i][k];
        if(old>prefix+suffix){
          floyd->buffer[j][k] = prefix+suffix;
        }
        else{
          floyd->buffer[j][k] = old;
        }
      }
    }
    bi_arr_cpy(floyd->capacity, floyd->capacity, floyd->cache, floyd->buffer);
  }

  return bi_arr_min(floyd->capacity, floyd->capacity, floyd->cache);
}