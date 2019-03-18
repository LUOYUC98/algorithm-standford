#ifndef HEADER_FILE
#define HEADER_FILE


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
#endif
