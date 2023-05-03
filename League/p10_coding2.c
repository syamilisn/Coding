#include <stdio.h>

int isUnique(int n, int *arr){
    for(int i=0; i<n-1; i++){
        if(arr[i] == arr[i+1])
            return 0;
    }
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
    int M;
	scanf("%d", &M);
	int arr[M];
	for(int i=0; i<M; i++){
		scanf("%d", &arr[i]);
	}
	int n = max_problems(M, arr);
	int sum = max_sum(n);
	
    int resarr[n];
	int count = 0;
    int flag = 0;
    
	for(int j=0; j<M-2; j++){
        int i = j;
        int res = 0;
        for(int k=0; k<n; k++){
            resarr[k] = arr[i++];
            res += resarr[k];
        }
        flag = isUnique(n, resarr);
        if(res == sum && isUnique(n, resarr))
        {
            j += n-1;
            count++;
        }
            
    }
	printf("%d\n", count);
}
