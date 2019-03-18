#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<ctype.h>
#include<assert.h>
#include"common.h"

void print_adjacent_array(list_t** arr, int len){
  for(int i = 0; i<len; i++){
    if(arr[i]->head){
      printf("arr[%d]: \n",i);
      print_list(arr[i]->head);
      puts("\n");
    }
    else{
      continue;
    }
  }
  return;
}

int get_index(char ch){
  return ch-65;
}

int get_max(int a, int b){
  if(a<b){
    return b;
  }
  return a;
}

int get_min(int a, int b){
  if(a<b){
    return a;
  }
  return b;
}

array_t* read_digraph(const char* filename){
  	array_t* arr = (array_t*)malloc(sizeof(array_t*));

  	FILE* fp = fopen(filename, "r");
    float weight;
    char from, to;
    int max, min, max_temp, min_temp;
    max = 0, min = 255;
    while(fscanf(fp, " %c,%f,%c", &from, &weight, &to)!=EOF){
      max_temp = get_max(get_index(from), get_index(to));
      min_temp = get_min(get_index(from), get_index(to));
      if(max_temp>max){
        max = max_temp;
      }
      if(min_temp<min){
        min = min_temp;
      }

    }
    arr->len = max-min+1;
  arr->arr = (list_t**)malloc(sizeof(list_t*)*(max-min+1));
  data_t *data = (data_t*)malloc(sizeof(data_t));
  for(int i = 0; i<arr->len;i++){
    arr->arr[i] = make_empty_list();
    data->label = (char)(i+65);
    data->weight = 0.0;
    arr->arr[i] = insert_at_foot(arr->arr[i], *data);
  }
  rewind(fp);
  
  while(fscanf(fp, " %c,%f,%c", &from, &weight, &to)!=EOF){
      data->weight = weight;
      data->label = to;
      arr->arr[get_index(from)] = insert_at_foot(arr->arr[get_index(from)], *data);
   }
  return arr;
}
