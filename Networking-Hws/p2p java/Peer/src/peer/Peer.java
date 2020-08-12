/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package peer;

import java.net.InetAddress;
import java.net.NetworkInterface;
import java.net.SocketException;
import java.net.UnknownHostException;
import java.util.Arrays;
import java.util.Collections;
import java.util.Enumeration;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *

 */
public class Peer {

	
	
	
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
    
    

