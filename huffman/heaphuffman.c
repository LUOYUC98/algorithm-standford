#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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

void swap(data_t* a, data_t*b){
  data_t temp = *a;
  *a = *b;
  *b = temp;

}


void siftUp(int nodeIndex, heap_t* heap){
    int parentIndex, tmp;
    if (nodeIndex != 0) {
      parentIndex = getParentIndex(nodeIndex);
      if(cmp(heap->data[parentIndex], heap->data[nodeIndex])>0) {
        swap(heap->data[parentIndex], heap->data[nodeIndex]);
        siftUp(parentIndex, heap);
      }
    }
}


void siftDown(int nodeIndex, heap_t* heap) {
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
        if(cmp(heap->data[leftChildIndex], heap->data[rightChildIndex])<0){
          minIndex = leftChildIndex;
        }
        else{
            minIndex = rightChildIndex;
        }
      }
      if (cmp(heap->data[nodeIndex], heap->data[minIndex])>0){
          swap(heap->data[nodeIndex], heap->data[minIndex]);
          siftDown(minIndex, heap);
      }
}


int NonEmpty(heap_t* heap){
  return heap->heapsize;
}


data_t* removeMin(heap_t* heap){
  data_t* min = NULL;
  if(NonEmpty(heap)){
    

    swap(heap->data[0], heap->data[heap->heapsize - 1]);
    min = heap->data[heap->heapsize - 1];
    heap->heapsize--;
    if(NonEmpty(heap)){
      siftDown(0, heap);
    }
  }
  return min;
}


void insertVal(heap_t* heap, data_t *val){
  heap->data[heap->heapsize] = (data_t*)malloc(sizeof(data_t));
  *heap->data[heap->heapsize] = *val;
  heap->heapsize++;
  siftUp(heap->heapsize-1, heap);
}


heap_t* makeHeap(int len){
  heap_t *heap = (heap_t*)malloc(sizeof(heap_t));
  heap->data = (data_t**)malloc(sizeof(data_t*)*len);
  heap->capacity = len;
  heap->heapsize = 0;
  return heap;
}


void printHeap(heap_t* heap){
  puts("heap: ");
  printf("heapsize: %d\n", heap->heapsize);
  for(int i = 0; i<heap->heapsize;i++){
    printf("(%d,%d) ", heap->data[i]->symbol, heap->data[i]->weight);
  }
  putchar('\n');
}

int* heapSort(heap_t *heap){
  heap_t* H = (heap_t*)malloc(sizeof(heap_t));
  H->data = (data_t**)malloc(sizeof(data_t*)*heap->capacity);
  int* ordered = (int*)malloc(sizeof(int)*heap->capacity);
  H->capacity = heap->capacity;
  for(int i = 0; i<H->capacity; i++){
    insertVal(H, heap->data[i]);
  }
  for(int i = 0; i<H->capacity; i++){
    ordered[i] = removeMin(H)->weight;
  }
  return ordered;
}

