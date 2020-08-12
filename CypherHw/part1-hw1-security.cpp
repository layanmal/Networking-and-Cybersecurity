#include <iostream>
#include <string>
using namespace std;

int main() {
	int command ;
	 cout << "for encrypt enter 1 , for decrypt enter 2 and for crack enter 3 \n";
	 cin >> command;
	 
	string  input;
	int k;
	int cipher=0;
if (command == 1){
	
cout << "please enter a text \n";
cin >> input;
cout << "please enter a key number  \n";
cin >> k;

if (k > 26){
	k=k%26;
}
int len=input.length();
for (int i=0;i<len;i++){
	if(isalpha(input[i])){
		if(islower(input[i])){
		  if ((int)input[i] > (122-k)){
		
            input[i] =((int)input[i] +k )-26 ;
         }
         else{
         input[i] =	(int)input[i] +k ;
		 }
	}
		else{
		
    	  if ((int)input[i] > (90-k)){
		
            input[i] =((int)input[i] +k )-26 ;
         }
         else{
         input[i] =	(int)input[i] +k ;
		 }
	}
}
}
cout<<"\n"<<input<<endl;
}
if (command == 2){
		cout << "please enter a text \n";
cin >> input;
cout << "please enter a key number  \n";
cin >> k;

if (k > 26){
	k=k%26;
}
int len=input.length();
for (int i=0;i<len;i++){
	if(isalpha(input[i])){
		if(islower(input[i])){
		  if ((int)input[i] < (97+k)){
		
            input[i] =((int)input[i] -k )+26 ;
         }
         else{
         input[i] =	(int)input[i] -k ;
		 }
	}
		else{
		
    	  if ((int)input[i] > (65-k)){
		
            input[i] =((int)input[i] -k )+26 ;
         }
         else{
         input[i] =	(int)input[i] -k ;
		 }
	}
}
}
cout<<"\n"<<input<<endl;
}
if (command == 3){
cout << "please enter a text \n";
cin >> input;
int num=0;
int len=input.length();
for ( int k=0;k<26;k++){	
for (int i=0;i<len;i++){
	if(isalpha(input[i])){

		if(islower(input[i])){
		  if ((int)input[i] < (97+k)){
		
            input[i] =((int)input[i] - k )+26 ;
         }
         else{
         input[i] =	(int)input[i] - k ;
		 }
	}
		else{
		
    	  if ((int)input[i] > (65-k)){
		
            input[i] =((int)input[i] -k )+26 ;
         }
         else{
         input[i] =	(int)input[i] -k ;
		 }
	}
}
	
}
cout<<"\n"<<input<<endl;
num++;

}
cout<<"\n"<<num<<endl;
}
}


