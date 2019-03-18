#include<stdio.h>
#include<stdlib.h>
#include "common.h"


int getParentIndex(int nodeIndex){
  if(nodeIndex%2){
    return nodeIndex/2;
  }
  return nodeIndex/2-1;
}

int getLeftChildIndex(int nodeIndex){
  return nodeIndex*2+1;
}

int getRightChildIndex(int nodeIndex){
  return nodeIndex*2+2;
}

int cmp(data_t* a, data_t* b){
  return a->weight - b->weight;
}

void swap(data_t* a, data_t*b, int heapIndexTracker[]){
  int aPos = heapIndexTracker[get_index(a->label)];
  int bPos = heapIndexTracker[get_index(b->label)];
  int tempPos = aPos;
  heapIndexTracker[get_index(a->label)] = bPos;
  heapIndexTracker[get_index(b->label)] = tempPos;
  
  data_t temp = *a;
  *a = *b;
  *b = temp;

}


void siftUp(int nodeIndex, heap_t* heap,int heapIndexTracker[]){
    int parentIndex, tmp;
    if (nodeIndex != 0) {
      parentIndex = getParentIndex(nodeIndex);
      if(cmp(&heap->data[parentIndex], &heap->data[nodeIndex])>0) {
        swap(&heap->data[parentIndex], &heap->data[nodeIndex], heapIndexTracker);
        siftUp(parentIndex, heap, heapIndexTracker);
      }
    }
}


void siftDown(int nodeIndex, heap_t* heap, int heapIndexTracker[]) {
      int leftChildIndex, rightChildIndex, minIndex, tmp;
      leftChildIndex = getLeftChildIndex(nodeIndex);
      rightChildIndex = getRightChildIndex(nodeIndex);
      if (rightChildIndex >= heap->heapsize) {
        if(leftChildIndex >= heap->heapsize){
          return;
        }
        else{
              minIndex = leftChildIndex;
        }
      }
      else{
        if(cmp(&heap->data[leftChildIndex], &heap->data[rightChildIndex])<0){
          minIndex = leftChildIndex;
        }
        else{
            minIndex = rightChildIndex;
        }
      }
      if (cmp(&heap->data[nodeIndex], &heap->data[minIndex])>0){
          swap(&heap->data[nodeIndex], &heap->data[minIndex], heapIndexTracker);
          siftDown(minIndex, heap, heapIndexTracker);
      }
}


int NonEmpty(heap_t* heap){
  return heap->heapsize;
}


void removeMin(heap_t* heap, int heapIndexTracker[]){
  if(NonEmpty(heap)){
    swap(&heap->data[0], &heap->data[heap->heapsize - 1], heapIndexTracker);
    heap->heapsize--;
    if(NonEmpty(heap)){
      siftDown(0, heap, heapIndexTracker);
    }
  }
}


void insertVal(heap_t* heap, data_t val, int heapIndexTracker[]){
  heap->data[heap->heapsize].weight = val.weight;
  heap->heapsize++;
  siftUp(heap->heapsize-1, heap, heapIndexTracker);
  
}


void increaseKey(heap_t* heap, int increment, int nodeIndex, int heapIndexTracker[]){
  heap->data[nodeIndex].weight+=increment;
  siftDown(nodeIndex, heap, heapIndexTracker);
}

void decreaseKey(heap_t* heap, int decrement, int nodeIndex, int heapIndexTracker[]){
  heap->data[nodeIndex].weight-=decrement;
  siftUp(nodeIndex, heap, heapIndexTracker);
}

heap_t* makeHeap(int len){
  heap_t *heap = (heap_t*)malloc(sizeof(heap_t));
  heap->data = (data_t*)malloc(sizeof(data_t)*len);
  heap->heapsize = len;
  return heap;
}





