#include <stdio.h>
#include<stdlib.h>

typedef struct array{
  unsigned long* arr;
  int len;
}array_t;



array_t* readfile(const char* fn);

array_t* init_storage(array_t*weight_set);
array_t* wis(array_t*weight_set, array_t* storage, int i);
int* reconstruct(array_t* storage, array_t*weight_set);
int verify(array_t* weight_set, array_t*storage, int* path);