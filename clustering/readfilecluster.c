#include<stdio.h>
#include<stdlib.h>
#include"common.h"

int get_vertex_num(const char*fm){
  int len;
  FILE* fp = fopen(fm, "r");
  fscanf(fp, "%d", &len);
  rewind(fp);
  fclose(fp);
  return len;
}

int get_edge_num(const char*fm){
  FILE*fp = fopen(fm, "r");
  int ch;
  int lines = 0;
  while(fgetc(fp)!='\n');
  while((ch = fgetc(fp))!=EOF){
    if(ch =='\n'){
      lines++;
    }
  }
  return lines;
}



void load_data(const char*fm, edge_t edge_arr[], int len){
  FILE* fp = fopen(fm, "r");
  int a, b, c;
  while(fgetc(fp)!='\n');
  edge_t *edge = (edge_t*)malloc(sizeof(edge_t));

  for(int i = 0; i<len; i++){
    fscanf(fp, "%d %d %d", &edge->dot1, &edge->dot2, &edge->length);
    edge_arr[i] = *edge;
  }

}  

