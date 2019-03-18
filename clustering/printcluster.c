#include<stdio.h>
#include<stdlib.h>
#include"common.h"
  


void print_edge_arr(edge_t* edge_arr, int len){
  for(int i = 0; i<len; i++){
    printf("edge[%d]=%d %d %d\n", i, edge_arr[i].dot1, edge_arr[i].dot2, edge_arr[i].length);
  }
}

void print_vertex_arr(vertex_t* vertex_arr, int len){
  for(int i = 0; i<len; i++){
    printf("vertex[%d]=%d rank:%d parent:%d\n", i, vertex_arr[i].dot, vertex_arr[i].rank, vertex_arr[i].parent);
  }
}
