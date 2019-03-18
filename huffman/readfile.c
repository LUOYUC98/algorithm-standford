#include <stdio.h>
#include<stdlib.h>
#include"common.h"

heap_t* read_data(const char* fn){
  int len;
  FILE* fp = fopen(fn, "r");
  fscanf(fp, "%d", &len);
  heap_t* H = makeHeap(len);
  data_t* val = (data_t*)malloc(sizeof(data_t*));
  for(int i = 0; i<H->capacity;i++){
    val->symbol = i;
    fscanf(fp, "%d", &val->weight);
    val->left = val->rght = NULL;
    //printf("data: symbol = %d, weight = %d\n", val->symbol, val->weight);
    insertVal(H, val);
  }
  return H;
}