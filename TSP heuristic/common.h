#ifndef HEADER_FILE
#define HEADER_FILE
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<assert.h>
#define SEARCHX 1
#define SEARCHY 2

typedef struct float_matrix {
  float** arr;
  unsigned long long ho;
  unsigned long long ve;
} float_matrix_t;





typedef struct city {
  int city_id;
  float x;
  float y;
} city_t;

typedef struct array {
  city_t* arr;
  int len;
} array_t;

typedef struct candidate {
  int* cities;
  int len;
} cand_t;

typedef struct constraint {
  int left;
  int rght;
  int up;
  int down;
} constraint_t;



/*read*/
array_t* read_file(const char* fn);
void print_int_arr(int len, int*A);

float_matrix_t* float_matrix_init(unsigned long long ho, unsigned long long ve);

void print_float_matrix(float_matrix_t* matrix);

/*tsp*/
array_t* visitable(int curr_city, array_t* all_cities);
array_t* all_cities(float_matrix_t* matrix);
float city_distance(array_t* array, int city_a, int city_b);
int compar_dis(const void* a, const void* b);
constraint_t* get_constraint(int curr_city, array_t* array, constraint_t* constraint);
/*utility*/
city_t* binarySearch(city_t A[], int len, float val, int mode);
void print_constraint(constraint_t* constraint);
void print_array(array_t* array);
int compar_dis(const void* a, const void* b);
#endif
