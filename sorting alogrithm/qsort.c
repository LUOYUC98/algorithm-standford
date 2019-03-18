#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/* i = 0, j=0

if i is the boundary for the two parts, j is the boundary to indicate partitioned and unpartitioned
everytime when finishing one step in linear scan we increment j, if we find A[j]>pivot, else we need 
one more step, swapping A[j] and A[i] and increment i

finally we will swap pivot with A[i]*/
int* random_array_generation(){
	 //srand (time(NULL));
	 int num = 100;
	 int *A = (int*)malloc(sizeof(int)*num);
	 for (int i = 0; i < num; ++i)
	 {
		A[i] = rand()%100;
		
	 }

	 return A;
}


void print_array(int A[],int len){
	for (int i = 0; i < len; ++i)
	{
		printf("%d ", A[i]);
	}
	putchar('\n');
}

int choosePivot(int A[], int len){
  int left, right, middle;
  left = 0;
  right = len-1;
	if (len%2==0){
     middle = len/2-1;
  }
  else{
    middle = len/2;
    }

  int max = 0;
  int min = A[0];
  int B[3] = {A[left], A[middle], A[right]};
  for(int i = 0;i<3;i++){
    if(B[i]>=max){
      max = B[i];
    }
    if(B[i]<=min){
      min = B[i];
    }
  }
  int result;
  for(int i = 0;i<3;i++){
    if(B[i]!=max&&B[i]!=min){
      
      result = i;
    }
  }
  if(result==0){
    return left;
  }
  else if(result==1){
    return middle;
  }
  return right;
  
}






void swap(int*p,int*q){
	int temp = *p;
	*p = *q;
	*q = temp;
}


int partition(int A[], int len){
    static int count = 0;

  int i,j;
	int pivot = choosePivot(A, len);
  swap(A+pivot, A);
  i = j = 1;
	while(j<len){
    count++;
		if(A[j]<A[0]){
			swap(A+j,A+i);
			i++;
		}
		j++;
	}
	swap(A+i-1, A);
  //printf("count = %d\n", count);
	return i;
}


void quicksort(int A[], int len){
  static int count2 = 0;
	if(len <= 1){
		return;
	}
  count2+=len-1;
	int split = partition(A, len);
	quicksort(A, split-1);
	quicksort(A+split, len-split);
  //printf("count2 = %d", count2);
}

int main(int argc, char const *argv[])
{

  FILE *myFile;
  myFile = fopen("num.txt", "r");
  int A[10000];
  int i;
 for (i = 0; i < 10000; i++) {
        fscanf(myFile, "%d,", &A[i] );
    }  
  int len = 10000;


	quicksort(A, len);
	//print_array(A,len);
	return 0;
}





















