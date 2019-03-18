#ifndef HEADER_FILE
#define HEADER_FILE

#define INFINITY 10000

typedef struct node node_t;


typedef struct data {
	int weight;
	int head;
  int tail;
} data_t;


struct node {
	data_t data;
	node_t *next;
};


typedef struct {
	node_t *head;
	node_t *foot;
} list_t;

typedef struct heap{
  data_t *data;
  int heapsize;
} heap_t;


typedef struct graph {
  list_t** arr;
  long vertex_num;
  long edge_num;
} graph_t;


typedef struct matrix {
  int** arr;
  long vertex_num;
  long edge_num;
} matrix_t;


typedef struct storage {
  int* cache;
  int* buffer;
  long capacity;
} storage_t;


typedef struct floyd {
  int **cache;
  int **buffer;
  long capacity;
} floyd_t;


/*linklist*/
list_t*insert_at_foot(list_t *list, data_t value);
void print_list(node_t* head);
int get_len_linklist(list_t* list);
list_t*make_empty_list(void);
list_t *insert_at_head(list_t *list, data_t value);
/*2d_init*/
int** bi_arr_init(long ho, long ve);
void bi_arr_cpy(long ho, long ve, int** A, int** B);
int bi_arr_min(long ho, long ve, int** A);
/*read*/
graph_t* read_file(const char* fn);
matrix_t* readfile(const char* fn);
/*print*/
void print_adjacent_array(graph_t* graph);
void print_heapIndexTracker(long* IndexTracker, long len);
void print_matrix(long ho, long ve, int** matrix);
void printDist(int dist[], graph_t* graph);
void printHeap(heap_t* heap);
/*Bellman_ford*/
storage_t* init_storage(graph_t* graph, int start);
int* Bellman_ford_algo(graph_t* graph, storage_t* storage);
/*floyd_warshall*/
floyd_t* init_floyd(matrix_t* matrix);
int floyd_warshall(matrix_t* matrix);
/*johnson*/
void add_extra_s(graph_t* graph);
void delete_extra_s(graph_t* graph);
int* reweight(graph_t* graph);
int johnson_algo(graph_t* graph);
/*heap*/
int get_index(int);
void swap(data_t* a, data_t*b, long heapIndexTracker[]);
int NonEmpty(heap_t* heap);
void removeMin(heap_t* heap, long heapIndexTracker[]);
void insertVal(heap_t* heap, data_t val, long heapIndexTracker[]);
void increaseKey(heap_t* heap, int increment, int nodeIndex, long heapIndexTracker[]);
void decreaseKey(heap_t* heap, int decrement, int nodeIndex, long heapIndexTracker[]);
heap_t* makeHeap(long len);
/*Dijkstra*/
heap_t* init_heap(int len);
int* init_dist(int len);
long* init_heapIndexTracker(int len);
void reset(int dist[], long heapIndexTracker[], long start, graph_t* graph, heap_t* heap);
void onestep(int dist[], graph_t* graph, heap_t* heap, long heapIndexTracker[]);
void Dijkstra(int dist[], graph_t* graph, heap_t* heap, long heapIndexTracker[]);
/*rephrase*/
int* lenList(graph_t* graph);
void rephrase(graph_t* graph);
#endif
