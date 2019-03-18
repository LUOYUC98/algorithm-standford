#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "common.h"


storage_t* init_storage(graph_t* graph, int start){
  storage_t* storage = (storage_t*)malloc(sizeof(storage_t));
  storage->cache = (int*)malloc(sizeof(int)*graph->vertex_num);
  storage->buffer = (int*)malloc(sizeof(int)*graph->vertex_num);
  storage->capacity = graph->vertex_num;
  for(long i = 0; i<storage->capacity; i++){
    storage->cache[i] = INFINITY;
  }
  storage->cache[start-1] = 0;
  return storage;
}



int* Bellman_ford_algo(graph_t* graph, storage_t* storage){
  int old, prefix, suffix, min;
  for(long budget = 1; budget < graph->vertex_num; budget++){
    for(long vertex = 0; vertex < graph->vertex_num; vertex++){
      old = storage->cache[vertex];
      node_t* curr = graph->arr[vertex]->head;
      min = INFINITY;
      while(curr){
        prefix = storage->cache[curr->data.head-1];
        suffix = curr->data.weight;
        if(prefix + suffix < min){
          min = prefix + suffix;
        }
        curr = curr->next;
      }
      if(min < old){
      storage->buffer[vertex] = min;
      }
      else{        
        storage->buffer[vertex] = old;
      }
    }
    for(long i = 0; i<storage->capacity; i++){
      storage->cache[i] = storage->buffer[i];
    }
  }
  for(long i = 0; i<graph->vertex_num; i++){
    node_t* curr = graph->arr[i]->head;
    while(curr){
      int head = curr->data.head;
      int tail = i+1;
      if(storage->cache[head-1] + curr->data.weight < storage->cache[tail-1]){
        puts("negative loop detected");
        return NULL;
      }
      curr = curr->next;
    }
  }
  return storage->cache;
}