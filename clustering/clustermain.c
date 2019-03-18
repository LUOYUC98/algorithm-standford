#include<stdio.h>
#include<stdlib.h>
#include"common.h"
  
  
/*
step1: init all data structures:

edge_t:{
  dot1;
  dot2;
  length;
}
vertex_t:{
  dot;
  rank;
  parent;
}
edge_t arr_edge[edge_num];
vertex_t arr_vertex[vertex_num];
qsort(arr_edge);
step2: init all basic functions:

form_loop(vertex_t x, vertex_t y, vertex_t arr_vertex[])

find(vertex_t x, vertex_t arr_vertex[])


union(vertex_t x, vertex_t y, vertex_t arr_vertex[])


step3:
init parameter for clustering:
groups = number of vertex;

in  arr_vertex[num_vertex], ranks = 0, parent = itself



step4: excution!
while(groups>k){
  edges = find_min;
  vertex_leader_i = find(i);
  vertex_leader_j= find(j);
  union(i,j);
  groups--;
}


*/


int main(){
  const char* fn = "clustering.txt";
  int clusters = 4;
  int vertex_num = get_vertex_num(fn);
  
  int edges_num = get_edge_num(fn);
  vertex_t vertex_arr[vertex_num];
  edge_t edges_arr[edges_num];
  load_data(fn, edges_arr, edges_num);
  qsort(edges_arr, edges_num, sizeof(edges_arr[0]), cmpfunc);
  init_vertex_arr(vertex_arr, vertex_num);
  int result = clustering(edges_arr, vertex_arr, vertex_num, clusters);
  printf("result = %d", result);
  return 0;
}