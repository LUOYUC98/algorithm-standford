#include <stdio.h>
#include<stdlib.h>
#include"common.h"


array_t* init_storage(array_t*weight_set){
  array_t* storage = (array_t*)malloc(sizeof(array_t));
  storage->len = weight_set->len+1;
  storage->arr = (unsigned long*)malloc(sizeof(unsigned long)*storage->len);
  return storage;
}


array_t* wis(array_t*weight_set, array_t* storage, int i){
  unsigned long decision;
  if(i==weight_set->len+1){
    return storage;
  }
  else if(i == 0){
    storage->arr[i] = 0;
    return wis(weight_set, storage, i+1);
      }
  else if(i == 1){
    storage->arr[1] = weight_set->arr[0];
    return wis(weight_set, storage, i+1);
  }
  else{
    if(storage->arr[i-1]>=storage->arr[i-2]+weight_set->arr[i-1]){
    decision = storage->arr[i-1];
    }
    else{
      decision = storage->arr[i-2]+weight_set->arr[i-1];
    }
    storage->arr[i] = decision;
    return wis(weight_set, storage, i+1);
  }

}


int
* reconstruct(array_t* storage, array_t*weight_set){
  int *path = (int*)malloc(sizeof(int)*storage->len);
  int index = storage->len-1;
  int i = 0;
  while(index>=2){
    if(storage->arr[index-1]<storage->arr[index-2]+weight_set->arr[index-1]){
      path[index] = 1;
      path[index-1] = 0;
      index--;
    }
    index--;
  }
  if(path[2]==0){
    path[1] = 1;
  }
  else{
    path[1] = 0;
  }
  path[0] = 0;
  return path;
}

int verify(array_t* weight_set, array_t*storage, int* path){
  unsigned long sum = 0;
  for(int i = 0; i<weight_set->len; i++){
    sum+=weight_set->arr[i]*path[i+1];
  }
  printf("sum = %lu, ans = %lu\n",sum,storage->arr[weight_set->len] );
  return sum==storage->arr[weight_set->len];
}