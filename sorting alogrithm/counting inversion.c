#include <stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct array array_t;

struct array
{
	int* A;
	int len;
	
};


array_t* random_array_generation(){
	 array_t *retval = (array_t*)malloc(sizeof(array_t));
	 srand (time(NULL));
	 int num = 100000;
	 int *A = (int*)malloc(sizeof(int)*num);
	 for (int i = 0; i < num; ++i)
	 {
		A[i] = rand()%10000;
		
	 }
	 retval->len = num;
	 retval->A = A;
	 return retval;
}


int non_algorithmatic_counting_inversion(int A[], int len){
	if(len == 1)
	{
		return 0;
	}

	int count = 0;

	for (int i = 0; i < len; ++i)
	{
		for (int j = i+1; j < len; ++j)
		{
			if (A[i]>A[j])
			{
				count++;
			}
		}
	}
	printf("count = %d\n",count);
	return count;
}




long long merge_and_count(int *left, int left_len, int *rght, int rght_len){
	int i,j,k;
	 i = j = k = 0;
	long long inversion = 0;
	int temp[left_len+rght_len];
	while(i<left_len && j<rght_len){
    if(rght[j]<left[i]){
			inversion += left_len-i;
			for (int m = i; m < left_len; ++m)
			{
			}
      j++;
		}
    else{
      i++;
    }
    

  }
  i = j = 0;
	while(i<left_len && j<rght_len){
		if (left[i]<rght[j]){
		temp[k] = left[i];
		i++;
		}
		else{
			temp[k] = rght[j];
			j++;
		}
		k++;
	}
	while(i<left_len){
		temp[k] = left[i];
		i++;
		k++;
	}
	while(j<rght_len){
		temp[k] = rght[j];
		j++;
		k++;
	}
	for (int i = 0; i < left_len+rght_len; ++i)
	{
		left[i] = temp[i];
	}
	for (int i = 0; i < left_len; ++i)
	{
	}
		for (int i = 0; i < rght_len; ++i)
	{
	}

	return inversion;

}

long long algorithmatic_counting_inversion(int A[], int len){
	if(len == 1){
		return 0;
	}
	if(len == 2){
		if(A[0]>A[1]){
      int temp = A[0];
      A[0] = A[1];
      A[1] = temp;
			return 1;
		}
		return 0;
	}
	int mid = len/2;
	//printf("mid = %d\n", mid);
	int *left = A;
	int *rght = A+mid;
	int left_len = mid;
	long long rght_len = len-mid;
	long long left_inversion = algorithmatic_counting_inversion(left, left_len);
	long long rght_inversion = algorithmatic_counting_inversion(rght, rght_len);
	long long split_inversion = merge_and_count(left,left_len,rght,rght_len);
	return left_inversion+rght_inversion+split_inversion;
}





int main(int argc, char const *argv[])
{

	array_t *A = random_array_generation();
	//long long inversion = non_algorithmatic_counting_inversion(A->A, A->len);
	long long fuck = algorithmatic_counting_inversion(A->A, A->len);
	printf("inversion = %li\n", fuck);
	return 0;
}
