/*
* Author     : Syamili S N 		Filename   : P4_variables            
* Date       : 27-04-2023        	Description: variables and datatypes default values
*/


class P4_variables
{
	static int aa; 
	static double dd; 
	static boolean bb; 
	static char cc;
	static long ll;
	static float ff;
	static String ss;

        public static void main(String args[])
        {
                System.out.println("***************************************************************************");
		/* Datatypes:	B->byte
		 *	byte - 1B
		 *	short - 2B
		 *	int - 4B
		 *   [L]long - 8B	[C: 4B]
		 *   [f]float - 4B
		 *   [d]double - 8B
		 *	boolean - 1bit	(true/false)
		 *	char - 2B
		 */
		int num = 10;			//	Integer
		System.out.println(num);
		String name = "Asta";		//	string
		System.out.println(name);
		float pi = 3.14f;		//	float
		System.out.println(pi);
		double pi2 = 3.14;		//	double
		System.out.println(pi2);	
		char c = 'c';			//	char
		System.out.println(c);
		char A = 65, B = 66, C = 67;
		System.out.print(A);
		System.out.print(B);
		System.out.println(C);
		System.out.println(A+B+C);
		boolean mybool = true;		//	bool
		System.out.println(mybool);
		final float pi3 = 3.14f;	//	CONSTANT
		System.out.println(pi3);
		/****************************************************/
		String firstName = "John ";
		String lastName = "Doe";
		String fullName = firstName + lastName;
		System.out.println(fullName);
		/****************************************************/
		//	Multi-initialization and decalaration
		int a = 10, b = 20;
		a = b = 10;
		System.out.println(a+b);
		/****************************************************/
		//	default values -> HAVE TO BE DECLARED AS CLASS VARIABLES ONLY
		System.out.println("Default values:");
		System.out.println("int:"+aa);
		System.out.println("bool:"+bb);
		System.out.println("char:"+cc);
		System.out.println("double:"+dd);
		System.out.println("long:"+ll);
		System.out.println("float:"+ff);
		System.out.println("string:"+ss);
        }
}
        
