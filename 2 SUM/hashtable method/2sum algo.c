#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<assert.h>
#include "common.h"

int compar(const void* a, const void* b){
  long long result =  *(long long*)a - *(long long*)b;
  if(result > 0){
    return 1;
  }
  else if(result == 0){
    return 0;
  }
  return -1;
}





long long* binarySearch(long long A[], int len, long long val){
  if(len == 1){
    return A;
  }
  if(val<A[len/2]){
    return binarySearch(A, len/2, val);
  }
  return binarySearch(A+len/2, len-len/2, val);
}

section_t* findSection(long long A[], int len, long long lowBound, long long upBound, long long val){
  section_t* section= (section_t*)malloc(sizeof(section_t));
  

  section->start = NULL;
  section->end = NULL;
  long long* indexend = binarySearch(A, len, upBound-val);
  long long* indexstart = binarySearch(A, len, lowBound-val);
  if(*indexstart<lowBound-val){
    indexstart++;
  }

  if((*indexstart<=*indexend) && (*indexstart<=upBound-val) && (*indexend>=lowBound-val)){
    section->start = indexstart;
    section->end = indexend;
  }
  return section;
}

int dupFilter(long long A[], int len){
    qsort(A, len, sizeof(long long), compar);
  int curr;
  for(curr = 1; curr<len; curr++){
    if(A[curr] == A[curr-1]){
      A[curr-1] = NULLKEY;
    }
  }
  int index = 0;
  for(curr = 0; curr<len; curr++){
    if(A[curr]!=NULLKEY){
      A[index] = A[curr];
      index++;
    }
  }
  return index;
}


int findTval(long long A[], int len, long long lowBound, long long upBound){
  long long* t = (long long*)malloc(sizeof(long long));
  int index = 0;
  section_t* section;
  long long* curr;
  int i;
  for(i = 0; i<len; i++){
    section = findSection(A, len, lowBound, upBound, A[i]);
    curr = section->start;
    if(section->start!=NULL&&section->end!=NULL&&*curr!=A[i]){
      do{
        t[index] = *curr+A[i];
        curr++;
        index++;
        t = (long long *)realloc(t, sizeof(long long)*(index+1));
        
      }while(curr <= section->end);
    }
  }
  return dupFilter(t, index);
}

