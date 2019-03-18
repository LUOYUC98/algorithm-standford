#include<stdio.h>
#include<stdlib.h>
#include"common.h"

int cmpfunc(const void*a, const void*b){
  edge_t *edge_a = (edge_t*)a;
  edge_t *edge_b = (edge_t*)b;
  return edge_a->length-edge_b->length;

}

void init_vertex_arr(vertex_t vertex_arr[], int len){
  for(int i = 0; i<len; i++){
    vertex_arr[i].dot = i+1;
    vertex_arr[i].rank = 0;
    vertex_arr[i].parent = vertex_arr[i].dot;
  }
}

