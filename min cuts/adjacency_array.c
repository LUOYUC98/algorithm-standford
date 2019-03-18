#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<ctype.h>
#include<assert.h>
#include"common.h"

int cmp(const void* a, const void* b){
  //printf("%d")
  return ((list_t*)a)->head->data - ((list_t*)b)->head->data;
}


array_t* create_adjacent_list(const char* filename){
  array_t* arr = (array_t*)malloc(sizeof(array_t*));
  FILE * fp = fopen(filename, "r");
  int lines = 0;
  char ch;  
  while(!feof(fp))
  {
    ch = fgetc(fp);
    if(ch == '\n')
    {
      lines++;
    }
  }
  lines++;
  char line[MAXLEN], *p = line;
  rewind(fp);  
  
  list_t** adjacent_list = (list_t**)malloc(sizeof(list_t*)*lines);
  assert(adjacent_list);
  lines = 0;
  while(fgets(line, MAXLEN, fp)!=NULL)
  { 
    adjacent_list[lines] = make_empty_list();
    
    while (*p) 
    { 
      if (isdigit(*p)) 
      {
        long val = strtol(p, &p, 10); 
        adjacent_list[lines] = insert_at_foot(adjacent_list[lines], val);
      } 
      else
      {
        p++;
      }
    }
    p = line;
    lines++;
  }
  fclose(fp);
  arr->arr = adjacent_list;
  arr->len = lines;
  return arr;
}

void print_int_array(int A[], int len){
  for(int i = 0; i<len; i++){
    printf(" %d", A[i]);
  }
}


void free_adjacent_array(array_t* arr){
  list_t** adjacent_array = arr->arr;
  int len = arr->len;
  for(int i = 0; i<len; i++){
    
    node_t* curr = adjacent_array[i]->head;
    node_t* next;
    while(curr!=NULL){
      next = curr->next; 
       free(curr); 
       curr = next; 
    }
  free(adjacent_array[i]);
  }
  free(arr);
}
