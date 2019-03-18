#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>
#include<string.h>
#include "common.h"

int comply(long long a, long long b, long long upBound, long long lowBound){

  return(a+b<=upBound)&&(a+b>=lowBound)&&(a!=b);
}

long long absolute(long long val){
  if(val<0){
    return -val;
  }
  return val;
}

long hash(long long val, long long upBound, long long lowBound){
  if(val>0){
  return val/(upBound-lowBound);
  }
  return val/(upBound-lowBound)-1;
}


void insertion(adjarr_t* sepreateChain, data_t val, long long upBound, long long lowBound){
  long index = hash(val, upBound, lowBound);
  sepreateChain->arr[sepreateChain->neglen+index] = insert_at_foot(sepreateChain->arr[sepreateChain->neglen+index], val);
}

long searchY(data_t x,long long upBound, long long lowBound){
  long index_X = hash(x, upBound, lowBound);
  return -index_X;
}

adjarr_t* initSepreateChain(long long upBound, long long lowBound, long long max, long long min){
  long long nmax;
  long long nmin;
  if(max<0){
    nmax = -max;
  }
  else{
    nmax = max;
  }
  if(min<0){
    nmin = -min;
  }
  else{
    nmin = min;
  }
  long negtiveLen, positiveLen;

  positiveLen = nmax/((upBound-lowBound))+1;
  negtiveLen = nmin/((upBound-lowBound))+1;
  adjarr_t* sepreateChain = (adjarr_t*)malloc(sizeof(adjarr_t*));
  sepreateChain->arr = (list_t**)malloc(sizeof(list_t*)*(negtiveLen+positiveLen));
  for(long i = 0; i<negtiveLen+positiveLen;i++){
    sepreateChain->arr[i] = make_empty_list();
  }
  sepreateChain->neglen = negtiveLen;
  sepreateChain->poslen = positiveLen;
  sepreateChain->len = negtiveLen+positiveLen;
  return sepreateChain;
}


void hashData(adjarr_t* sepreateChain, long long data[], long len, long long upBound, long long lowBound){
  for(int i = 0; i<len; i++){
    insertion(sepreateChain, data[i], upBound, lowBound);
  }
}

long long* searchList(list_t* list, long long val, long long upBound, long long lowBound, long long* t, long* pindex_t){
  node_t* curr;
  if(list!=NULL){
    curr = list->head;
    
    while(curr!=NULL){
      if(comply(val,curr->data, upBound, lowBound)){
        t[*pindex_t] = val+curr->data;
        *pindex_t = *pindex_t+1;
        t = (long long *)realloc(t, sizeof(long long)*(*pindex_t+1));
      }
      curr = curr->next;
    }
  }
  return t;
}



int findT(adjarr_t* sepreateChain, long long* data, long len, long long upBound, long long lowBound){
  long long* t = (long long*)malloc(sizeof(long long));
  long index_t = 0;
  long* pindex_t = &index_t;
  long index;
  node_t*curr;
  for(long i = 0; i<len; i++){
    index = searchY(data[i], upBound, lowBound);
    if(index<sepreateChain->poslen&&index-1>-sepreateChain->neglen){
      t = searchList((sepreateChain->arr+sepreateChain->neglen)[index], data[i], upBound, lowBound, t, pindex_t);
      t = searchList((sepreateChain->arr+sepreateChain->neglen)[index-1], data[i], upBound, lowBound, t, pindex_t);
    }
    else if(index>= sepreateChain->poslen&&index-1<sepreateChain->poslen){
      t = searchList((sepreateChain->arr+sepreateChain->neglen)[index-1], data[i], upBound, lowBound, t, pindex_t);
    }
    
    else if(index-1<=sepreateChain->neglen&&index>sepreateChain->neglen){
      t = searchList((sepreateChain->arr+sepreateChain->neglen)[index], data[i], upBound, lowBound, t, pindex_t);
    }
    else{
      continue;
    }
  }
  return dupFilter(t, index_t);
}