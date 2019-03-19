#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<assert.h>
#include "common.h"

float distance(float a, float b, float x, float y){
  return sqrt((a-x)*(a-x)+(b-y)*(b-y));
}

int max(int a, int b){
  if(a > b){
    return a;
  }
  return b;
}


long combination(int total, int items){
  long denom, numer;
  denom = numer = 1;
  int big = max(total - items, items);
  for(int i = big+1; i <= total; i++){
    numer *= i;
  }
  for(int i = 2; i <= total - big; i++){
    denom *= i;
  }
  return numer/denom;

}



float_matrix_t* city_distance(float_matrix_t* matrix){
  float_matrix_t* city_dis = float_matrix_init(matrix->ho, matrix->ho);
  for(int i = 0; i < matrix->ho; i++){
    for(int j = 0; j < matrix->ho; j++){
      city_dis->arr[i][j] =  distance(matrix->arr[0][i], matrix->arr[1][i], matrix->arr[0][j], matrix->arr[1][j]);
    }
  }
  return city_dis;
}


int_matrix_t* seq_init(float_matrix_t* city_dis){
  int_matrix_t* path = int_matrix_init(1, city_dis->ve-1);
  for(int i = 2; i <= city_dis->ve; i++){
    path->arr[i-2][0] = i;
  }
  return path;
}


int_matrix_t* path_generator(int_matrix_t* path, float_matrix_t* city_dis){
  int_matrix_t* new_path = int_matrix_init(path->ho+1, combination(city_dis->ve-1, path->ho+1));
  int index = 0;
  for(int i = 0; i < path->ve; i++){
    for(int j = path->arr[i][path->ho-1]+1; j <= city_dis->ve; j++){
      memcpy(new_path->arr[index], path->arr[i], sizeof(int)*path->ho);
      new_path->arr[index][new_path->ho-1] = j;
      index++;
    }
  }
  return  new_path;
}


long combo_sum(int from, int successive, int items){
  long sum = 0;
  for(int i = 0; i < successive; i++){
    sum+=combination(from-i, items);
  }
  return sum;
}


int get_index(int_matrix_t* path, int*seq, int cities){
  int jump[path->ho];
  jump[0] = seq[0] - 2;
  for(int i = 1; i < path->ho; i++){
    jump[i] = seq[i] - seq[i-1]-1;
  }
  long index;
  int curr_block, curr_items;
  index = combo_sum(cities-2, jump[0], path->ho-1);
  curr_block = cities-2-jump[0];
  curr_items = path->ho-1;

  for(int i = 1; i < path->ho; i++){
    index += combo_sum(--curr_block, jump[i], --curr_items);
    curr_block-= jump[i];
  }
  return index;
}


cache_t* init_cache(int_matrix_t* init, float_matrix_t* city_dis){
  cache_t* cache =(cache_t*)malloc(sizeof(cache_t));
  cache->cache = float_matrix_init(1, city_dis->ve-1);
  for(int i = 0; i < cache->cache->ve; i++){
    cache->cache->arr[i][0] = city_dis->arr[0][i+1];
  }
  cache->buffer = float_matrix_init(2, combination(city_dis->ve-1, 2));
  return cache;
}



int equal(int* a, int*b, int len){
  for(int i = 0; i < len; i++){
    if(a[i]!=b[i]){
      return 0;
    }
  }
  return 1;
}

float get_final_hop(float_matrix_t* city_dis, int target_index, int* seq, float_matrix_t* prev_val, int_matrix_t* prev_path){
  int buffer[prev_path->ho];
  int index = 0;
  for(int i = 0; i < prev_path->ho+1; i++){
    if(i == target_index){
      continue;
    }
    buffer[index++] = seq[i];
  }
  index = get_index(prev_path, buffer, city_dis->ve);
  assert(equal(prev_path->arr[index], buffer, prev_path->ho));
  float curr, min = INFINITY;
  for(int i = 0; i < prev_path->ho; i++){
    if((curr = prev_val->arr[index][i] +city_dis->arr[seq[target_index]-1][buffer[i]-1]) < min){
      min = curr;
    }
  }
  return min;
}


int_matrix_t* transform(cache_t* cache, float_matrix_t* city_dis, int_matrix_t* prev_path){
  int_matrix_t* new_path = path_generator(prev_path, city_dis);
  for(long i = 0; i < new_path->ve; i++){
    for(int j = 0; j < new_path->ho; j++){
      
      cache->buffer->arr[i][j] = get_final_hop(city_dis, j, new_path->arr[i], cache->cache, prev_path);
    }
  }
  cache->cache = resize(cache->cache, city_dis->ve-1);
  float_matrix_cpy(cache->cache, cache->buffer);
  cache->buffer =  resize(cache->buffer, city_dis->ve-1);
  free_int_matrix(prev_path);
  return new_path;
}

float tsp_algo(float_matrix_t* city_dis){
  int_matrix_t* path = seq_init(city_dis);
  cache_t* cache = init_cache(path, city_dis);
  for(int i = 0; i < city_dis->ho-2; i++){
    path = transform(cache, city_dis, path);
  }
  float curr, min = INFINITY;
  for(int i = 0; i < cache->cache->ho; i++){
    if((curr = cache->cache->arr[0][i] + city_dis->arr[0][i+1])<min){
      min = curr;
    }
  }
  printf("min = %f", min);
  return min;
}








