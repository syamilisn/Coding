/*
* Author     : Syamili S N
* Version    : #58~20.04.1-Ubuntu SMP Thu Oct 13 13:09:46 UTC 2022
* Release    : 5.15.0-52-generic
*
* Modulename : P2_format
* Description: 
*/


class P2_format
{
	public static void main(String args[])
	{
		int a = 10, b = 20, c = 30;
		String s1 = "java";
		String s2 = "python";
		String s3 = "javascript";
		System.out.printf("%-15s",s1);
                System.out.printf("%03d",a);
		System.out.println();
		System.out.printf("%-15s",s2);
                System.out.printf("%03d",b);
		System.out.println();
		System.out.printf("%-15s",s3);
                System.out.printf("%03d",c);
		System.out.println();
	}
}
	



