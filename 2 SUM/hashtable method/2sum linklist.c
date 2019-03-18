
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include"common.h"



/* function prototypes -------------------------------------------------------*/

// list operations


/* end function prototypes ---------------------------------------------------*/


list_t
*make_empty_list(void) {
	list_t *list;
	list = (list_t*)malloc(sizeof(*list));
	assert(list!=NULL);
	list->head = list->foot = NULL;


	return list;
}

int
is_empty_list(list_t *list) {
	assert(list!=NULL);
	return list->head==NULL;
}

void
free_list(list_t *list) {
	node_t *curr, *storage;
	assert(list!=NULL);
	curr = list->head;
	while (curr) {
		storage = curr;
		curr = curr->next;
		free(storage);
	}
	free(list);
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

list_t
*insert_at_foot(list_t *list, data_t value) {
	node_t *_new;
	_new = (node_t*)malloc(sizeof(*_new));
	assert(list!=NULL && _new!=NULL);
	_new->data = value;
	_new->next = NULL;
	if (list->foot==NULL) {
		/* this is the first insertion into the list */
		list->head = list->foot = _new;
	} else {
		list->foot->next = _new;
		list->foot = _new;
	}
	return list;
}

list_t
*insert_in_order(list_t* list, data_t value){
	node_t *_new = (node_t*)malloc(sizeof(node_t));
	_new->data = value;
	node_t *curr = list->head;
	node_t *prev = NULL;
  
	if(curr == NULL){
		list->head = _new;
		list->foot = _new;
		return list;
	}
	while(curr!=NULL){
		if(_new->data <= curr->data){
			break;
		}
		prev = curr;
		curr = curr->next;
	}
	if(prev == NULL && curr!=NULL){
		list->head = _new;
		_new->next = curr;
	}
  else if(prev!=NULL && curr!=NULL){
		prev->next = _new;
		_new->next = curr;
	}
	else{
		prev->next = _new;
		_new->next = curr;
		list->foot = _new;
	}
	return list;
}

int get_len(list_t* list){
  int len = 0;
  assert(list!=NULL);
  node_t* curr = list->head;
    while(curr!=NULL){
    len++;
    curr = curr->next;
  }
  return len;
}



data_t list_pop(list_t* list, unsigned index){
    int len = get_len(list);
    assert(len && index<len && list!=NULL);
    node_t* curr = list->head;
    node_t* prev = NULL;
    if(list->head == list->foot){
        if(index == 0){
        list->head = NULL;
        list->foot = NULL;
        return curr->data;
        }
    }
    else{
        for(int i = 0;i<index;i++){
        prev = curr;
        curr = curr->next;
        }
        if(prev!=NULL && curr->next!= NULL){
        prev->next = curr->next;
        curr->next = NULL;
        }
        else if(prev!=NULL && curr->next == NULL){
        prev->next = curr->next;
        list->foot = prev;    
        }
        else{
            list->head = curr->next;
        }       
    }
    return curr->data;
}