#include<stdio.h>
#include<stdlib.h>
#include"common.h"


int form_loop(vertex_t* x, vertex_t* y, vertex_t vertex_arr[]){
  vertex_t* root_x = find(vertex_arr, x->dot);
  vertex_t* root_y = find(vertex_arr, y->dot);
  if(root_x->dot == root_y->dot){
    return 1;
  }
  return 0;
}

int clustering(edge_t edges_arr[], vertex_t vertex_arr[], int vertex_num, int clusters){
  int groups = vertex_num;
  int i, dot_x, dot_y;
  for(i = 0; groups>clusters;i++){


     dot_x = edges_arr[i].dot1;
     dot_y = edges_arr[i].dot2;
    int loop = form_loop(vertex_arr+dot_x-1, vertex_arr+dot_y-1, vertex_arr);
    if(!loop){
    uni(vertex_arr+dot_x-1, vertex_arr+dot_y-1, vertex_arr);
    groups--;

    }
  }
  dot_x = edges_arr[i].dot1;
  dot_y = edges_arr[i].dot2;
  while(1){
    dot_x = edges_arr[i].dot1;
    dot_y = edges_arr[i].dot2;
    if(!form_loop(vertex_arr+dot_x-1, vertex_arr+dot_y-1, vertex_arr)){
      break;
    }
    i++;
  }
  return edges_arr[i].length;
  
}