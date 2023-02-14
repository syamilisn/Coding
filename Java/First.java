import java.util.Scanner;

class First{
	void display(String prompt){
		System.out.print(prompt);
	}
	int dynamic(){
		System.out.println("Enter value:");
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		display("Value a: "+a);		
		return a;
	}

	void foreach(int n, int arr[]){
		display("\n\tusing ARRAY\n");
		for(int i=0; i<n; i++)
			display(arr[i]+" ");
			
		display("\n\tusing FOREACH\n");
		for(int item : arr)
			display(item+" ");

		display("\n\tusing FOREACH - var\n");
		for(var item : arr)
			display(item+" ");
	}
	public static void main (String args[]){
		int value=20;
		int arr[] = {10, 20, 30, 40, 50};
		System.out.println("Hello world");
		First obj = new First();
		obj.display("Katrina Kaif");
		//int value = obj.dynamic();
		obj.display("Value value: "+value);		
		obj.foreach(5, arr);
	}
}
