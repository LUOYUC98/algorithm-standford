#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "common.h"


void print_cache(bag_t* knapsack){
  printf("item%d: \n", knapsack->item1_id);
  for(int i = 0; i<=knapsack->capacity; i++){
    printf("K[0][%d] = %li\n", i, knapsack->cache[0][i]);
  }
    printf("item%d: \n", knapsack->item2_id);
  for(int i = 0; i<=knapsack->capacity; i++){
    printf("K[1][%d] = %li\n", i, knapsack->cache[1][i]);
  }
  puts("\n-------------\n");
}