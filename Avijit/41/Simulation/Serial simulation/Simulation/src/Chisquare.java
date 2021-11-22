import java.util.Random;
import java.util.Scanner;


public class Chisquare{

	public static void main(String[] args) {
		int N;
		System.out.print("Enter how many number are nandom to test : ");
		Scanner sc= new Scanner(System.in);
		N=sc.nextInt();
		int i,j;
		Random rand=new Random();
		
		Double[] random_number=new Double[N+1];
		
		for(i=0;i<N;i++)
		{
			random_number[i]=rand.nextDouble();
		}
		System.out.println("Random number : ");
		for(i=1;i<N;i++)
		{
			System.out.println(random_number[i]); 
		}
		int n;
		System.out.print("Enter the class number : ");
		n=sc.nextInt();
		int Ei=N/n;
		
		double range=(float)100/n;
		
		range=(float)range/100;
		
		double rangeup=range,rangedown=0.00f;
		
		int[] Oi=new int[n];
		int count=0;
		int[] difference=new int[n]; 
		int [] differcencSquare=new int[n];
		double [] calculation=new double[n];
		//System.out.println("Rangeup "+rangeup+" range down "+rangedown);
		for(i=0;i<n;i++)
		{
			for(j=0;j<N;j++)
			{
				  if(random_number[j]>rangedown && random_number[j]<=rangeup)
				  {
					  count=count+1;
				  }
			}
			//System.out.println("count "+i+" = "+count);
			rangedown=rangeup+0.0001;
			rangeup=rangeup+range;
			Oi[i]=count;
			count=0;
			difference[i]=Oi[i]-Ei;
			differcencSquare[i]=difference[i]*difference[i];
			calculation[i]=(float)differcencSquare[i]/Ei;
		}
		System.out.println("Interval     Oi     Ei    (Oi-Ei)  (Oi-Ei)^2   (Oi-Ei)^2/Ei");
		for(i=0;i<n;i++)
		{
			System.out.println((i+1)+"             "+Oi[i]+"     "+Ei+"      "+difference[i]+"       "+differcencSquare[i]+"       "+calculation[i] );
		}
		float sumEi=0,sum_difference=0,sum_square_diff=0,sum_calculate=0,sumOi=0;
		for(i=0;i<n;i++)
		{
			sumEi=sumEi+Ei;
			sumOi=sumOi+Oi[i];
			sum_difference=sum_difference+difference[i];
			sum_square_diff=sum_square_diff+differcencSquare[i];
			sum_calculate=(float)(sum_calculate+calculation[i]);
		}
		System.out.println(" Summation:  "+sumOi+"   "+sumEi+"    "+sum_difference+"    "+sum_square_diff+"    "+sum_calculate );
	 
		double critical_value;
		System.out.print("Enter the critical value : ");
		critical_value=sc.nextDouble();
		if(critical_value>=sum_calculate)
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
