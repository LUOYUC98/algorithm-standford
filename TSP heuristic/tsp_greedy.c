#include "common.h"






float distance(float a, float b, float x, float y){
  return sqrt((a-x)*(a-x)+(b-y)*(b-y));
}



float min(float a, float b){
  if(a>b){
    return b;
  }
  return a;
}


float city_distance(array_t* array, int city_a, int city_b){
  return distance(array->arr[city_a-1].x, array->arr[city_a-1].y, array->arr[city_b-1].x, array->arr[city_b-1].y);
}


constraint_t* get_constraint(int curr_city, array_t* array, constraint_t* constraint){
  float MIN;
  int city_up = curr_city-1;
  int city_down = curr_city+1;
  if(curr_city > 1 && curr_city < array->len){
    if(array->arr[city_up-1].x==array->arr[city_down-1].x){
      MIN = min(city_distance(array, city_up, curr_city),city_distance(array, city_down, curr_city))+1;
        printf("1MIN = %f\n", MIN);

    }
    else if(array->arr[city_up-1].x==array->arr[curr_city-1].x&&array->arr[city_down-1].x!=array->arr[curr_city-1].x){
      MIN = city_distance(array, city_up, curr_city)+1; 
        printf("2MIN = %f\n", MIN);

    }
    else{
      MIN = city_distance(array, city_down, curr_city)+1;
        printf("3MIN = %f\n", MIN);
    }
  }
  else{
    if(curr_city==1){
       MIN = city_distance(array, city_down, curr_city)+1;
    }
    else{
    MIN = city_distance(array, city_up, curr_city)+1;
    }
  }
  printf("MIN = %f\n", MIN);
  constraint->up = (int)(array->arr[curr_city-1].y+MIN);
  constraint->down = (int)(array->arr[curr_city-1].y-MIN);
  constraint->rght = (int)(array->arr[curr_city-1].x+MIN);
  constraint->left = (int)(array->arr[curr_city-1].x-MIN);
  if(constraint->left < array->arr[0].x){
    constraint->left = (int)(array->arr[0].x);
  }
  if(constraint->rght > array->arr[array->len-1].x){
    constraint->rght = (int)(array->arr[array->len-1].x);
  }
  return constraint;
}



cand_t* get_candidate(array_t* array, constraint_t* constraint){
  cand_t* cand = (cand_t*)malloc(sizeof(cand_t));
  cand->cities = (int*)malloc(sizeof(int));
  cand->len = 0; 
  int lowbound = binarySearch(array->arr, array->len, constraint->up, SEARCHX)-array->arr;
  int upbound = binarySearch(array->arr, array->len, constraint->down, SEARCHX)-array->arr;
  int block_start[upbound-lowbound+1];
  for(int i = 0; i < upbound-lowbound; i++){
    block_start[i] = 0;
  }
  block_start[0] = lowbound;
  int index = 0;
  for(int i = lowbound+1; i<= upbound; i++){
    if(array->arr[i+1].x!=array->arr[i].x){
      block_start[++index] = i+1;
    }
  }
  block_start[++index] = upbound;
  index = 0;
  for(int i = 0; i < index; i++){
    int up = binarySearch(array->arr+block_start[i], block_start[i+1] - block_start[i], constraint->up, SEARCHY)-array->arr;
    int down =  binarySearch(array->arr+block_start[i], block_start[i+1] - block_start[i], constraint->down, SEARCHY)-array->arr;
    for(int i = up; i<= down; i++){
      cand->cities[index++] = i;
      cand->cities = realloc(cand->cities, index+1);
    }
  }
  return cand;
}


