#include <stdio.h>
#include<stdlib.h>
#include"common.h"


void fuse_two_mins(heap_t* H){
  data_t* left = removeMin(H);
  data_t* rght = removeMin(H);
  data_t* _new = (data_t*)malloc(sizeof(data_t));
  _new->weight = left->weight+rght->weight;
  _new->symbol = INTERAL_VAL;
  _new->left = left;
  _new->rght = rght;
  insertVal(H, _new);
}

void construct_HT(heap_t* H){
  while(H->heapsize>1){
    fuse_two_mins(H);
  }

}



int recursive_get_depth(data_t *node){
  if(!node){
    return 0;
  }

  int ldepth = recursive_get_depth(node->left);
  int rdepth = recursive_get_depth(node->rght);
  if(ldepth>rdepth){
    return ldepth+1;
  }
  else{
    return rdepth+1;
  }

}

int get_depth(heap_t* H){
  data_t *root = H->data[0];
  return recursive_get_depth(root);
}

int min(int a, int b){
  if(a<b){
    return a;
  }
  return b;
}



int minDepth(data_t *root) 
{ 
    // Corner case. Should never be hit unless the code is  
    // called on root = NULL 
    if (root == NULL) 
        return 0; 
  
    // Base case : Leaf Node. This accounts for height = 1. 
    if (root->left == NULL && root->rght == NULL) 
    return 1; 
  
    // If left subtree is NULL, recur for right subtree 
    if (!root->left) 
    return minDepth(root->rght) + 1; 
  
    // If right subtree is NULL, recur for left subtree 
    if (!root->rght) 
    return minDepth(root->left) + 1; 
  
    return min(minDepth(root->left), minDepth(root->rght)) + 1; 
} 
