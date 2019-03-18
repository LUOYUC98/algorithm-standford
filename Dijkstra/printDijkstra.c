#include<stdio.h>
#include<stdlib.h>
#include"common.h"

void printHeap(heap_t* heap, array_t* graph){
  puts("heap: ");
  printf("heapsize: %d\n", heap->heapsize);
  for(int i = 0; i<graph->len;i++){
    printf("(%c,%f) ", heap->data[i].label, heap->data[i].weight);
  }
  putchar('\n');
}

void printPrev(char prev[], array_t* graph){
  puts("prev: ");
  
  for(int i = 0; i<graph->len;i++){
    printf("%c, ", prev[i]);
  }
  putchar('\n');
}

void printDist(float dist[], array_t* graph){
  puts("dist: ");
  for(int i =0; i<graph->len; i++){
    printf("(%c: %f), ",graph->arr[i]->head->data.label, dist[i]);
  }
  putchar('\n');

}

void printIndexTracker(int IndexTracker[], array_t* graph){
  puts("IndexTracker: ");
  for(int i =0; i<graph->len; i++){
    printf("(%c:%d), ", graph->arr[i]->head->data.label,IndexTracker[i]);
  }
  putchar('\n');

}
