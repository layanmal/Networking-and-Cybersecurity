/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package peer;

/**
 *
 * @author Ghadir
 */
public class Commands {
    
    public static final String Connect="Connect";//Connect;MyName;
    public static final String ConnectAccepted="ConnectAccepted";//ConnectAccepted;Name;
    public static final String Msg="Msg";//Msg;text;
    
    
    public static String getCommand(String command[]) {
		String Command="";
		for(int i=0;i<command.length;i++) {
			Command=Command+command[i];
			if(i<command.length-1) {
				Command=Command+";";
			}
		}
		Command=Command+";\n";
		return Command;
	}
    
}
