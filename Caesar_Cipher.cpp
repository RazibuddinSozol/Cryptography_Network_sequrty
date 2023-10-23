#include<bits/stdc++.h>
using namespace std;
int main(){
   
   string s,t,D;
    getline(cin,s);

    int key;
    cin>>key;
    key=key%26;
    for(int i=0;i<s.size();i++){
    	if(s[i]>='A' && s[i]<='Z'){
        t+=(s[i]-'A'+key)%26+'A';
  	}
  	else if(s[i]>='a'&&s[i]<='z'){
  	  t+=(s[i]-'a'+key)%26+'a';	
  	}
  	else{
  		t+=" ";
  	}
    }
    cout<<"Encrypted message is: "<<t<<'\n';
     for(int i=0;i<t.size();i++){
     	if(t[i]>='A'&&t[i]<='Z'){
        D+=(t[i]-'A'-key+26)%26+'A';
  	}
  	else if(t[i]>='a'&&t[i]<='z'){
  	  D+=(t[i]-'a'-key+26)%26+'a';	
  	}
  	else{
  		D+=" ";
  	}
    }
    cout<<"Encrypted message is: "<<D<<'\n';
    
    return 0;
}