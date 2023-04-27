/*
* Author     : Syamili S N 		Filename   : P16_recursion            
* Date       : 27-04-2023  	        Description: factorial of a number using recursion
*/


class P16_recursion
{
	static int fact(int n){
		if(n < 2)
			return 1;
		else
			return n * fact(n-1);
	}
        public static void main(String args[])
        {
                System.out.println("***************************************************************************");
		System.out.println("Factorial of 4: "+fact(4));
        }
}
        
