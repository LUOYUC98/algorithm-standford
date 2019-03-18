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
	assert(list!=NULL);
  assert(_new!=NULL);
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

