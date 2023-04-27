/*
* Author     : Syamili S N 		Filename   : P5_typecast            
* Date       : 27-04-2023  	        Description: implicit(auto) and explicit(manual) type casting
*/


class P5_typecast
{
        public static void main(String args[])
        {
                System.out.println("***************************************************************************");
		//	auto cast for small to big types
		int a = 10;
		double b = a;
		System.out.println(b);
		//	explicit for big to small types
		double myDouble = 9.78d;
		int myInt = (int) myDouble; // Manual casting: double to int

	 	System.out.println(myDouble);   // Outputs 9.78
  		System.out.println(myInt);      // Outputs 9

        }
}
        
