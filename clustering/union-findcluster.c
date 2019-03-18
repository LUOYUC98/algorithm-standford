#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"common.h"
  

  vertex_t* find(vertex_t vertex_arr[], int dot){
    int curr = dot;
    int root;
    while(curr!=vertex_arr[curr-1].parent){
      curr = vertex_arr[curr-1].parent;
    }
    root = curr;
    curr = dot;
    while(vertex_arr[curr-1].parent!=root){
      vertex_arr[curr-1].parent = root;
    }
    return vertex_arr+root-1;
  }

void uni(vertex_t* x, vertex_t* y, vertex_t arr_vertex[]){
  vertex_t *root_x = find(arr_vertex,x->dot);
  vertex_t *root_y = find(arr_vertex,y->dot);
  if(root_x->rank>root_y->rank){
    root_y->parent = root_x->dot;
  }
  else if(root_x->rank<root_y->rank){
    root_x->parent = root_y->dot;
  }
  else{
    root_x->parent = root_y->dot;
    root_y->rank++;
  }
}

