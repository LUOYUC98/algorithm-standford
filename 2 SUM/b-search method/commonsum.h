#ifndef HEADER_FILE
#define HEADER_FILE
#define NULLKEY -33333
#define UPBOUND 10
#define LOWBOUND 3

typedef struct node node_t;


typedef int data_t;


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


typedef struct arr{
  list_t** arr;
  int len;
}adjarr_t;



/*load file.c*/
int countlines(char *filename);

long long* loadFile(const char* filename, int len);

/*preprocessing.c*/
int dupFilter(long long A[], int len);
void print_longlong_array(long long A[], int len);
long avgGap(long long A[], int len);

long long* binarySearch(long long A[], int len, long long val);
int compar(const void* a, const void* b);
section_t* findSection(long long A[], int len, long long lowBound, long long upBound, long long val);
int findTval(long long A[], int len, long long lowBound, long long upBound);
void printSection(section_t* section);
#endif
