import java.rmi.Naming;
import java.rmi.RemoteException;


public class Server  {
	public static void main(String args[])
	{
		try {
			Interface1 obj=new InterfaceImplementation();
			Naming.rebind("rmi://localhost:5000/exem", obj);
		} catch (Exception e) {
			 System.out.println("Problem in Server");
		}
	}

}
