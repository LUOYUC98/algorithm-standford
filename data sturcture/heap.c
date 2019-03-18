#include<stdio.h>
#include<stdlib.h>


typedef int data_t;



typedef struct heap{
  data_t *data;
  int heapsize;
} heap_t;


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
  return *a - *b;
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
      if(cmp(&heap->data[parentIndex], &heap->data[nodeIndex])>0) {
        swap(&heap->data[parentIndex], &heap->data[nodeIndex]);
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
        if(cmp(&heap->data[leftChildIndex], &heap->data[rightChildIndex])<0){
          minIndex = leftChildIndex;
        }
        else{
            minIndex = rightChildIndex;
        }
      }
      if (cmp(&heap->data[nodeIndex], &heap->data[minIndex])>0){
          swap(&heap->data[nodeIndex], &heap->data[minIndex]);
          siftDown(minIndex, heap);
      }
}


int NonEmpty(heap_t* heap){
  return heap->heapsize;
}


void removeMin(heap_t* heap){
  if(NonEmpty(heap)){
    heap->data[0] = heap->data[heap->heapsize - 1];
    heap->heapsize--;
    if(NonEmpty(heap)){
      siftDown(0, heap);
    }
  }
}


void insertVal(heap_t* heap, int val){
  heap->data[heap->heapsize] = val;
  heap->heapsize++;
  siftUp(heap->heapsize-1, heap);
  
}


void increaseKey(heap_t* heap, int increment, int nodeIndex){
  heap->data[nodeIndex]+=increment;
  siftDown(nodeIndex, heap);
}

void decreaseKey(heap_t* heap, int decrement, int nodeIndex){
  heap->data[nodeIndex]-=decrement;
  siftUp(nodeIndex, heap);
}

heap_t* makeHeap(int len){
  heap_t *heap = (heap_t*)malloc(sizeof(heap_t));
  heap->data = (data_t*)malloc(sizeof(data_t)*len);
  heap->heapsize = 0;
  return heap;
}






