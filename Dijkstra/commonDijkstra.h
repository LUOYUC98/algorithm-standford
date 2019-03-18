#ifndef HEADER_FILE
#define HEADER_FILE
#define INFINITY 1000.0

typedef struct node node_t;


typedef struct data{
	float weight;
	int label;
}data_t;


typedef struct heap{
  data_t *data;
  int heapsize;
} heap_t;


struct node {
	data_t data;
	node_t *next;
};

typedef struct {
	node_t *head;
	node_t *foot;
} list_t;


typedef struct arr{
  list_t** arr;
  int len;
}array_t;


list_t*insert_at_foot(list_t *list, data_t value);
void print_list(node_t* head);

void print_adjacent_array(list_t** arr, int len);

void print_int_array(int A[], int len);

int get_len_linklist(list_t* list);

array_t* read_digraph(const char* filename);

list_t*make_empty_list(void);

list_t *insert_at_head(list_t *list, data_t value);

int get_index(char ch);
void swap(data_t* a, data_t*b, int heapIndexTracker[]);
int NonEmpty(heap_t* heap);
void removeMin(heap_t* heap, int heapIndexTracker[]);
void insertVal(heap_t* heap, data_t val, int heapIndexTracker[]);
void increaseKey(heap_t* heap, int increment, int nodeIndex, int heapIndexTracker[]);
void decreaseKey(heap_t* heap, int decrement, int nodeIndex, int heapIndexTracker[]);
heap_t* makeHeap(int len);
heap_t* init(float dist[], int len, char prev[], int heapIndexTracker[], char start, array_t* graph);
void prevUpdate(char prev[], char _new);
void distUpdate(float dist[], int greedyScore, char obj);
void heapUpdate(float dist[], char prev[], array_t* graph, heap_t* heap, int heapIndexTracker[]);
void Dijkstra(float dist[], char prev[],array_t* graph, heap_t* heap, int heapIndexTracker[]);
void printIndexTracker(int IndexTracker[], array_t* graph);
void printDist(float dist[],array_t*graph);
void printPrev(char prev[], array_t* graph);
void printHeap(heap_t* heap, array_t* graph);
#endif
