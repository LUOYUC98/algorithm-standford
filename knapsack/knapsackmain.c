#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct bag{
  long* cache;
  long* buffer;
  int itemnum;
  int capacity;
  int item_id;
}bag_t;

typedef struct item{
  long weight;
  long value;
}item_t;

/*readfile*/
item_t* init_item(const char*fn, item_t* items);
bag_t* init_knapsack(const char*fn, bag_t* knapsack);

/*cache*/
bag_t* init_cache(bag_t*knapsack);
void trans_to_next(bag_t* knapsack);
long knapsackalgo(bag_t* knapsack, item_t items[]);

/*print*/
void print_cache(bag_t* knapsack);



const char* fn = "knapsack4.txt";

int main(){
  item_t *items;
  bag_t *knapsack;
  items = init_item(fn, items);
  knapsack = init_knapsack(fn, knapsack);
  long result = knapsackalgo(knapsack, items);
  printf("result = %li", result);
  return 0;
}


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

