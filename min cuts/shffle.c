#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<ctype.h>
#include<assert.h>
#include "common.h"

void SwapObjects (void* vp1,void* vp2,int size)
{
    char* buf = (char*)malloc(size);
    memcpy(buf,vp1,size);
    memcpy(vp1,vp2,size);
    memcpy(vp2,buf,size);
}

void shuffle_array(data_t arr[], int n, int size)
{
    srand(time(NULL));
    if (n > 1) 
    {
        int i;
        for (i = 0; i < n - 1; i++) 
        {
          int j = i + rand() / (RAND_MAX / (n - i) + 1);
          SwapObjects(arr+i, arr+j, size);
        }    
    }
}

void shuffle_adjacent_list(list_t* adjacent_list[], int n, int size)
{
    srand(time(NULL));
    if (n > 1) 
    {
        int i;
        for (i = 0; i < n - 1; i++) 
        {
          int j = i + rand() / (RAND_MAX / (n - i) + 1);
          SwapObjects(adjacent_list+i, adjacent_list+j, size);
        }    
    }
}

/*O(n) for shuffling a linked list*/
void shuffle_linklist(list_t* list, int len){
  data_t temp[len-1];
  node_t* curr = list->head->next;
  for(int i = 0; i<len-1 && curr!=NULL; i++){
    temp[i] = curr->data;
    curr = curr->next;
  }
  shuffle_array(temp,  len-1, sizeof(data_t));
  int i = 0;
  for(curr = list->head->next;curr!=NULL; curr = curr->next){
    curr->data = temp[i];
    i++;
  }
  
}

void shuffle(array_t* arr){
  shuffle_adjacent_list(arr->arr, arr->len, sizeof(list_t*));
  for(int i = 0; i<arr->len; i++){
  shuffle_linklist(arr->arr[i], get_len_linklist(arr->arr[i]));
  }
}