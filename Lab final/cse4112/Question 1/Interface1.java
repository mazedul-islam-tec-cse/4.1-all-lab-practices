import java.rmi.*;
public interface Interface1 extends Remote{
	public String lower_toU(String first) throws RemoteException;
	public  String upper_toL(String second) throws RemoteException;
	public  String combined(String first,String second) throws RemoteException;
	

}
