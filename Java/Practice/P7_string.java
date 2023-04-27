/*
* Author     : Syamili S N 		Filename   : p7_string            
* Date       : 27-04-2023         Description: string functions
*/


class P7_string
{
        public static void main(String args[])
        {
                System.out.println("***************************************************************************");
		String name = "I am Light Yagami";
		String uni = "I got to college";
		System.out.println("String:"+name);
		System.out.println("Length:"+name.length());
		System.out.println("Uppercase:"+name.toUpperCase());
		System.out.println("Lowercase:"+name.toLowerCase());
		System.out.println("IndexOf:"+name.indexOf("Light"));
		System.out.println("Concat:"+name.concat(uni));

        }
}
        
