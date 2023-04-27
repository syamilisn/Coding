/*
* Author     : Syamili S N 		Filename   : P12_loops            
* Date       : 27-04-2023         Description: loop stats
*/


class P12_loops
{
        public static void main(String args[])
        {
                System.out.println("***************************************************************************");
		int i = 0;
		while(i<5){
			System.out.print(i+" ");
			i++;
		}
		i=0;
		do{
			System.out.print(i+" ");
			i++;
		}while(i<5);

		for (i = 0; i <= 10; i = i + 2) {
 			 System.out.println(i);
		}

		String[] cars = {"Volvo", "BMW", "Ford", "Mazda"};
		for (String item : cars) {
 			 System.out.println(item);
		}
        }
}
        
