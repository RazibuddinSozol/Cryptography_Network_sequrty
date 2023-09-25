/*
  Authors : Md Sidul Islam Sozol
  Dept.   : ICE
  ID      : 180608

*/


#include<bits/stdc++.h>
using namespace std;

#define rapid() ios_base::sync_with_stdio(false);cin.tie(NUL L);cout.tie(NULL);
#define endl '\n'
#define inf 1e36
#define pb push_back
#define mp make_pair
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

typedef long long ll;

const ll dp=1e9+7;

vector<int>vec(1000);

int main(){
  // rapid();
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
   string p,s,s1,s2,s3;

   getline(cin,p);
   getline(cin,s);

   /*
    
    sozol
    razib

    */

   

   int ac;

   for(int i=0;i<p.size();i++){
    ac=p[i]^s[i];
    s2+=ac;
    if(ac<97){
      ac+=97;
      vec[i]=97;
    }
    else{
      ac=(ac)%122;
      if(ac<97)ac+=97;
    }
    cout<<bitset<8>(ac)<<endl;
    s1+=char(ac);
   }
   cout<<s1<<endl;
   int bc;
   for(int i=0;i<p.size();i++){
    bc=s2[i]^p[i];
    s3+=char(bc);
    cout<<bitset<8>(bc)<<endl;;
   }
   cout<<s3<<endl;

  return 0;
}
