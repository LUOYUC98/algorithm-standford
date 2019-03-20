#include "common.h"
/*https://github.com/beaunus/stanford-algs/*/
void print_int_arr(int len, int*A){
  puts("buffer: ");
  for(int i = 0; i < len; i++){
    printf("%d ", A[i]);
  }
  puts("\n");
  
}


city_t* binarySearch(city_t A[], int len, float val, int mode){
  if(len == 1){
    return A;
  }
  if(mode == SEARCHX){
    if(val<A[len/2].x){
      return binarySearch(A, len/2, val, SEARCHX);
    }
    return binarySearch(A+len/2, len-len/2, val, SEARCHX);
  }
  if(val<A[len/2].y){
      return binarySearch(A, len/2, val, SEARCHY);
    }
  return binarySearch(A+len/2, len-len/2, val, SEARCHY);
  
}

void print_constraint(constraint_t* constraint){
  printf("left_right:%d<--->%d\n",constraint->left, constraint->rght);
  printf("down_up:%d<--->%d\n",constraint->down, constraint->up);
}


void print_array(array_t* array){
  for(int i = 0; i< array->len; i++){
    printf("city%d： x = %f, y = %f\n", i, array->arr[i].x, array->arr[i].y);
  }

}


int compar_dis(const void* a, const void* b){
  city_t city_a = *(city_t*)a;
  city_t city_b = *(city_t*)b;
  if(city_a.x > city_b.x){
    return 1;
  }
  else if(city_a.x == city_b.x){
    if(city_a.y > city_b.y){
      return 1;
    }
    return 0;
  }
  return 0;
}
