import java.util.Scanner;


public class Chemical_Reaction {
	public static void main(String args[])
	{
		double k1,k2,dt,n;
		int t,i=1;
		System.out.println("Enter the smallest time period(dt) ");
		Scanner obj=new Scanner(System.in);
		dt=obj.nextDouble();
		System.out.println("Enter the total time (N) ");
		n=obj.nextInt();
		t=(int)(n/dt);
		Double[] a=new Double[t+2];
		Double[] b=new Double[t+2];
		Double[] c=new Double[t+2];
		System.out.println("Enter the value of k1 and k2 ");
		k1=obj.nextDouble();
		k2=obj.nextDouble();
		System.out.println("Enter the value of a(0) and b(0) ");
		a[0]=obj.nextDouble();
		b[0]=obj.nextDouble();
		c[0]=0.0;
		double temp=0;
		System.out.println( "Time\t "+"A(T)\t "+"B(T)\t "+"C(T)\n");
		do
		{
			System.out.println(temp+"\t "+a[i-1]+"\t "+b[i-1]+"\t "+c[i-1]+"\n");
			a[i]=a[i-1]+(((k2*c[i-1])-((k1*a[i-1])*b[i-1]))*dt);
			b[i]=b[i-1]+(((k2*c[i-1])-((k1*a[i-1])*b[i-1]))*dt);
			double t1=2*(k1*(a[i-1]*b[i-1]));
			double t2=(k2*c[i-1])*2;
			c[i]=c[i-1]+(t1-t2)*dt;
			temp=dt+temp;
			i=i+1;
			
		}while(temp<n);
		
	}
}
