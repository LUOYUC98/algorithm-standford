#ifndef HEADER_FILE
#define HEADER_FILE
#define INFINITY 333333

typedef struct node node_t;


typedef struct{
  int label;
  int weight;
  int used;
}data_t;




typedef struct heap{
  data_t *data;
  int heapsize;
  int capacity;
} heap_t;


struct node {
	data_t data;
	node_t *next;
};

typedef struct {
	node_t *head;
	node_t *foot;
} list_t;


typedef struct adjrr{
  list_t** arr;
  int len;
  int edges;
}adjarr_t;

/*linklist.c*/
list_t *make_empty_list(void);
int    is_empty_list(list_t*);
void   free_list(list_t*);
list_t *insert_at_head(list_t*, data_t);
list_t *insert_at_foot(list_t *list, data_t value);
list_t *insert_in_order(list_t* list, data_t value);



/*load file.c*/
adjarr_t* load_data(const char*fn);

long long* loadFile(const char* filename, int len);
/*graph.c*/
void printAdjarr(adjarr_t* adjarr, long long upBound, long long lowBound);

/*heap.c*/
int get_index(int label);
heap_t* makeHeap(int len);
void decreaseKey(heap_t* heap, int decrement, int nodeIndex, int heapIndexTracker[]);
void removeMin(heap_t* heap, int heapIndexTracker[]);
void swap(data_t* a, data_t*b, int heapIndexTracker[]);
/*prim.c*/
heap_t* init(int dist[], int len, int prev[], int heapIndexTracker[], int start, adjarr_t* graph);
void heapUpdate(int dist[], int prev[], adjarr_t* graph, heap_t* heap, int heapIndexTracker[]);
int prim(int dist[], int prev[],adjarr_t* graph, heap_t* heap, int heapIndexTracker[]);

/*print.c*/
void adjarr_print(adjarr_t* graph);
void heap_print(heap_t* H);
void prev_print(int prev[], adjarr_t* graph);
#endif
