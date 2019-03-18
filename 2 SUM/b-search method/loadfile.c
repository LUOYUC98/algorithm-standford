#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include "common.h"

int countlines(char *filename)
{
  // count the number of lines in the file called filename                                    
  FILE *fp = fopen(filename,"r");
  int ch=0;
  int lines=0;

  if (fp == NULL){;
  return 0;
  }
  lines++;
  while ((ch = fgetc(fp)) != EOF)
    {
      if (ch == '\n')
    lines++;
    }
  fclose(fp);
  return lines;
}


long long* loadFile(const char* filename, int len){
  FILE* fp = fopen(filename, "r");
  long long* Data = (long long*)malloc(sizeof(long long)*len);
  for(int i = 0; i<len; i++){
    fscanf(fp, " %lli", Data+i);
  }
  return Data;
}
