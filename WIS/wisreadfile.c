#include <stdio.h>
#include<stdlib.h>
#include"common.h"



array_t* readfile(const char* fn){

  FILE* fp = fopen(fn, "r");
  int len;
  fscanf(fp, "%d", &len);
  array_t* arr = (array_t*)malloc(sizeof(array_t*));
  arr->len = len;
  arr->arr = (unsigned long*)malloc(sizeof(unsigned long)*len);
  for(int i = 0; i<len; i++){
    fscanf(fp, "%lu",arr->arr+i);
  }
  return arr;
}