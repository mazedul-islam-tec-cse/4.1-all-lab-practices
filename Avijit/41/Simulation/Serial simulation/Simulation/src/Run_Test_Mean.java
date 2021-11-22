import java.util.Random;
import java.util.Scanner;


public class Run_Test_Mean {
	public static void main(String[] args) {
		int N;
		System.out.print("Enter how many number are nandom to test : ");
		Scanner sc= new Scanner(System.in);
		N=sc.nextInt();
		int i;
		Random rand=new Random();
		
		Double[] random_number=new Double[N+1];
		
		for(i=0;i<N;i++)
		{
			random_number[i]=rand.nextDouble();
		}
		for(i=0;i<N;i++)
		{
			System.out.print(random_number[i]+" ");
		}
		System.out.println();
		String sign=new String();
		double highest=random_number[0];
		double lowest=random_number[0];
		
		for(i=1;i<N;i++)
		{
			if(random_number[i]>=highest)
			{
				highest=random_number[i];
			}
			if(random_number[i]<=lowest)
			{
				lowest=random_number[i];
			}
			
		}	
		double avg=(lowest+highest)/2;
	
		for(i=0;i<N;i++)
		{
			if(random_number[i]>=avg)
			{
				sign=sign+"+";
			}
			else
			{
				sign=sign+"-";
			}
		}	
		
		System.out.println("Sign:\n"+sign);
		char temp1=sign.charAt(0);
		int value_of_b=1;
		for(i=1;i<N;i++)
		{
			char temp2=sign.charAt(i);
			if(temp1==temp2)
			{
				 
			}
			else
			{
				temp1=temp2;
				value_of_b=value_of_b+1;
			}
		}
		System.out.println("Run :"+value_of_b);
		 
		char temp='+';
		int n1=0,n2=0;
		
		for(i=0;i<N;i++)
		{
			char temp2=sign.charAt(i);
			if(temp==temp2)
			{
				n1=n1+1; 
			}
			else
			{
				n2=n2+1; 
			}
		}
		System.out.println("Value of n1 : "+n1+"\nValue of n2 : "+n2);
		double ub;
		int mult=2*(n1*n2);
		ub=(float)(mult/N+0.5);
		double sigma_square;
		sigma_square=(float)(mult*(mult-N)/((N*N)*(N-1)));
		double square_root=Math.sqrt(sigma_square);
		double Zn=(float)((value_of_b-ub)/square_root);
		System.out.println("Value of Ua= "+ub+"\nValue of Sigma square = "+sigma_square+"\nValue of Zn = "+Zn);
		double critical_value;
		System.out.print("Enter the critical value : ");
		critical_value=sc.nextDouble();
		double critical_value_neg=-1*critical_value;
		
		if(critical_value>=Zn&&Zn>=critical_value_neg)
		{
			System.out.println("The uniform distribution is not rejected");
		}
		else
		{
			System.out.println("The uniform distribution is rejected");
		}
		
		
		
	}
}
