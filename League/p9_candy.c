#include <stdio.h>

void main(){

        int n, m, m_tot=0, t1, t2, sum=0, k=0;
        scanf("%d%d", &n, &m);
        int arr[m][2];
        for(int i=0; i<m; i++){
                scanf("%d%d", &arr[i][0], &arr[i][1]);
        }
        //arranging array according to num of candies
        for(int i=0; i<m; i++){
                for(int j=0; j<m-i-1; j++){
                        if(arr[j][1] < arr[j+1][1]){
                                t1 = arr[j][1], t2 = arr[j][0];
                                arr[j][1] = arr[j+1][1], arr[j][0] = arr[j+1][0];
                                arr[j+1][1] = t1, arr[j+1][0] = t2;
                        }
                }
        }

        for(int i=0; i<m; i++){
                if(arr[i][0] <= n){
                        sum += (arr[i][0] * arr[i][1]);
                        n -= arr[i][0];
                        if( n < 0 )
                            break;
                }
                else{
                        sum += (n * arr[i][1]);
                            break;
                }
        }

        printf("%d\n", sum);

}

