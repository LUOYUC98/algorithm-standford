#include<stdio.h> 
#include<stdlib.h>
#include "common.h"


heap_t* init(float dist[], int len, char prev[], int heapIndexTracker[], char start, array_t* graph){
  heap_t* heap = makeHeap(len);
  for(int i = 0; i<len; i++){
    dist[i] = INFINITY;
    heap->data[i].label = graph->arr[i]->head->data.label;
    heap->data[i].weight = INFINITY;
    prev[i] = 0;
    heapIndexTracker[get_index(graph->arr[i]->head->data.label)] = i;
  }
  
  dist[get_index(start)] = 0;
  heap->data[get_index(start)].weight = 0;
  swap(&heap->data[get_index(start)], &heap->data[0],heapIndexTracker);
  return heap;
}

void prevUpdate(char prev[], char _new){
  static int lastElemIndex = 0;
  prev[lastElemIndex] = _new;
  lastElemIndex++;
}

void distUpdate(float dist[], int greedyScore, char obj){
  dist[get_index(obj)] = greedyScore;
}

void heapUpdate(float dist[], char prev[], array_t* graph, heap_t* heap, int heapIndexTracker[]){
  char min = heap->data[0].label;
  node_t* curr = graph->arr[get_index(min)]->head->next;
  float oldGreedyScore, currGreedyScore, decrement;
  currGreedyScore = heap->data[0].weight;
  removeMin(heap, heapIndexTracker);
  prevUpdate(prev, min);
  while(curr){
    oldGreedyScore = heap->data[heapIndexTracker[get_index(curr->data.label)]].weight;
    
    if(currGreedyScore+curr->data.weight<oldGreedyScore){
     

      decrement = oldGreedyScore - (currGreedyScore+curr->data.weight);
      
      decreaseKey(heap, decrement, heapIndexTracker[get_index(curr->data.label)], heapIndexTracker);

      distUpdate(dist, currGreedyScore+curr->data.weight, curr->data.label);
    }
    curr = curr->next;
  }

}

void Dijkstra(float dist[], char prev[],array_t* graph, heap_t* heap, int heapIndexTracker[]){
  while(heap->heapsize){
    heapUpdate(dist, prev, graph, heap,heapIndexTracker);
  }
  
}