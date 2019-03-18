#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "common.h"

long knapsackalgo(bag_t* knapsack, item_t items[]){
  long retain_val, last_val, curr_val, curr_weight, last_weight; 
  for(;knapsack->item_id<=knapsack->itemnum;knapsack->item_id++){
    curr_weight = items[knapsack->item_id-1].weight;
    memcpy(knapsack->buffer, knapsack->cache, sizeof(long)*curr_weight);
    for(long i = curr_weight; i<=knapsack->capacity; i++){
      retain_val = knapsack->cache[i];
      last_val = knapsack->cache[i-items[knapsack->item_id-1].weight];
      curr_val = items[knapsack->item_id-1].value;
      last_weight = i-items[knapsack->item_id-1].weight;
      if((retain_val<last_val+curr_val)&&(last_weight+curr_weight<=i)){
        knapsack->buffer[i] = curr_val+last_val;
        }
      else{
          knapsack->buffer[i] = retain_val;
        }
      
    }
    memcpy(knapsack->cache, knapsack->buffer, (knapsack->capacity+1)*sizeof(long));
    }
    return knapsack->cache[knapsack->capacity];
}

