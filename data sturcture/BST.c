#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node node_t;
int cmp(void*a, void*b);
struct node {
	void *data;              /* ptr to stored structure */
	node_t *left;            /* left subtree of node */
	node_t *rght;            /* right subtree of node */
};

typedef struct {
	node_t *root;            /* root node of the tree */
	int (*cmp)(void*,void*); /* function pointer */
} tree_t;


tree_t
*make_empty_tree(int func(void*,void*)) {
	tree_t *tree;
	tree = malloc(sizeof(*tree));
	assert(tree!=NULL);
	/* initialize tree to empty */
	tree->root = NULL;
	/* and save the supplied function pointer */
	tree->cmp = func;        
	return tree;
}

int
is_empty_tree(tree_t *tree) {
	assert(tree!=NULL);
	return tree->root==NULL;
}



node_t* recursive_search_tree(node_t *root, void*key){
  /*HAVE to confirm that the new recursion is runnable and not
  extend to further recusion, the return NULL is meaning that under the circumstance that we havent found the key in the tree but time to hold it since it reachs the depest*/
  	if (!root) {
		return NULL;
	}
  int outcome = cmp(key, root->data);
  printf("key = %d, root->data = %d\n", *(int*)(key), *(int*)(root->data));
  printf("outcome = %d\n", outcome);
  if(outcome>0){
    printf("go right\n");
    recursive_search_tree(root->rght, key);
  }
  else if(outcome<0){
    printf("go left\n");
    recursive_search_tree(root->left, key);
  }
  else{
    printf("found!");
    return root->data;
  }
}

















static node_t *recursive_insert(node_t*, node_t*,
		int(void*,void*));




static node_t* recursive_insert(node_t*root, node_t*new, int cmp(void*, void*)){
  if(root == NULL){return new;}
  int outcome = cmp(new->data, root->data);
  if(root!=NULL){
  if(outcome>0){
    root->rght = recursive_insert(root->rght, new, cmp);
               }
  else{
    root->left = recursive_insert(root->left, new, cmp);
      } 
  }


}








tree_t* insert_in_order(tree_t* tree, void*data){
  node_t* new = (node_t*)malloc(sizeof(node_t));
  assert(tree!=NULL&&new!=NULL);
  new->rght = NULL;
  new->left = NULL;
  new->data = data;
  tree->root = recursive_insert(tree->root, new, cmp);
  return tree;
}



void preorder(node_t* root){
  if(root == NULL){return;}
  printf("data = %d\n", *(int*)root->data);
  preorder(root->left);
  preorder(root->rght);
}




static void recursive_free_tree(node_t*);

static void
recursive_free_tree(node_t *root) {
	if (root) {
		recursive_free_tree(root->left);
		recursive_free_tree(root->rght);
		free(root);
	}
}

/* Release all memory space associated with the tree
   structure. */
void
free_tree(tree_t *tree) {
	assert(tree!=NULL);
	recursive_free_tree(tree->root);
	free(tree);
}

int 
cmp(void*a, void*b){
  int *int_a = a;
  int *int_b = b;
  return *int_a-*int_b;
}




int main(){
  tree_t* tree = make_empty_tree(cmp);
  int A[10] = {2,1,5,3,4,6,8,7,0,9};
  for(int i = 0; i<10; i++){
  insert_in_order(tree, (A+i));
  }
  recursive_search_tree(tree->root,A+2);
  //preorder(tree->root);
  return 0;
} 