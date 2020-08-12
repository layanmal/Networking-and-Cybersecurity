
package peer;


import java.net.SocketException;


public class Peer {

	
	/* How  To Use :
	 * 
	 * 1- enter user name then login [2 user]
	 * 2- enter port and address of another and use connect button to call him.
	 * Any help Email: zaid-habiba@hotmail.com or Facebook: "Zaid Habiba"
	 */
	
    public static void main(String[] args) throws SocketException {
        ConnectionData data=new ConnectionData();
        Receiver r=new Receiver(data);
        Sender s=new Sender(data);
        PeerView view=new PeerView(data);
        CommandDetection c=new CommandDetection(view, data);
        r.start();
        s.start();
        
    }
    
} 
    
    

