#include<stdio.h>
#include<stdlib.h>
#include"common.h"




int main(int argc, char const *argv[])
{ 
  array_t* graph = read_digraph("test.txt");
  char start = 'A';
  float dist[graph->len];
  char prev[graph->len];
  int heapIndexTracker[graph->len];
  heap_t* heap = init(dist, graph->len, prev,heapIndexTracker, start, graph);
  Dijkstra(dist, prev, graph, heap, heapIndexTracker);
  printDist(dist, graph);
  printPrev(prev, graph);
  return 0;
}

