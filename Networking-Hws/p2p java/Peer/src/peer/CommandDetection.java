/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package peer;

import javax.swing.JOptionPane;

/**
 *
 
 */
public class CommandDetection {
 
    private static PeerView view;
    private static ConnectionData data;
    public CommandDetection(PeerView view,ConnectionData data){
        this.view=view;
        this.data=data;
    }
    
    
    
    public static void detectionCommand(String CommandComing,String ip,int port) {
        
       // System.out.println(CommandComing);
	String command[]=CommandComing.split(";");
        String TestPortAndIp=ip+";"+port;
       // System.out.println("::::"+command[0]+"::::"+command[1]);
        if(command[0].equals(Commands.ConnectAccepted)){
            PeerView.setState("Connection Accept");
            PeerData peer=new PeerData();
            peer.setAddress(ip);
            peer.setPort(port);
            peer.setName(command[1]);
            data.addPeerToList(peer);
            view.updataNewPeerComing(peer);
        }else if(command[0].equals(Commands.Msg)){
            PeerView.setState("Msg Received");
            String msg=command[1];
            for(PeerData peer:data.getPeerList()){
                String test=peer.getStringAddress()+";"+peer.getPort();
                System.out.println("Test:"+TestPortAndIp+"]["+test);
                if(test.equals(TestPortAndIp)){
                    peer.addMsg(peer.getName()+":"+msg);
                    view.updataMsgSendNow(peer);
                }  
            } 
        }else if(command[0].equals(Commands.Connect)){
            PeerView.setState("Connection send");
            int n=JOptionPane.showConfirmDialog(PeerView.getView(),command[1]+" want to connect with you ?",
                            "Connect",
                            JOptionPane.YES_NO_OPTION);
            if(n==JOptionPane.YES_OPTION){
                PeerData peer=new PeerData();
                peer.setAddress(ip);
                peer.setPort(port);
                peer.setName(command[1]);
                data.addPeerToList(peer);
                view.updataNewPeerComing(peer);
                String c[]={Commands.ConnectAccepted,data.getName()};
                Sender.sendCommand(Commands.getCommand(c));
            }
        }
        
    }
    
    
}
