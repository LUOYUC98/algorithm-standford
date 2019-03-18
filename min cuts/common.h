#ifndef HEADER_FILE
#define HEADER_FILE
#define MAXLEN 200
typedef struct node node_t;
typedef int data_t;
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

node_t* SortedMerge( node_t* a, node_t* b); 
void FrontBackSplit(node_t* source, node_t** frontRef, node_t** backRef); 
void MergeSort(node_t** headRef);
void push(node_t** head_ref, int new_data);
list_t*make_empty_list(void);
list_t*insert_at_foot(list_t *list, int value);
void print_list(node_t* head);
void print_adjacent_array(list_t** arr, int len);
array_t* create_adjacent_list(const char* filename);
int cmp(const void* a, const void* b);
void print_int_array(int A[], int len);
void shuffle_array(data_t arr[], int n, int size);
void shuffle_linklist(list_t* list, int len);
void shuffle_adjacent_list(list_t* adjacent_list[], int n, int size);
void shuffle(array_t* arr);
int get_len_linklist(list_t* list);
void selfloop_deletion(list_t* list);
void contract(list_t**adjacent_array, int len);
void graph_contraction(list_t** adjacent_array, int len);
void free_adjacent_array(array_t* arr);
#endif
