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


	/*
	4
	1 3 2 4
	instrume 

	i n s t
	r u m e

	*/
	int n;
	cin>>n;

	vector<int>vec(n);
	vector< pair<int,string> >r;

	for(int i=0;i<n;i++)cin>>vec[i];

	string s,s1="",s2;
	cin>>s;	

	for(int i=0;i<s.size();i+=2){
		s2+=s[i];
	}

	for(int i=1;i<s.size();i+=2){
		s2+=s[i];
	}
	// cout<<s<<endl;

	// s=s2;

	int k=0,j;	
	for(int i=0;i<s.size()/2;i++){
		s1+=s[i];
		s1+=s[(s.size()/2)+i];
		if(s1.size()==(s.size()/n)){
			r.push_back({vec[k],s1});
			k++;
			s1="";
		}		
	}
	
	for(int i=0;i<s.size()/2;i++){
		cout<<s[i];
	}cout<<endl;
	for(int i=s.size()/2;i<s.size();i++){
		cout<<s[i];
	}cout<<endl;

	sort(r.begin(),r.end());
	char a[(s.size()/n)][n];	
	
	cout<<"\n\nMAPING-------------------------->>"<<endl;;
	cout<<endl;

	for(auto u:r)cout<<u.first<<" "<<u.second<<endl;
	int g=0;
	for(int i=0;i<(s.size()/n);i++){
		int p=0;
			for(int j=0;j<n;j++){
				string st=r[j].second;
				a[g][p]=st[g];
				p++;
			}
			g++;
	}
cout<<"\n\nCIPHER TEXT & MATRIX---------------->>"<<endl;
for(auto u:r)cout<<u.second;
cout<<endl;
cout<<endl;
char b[n][(s.size()/n)];
	for(int i=0;i<(s.size()/n);i++){
		for(int j=0;j<n;j++){
			// cout<<a[i][j];
			b[j][i]=a[i][j];
		}
		// cout<<endl;
	}
cout<<endl;
map<int,string>p;
cout<<"\n\nMAPPING--------------------------->>"<<endl;
cout<<endl;
	for(int i=0;i<n;i++){
		string s1="";
		for(int j=0;j<(s.size()/n);j++){
			cout<<b[i][j];
			s1+=b[i][j];
		}
		p[i+1]=s1;
		cout<<endl;
	}
cout<<"\n\nORIGINAL TEXT----------------------->>"<<endl;
cout<<endl;
string st;
	for(auto u:vec){
		st+=p[u];
	}
	for(int i=0;i<st.size();i+=2)cout<<st[i];
	for(int i=1;i<st.size();i+=2)cout<<st[i];
	cout<<endl;


  return 0;
}
