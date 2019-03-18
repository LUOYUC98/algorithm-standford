#include<stdio.h>
#include<stdlib.h>
#include "common.h"

const char* tsp = "tsp.txt";
const char* small = "tspsmall.txt";
const char* little = "small.txt";

int main(){
  float_matrix_t* matrix = read_file(tsp);
  float_matrix_t* city_dis = city_distance(matrix);
  tsp_algo(city_dis);
  return 0;
}