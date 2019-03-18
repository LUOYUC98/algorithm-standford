#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include "common.h"


void printAdjarr(adjarr_t* adjarr, long long upBound, long long lowBound){
  node_t* curr = NULL;
  printf("len = %li\n", adjarr->len);
  for(int i = 0; i<adjarr->len; i++){
    printf("adjarr[%li] = ", i-adjarr->neglen);
    if(adjarr->arr[i]->head == NULL){
      continue;
    }
    int count = 0;
    curr = adjarr->arr[i]->head;
    while(curr!=NULL&&count<=0){
      printf("%lli \n", curr->data);
      //printf("hash = %lli\n", (curr->data)/(upBound-lowBound));
      curr = curr->next;
      count++;
    }
    //puts("\n");
  }
  
}
