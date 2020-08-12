/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package peer;

import java.io.IOException;
import java.net.DatagramPacket;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *

 */
public class Receiver extends Thread{
    
        private ConnectionData data;
        
        public Receiver(ConnectionData data){
            this.data=data;
        }
        
    	@Override
	public void run() {
		
		while(true) {
			try {
				
                        byte[] receiveData = new byte[1024];        
		        DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
		       
                            if(data.getMyPeerSocket()!=null){
                                data.getMyPeerSocket().receive(receivePacket);
                                String CommandComing=new String(receivePacket.getData());
                                String address=receivePacket.getAddress().toString().substring(1);
                                int port=receivePacket.getPort();
                               CommandDetection.detectionCommand(CommandComing,address,port);
                            }
                        } catch (IOException ex) {
                        }catch (Exception e) {
                        e.printStackTrace();
                        }
			try {
				Thread.sleep(5);
			} catch (InterruptedException e) {}
	       
		}
		
		
		
	}
    
    
}
