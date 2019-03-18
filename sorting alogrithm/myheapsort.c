#include <stdio.h>

void int_swap(int *a, int *b){
	int temp = *b;
	*b = *a;
	*a = temp;
}


void heap_adjust(int k[], int s, int n){
	int i, temp;
	temp = k[s];
	for (i = 2*s; i<=n; i*=2)
	{
		if(i<n && k[i] < k[i+1]){
			i++;
		}
		if(temp >= k[i]){
			break;
		}
		k[s] = k[i];
		s = i;
	}
	k[s] = temp;
}

void heapsort(int k[], int n){
	int i;
	for (int i = n/2; i > 0; i--)
	{
		int_swap(k+1, k+i);
		heap_adjust(k, 1, i-1);
	}
}

int main(int argc, char const *argv[])
{
	int A[10] = {2,1,5,3,4,6,8,7,0,9};
	heapsort(A, 10);
    for(int i = 1;i<10;i++){
        printf("A[%d] = %d\n", i, A[i]);
    }
	return 0;
}