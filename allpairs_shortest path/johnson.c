#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "common.h"


void add_extra_s(graph_t* graph){
  data_t *data = (data_t*)malloc(sizeof(data_t));
  data->head = graph->vertex_num+1;
  data->weight = 0;
  for(long i = 0; i < graph->vertex_num; i++){
    graph->arr[i] = insert_at_foot(graph->arr[i], *data);
  }
  graph->vertex_num++;
  graph->arr = (list_t**)realloc(graph->arr,(sizeof(list_t*)*graph->vertex_num));
  graph->arr[graph->vertex_num-1] = make_empty_list();
}


void delete_extra_s(graph_t* graph){
  
  node_t* curr = graph->arr[graph->vertex_num-1]->head;
  node_t* prev = NULL;
  while(curr){
    prev = curr;
    curr = curr->next;
    free(prev);
  }
  free(graph->arr[graph->vertex_num-1]);
  graph->arr[graph->vertex_num-1] = NULL;
  graph->vertex_num--;
  for(long i = 0; i<graph->vertex_num; i++){
    curr = graph->arr[i]->head;
    if(curr&&!curr->next){
      free(curr);
      graph->arr[i]->head = NULL;
      graph->arr[i]->foot = NULL;
    }
    else{
      while(curr->next&&curr->next!=graph->arr[i]->foot){
        curr = curr->next;
      }
      free(curr->next);
      curr->next = NULL;
      graph->arr[i]->foot = curr;
    }
  }
}


int* reweight(graph_t* graph){
  storage_t* storage = init_storage(graph, graph->vertex_num-1);
  Bellman_ford_algo(graph, storage);
  int * new_weight = Bellman_ford_algo(graph, storage);
  for(long i = 0; i<graph->vertex_num; i++){
    node_t* curr = graph->arr[i]->head;
    while(curr){
      int pu = new_weight[curr->data.head-1];
      int pv = new_weight[i];
      curr->data.weight += pu-pv;
      curr = curr->next;
    }
  }
  return new_weight;
}

int johnson_algo(graph_t* graph){
  add_extra_s(graph);
  int* new_weight = reweight(graph);
  delete_extra_s(graph);
  rephrase(graph);
  heap_t* heap = makeHeap(graph->vertex_num);
  int dist[graph->vertex_num];
  long heapIndexTracker[graph->vertex_num];
  int min = INFINITY;
  for(long i = 1; i<=graph->vertex_num; i++){
    reset(dist, heapIndexTracker, i, graph, heap);
    Dijkstra(dist, graph, heap,heapIndexTracker);
    for(long j = 0; j<graph->vertex_num; j++){
      dist[j] += new_weight[j] - new_weight[i-1];
      if(dist[j]<min){
        min = dist[j];
      }
    }
  }
  return min;
}



