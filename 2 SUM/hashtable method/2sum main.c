#include<stdio.h>
#include<stdlib.h>
#include <assert.h>
#include<time.h>
#include<string.h>
#include "common.h"




int main(){
  long long upBound = 10000;
  long long lowBound = -10000;
  int len = countlines("test.txt");
  long long* data = loadFile("test.txt", len);
  len = dupFilter(data, len);
  data = (long long*)realloc(data, sizeof(long long)*len);
  adjarr_t* sepreateChain = initSepreateChain(upBound, lowBound, data[len-1], data[0]);
  hashData(sepreateChain, data, len, upBound, lowBound);
  int result = findT(sepreateChain, data, len,  upBound, lowBound);
  printf("result = %d\n", result);
  return 0;  
}