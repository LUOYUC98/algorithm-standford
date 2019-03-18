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

int get_index(int head){
  return head-1;
}

void swap(data_t* a, data_t*b, long heapIndexTracker[]){
  long aPos = heapIndexTracker[get_index(a->tail)];
  long bPos = heapIndexTracker[get_index(b->tail)];
  long tempPos = aPos;
  heapIndexTracker[get_index(a->tail)] = bPos;
  heapIndexTracker[get_index(b->tail)] = tempPos;
  
  data_t temp = *a;
  *a = *b;
  *b = temp;

}


void siftUp(int nodeIndex, heap_t* heap,long heapIndexTracker[]){
    int parentIndex, tmp;
    if (nodeIndex != 0) {
      parentIndex = getParentIndex(nodeIndex);
      if(cmp(&heap->data[parentIndex], &heap->data[nodeIndex])>0) {
        swap(&heap->data[parentIndex], &heap->data[nodeIndex], heapIndexTracker);
        siftUp(parentIndex, heap, heapIndexTracker);
      }
    }
}


void siftDown(int nodeIndex, heap_t* heap, long heapIndexTracker[]) {
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


void removeMin(heap_t* heap, long heapIndexTracker[]){
  if(NonEmpty(heap)){
    swap(&heap->data[0], &heap->data[heap->heapsize - 1], heapIndexTracker);
    heap->heapsize--;
    if(NonEmpty(heap)){
      siftDown(0, heap, heapIndexTracker);
    }
  }
}


void insertVal(heap_t* heap, data_t val, long heapIndexTracker[]){
  heap->data[heap->heapsize].weight = val.weight;
  heap->heapsize++;
  siftUp(heap->heapsize-1, heap, heapIndexTracker);
  
}


void increaseKey(heap_t* heap, int increment, int nodeIndex, long heapIndexTracker[]){
  heap->data[nodeIndex].weight+=increment;
  siftDown(nodeIndex, heap, heapIndexTracker);
}

void decreaseKey(heap_t* heap, int decrement, int nodeIndex, long heapIndexTracker[]){
  heap->data[nodeIndex].weight-=decrement;
  siftUp(nodeIndex, heap, heapIndexTracker);
}

heap_t* makeHeap(long len){
  heap_t *heap = (heap_t*)malloc(sizeof(heap_t));
  heap->data = (data_t*)malloc(sizeof(data_t)*len);
  //heap->heapsize = len;
  return heap;
}





