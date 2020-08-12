#include <iostream>
#include <string>
#include <cstdlib>

#include <algorithm>
using namespace std;

int main() {
	int command ;
	 cout << "for encrypt enter 1 , for decrypt enter 2 \n";
	 cin >> command;
	string  input;
	int k;
	int cipher=0;
if (command == 1){
	cout << "please enter a text \n";
cin >> input;
k= rand() % 100 ;
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
int i = 0, alphabet[26] = {0}, b[26] = {0} ,j;
char result[26]={'0'};

   while (input[i] != '\0') {
      if (input[i] >= 'a' && input[i] <= 'z') {
         j = input[i] - 'a';
         ++alphabet[j];
      }
      ++i;
   }
   

  
  for(int i=0;i<26;i++) 
{
  
    b[i]=alphabet[i];
}

  sort(b,b+26,greater<int>());
        for (i = 0; i < 26; i++)
   cout<<  b[i]<< endl;


    for (int y = 0; y < 26; y++){
 	 	if(b[0] != 0) {
		  
 	 	if(b[0]==alphabet[y]){
		  result[y]='e';
 	 	
	  }
}
	if(b[1] != 0) {
		  
	   	if(b[1]==alphabet[y]){
		  result[y]='t';
 	 	
	  }
}
	if(b[2] != 0) {
		  
	   	if(b[2]==alphabet[y]){
		  result[y]='a';
 	 	
	  }
}
	if(b[3] != 0) {
		  
	   	if(b[3]==alphabet[y]){
		  result[y]='o';
 	 	
	  }
}
	if(b[4] != 0) {
		  
	   	if(b[4]==alphabet[y]){
		  result[y]='i';
 	 	
	  }
}
	if(b[5] != 0) {
		  
	   	if(b[5]==alphabet[y]){
		  result[y]='n';
 	 	
	  }
}
	if(b[6] != 0) {
		  
	   	if(b[6]==alphabet[y]){
		  result[y]='s';
 	 	
	  }
}
	if(b[7] != 0) {
		  
	   	if(b[7]==alphabet[y]){
		  alphabet[y]='r';
 	 	
	  }
}
	if(b[8] != 0) {
		  
	   	if(b[8]==alphabet[y]){
		  result[y]='h';
 	 	
	  }
}
	if(b[9] != 0) {
		  
	   	if(b[9]==alphabet[y]){
		  result[y]='d';
 	 	
	  }
}
	if(b[10] != 0) {
		  
	   	if(b[10]==alphabet[y]){
		  result[y]='l';
 	 	
	  }
}
	if(b[11] != 0) {
		  
	 
	   	if(b[11]==alphabet[y]){
		  result[y]='u';
 	 	
	  }
}
	if(b[12] != 0) {
		  
	   	if(b[12]==alphabet[y]){
		  result[y]='c';
 	 	
	  }
}
	if(b[13] != 0) {
		  
	   	if(b[13]==alphabet[y]){
		 result[y]='m';
 	 	
	  }
}
	if(b[14] != 0) {
		  
	   	if(b[14]==alphabet[y]){
		  result[y]='f';
 	 	
	  }
}
	if(b[15] != 0) {
		  
	   	if(b[15]==alphabet[y]){
		  result[y]='y';
 	 	
	  }
}
	if(b[16] != 0) {
		  
	   	if(b[16]==alphabet[y]){
		  result[y]='w';
 	 	
	  }
}
	if(b[17] != 0) {
		  
	   	if(b[17]==alphabet[y]){
		  result[y]='g';
 	 	
	  }
}
	if(b[18] != 0) {
		  
	   	if(b[18]==alphabet[y]){
		  result[y]='p';
 	 	
	  }
}
	if(b[19] != 0) {
		  
	   	if(b[19]==alphabet[y]){
		  result[y]='b';
 	 	
	  
	  }
}
	if(b[20] != 0) {
		  
	   	if(b[20]==alphabet[y]){
		  result[y]='v';
 	 	
	  }
}
	if(b[21] != 0) {
		  
	   	if(b[21]==alphabet[y]){
		 result[y]='k';
 	 	
	  }
}
	if(b[22] != 0) {
		  
	   	if(b[22]==alphabet[y]){
		  result[y]='x';
 	 	
	  }
}
	if(b[23] != 0) {
		  
	   	if(b[23]==alphabet[y]){
		  result[y]='q';
 	 	
	  }
}
	if(b[24] != 0) {
		  
	   	if(b[24]==alphabet[y]){
		  result[y]='j';
 	 	
	  }
}
	if(b[25] != 0) {
		  
	   	if(b[25]==alphabet[y]){
		  result[y]='z';
 	 	
	  }
}
	  
	 
}
 for (int i = 0; i < 26; i++){

 
   cout<< result[i];

}
 
 	}
}
