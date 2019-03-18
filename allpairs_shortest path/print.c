#include<stdio.h>
#include<stdlib.h>
#include "common.h"

void print_list(node_t* head){
  node_t* curr = head;
  while(curr!=NULL){
    printf("%d<--(%d)--%d\n",curr->data.tail, curr->data.weight, curr->data.head);
    curr = curr->next;
  }
}

void print_adjacent_array(graph_t* graph){
  printf("\n------------------------\n");
  for(int i = 0; i<graph->vertex_num; i++){
    printf("arr[%d]: \n",i);
    if(graph->arr[i]->head){
      print_list(graph->arr[i]->head);
      puts("\n");
    }
    else{
      continue;
    }
  }
  return;
}


void print_heapIndexTracker(long* IndexTracker, long len){
  puts("heapIndexTracker:");
  for(long i = 0; i<len; i++){
    printf("(%li:%li), ", i+1, IndexTracker[i]);
  }
}


void print_matrix(long ho, long ve, int** matrix){
  puts("matrix:\n");
  for(long i = 0; i<ve; i++){
    for(long j = 0; j<ho; j++){
      printf("%d | ", matrix[i][j]);
    }
    putchar('\n');
  }
}


void printHeap(heap_t* heap){
  puts("heap: ");
  printf("heapsize: %d\n", heap->heapsize);
  for(int i = 0; i<heap->heapsize; i++){
    printf("(%d,%d) ", heap->data[i].tail, heap->data[i].weight);
  }
  putchar('\n');
}


void printDist(int dist[], graph_t* graph){
  puts("dist: ");
  for(int i =0; i<graph->vertex_num; i++){
    printf("(%d: %d), ",i+1, dist[i]);
  }
  putchar('\n');
}
