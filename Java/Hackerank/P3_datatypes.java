/*
* Author     : Syamili S N
* Version    : #58~20.04.1-Ubuntu SMP Thu Oct 13 13:09:46 UTC 2022
* Release    : 5.15.0-52-generic
*
* Modulename : P3_datatypes
* Description: swap variables
*/


class P3_datatypes
{
	public static void main(String args[])
	{
		int a = 10;
		int b = 20;
		int temp;
		System.out.println("[before] a = "+ a);
		System.out.println("[before] b = "+ b);
		//	BEGIN SWAP
		temp = a; a = b; b = temp;
		//	END SWAP
		System.out.println("[after] a = "+ a);
		System.out.println("[after] b = "+ b);
	}
}
	



