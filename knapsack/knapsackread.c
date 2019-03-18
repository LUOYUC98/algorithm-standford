#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include "common.h"


item_t* init_item(const char*fn, item_t* items){
  FILE* fp = fopen(fn, "r");
  int itemnum, capacity;
  fscanf(fp, "%d %d", &capacity, &itemnum);
  items = (item_t*)malloc(sizeof(item_t)*itemnum);
  long value, weight;
  for(int i = 0; i<itemnum; i++){
    fscanf(fp, "%li %li",&items[i].value, &items[i].weight);
  }
  rewind(fp);
  fclose(fp);
  return items;
}


bag_t* init_knapsack(const char*fn, bag_t* knapsack){
    FILE* fp = fopen(fn, "r");
    int itemnum, capacity;
    fscanf(fp, "%d %d", &capacity, &itemnum);
    knapsack = (bag_t*)malloc(sizeof(bag_t));
    knapsack->capacity = capacity;
    knapsack->itemnum = itemnum;
    knapsack->cache=(long*)malloc((knapsack->capacity+1)*sizeof(long));
    knapsack->buffer=(long*)malloc((knapsack->capacity+1)*sizeof(long));
    memset(knapsack->cache, 0, sizeof(long)*(knapsack->capacity+1));
    knapsack->item_id = 1;
    fclose(fp);
    return knapsack;
}