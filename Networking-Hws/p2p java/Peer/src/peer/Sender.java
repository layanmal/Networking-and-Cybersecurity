/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package peer;

import java.net.DatagramPacket;
import java.net.InetAddress;

/**

public class Sender extends Thread{
    
    
	private ConnectionData data;
	
	//use to send Command VVV
	private static boolean commandsend=true;
	private static String Command;
	//use to send Command ^^^
	
	public Sender(ConnectionData p2pd3) {
		data=p2pd3;
	}
	
	int TimerCommandFaildSend=0;
	int MaxSendTest=2;
	@Override
	public void run() {
		
			while(true) {
				if(commandsend==false) {
						try {
							//enter code
						
								PeerData peer=data.getActivePeer();
                                                                if(peer!=null){
                                                                    DatagramPacket sendPacket = new DatagramPacket(Command.getBytes(), Command.length(),peer.getAddress(),peer.getPort());//p.port
                                                                    data.getMyPeerSocket().send(sendPacket); 
                                                                    System.out.println("Command Send is:"+Command+",Port:"+peer.getPort()+",Address:"+peer.getAddress().toString().substring(1));
                                                                }
							
						} catch (Exception e) {
							System.out.println("Sender udp exception");
							if(TimerCommandFaildSend<MaxSendTest) {
								commandsend=false;
								TimerCommandFaildSend++;
							}else {
								commandsend=true;
								ConnectionLost();
							}
							
						} 
						commandsend=true;
					
					}
					try {
						Thread.sleep(500);
					} catch (InterruptedException e) {}
			}
		}
	
	public static void sendCommand(String CommandComing) {
		if(CommandComing!=null) {
			
			Command=CommandComing;
			commandsend=false;//not send you have command need to send
		}
	}
	
	public void ConnectionLost() {
		
	}
	
    
    
}
