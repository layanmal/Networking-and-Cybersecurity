/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package hw1;
import java.net.*;
import java.util.ArrayList;
import javax.swing.JOptionPane;
/**
 *
 * @author Ahmed K.AS
 */
public class gui extends javax.swing.JFrame {

    
    DatagramSocket socket;
    private int port;
    private boolean loggedin;
    byte[] received=new byte[1000];
    Thread thread;
    String u;
    ArrayList <Integer> a = new <Integer>ArrayList ();
    
    
    public gui(String User) {
        initComponents();
        u=User;

        thread = new Thread(){
        public void run(){

            while(true){
                try {
                     received=new byte[1000];
                     DatagramPacket recievePacket=new DatagramPacket(received,received.length);
                     socket.receive(recievePacket);
                     String newsen=new String(recievePacket.getData());
                     conversation.append(newsen+"\n");
                     //newsen=new String("");
                     state.setText("Connected, Message Received From ["+ipr.getText()+","+portr.getText()+"]");

                } 
                catch (Exception ex) {
                }

            }
        }
        };

        thread.start();
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jScrollPane1 = new javax.swing.JScrollPane();
        conversation = new javax.swing.JTextArea();
        sendData = new javax.swing.JTextField();
        send = new javax.swing.JButton();
        jLabel2 = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        myport = new javax.swing.JTextField();
        jButton2 = new javax.swing.JButton();
        ipr = new javax.swing.JTextField();
        portr = new javax.swing.JTextField();
        ipm = new javax.swing.JTextField();
        jLabel5 = new javax.swing.JLabel();
        jLabel1 = new javax.swing.JLabel();
        clear = new javax.swing.JButton();
        state = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Messenger");
        setResizable(false);

        conversation.setEditable(false);
        conversation.setColumns(20);
        conversation.setRows(5);
        jScrollPane1.setViewportView(conversation);

        send.setText("Send");
        send.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                sendActionPerformed(evt);
            }
        });

        jLabel2.setText("Local Port:");

        jLabel3.setText("Remote ip:");

        jLabel4.setText("Remote port:");

        myport.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                myportActionPerformed(evt);
            }
        });

        jButton2.setText("Log in");
        jButton2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton2ActionPerformed(evt);
            }
        });

        ipr.setText("127.0.0.1");
        ipr.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                iprActionPerformed(evt);
            }
        });

        ipm.setText("127.0.0.1");
        ipm.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                ipmActionPerformed(evt);
            }
        });

        jLabel5.setText("Local ip:");

        jLabel1.setText("Available Interfaces:");

        clear.setText("Clear");
        clear.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                clearActionPerformed(evt);
            }
        });

        state.setText("Not Connected Yet");

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(state, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(sendData, javax.swing.GroupLayout.PREFERRED_SIZE, 328, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 315, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createSequentialGroup()
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(send, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                    .addGroup(layout.createSequentialGroup()
                                        .addGap(49, 49, 49)
                                        .addComponent(jButton2)
                                        .addGap(0, 0, Short.MAX_VALUE))
                                    .addGroup(layout.createSequentialGroup()
                                        .addGap(8, 8, 8)
                                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                            .addGroup(layout.createSequentialGroup()
                                                .addComponent(jLabel5)
                                                .addGap(31, 31, 31)
                                                .addComponent(ipm))
                                            .addGroup(layout.createSequentialGroup()
                                                .addComponent(jLabel2)
                                                .addGap(19, 19, 19)
                                                .addComponent(myport))
                                            .addGroup(layout.createSequentialGroup()
                                                .addComponent(jLabel3)
                                                .addGap(14, 14, 14)
                                                .addComponent(ipr))
                                            .addGroup(layout.createSequentialGroup()
                                                .addComponent(jLabel1)
                                                .addGap(0, 0, Short.MAX_VALUE))
                                            .addGroup(layout.createSequentialGroup()
                                                .addComponent(jLabel4)
                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                                .addComponent(portr, javax.swing.GroupLayout.PREFERRED_SIZE, 94, javax.swing.GroupLayout.PREFERRED_SIZE))))))
                            .addGroup(layout.createSequentialGroup()
                                .addGap(65, 65, 65)
                                .addComponent(clear)
                                .addGap(0, 0, Short.MAX_VALUE)))))
                .addContainerGap())
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(16, 16, 16)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 259, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(31, 31, 31))
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jLabel1)
                        .addGap(18, 18, 18)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(jLabel5)
                            .addComponent(ipm, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel2)
                            .addComponent(myport, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jButton2)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(jLabel3)
                            .addComponent(ipr, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel4)
                            .addComponent(portr, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(clear)
                        .addGap(18, 18, 18)))
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(send, javax.swing.GroupLayout.DEFAULT_SIZE, 40, Short.MAX_VALUE)
                    .addComponent(sendData))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(state)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void sendActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_sendActionPerformed
try{
if(!loggedin){
        JOptionPane.showMessageDialog(null,"please log in","Error",JOptionPane.ERROR_MESSAGE);
        throw new Exception();
}
            int x=Integer.parseInt(portr.getText());
            InetAddress ip=InetAddress.getByName(this.ipr.getText());
            String m=u+" : "+sendData.getText();
             DatagramPacket sendPacket=null;
            for (int i =0; i<a.size();i++){
                if (x == a.get(i)){
                     sendPacket=new DatagramPacket(m.getBytes(),m.length(),ip,x);
                      socket.send(sendPacket);
             conversation.append(m+"\n");
                }
            }
           
            
             sendData.setText("");
              this.state.setText("Connected, Message Sent To ["+ipr.getText()+","+x+"]");
}

catch(Exception e){
}


        // TODO add your handling code here:
    }//GEN-LAST:event_sendActionPerformed

    private void myportActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_myportActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_myportActionPerformed

    private void jButton2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton2ActionPerformed
        try{
            int x=Integer.parseInt(myport.getText());
            
                InetAddress y=InetAddress.getByName(this.ipm.getText());
                socket=new DatagramSocket(x,y);
               loggedin=true;
               a.add(x);
        JOptionPane.showMessageDialog(null,"Logged in","Done",JOptionPane.INFORMATION_MESSAGE);
        
        this.state.setText("Connected, IP : "+ipm.getText()+" Port : "+x);
    
   
        
        }
        catch(Exception e){
            JOptionPane.showMessageDialog(null,"Error in IP/Port","Error",JOptionPane.ERROR_MESSAGE);

        
        }




        // TODO add your handling code here:
    }//GEN-LAST:event_jButton2ActionPerformed

    private void iprActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_iprActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_iprActionPerformed

    private void ipmActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_ipmActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_ipmActionPerformed

    private void clearActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_clearActionPerformed

conversation.setText("");

        // TODO add your handling code here:
    }//GEN-LAST:event_clearActionPerformed

    
     

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton clear;
    private javax.swing.JTextArea conversation;
    private javax.swing.JTextField ipm;
    private javax.swing.JTextField ipr;
    private javax.swing.JButton jButton2;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JTextField myport;
    private javax.swing.JTextField portr;
    private javax.swing.JButton send;
    private javax.swing.JTextField sendData;
    private javax.swing.JLabel state;
    // End of variables declaration//GEN-END:variables
}

