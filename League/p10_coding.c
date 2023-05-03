#include <stdio.h>
int unique(int num, int n, int M, int *arr){
	int res[n];
	for(int i=num, k=0; k<n ; i++, k++){
		res[k] = arr[i];
	}
	int t;
	for(int i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++)
			t = res[j], res[j] = res[i], res[i] = t;
	for(int k=0; k<n; k++)
		if(res[k] == res[k+1])
				return 0;
	return 1;
}
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
	int M;
	scanf("%d", &M);
	int arr[M];
	for(int i=0; i<M; i++){
		scanf("%d", &arr[i]);
	}

	// int M = 50;
    // int arr[] = {5, 4, 3, 1, 1, 3, 4, 2, 5, 1, 3, 4, 2, 5, 1, 4, 2, 2, 2, 1, 4, 3, 5, 2, 1, 4, 3, 2, 1, 1, 2, 1, 1, 1, 1, 2, 1, 3, 5, 4, 2, 1, 1, 1, 1, 1, 5, 2, 4, 3};
	// int arr[] = {2, 2, 1, 1, 1, 1, 2, 2, 1, 3, 2, 1, 1, 1, 1, 2, 1, 1, 2, 2, 1, 2, 2, 2, 3, 3, 3};
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
		}
		if (res == sum){
			if(unique(i, n, M, arr) == 1)
				count++;
		}	
	}
	printf("success week count = %d\n", count);
}
