#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int len_integer(int num){
	int count = 1;
	while(num >= 10){
		num = num / 10;
		count += 1;
	}
	return count;
}

int sub_multiply(long long a, long long b){
	int len = len_integer(a);
	if(len == 1){
    return a*b;
	}
	int A[len];
	int B[len];
	int a_cp = a;
	int b_cp = b;
	int index = len - 1;
	while(index >= 0){
		A[index] = a_cp % 10;
		a_cp /= 10;
		B[index] = b_cp % 10;
		b_cp /= 10;
		index--;
	}
	long a1 = 0, a2 = 0, b1 = 0, b2 = 0;
	int half = len/2;
	for (int i = 0; i < half; ++i)
	{	
		a1 += A[i]*pow(10, half-1-i);
		b1 += B[i]*pow(10, half-1-i);
	}
	a2 = a - a1 * pow(10,len - half);
	b2 = b - b1 * pow(10,len - half);
  long long pt1 = sub_multiply(a1,b1);
  long long pt2 = sub_multiply(a2,b2);
  long long pt3 = sub_multiply(a1+a2, b1+b2)-pt1-pt2;
	return pow(10, 2*(len-half))*pt1+pow(10, len-half)*pt3+pt2;
}

int main(int argc, char const *argv[])
{
  int result = sub_multiply(15344, 18123);
  printf("%d", result);
  return 0;
}