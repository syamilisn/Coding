/*
* Author     : Syamili S N 		Filename   : P13_array            
* Date       : 27-04-2023         Description: array
*/


class P13_array
{
        public static void main(String args[])
        {
                System.out.println("***************************************************************************");
		int[] arr = {1,2,3,4,5};
		for(int n: arr)
			System.out.println(n);
		int[][] arr2d = { {1,2,3}, {4,5,6}, {7,8,9}};
		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				System.out.print(arr2d[i][j]+" ");
			}
			System.out.println("");
		}
        }
}
        
