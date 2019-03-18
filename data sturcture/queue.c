#include <stdio.h>
#include<stdlib.h>
#include"common.h"

queue_t* initQueue(queue_t* queue, int len){
  queue->rear = -1;
  queue->front = 0;
  queue->queueItemCount = 0;
  queue->data = (data_t**)malloc(sizeof(data_t*)*len);
  return queue;
}

void insert(data_t* data, queue_t *queue) {
   queue->data[++queue->rear] = data;
   queue->queueItemCount++;
}

data_t* removeData(queue_t* queue) {
   queue->queueItemCount--;
   return queue->data[queue->front++]; 
}

int isQueueEmpty(queue_t* queue) {
   return queue->queueItemCount == 0;
}

