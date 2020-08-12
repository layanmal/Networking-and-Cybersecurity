/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package peer;

import java.net.InetAddress;
import java.util.ArrayList;
import javax.swing.JOptionPane;

/**
 *
 * @author zaid-
 */
public class PeerData {
    
    private String Name;
    private InetAddress address;
    private int port;
    private ArrayList<String> Msgs;
    
    public PeerData(){
        Msgs=new ArrayList<String>();
    }
    
    public void addMsg(String msg){
        Msgs.add(msg);
    }
    
    public ArrayList<String> getMsgs(){
        return Msgs;
    }
    
    public String getName() {
        return Name;
    }

    public void setName(String Name) {
        this.Name = Name;
    }
   
     public int getPort() {
        return port;
    }

    public void setPort(int port) {
        this.port = port;
    }

    public InetAddress getAddress() {
        return address;
    }
    
    public String getStringAddress() {
        String add=this.address.getHostAddress().substring(0);
        return add;
    }
    
    
    public void setAddress(String address) {
        try {
            this.address=InetAddress.getByName(address);
        } catch (Exception ex) {
            JOptionPane.showMessageDialog(PeerView.getView(),"Address Enter Error","Error",JOptionPane.ERROR_MESSAGE);
        }
    }
    

    public void setAddress(InetAddress address) {
        this.address = address;
    }
    
    
    
    
}
