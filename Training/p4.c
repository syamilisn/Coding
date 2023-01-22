#include <stdio.h>
 void main(){
 	char arr[50][50];
 	int i, j;
 	for(i=0;i<2;i++){
 		for(j=0;j<2;j++){
 			scanf(" %c",&arr[i][j]);
 		}
 	}
 	for(i=0;i<2;i++){
 		for(j=0;j<2;j++){
 			printf("%c",arr[i][j]);
 		}
 	}
 }
