#define INTERAL_VAL -1
typedef struct data data_t;

typedef struct arr{
  int* arr;
  int len;
}arr_t;

 struct data{
  int symbol;
  int weight;
  data_t* left;
  data_t* rght;
};

typedef struct queue{
  data_t** data;
  int rear;
  int front;
  int queueItemCount;
}queue_t;



typedef struct heap{
  data_t **data;
  int heapsize;
  int capacity;
} heap_t;

/*readfile*/
heap_t* read_data(const char* fn);

/*heap*/

heap_t* makeHeap(int len);
void insertVal(heap_t* heap, data_t *val);
data_t* removeMin(heap_t* heap);
int NonEmpty(heap_t* heap);
void printHeap(heap_t* heap);
int* heapSort(heap_t *heap);
/*huffman*/
void fuse_two_mins(heap_t* H);
void construct_HT(heap_t* H);
int get_depth(heap_t* H);
int* makeTable(heap_t*H);
int minDepth(data_t *root);
/*queue*/
queue_t* initQueue(queue_t* queue, int len);
void insert(data_t* data, queue_t *queue);
data_t* removeData(queue_t* queue);
int isQueueEmpty(queue_t* queue);
