#include<stdio.h>
#include<stdlib.h>
#include "common.h"

const char* f1 = "test cases/g1.txt";
const char* f2 = "test cases/g2.txt";
const char* f3 = "test cases/g3.txt";
const char* large = "test cases/large.txt";
const char* test = "test cases/test.txt";
const char* test2 = "test cases/test2.txt";
const char* test3 = "test cases/test3.txt";
const char* johnson = "test cases/johnson.txt";
int main(){
  int result_johnson = johnson_algo(read_file(f3));
  int result_floyd_warshall = floyd_warshall(readfile(f3));
 
  return 0;
}