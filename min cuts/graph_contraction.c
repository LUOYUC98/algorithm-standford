#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<ctype.h>
#include<assert.h>
#include"common.h"

void selfloop_deletion(list_t* list){

  node_t* head = list->head;
  node_t* curr = head->next;
  node_t* prev = head;
  while(curr!=NULL){

    if(curr->data == head->data){
      if(curr->next != NULL){
        curr = curr->next;
        free(prev->next);
        prev->next = curr;

        continue;
        
      }
      else{
        prev->next = NULL;
        free(curr);
  
        list->foot = prev;
        break;
      }
    }
    prev = curr;
    curr = curr->next;

  }

  list->foot = prev;


}

void contract(list_t**adjacent_array, int len){

  list_t* tag_list = adjacent_array[len-1];
  node_t* rest = tag_list->head->next;
  data_t replacement = rest->data;
  data_t tag_data = tag_list->head->data;
  free(tag_list);
  tag_list = NULL;
  int i;
  for(i = 0; i<len-1;i++){
    if(adjacent_array[i]->head->data == replacement){
      break;
    }
  }

  adjacent_array[i]->foot->next = rest;

  node_t* curr = adjacent_array[i]->head->next;
  while(curr!=NULL){
  
    if(curr->data == tag_data){
      curr->data = replacement;
    }
    curr = curr->next;
  }

  selfloop_deletion(adjacent_array[i]);

  for(int i = 0; i<len-1; i++){
    curr = adjacent_array[i]->head;
    while(curr!=NULL){
      if(curr->data == tag_data){
        curr->data = replacement;
      }
      curr = curr->next;
    }
  }

}

void graph_contraction(list_t** adjacent_array, int len){
  if(len == 2){
    return;
  }
  contract(adjacent_array, len);
  return graph_contraction(adjacent_array, len-1);
}

