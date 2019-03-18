#include<stdio.h>
#include<stdlib.h>
#include "common.h"

int* lenList(graph_t* graph){
  int* lenRecord = (int*)malloc(graph->vertex_num*sizeof(int));
  int count;
  node_t* curr;
  for(int i = 0; i<graph->vertex_num; i++){
    count = 0;
    curr = graph->arr[i]->head;
    while(curr){
      count++;
      curr = curr->next;
    }
    lenRecord[i] = count;
  }
  return lenRecord;
}



void rephrase(graph_t* graph){
  int* lenRecord = lenList(graph);
  node_t* curr;
  node_t* prev;
  for(int i = 0; i<graph->vertex_num; i++){
    curr = graph->arr[i]->head;
    for(int j = 0; j < lenRecord[i]; j++){
      int from = curr->data.head;
      graph->arr[get_index(from)] = insert_at_foot(graph->arr[get_index(from)], curr->data);

      curr = curr->next;
    }
  }
  for(long i = 0; i<graph->vertex_num; i++){
    curr = graph->arr[i]->head;
    prev = NULL;
    for(int j = 0; j < lenRecord[i]; j++){
      if(curr->next){
        prev = curr;
        curr = curr->next;
        free(prev);
        graph->arr[i]->head = curr;
      }
      else{
        free(curr);
        graph->arr[i]->foot = graph->arr[i]->head = NULL;
        continue;
      }

    }
  }
}