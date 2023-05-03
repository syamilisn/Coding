#include <stdio.h>
int max_problems(int n, int *arr){
	int max_val = arr[0];
	for(int i=1; i<n; i++){
		if(max_val<arr[i])
			max_val = arr[i];
	}
	return max_val;
}
int max_sum(int n){
	if(n == 0)
		return n;
	else
		return max_sum(n-1) + n;
}
void main()
{
	int M = 27;
	int arr[] = {2, 2, 1, 1, 1, 1, 2, 2, 1, 3, 2, 1, 1, 1, 1, 2, 1, 1, 2, 2, 1, 2, 2, 2, 3, 3, 3};
	int n = max_problems(M, arr);
	printf("m (max_problems) = %d\n", n);
	int sum = max_sum(n);
	printf("sum (max_sum) = %d\n", sum);
	int res = 0;
	int count = 0;
	for(int i=0; i<(M-n); i++){
		res = 0;
		for(int j=i, k=0; k<n; j++, k++){
			res += arr[j];
			if (res == sum){
				if(unique())
					count++;
			}	
		}
	}
	printf("success week count = %d\n", count);
}
