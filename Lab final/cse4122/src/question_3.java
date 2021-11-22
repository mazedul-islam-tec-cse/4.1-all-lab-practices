import java.util.Scanner;


public class question_3 {
	public static void main(String [] args)
	{
		Scanner obj=new Scanner (System.in);
		System.out.println("Enter the value of a,c and m for both x and y co-ordiante");
		
		
		int a1=3;
		int c1=5;
		int m1=10;
		int a2=4;
		int c2=50;
		int m2=100;
		a1=obj.nextInt();
		c1=obj.nextInt();
		m1=obj.nextInt();
		a2=obj.nextInt();
		m2=obj.nextInt();
		
		double xb[]=new double[4];
		double yb[]=new double[4];
		xb[0]=71;
		yb[0]=63;
		for(int i=1;i<4;i++)
		{
			xb[i]=(a1*xb[i-1]+c1)%m1;
			yb[i]=(a2*yb[i-1]+c2)%m2;
		}
		
		double xf[]=new double[4];
		double yf[]=new double[4];
		xf[0]=5.0;
		yf[0]=6.0;
		double valocity=20;
		double distance=0.0;
		int flag=0;
		double y=(yb[0]-yf[0])*(yb[0]-yf[0]);
		distance=Math.sqrt(y+((xb[0]-xf[0])*(xb[0]-xf[0])));
		//System.out.println(" at time 1"+" where distance is : "+distance);
		for(int i=1;i<4;i++)
		{
			if(distance<=25.0)
			{
				System.out.println("The fighter distroy the UFO at time "+(i)+" where distance is : "+distance);
				flag=1;
				break;
			}
			
			else{
				double sin=(yb[i-1]-yf[i-1])/distance;
				double cos=(xb[i-1]-xf[i-1])/distance;
				xf[i]=xf[i-1]+valocity*cos;
				yf[i]=yf[i]+valocity*sin;
				y=(yb[i-1]-yf[i-1])*(yb[i-1]-yf[i-1]);
				distance=Math.sqrt(y+((xb[i-1]-xf[i-1])*(xb[i-1]-xf[i-1])));
				System.out.println("at time "+(i)+" where distance is : "+distance);
				}
			
		}
		
		if(flag==0)
		{
			System.out.println("The fighter wouldn't distroy the UFO in the given time" );
		}
}

}
