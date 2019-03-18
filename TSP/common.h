#ifndef HEADER_FILE
#define HEADER_FILE


typedef struct float_matrix {
  float** arr;
  unsigned long long ho;
  unsigned long long ve;
} float_matrix_t;

typedef struct int_matrix {
  int** arr;
  unsigned long long ho;
  unsigned long long ve;
  unsigned long long hops;
} int_matrix_t;


typedef struct cache {
  int_matrix_t* path;
  float_matrix_t* cache;
  float_matrix_t* buffer;
} cache_t;


float_matrix_t* read_file(const char* fn);

void print_int_arr(int len, int*A);

/*2darr*/
int_matrix_t* int_matrix_init(unsigned long long ho, unsigned long long ve);
float_matrix_t* float_matrix_init(unsigned long long ho, unsigned long long ve);
void free_float_matrix(float_matrix_t* A);
void print_float_matrix(float_matrix_t* matrix);
void print_int_matrix(int_matrix_t* matrix);
void free_int_matrix(int_matrix_t* A);

float_matrix_t* resize(float_matrix_t* prev, int cities);

void float_matrix_cpy(float_matrix_t* A, float_matrix_t* B);
/*tsp*/
float_matrix_t* city_distance(float_matrix_t* matrix);
unsigned long long combination(int total, int items);
unsigned long long multi_multiplication(int start, int end);
int_matrix_t* seq_init(unsigned long long cities);
int_matrix_t* path_generator(int_matrix_t* storage, int cities);
int get_index(int_matrix_t* prev, int*seq, int cities);
unsigned long long combo_sum(int from, int successive, int items);
void tester(int_matrix_t* prev,  int cities);
void complete_test(int cities);
cache_t* init_cache(int_matrix_t* init, float_matrix_t* city_dis);
int tsp_algo(float_matrix_t* city_dis);
int_matrix_t* transform(cache_t* cache, float_matrix_t* city_dis, int_matrix_t* prev_path);
float get_final_hop(float_matrix_t* city_dis, int target_index, int* seq, float_matrix_t* prev_val, int_matrix_t* prev_path);
#endif
