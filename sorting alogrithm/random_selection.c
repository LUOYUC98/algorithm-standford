#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/* i = 0, j=0

if i is the boundary for the two parts, j is the boundary to indicate partitioned and unpartitioned
everytime when finishing one step in linear scan we increment j, if we find A[j]>pivot, else we need 
one more step, swapping A[j] and A[i] and increment i

finally we will swap pivot with A[i]*/
void shuffle(int array[], size_t n)
{
    if (n > 1) 
    {
        size_t i;
        for (i = 0; i < n - 1; i++) 
        {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          int t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}


void print_array(int A[],int len){
	for (int i = 0; i < len; ++i)
	{
		printf("%d ", A[i]);
	}
	putchar('\n');
}



int choosePivot(int A[], int len){
	return rand()%len;
}

void swap(int*p,int*q){
	int temp = *p;
	*p = *q;
	*q = temp;
}


int partition(int A[], int len){

  int i,j;
	int pivot = choosePivot(A, len);
  swap(A+pivot, A);
  i = j = 1;
	while(j<len){
		if(A[j]<A[0]){
			swap(A+j,A+i);
			i++;
		}
		j++;
	}
	swap(A+i-1, A);
  printf("\n");
	return i;
}

void Rselect(int A[], int len, int ith_statistic){
  printf("join in rselect:\n");
  print_array(A, len);
  if(len==1){
    printf("the only one rest = %d\n",A[0]);
    return;
  }
  int pivot_curr_pos = partition(A, len)-1;
  printf("pick pivot index = %d\n", pivot_curr_pos);
  printf("after reorder, array:\n");
  print_array(A,len);
  printf("ith_statistic = %d, pivot_curr_pos = %d\n",ith_statistic,pivot_curr_pos);
  if(ith_statistic == pivot_curr_pos){
    printf("find %dth statistic as %d",ith_statistic, A[ith_statistic]);
    return;
    }
  else if(ith_statistic > pivot_curr_pos){
    return Rselect(A+pivot_curr_pos+1,len-pivot_curr_pos-1, ith_statistic-pivot_curr_pos-1);
  }
  else{
    return Rselect(A, pivot_curr_pos, ith_statistic);
  }


}



int main(int argc, char const *argv[])
{
  srand(time(NULL));

	int A[100];
	int len = 100;
	for(int i = 0;i<len;i++){
		A[i] = 2*i;
	}
	shuffle(A, len);
	print_array(A,len);
	Rselect(A, len, 93);
	return 0;
}














