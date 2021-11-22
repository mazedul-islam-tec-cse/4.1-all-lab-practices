import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
public class InterfaceImplementation extends UnicastRemoteObject implements Interface1 {

	protected InterfaceImplementation() throws RemoteException {
		super();
		 
	}

	@Override
	public String lower_toU(String first) throws RemoteException {
		 
		String upper="";
		 
	 
			upper=first.toUpperCase();
	 
		return upper;
	}

	@Override
	public String upper_toL(String second) throws RemoteException {
	 
		String  lower="";
		 
		 lower=second.toLowerCase();
		 
		return lower;
		 
	}

	@Override
	public String combined(String first, String second) throws RemoteException {
		 
		return first+" and "+second;
	}

}
