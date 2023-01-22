#include <stdio.h>

void outlets_per_day(int n, int *outlet, int q, int *coins){
    int output[q];
    //  MAIN LOGIC
    for(int i=0 ; i<q; i++){
        int count = 0;  //  initialize outlet_count for each day as Zero.
        for(int j=0; j<n; j++){
            if(coins[i] >= outlet[j]){
                count += 1;
            }
        }
        output[i] = count;
        printf("%d\n", output[i]);
        count = 0;
    }

}
void main(){
    int n, q;
    scanf("%d", &n);
    int outlet[n];
    for(int i=0; i<n; i++)
        scanf("%d", &outlet[i]);

    scanf("%d", &q);
    int coins[q];
    for(int i=0; i<q; i++)
        scanf("%d", &coins[i]);
    outlets_per_day(n, outlet, q, coins);
}