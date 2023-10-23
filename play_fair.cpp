#include<bits/stdc++.h>
using namespace std;

#define rapid() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
#define inf 1e36
#define pb push_back
#define mp make_pair
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

/*

## TWO-Dimentional Vector

vector<vector<int>>vec;
  for(int i=0;i<4;i++){
    vector<int>v1;
    for(int j=0;j<4;j++){
      char a;
      cin>>a;
      if(a>='1'&&a<='9')
        v1.push_back(i+j);
    }
    vec.push_back(v1);
  }


*/


typedef long long ll;

const ll dp=1e9+7;

int main(){
	string key,ke,ke1;
	string plane_text;

/*
	playfair
	meetmeafterthetoggaparty 
*/

	getline(cin,key);
	getline(cin,plane_text);

string sg=plane_text;
	char a[5][5];

	for(int i=0;i<key.size();i++){
		if(key[i]!=' '){
			ke+=key[i];
		}
	}
	// cout<<ke<<endl;
 
	for(int i=0;i<ke.size();i++){
		if((find(ke1.begin(),ke1.end(),ke[i]))==ke1.end() ){
			ke1+=ke[i];
		}
	}
// cout<<endl;
	cout<<ke1<<endl;
    set<char>s1,s2;

	int g=0;
	bool flag=0;
	for (int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			a[i][j]=ke1[g];
			g++;
			s1.insert(ke1[g]);
			if(g>ke1.size()){
				a[i][j]='0';
			}
		}
	}

	int d=0,x=0;
	bool flag1=0;
	
	for(int x=0;x<26;x++){
		flag1=0;
		if(!s1.count(x+'a') && (x+'a')!='j'){
				for(int i=0;i<5;i++){
					for(int j=0;j<5;j++){
						if(a[i][j]=='0'){
							a[i][j]=x+'a';
							s1.insert(x+'a');
							flag1=1;
							break;
						}
					}
					if(flag1)break;
				}  
		}
	} 

for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
cout<<endl;

	char td[100][3];
	vector<pair<int,int>>pr;
	int cnt=0;
	for(int i=0;i<plane_text.size();i+=2){
		td[i][0]=plane_text[i];
		td[i][1]=plane_text[i+1];
		cnt++;
	}
	bool flg=0;
	for(int i=0;i<plane_text.size();i++){
		flg=0;
		for(int j=0;j<5;j++){
			for(int k=0;k<5;k++){
				if(a[j][k]==plane_text[i]){
					pr.pb({j,k});
					flg=1;
					break;
				}
			}
		}
		if(!flg)pr.pb({0,0});
	}
	string mo;

	for(int i=0;i<pr.size();i+=2){
		cout<<pr[i].first<<" "<<pr[i].second<<endl;;
		cout<<pr[i+1].first<<" "<<pr[i+1].second<<endl;
		cout<<endl; 
	}

	for(int i=0;i<pr.size();i+=2){
		if(pr[i].first==pr[i+1].first){
			mo+=a[pr[i].first][(pr[i].second+1)%5];
			mo+=a[pr[i+1].first][(pr[i+1].second+1)%5];
		}
		else if(pr[i].second==pr[i+1].second){
			mo+=a[(pr[i].first+1)%5][pr[i].second];
			mo+=a[(pr[i+1].first+1)%5][pr[i+1].second];
		}
		else{
			mo+=a[pr[i].first][pr[i+1].second];
			mo+=a[pr[i+1].first][pr[i].second];
		}
	}
	cout<<mo<<endl;
	cout<<endl;
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<sg<<endl;


}