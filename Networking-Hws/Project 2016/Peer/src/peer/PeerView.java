/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package peer;

import java.awt.Color;
import java.io.IOException;
import java.net.InetAddress;
import java.net.NetworkInterface;
import java.net.ServerSocket;
import java.net.SocketException;
import java.util.Collections;
import java.util.Enumeration;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JTextField;

/**
 *
 * @author zaid-
 */
public class PeerView extends javax.swing.JFrame {

    private ConnectionData dataConnection;
    
    
 
    
    /**
     * Creates new form PeerView
     */
    public PeerView(ConnectionData dataConnection) {
        initComponents();
        jPanel3.setBackground(new Color(210,210,210,230));
        
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setVisible(true);
        this.dataConnection=dataConnection;
        biuldAddressList();
        String i=(String)AddressList.getSelectedItem();
        dataConnection.setAddress(i); 
        frame=this;
        statee=StateBox;
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPanel1 = new javax.swing.JPanel();
        NameBox = new javax.swing.JTextField();
        LoginButton = new javax.swing.JButton();
        StateBox = new javax.swing.JTextField();
        jLabel1 = new javax.swing.JLabel();
        jPanel2 = new javax.swing.JPanel();
        AddressList = new javax.swing.JComboBox<>();
        AutoPortSelcter = new javax.swing.JCheckBox();
        PortBox = new javax.swing.JTextField();
        jScrollPane3 = new javax.swing.JScrollPane();
        OnlineList = new javax.swing.JList<>();
        jLabel2 = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        ReceverAddressBox = new javax.swing.JTextField();
        ReceverPortBox = new javax.swing.JTextField();
        jLabel5 = new javax.swing.JLabel();
        jLabel6 = new javax.swing.JLabel();
        jButton1 = new javax.swing.JButton();
        jPanel3 = new javax.swing.JPanel();
        SenderButton = new javax.swing.JButton();
        jScrollPane2 = new javax.swing.JScrollPane();
        MsgSenderBox = new javax.swing.JTextPane();
        fffsafas = new javax.swing.JScrollPane();
        MsgBox = new javax.swing.JTextArea();
        jPanel4 = new javax.swing.JPanel();
        jLabel8 = new javax.swing.JLabel();
        NameActiveBox = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setResizable(false);

        jPanel1.setBackground(new java.awt.Color(0, 102, 102));

        NameBox.setText("ZaidHabiba");

        LoginButton.setText("Login");
        LoginButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                LoginButtonActionPerformed(evt);
            }
        });

        StateBox.setEditable(false);
        StateBox.setText("Plase Login");

        jLabel1.setText("State");

        jPanel2.setBackground(new java.awt.Color(0, 160, 204));

        AddressList.addItemListener(new java.awt.event.ItemListener() {
            public void itemStateChanged(java.awt.event.ItemEvent evt) {
                AddressListItemStateChanged(evt);
            }
        });
        AddressList.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                AddressListMouseClicked(evt);
            }
        });
        AddressList.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                AddressListActionPerformed(evt);
            }
        });

        AutoPortSelcter.setSelected(true);
        AutoPortSelcter.setText("auto Port");
        AutoPortSelcter.setContentAreaFilled(false);
        AutoPortSelcter.addChangeListener(new javax.swing.event.ChangeListener() {
            public void stateChanged(javax.swing.event.ChangeEvent evt) {
                AutoPortSelcterStateChanged(evt);
            }
        });

        PortBox.setEditable(false);
        PortBox.setText("*****");

        OnlineList.setSelectionMode(javax.swing.ListSelectionModel.SINGLE_SELECTION);
        OnlineList.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                OnlineListMouseClicked(evt);
            }
        });
        jScrollPane3.setViewportView(OnlineList);

        jLabel2.setText("Recever Options:");

        jLabel3.setText("Sender Options:");

        jLabel4.setText("Address:");

        ReceverAddressBox.setText("127.0.0.1");

        jLabel5.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel5.setText("Port:");

        jLabel6.setFont(new java.awt.Font("Tahoma", 0, 18)); // NOI18N
        jLabel6.setText("Online:");

        jButton1.setText("Connect");
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jPanel2Layout = new javax.swing.GroupLayout(jPanel2);
        jPanel2.setLayout(jPanel2Layout);
        jPanel2Layout.setHorizontalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel2Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jScrollPane3, javax.swing.GroupLayout.PREFERRED_SIZE, 0, Short.MAX_VALUE)
                    .addComponent(AddressList, javax.swing.GroupLayout.Alignment.TRAILING, 0, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addGroup(jPanel2Layout.createSequentialGroup()
                        .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                            .addComponent(jLabel4, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(jLabel5, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(ReceverPortBox)
                            .addComponent(ReceverAddressBox)))
                    .addGroup(jPanel2Layout.createSequentialGroup()
                        .addComponent(AutoPortSelcter, javax.swing.GroupLayout.PREFERRED_SIZE, 83, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(PortBox, javax.swing.GroupLayout.PREFERRED_SIZE, 81, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(jPanel2Layout.createSequentialGroup()
                        .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel3)
                            .addComponent(jLabel6, javax.swing.GroupLayout.PREFERRED_SIZE, 95, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addGroup(jPanel2Layout.createSequentialGroup()
                                .addComponent(jLabel2)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                .addComponent(jButton1)))
                        .addGap(0, 26, Short.MAX_VALUE)))
                .addContainerGap())
        );
        jPanel2Layout.setVerticalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel2Layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jLabel3)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(AddressList, javax.swing.GroupLayout.PREFERRED_SIZE, 25, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(PortBox, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(AutoPortSelcter, javax.swing.GroupLayout.Alignment.TRAILING))
                .addGap(18, 18, 18)
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(jButton1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(jLabel2, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel4)
                    .addComponent(ReceverAddressBox, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(ReceverPortBox, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel5))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 20, Short.MAX_VALUE)
                .addComponent(jLabel6, javax.swing.GroupLayout.PREFERRED_SIZE, 19, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jScrollPane3, javax.swing.GroupLayout.PREFERRED_SIZE, 145, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap())
        );

        jPanel3.setBackground(new java.awt.Color(204, 204, 204));

        SenderButton.setText("Send");
        SenderButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                SenderButtonActionPerformed(evt);
            }
        });

        jScrollPane2.setViewportView(MsgSenderBox);

        MsgBox.setEditable(false);
        MsgBox.setColumns(20);
        MsgBox.setRows(5);
        fffsafas.setViewportView(MsgBox);

        jPanel4.setBackground(new java.awt.Color(255, 255, 255));

        jLabel8.setIcon(new javax.swing.ImageIcon(getClass().getResource("/peer/icons8-account-32.png"))); // NOI18N

        NameActiveBox.setFont(new java.awt.Font("Tahoma", 0, 18)); // NOI18N
        NameActiveBox.setText("No User");

        javax.swing.GroupLayout jPanel4Layout = new javax.swing.GroupLayout(jPanel4);
        jPanel4.setLayout(jPanel4Layout);
        jPanel4Layout.setHorizontalGroup(
            jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel4Layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jLabel8, javax.swing.GroupLayout.DEFAULT_SIZE, 38, Short.MAX_VALUE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(NameActiveBox, javax.swing.GroupLayout.PREFERRED_SIZE, 103, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(260, 260, 260))
        );
        jPanel4Layout.setVerticalGroup(
            jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jLabel8, javax.swing.GroupLayout.DEFAULT_SIZE, 43, Short.MAX_VALUE)
            .addComponent(NameActiveBox, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );

        javax.swing.GroupLayout jPanel3Layout = new javax.swing.GroupLayout(jPanel3);
        jPanel3.setLayout(jPanel3Layout);
        jPanel3Layout.setHorizontalGroup(
            jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel3Layout.createSequentialGroup()
                .addGap(6, 6, 6)
                .addGroup(jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(fffsafas)
                    .addGroup(jPanel3Layout.createSequentialGroup()
                        .addComponent(jScrollPane2, javax.swing.GroupLayout.PREFERRED_SIZE, 340, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(SenderButton, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                    .addComponent(jPanel4, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addContainerGap())
        );
        jPanel3Layout.setVerticalGroup(
            jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel3Layout.createSequentialGroup()
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(jPanel4, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(fffsafas, javax.swing.GroupLayout.PREFERRED_SIZE, 216, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(SenderButton, javax.swing.GroupLayout.DEFAULT_SIZE, 39, Short.MAX_VALUE)
                    .addComponent(jScrollPane2))
                .addContainerGap())
        );

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addComponent(NameBox)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(LoginButton, javax.swing.GroupLayout.PREFERRED_SIZE, 88, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addComponent(jLabel1)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(StateBox))
                    .addComponent(jPanel3, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(jPanel2, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap())
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGap(5, 5, 5)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(NameBox, javax.swing.GroupLayout.PREFERRED_SIZE, 32, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(LoginButton, javax.swing.GroupLayout.PREFERRED_SIZE, 32, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jPanel3, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(StateBox, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(jLabel1)))
                    .addComponent(jPanel2, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addContainerGap())
        );

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void AddressListActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_AddressListActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_AddressListActionPerformed

    private void AddressListMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_AddressListMouseClicked
        // TODO add your handling code here:
       
    }//GEN-LAST:event_AddressListMouseClicked

    private void AddressListItemStateChanged(java.awt.event.ItemEvent evt) {//GEN-FIRST:event_AddressListItemStateChanged
        // TODO add your handling code here:
         String i=(String)AddressList.getSelectedItem();
         dataConnection.setAddress(i);
        //System.out.println(i);
    }//GEN-LAST:event_AddressListItemStateChanged

    private void LoginButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_LoginButtonActionPerformed
        try {
            //connect
              if(AutoPortSelcter.isSelected()){
                ServerSocket s = new ServerSocket(0);
                dataConnection.setPort(s.getLocalPort());
                PortBox.setText(""+s.getLocalPort());
                dataConnection.setName(NameBox.getText());
                s.close();
              }else{
                  int port=Integer.valueOf(PortBox.getText());
                  dataConnection.setPort(port);
                  dataConnection.setName(NameBox.getText());
              }
           
           if(dataConnection.connect(NameBox.getText())){
               StateBox.setText("Login successful "+NameBox.getText());
           }else{
               StateBox.setText("Login Failed");
           }
        } catch (Exception ex) {
             JOptionPane.showMessageDialog(null,"Login Failed [same data is miss]","Error",JOptionPane.ERROR_MESSAGE);
         }
        
        
        
    }//GEN-LAST:event_LoginButtonActionPerformed

    
    private void AutoPortSelcterStateChanged(javax.swing.event.ChangeEvent evt) {//GEN-FIRST:event_AutoPortSelcterStateChanged
        // TODO add your handling code here:
        if(AutoPortSelcter.isSelected()){
            PortBox.setEditable(false);
        }else{
             PortBox.setEditable(true);
        }
        
    }//GEN-LAST:event_AutoPortSelcterStateChanged

    private void OnlineListMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_OnlineListMouseClicked
        try{
            String nameSelect=OnlineList.getSelectedValue();
            for(PeerData peer:dataConnection.getPeerList()){
                if(nameSelect.equals(peer.getName())){
                     NameActiveBox.setText(peer.getName());
                     MsgBox.setText("");
                     for(String text:peer.getMsgs()){
                          MsgBox.append(text+"\n");
                     }
                     dataConnection.setActivePeer(peer);
                }
            }
        }catch(Exception e){}
      
        
    }//GEN-LAST:event_OnlineListMouseClicked

    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton1ActionPerformed
        
        String command[]={Commands.Connect,dataConnection.getName()};
        System.out.println(dataConnection.getName());
        PeerData peer=new PeerData();
        peer.setAddress(ReceverAddressBox.getText());
        peer.setPort(Integer.valueOf(ReceverPortBox.getText()));
        String test=ReceverAddressBox.getText()+";"+ReceverPortBox.getText();
        boolean have=false;
        /*for(PeerData pee:dataConnection.getPeerList()){
            String t=pee.getStringAddress()+";"+pee.getPort();
            if(t.equals(test)){
                have=true;
            }
        }*/
        if(!have){
            dataConnection.setActivePeer(peer);
            Sender.sendCommand(Commands.getCommand(command));
            newConnectSend=true;
            dataConnection.setActivePeer(peer);
            MsgBox.setText("");
            NameActiveBox.setText("Connect ...");
        } 
    }//GEN-LAST:event_jButton1ActionPerformed

    private void SenderButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_SenderButtonActionPerformed
        // TODO add your handling code here:
        dataConnection.getActivePeer().addMsg("You:"+this.MsgSenderBox.getText());
        MsgBox.setText("");
       for(String text:dataConnection.getActivePeer().getMsgs()){
            MsgBox.append(text+"\n");
       }
        String c[]={Commands.Msg,this.MsgSenderBox.getText()};
        Sender.sendCommand(Commands.getCommand(c));
        
        
    }//GEN-LAST:event_SenderButtonActionPerformed
    public boolean newConnectSend=false;
    public void biuldAddressList(){
        try {
            Enumeration<NetworkInterface> nets = NetworkInterface.getNetworkInterfaces();
            for (NetworkInterface netint : Collections.list(nets)){

                Enumeration<InetAddress> inetAddresses = netint.getInetAddresses();
                for (InetAddress inetAddress : Collections.list(inetAddresses)) {
                     //System.out.println("InetAddress:"+inetAddress);
                    if(this.isRealAddress(inetAddress))
                    AddressList.addItem(inetAddress.toString().substring(1));
                }

            }
        } catch (SocketException ex) {}
    }
    
    static JTextField statee;
    public static void setState(String state){
        statee.setText(state);
    }
    
    static JFrame frame;
    public static JFrame getView(){
        return frame;
    }
    
    public boolean isRealAddress(InetAddress inetAddress){
        String add=inetAddress.toString();
        add=add.substring(1);
        String items[]=add.split("\\.");      
        if(items.length<2){
            return false;
        }else{
            return true;
        }
    }
    
 

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JComboBox<String> AddressList;
    private javax.swing.JCheckBox AutoPortSelcter;
    private javax.swing.JButton LoginButton;
    private javax.swing.JTextArea MsgBox;
    private javax.swing.JTextPane MsgSenderBox;
    private javax.swing.JLabel NameActiveBox;
    private javax.swing.JTextField NameBox;
    private javax.swing.JList<String> OnlineList;
    private javax.swing.JTextField PortBox;
    private javax.swing.JTextField ReceverAddressBox;
    private javax.swing.JTextField ReceverPortBox;
    private javax.swing.JButton SenderButton;
    private javax.swing.JTextField StateBox;
    private javax.swing.JScrollPane fffsafas;
    private javax.swing.JButton jButton1;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JLabel jLabel8;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JPanel jPanel2;
    private javax.swing.JPanel jPanel3;
    private javax.swing.JPanel jPanel4;
    private javax.swing.JScrollPane jScrollPane2;
    private javax.swing.JScrollPane jScrollPane3;
    // End of variables declaration//GEN-END:variables

    void updataNewPeerComing(PeerData peer) {
        System.out.println("name PeerConnect:"+peer.getName());
        dataConnection.setActivePeer(peer);
        MsgBox.setText("");
        NameActiveBox.setText(peer.getName());
        OnlineListData[peerCounter]=peer.getName();
        OnlineList.setListData(OnlineListData);
        //String c[]={Commands.ConnectAccepted,dataConnection.getName()};
        //Sender.sendCommand(Commands.getCommand(c));
        peerCounter++;
    }

    String OnlineListData[]=new String[20];
    int peerCounter=0;
    void updataMsgSendNow(PeerData peer) {
       NameActiveBox.setText(peer.getName());
       MsgBox.setText("");
       for(String text:peer.getMsgs()){
            MsgBox.append(text+"\n");
       }
       dataConnection.setActivePeer(peer);
    }
}
