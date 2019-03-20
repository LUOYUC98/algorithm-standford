
#include "common.h"


array_t* read_file(const char* fn){
  FILE* fp = fopen(fn, "r");
  array_t* array = (array_t*)malloc(sizeof(array_t));
  fscanf(fp, "%d", &array->len);
  array->arr = (city_t*)malloc(sizeof(city_t)*array->len);
  for(int i = 0; i < array->len; i++){
    fscanf(fp, "%d %f %f", &array->arr[i].city_id, &array->arr[i].x, &array->arr[i].y);
    
  }
  return array;
}



     
