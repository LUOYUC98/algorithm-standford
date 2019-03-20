#include "common.h"

const char* tsp = "tsp.txt";
const char* small = "small.txt";

int main(){
  array_t* array = read_file(small);
  qsort(array->arr, array->len, sizeof(city_t),compar_dis);
  constraint_t* constraint = (constraint_t*)malloc(sizeof(constraint_t));
  print_array(array);
  constraint = get_constraint(4, array,constraint);
  print_constraint(constraint);
  return 0;
}
