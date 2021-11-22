import java.util.Scanner;


public class Bombo_Fighter {
	public static void main(String args[])
	{
		Double[] xb=new Double[13];
		Double[] yb=new Double[13];
		Double[] xf=new Double[14];
		Double[] yf=new Double[14];
		Scanner obj=new Scanner(System.in);
		double valocity;
		System.out.println("Enter the value of bomber position(xb,yb) ");
		int i;
		for(i=0;i<13;i++)
		{
			xb[i]=obj.nextDouble();
			yb[i]=obj.nextDouble();
			
		}
		System.out.println("Enter the initial value of fighter position position(xb,yb) ");
		xf[0]=obj.nextDouble();
		yf[0]=obj.nextDouble();
		System.out.println("Enter the valocity ");
		valocity=obj.nextDouble();
		double sin,cos;
		Double []dist=new Double[13];
		double temp;
		for(i=0;i<13;i++)
		{
			temp=((xb[i]-xf[i])*(xb[i]-xf[i]))+((yf[i]-yb[i])*(yf[i]-yb[i]));
			dist[i]=Math.sqrt(temp);
			if(dist[i]<=10)
			{
				System.out.println("Caught at "+i+" minutes and "+dist[i]+" km/s distance");
				break;
			}
			sin=(yb[i]-yf[i])/dist[i];
			cos=(xb[i]-xf[i])/dist[i];
			
			xf[i+1]=xf[i]+(valocity*cos);
			yf[i+1]=yf[i]+(valocity*sin);
		}
		if(i>12)
		{
			System.out.println("Rabiul Escaped");
		}
		
		
		
		
	}

}
