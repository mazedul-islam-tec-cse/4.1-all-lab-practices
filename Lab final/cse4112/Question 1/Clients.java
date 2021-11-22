import java.net.MalformedURLException;
import java.rmi.Naming;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;


public class Clients {
	public static void main(String args[])
	{
		String Uppercase="BangladesH is Our County";
		String lowerCase=" We love our countrY";
		try {
			Interface1 obj=(Interface1)Naming.lookup("rmi://localhost:5000/exem");
			String upperTolower=obj.upper_toL(Uppercase);
			String lowerTupper=obj.lower_toU(lowerCase);
			String combined=obj.combined(upperTolower, lowerTupper);
			System.out.println(combined);
		} catch (Exception e) {
			
			System.out.println("Problem in Client "+e);
		}
		
	}

}
