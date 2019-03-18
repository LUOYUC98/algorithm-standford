#include<stdio.h>
#define MAXSIZE 10


void mergeing(int *list1, int list1_size, int *list2, int list2_size){
	int i, j, k;
	int temp[MAXSIZE];
	i = j = k = 0;
	while(i<list1_size && j<list2_size){
		if(list1[i]<list2[j]){
			temp[k++] = list1[i++];
		}
		else{
			temp[k++] = list2[j++];
		}
	}

	while(i < list1_size){
		temp[k++] = list1[i++];
	}
	while(j < list2_size){
		temp[k++] = list2[j++];
	}
	for(int m = 0; m<list2_size+list1_size; m++){
		list1[m] = temp[m];
	}

}

void mergesort(int k[], int n){
	if( n>1 ){
	int *list1 = k;
	int list1_size = n/2;
	int *list2 = k+n/2;
	int list2_size = n - list1_size;
	mergesort(list1, list1_size);
	mergesort(list2, list2_size);
	mergeing(list1, list1_size, list2, list2_size);
	}
}

int main(int argc, char const *argv[])
{
	int A[10] = {2,4,3,5,6,8,1,0,9,7};
	mergesort(A, 10);
	for(int i = 0; i<10;i++){
		printf("%d ", A[i]);
	}
	return 0;
}