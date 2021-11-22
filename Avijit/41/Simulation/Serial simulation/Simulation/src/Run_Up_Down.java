import java.util.Random;
import java.util.Scanner;


public class Run_Up_Down {
	public static void main(String [] args)
	{
		int N;
		System.out.print("Enter howmany random number ? ");
		Scanner obj=new Scanner(System.in);
		N=obj.nextInt();
		Random random=new Random();
		int loop_variable;
		double a=1.0;
		Double value[]=new Double[N+1];
		for(loop_variable=1;loop_variable<=N;loop_variable++)
		{
			 value[loop_variable]=random.nextDouble();
		}
		System.out.println("Random Numbers are : ");
		for(loop_variable=1;loop_variable<=N;loop_variable++)
		{
			System.out.printf("%.3f ",value[loop_variable]);
		 
			if(loop_variable%10==0)
			{
				System.out.println();
			}
		}
		String sign="";
		for(loop_variable=2;loop_variable<=N;loop_variable++)
		{
			if(value[loop_variable-1]<=value[loop_variable])
			{
				sign=sign+"+";
				
			}
			else
			{
				sign=sign+"-";
				 
			}
			
					
		}
		char condition=sign.charAt(0);
		System.out.println("\n"+sign+"\n");
		for(loop_variable=1;loop_variable<sign.length();loop_variable++)
		{
			if(sign.charAt(loop_variable)==condition)
			{
				
			}
			else
			{
				a=a+1;
				condition=sign.charAt(loop_variable);
			}
		}
		System.out.println("Number of Run : "+a);
		double sigma=0.0;
		sigma=((2*N)-1)/3.0;
		double sigma_Suare=((16*N)-29)/90.0;
		double temp=(float)(a)-(float)(sigma);
		double Z=temp/Math.sqrt(sigma_Suare);
		System.out.println("Value of Sigma : "+sigma);
		System.out.println("Value of Sigma square : "+sigma_Suare);
		System.out.println("Value of Z : "+Z);
		double critical_value=0;
		System.out.println("Enter the critical value : ");
		critical_value=obj.nextDouble();
		double critical_value_neg=-1*critical_value;
		if(critical_value>=Z&critical_value_neg<=Z)
		{
			System.out.println("The indepandence of the numbers cannot be rejected");
		}
		else
		{
			System.out.println("The indepandence of the numbers can be rejected");
		}
		
		obj.close();
		
	}

}
