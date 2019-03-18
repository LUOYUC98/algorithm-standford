#include<stdio.h> 
#include<stdlib.h> 
#include<assert.h>
#include "common.h"
list_t
*make_empty_list(void) {
	list_t *list;
	list = (list_t*)malloc(sizeof(*list));
	assert(list!=NULL);
	list->head = list->foot = NULL;
	return list;
}

list_t
*insert_at_foot(list_t *list, int value) {
	node_t *_new;
	_new = (node_t*)malloc(sizeof(*_new));
	assert(list!=NULL && _new!=NULL);
	_new->data = value;
	_new->next = NULL;
	if (list->foot==NULL) {
		list->head = list->foot = _new;
	} else {
		list->foot->next = _new;
		list->foot = _new;
	}
	return list;
}

void print_list(node_t* head){
  node_t* curr = head;
  while(curr!=NULL){
    printf("%d ", curr->data);
    curr = curr->next;
  }
}

void print_adjacent_array(list_t** arr, int len){
  for(int i = 0; i<len; i++){
    if(arr[i]->head){
      print_list(arr[i]->head);
      puts("\n\n");
    }
    else{
      continue;
    }
  }
  return;
}

int get_len_linklist(list_t* list){
  node_t* curr = list->head;
  int i;
  for(i = 0; curr!=NULL; i++){
    curr = curr->next;
  }
  return i;
}

