#include <stdio.h>
#include<stdlib.h>
#include"common.h"

const char* fn = "huffman.txt";


int main(){
  heap_t* H = read_data(fn);
  int* ordered = heapSort(H);
  construct_HT(H);
  int height = get_depth(H);
  int min = minDepth(H->data[0]);
  printf("height,MIN = %d,%d\n", height-1, min-1);

  
 
  return 0;
}