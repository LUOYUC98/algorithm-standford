#ifndef HEADER_FILE
#define HEADER_FILE
#define NULLKEY -333333
#define UPBOUND 10
#define LOWBOUND 3

typedef struct node node_t;


typedef long long data_t;


typedef struct section{
  long long* start;
  long long* end;
}section_t;


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
  long poslen;
  long neglen;
  long len;
}adjarr_t;

/*linklist.c*/
list_t *make_empty_list(void);
int    is_empty_list(list_t*);
void   free_list(list_t*);
list_t *insert_at_head(list_t*, data_t);
list_t *insert_at_foot(list_t *list, data_t value);
list_t *insert_in_order(list_t* list, data_t value);



/*load file.c*/
int countlines(char *filename);

long long* loadFile(const char* filename, int len);
/*graph.c*/
void printAdjarr(adjarr_t* adjarr, long long upBound, long long lowBound);/*preprocessing.c*/
int dupFilter(long long A[], int len);
void print_longlong_array(long long A[], int len);
long avgGap(long long A[], int len);

long long* binarySearch(long long A[], int len, long long val);
int compar(const void* a, const void* b);
int comply(long long a, long long b, long long upBound, long long lowBound);
section_t* findSection(long long A[], int len, long long lowBound, long long upBound, long long val);
int findTval(long long A[], int len, long long lowBound, long long upBound);

/*hashtable.c*/
long hash(long long val, long long upBound, long long lowBound);
void insertion(adjarr_t* sepreateChain, data_t val, long long upBound, long long lowBound);
adjarr_t* initSepreateChain(long long upBound, long long lowBound, long long max, long long min);
long searchY(data_t x,long long upBound, long long lowBound);
void hashData(adjarr_t* sepreateChain, long long data[], long len, long long upBound, long long lowBound);
long long* searchList(list_t* list, long long val, long long upBound, long long lowBound, long long* t, long* pindex_t);
int findT(adjarr_t* sepreateChain, long long* data, long len, long long upBound, long long lowBound);
#endif
