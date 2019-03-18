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
*insert_at_foot(list_t *list, data_t value) {
	node_t *_new;
	_new = (node_t*)malloc(sizeof(*_new));
	assert(list!=NULL);
  assert(_new!=NULL);
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
    printf("%c, %1f\n", curr->data.label, curr->data.weight);
    curr = curr->next;
  }
}

int get_len_linklist(list_t* list){
  node_t* curr = list->head;
  int i;
  for(i = 0; curr!=NULL; i++){
    curr = curr->next;
  }
  return i;
}


void print_int_array(int A[], int len){
  for(int i = 0; i<len; i++){
    printf("%d ", A[i]);
  }
  puts("\n");
}

list_t
*insert_at_head(list_t *list, data_t value) {
	node_t *_new;
	_new = (node_t*)malloc(sizeof(*_new));
	assert(list!=NULL && _new!=NULL);
	_new->data = value;
	_new->next = list->head;
	list->head = _new;
	if (list->foot==NULL) {
		/* this is the first insertion into the list */
		list->foot = _new;
	}
	return list;
}