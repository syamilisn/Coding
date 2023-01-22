/*
	getchar()
*/

#include <stdio.h>

void main(){
	printf("Enter character: \n");
	char c = getchar();	
	putchar(c);
	printf("\n");
	(c == 'y')? printf("yes\n"): (c == 'n')? printf("no\n"): printf("others\n");

//	char character;
//	character = ' ';
//	while(character!= '\n')	{character = getchar();}
//	printf("%c",character);

	
}
