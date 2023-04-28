/*
* Author     : Syamili S N 		Filename   : P17_object            
* Date       : 27-04-2023  	        Description: object creation
*/


class P17_object
{
	static int x = 10;
	int y = 2000;
	final int pi = 3;

	static void display(int n){
		System.out.println("val = "+n);
	}
        public static void main(String args[])
        {
                System.out.println("***************************************************************************");
		System.out.println("[main] x = "+ x);
		display(x);
		//	object creation
		P17_object obj = new P17_object();
		obj.x = 100;
		obj.display(x);
		//display(y);			error: cant be displayed from static context. i.e. use static keyword for class variable to be used in main method
		obj.display(obj.y);
		obj.display(obj.pi);

        }
}
        
