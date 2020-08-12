/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package net.hw2;
/**
 *
 * @author ASUS
 */
public class NetHW2 extends javax.swing.JFrame{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
       try{
        PeerView2 PV = new PeerView2();
        PV.setVisible(true);
       
       }
       catch(Exception d){
           System.out.print("Shit");
       }
    }
    
}
