#include <stdio.h>
#include<stdlib.h>
#include"common.h"
const char *fn = "mwis.txt";
int index_[8] = { 1, 2, 3, 4, 17, 117, 517, 997};

int main(){
  array_t* weight_set = readfile(fn);
  array_t *storage = init_storage(weight_set);
  wis(weight_set, storage, 0);
  int* path = reconstruct(storage, weight_set);
  for(int i = 0; i<8; i++){
    printf("%d", path[index_[i]]);
  }
  return 0;
}




