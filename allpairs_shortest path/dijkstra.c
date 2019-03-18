#include<stdio.h> 
#include<stdlib.h>
#include "common.h"


void reset(int dist[], long heapIndexTracker[], long start, graph_t* graph, heap_t* heap){
  for(long i = 0; i<graph->vertex_num; i++){
    dist[i] = INFINITY;
    heap->data[i].tail = i+1;
    heap->data[i].weight = INFINITY;
    heapIndexTracker[i] = i;
  }
  dist[get_index(start)] = 0;
  heap->heapsize = graph->vertex_num;
  heap->data[get_index(start)].weight = 0;
  swap(&heap->data[get_index(start)], &heap->data[0],heapIndexTracker);

}





void Dijkstra(int dist[], graph_t* graph, heap_t* heap, long heapIndexTracker[]){
  while(heap->heapsize){
    int min = heap->data[0].tail;
    node_t* curr = graph->arr[get_index(min)]->head;
    int oldGreedyScore, currGreedyScore, decrement;
    currGreedyScore = heap->data[0].weight;
    removeMin(heap, heapIndexTracker);

    while(curr){
      oldGreedyScore = heap->data[heapIndexTracker[get_index(curr->data.tail)]].weight;
      if(currGreedyScore+curr->data.weight<oldGreedyScore){
        decrement = oldGreedyScore - (currGreedyScore+curr->data.weight);
        decreaseKey(heap, decrement, heapIndexTracker[get_index(curr->data.tail)], heapIndexTracker);
        
        dist[get_index(curr->data.tail)] = currGreedyScore+curr->data.weight;
      }
      curr = curr->next;
    }
  }

}

