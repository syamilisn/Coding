/*
* Author     : Syamili S N 		Filename   : P14_method            
* Date       : 27-04-2023  	        Description: functions in java
*/


class P14_method
{
	//	static: implies function belongs to Main class and not to Main class' object.
	static void display(int n){
		System.out.println("[display] from func: "+n);
	}
	static int sum(int a, int b){
		return a+b;
	}
        public static void main(String args[])
        {
                System.out.println("***************************************************************************");
		display(sum(2,2));
		
        }
}
        
