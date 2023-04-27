/*
* Author     : Syamili S N 		Filename   : P15_overloading            
* Date       : 27-04-2023  	        Description: method overloading
*/


class P15_overloading
{
	static void area(int side){
		System.out.println("[area_square] "+(side*side));
	}
	static void area(int side1, int side2){
		System.out.println("[area_rectangle] "+(side1*side2));
	}
        public static void main(String args[])
        {
                System.out.println("***************************************************************************");
		area(4);
		area(3,4);

        }
}
        
