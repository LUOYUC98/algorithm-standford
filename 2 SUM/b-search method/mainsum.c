#include<stdio.h>
#include<stdlib.h>
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
  int t = findTval(data, len, lowBound, upBound);
  printf("result = %d", t);

    return 0;  
}