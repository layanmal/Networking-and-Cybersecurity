/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package peer;

import java.net.DatagramSocket;

import java.net.InetAddress;

import java.util.ArrayList;

import javax.swing.JOptionPane;


public class ConnectionData {
    private int port;
    private InetAddress address;
    private DatagramSocket MyPeerSocket;
    private String Name;
    private PeerData ActivePeer;
    private ArrayList <PeerData> peerList;
    
    public ConnectionData(){
        peerList=new ArrayList<PeerData>();
    }
    
    public void addPeerToList(PeerData peer){
        peerList.add(peer);
    }
    
    public ArrayList<PeerData> getPeerList(){
        return peerList;
    }
    
    public PeerData getActivePeer() {
        return ActivePeer;
    }

    public void setActivePeer(PeerData ActivePeer) {
        this.ActivePeer = ActivePeer;
    }

    
    public boolean connect(String name){
        try {
            MyPeerSocket=new DatagramSocket(port,address);
            return true;
        } catch (Exception ex) {
           JOptionPane.showMessageDialog(PeerView.getView(),"Connection Error","Error",JOptionPane.ERROR_MESSAGE);
           return false;
        }
    }
    
    public DatagramSocket getMyPeerSocket() {
        return MyPeerSocket;
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
    
  /*  public String getStringAddress() {
        String add=this.address.getHostAddress();
        return add;
    }
    */
    
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
