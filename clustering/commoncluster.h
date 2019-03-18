#ifndef HEADER_FILE
#define HEADER_FILE

typedef struct vertex{
  int dot;
  int rank;
  int parent;
}vertex_t;

typedef struct edge{
  int dot1;
  int dot2;
  int length;
}edge_t;

/*readfile*/
int get_vertex_num(const char*fm);
int get_edge_num(const char*fm);
void load_data(const char*fm, edge_t edge_arr[], int len);


/*preprocessing*/
int cmpfunc(const void*a, const void*b);
void init_vertex_arr(vertex_t vertex_arr[], int len);
/*print*/
void print_edge_arr(edge_t* edge_arr, int len);
void print_vertex_arr(vertex_t* vertex_arr, int len);

/*union-find*/
  vertex_t* find(vertex_t vertex_arr[], int dot);
  void uni(vertex_t* x, vertex_t* y, vertex_t arr_vertex[]);

/*clustering*/
int form_loop(vertex_t* x, vertex_t* y, vertex_t vertex_arr[]);
int clustering(edge_t edges_arr[], vertex_t vertex_arr[], int len, int clusters);
#endif
