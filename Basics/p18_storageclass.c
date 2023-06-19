#include <stdio.h>
int main() {
   register char x = 'S';
   register char y;
   register int a = 10;
   auto int b = 8;
   printf("The value of register variable a : %c\n",a);
   printf("The value of register variable x : %c\n",x);
   printf("The value of register variable y : %c\n",y);
   printf("The sum of auto and register variable : %d\n",(a+b));
   return 0;
}
