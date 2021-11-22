import java.util.Random;
import java.util.Scanner;


public class Kolmogoro_smirnot_test {
	public static void main(String arg[])
	{
		int n;
		System.out.print("Enter how many number are nandom to test : ");
		Scanner sc= new Scanner(System.in);
		n=sc.nextInt();
		int i,j;
		Random rand=new Random();
		
		Double[] random_number=new Double[n+1];
		
		for(i=1;i<=n;i++)
		{
			random_number[i]=rand.nextDouble();
		}
		System.out.println("Random number : ");
		for(i=1;i<=n;i++)
		{
			System.out.printf("%.2f\n",random_number[i]); 
		}
		double temp;
		for(i=1;i<=n-1;i++)
		{
			for(j=1;j<=n-i-1;j++)
			{
				if(random_number[j]>random_number[j+1])
				{
					temp=random_number[j];
					random_number[j]=random_number[j+1];
					random_number[j+1]=temp;
				}
			}
		}
		
		 
		Double[] dPlus=new Double[n+1];
		Double[] dMinus=new Double[n+1] ;
		
		double k;
		for(i=1;i<=n;i++)
		{
			k=(double)i/n;
			dPlus[i]=k-random_number[i];
			
		}
		for(i=1;i<=n;i++)
		{
			k=((double)(i-1)/n);
			dMinus[i]=(random_number[i]-k);
		}
		double dmax=dPlus[1],dmin=dPlus[1];
		
		for(i=2;i<=n;i++)
		{
			if(dmax<dPlus[i])
			{
				dmax=dPlus[i];
			}
			if(dmin<dMinus[i])
			{
				dmin=dMinus[i];
			}
		}
		System.out.println("D+ value : ");
		for(i=1;i<=n;i++)
		{
			System.out.printf("%.2f\n",dPlus[i]); 
		}
		System.out.println("D- value : ");
		for(i=1;i<=n;i++)
		{
			System.out.printf("%.2f\n",dMinus[i]); 
		}
		double D;
		if(dmax>dmin)
		{
			D=dmax;
		}
		else
		{
			D=dmin;
		}
		System.out.printf("The value of D : %.2f \n",D); 
		System.out.print("Enter the critical value : ");
		double critical_value;
		critical_value=sc.nextDouble();
		if(critical_value>=D)
		{
			System.out.println("The uniform distribution is not rejected");
		}
		else
		{
			System.out.println("The uniform distribution is rejected");
		}
		
		sc.close();
		
		
	}

}
