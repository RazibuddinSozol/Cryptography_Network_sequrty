#include<bits/stdc++.h> 
using namespace std; 
int main(){ 
string most_use_lc="etaoinsrhldcumfpgwybvkxjqz"; 
string most_use_uc="ETAOINSRHLDCUMFPGWYBVKXJQZ"; 

string plane_text,en,plain_text1; 
getline(cin,plane_text); 
map<char,int>m; 
vector<pair<int,char>>pr; 
plain_text1=plane_text; 
for(int i=0;i<plane_text.size();i++){ 
	if((plane_text[i]>='a' && plane_text[i]<='z') || (plane_text[i]>='A' && plane_text[i]<='Z')) 
	m[plane_text[i]]++; 
} 
for(auto u:m){ 
	pr.push_back({u.second,u.first}); 
} 
sort(pr.rbegin(),pr.rend());
int k=0; 
vector<int>a(100); 
for(int i=0;i<pr.size();i++){ 
	for(int j=0;j<plane_text.size();j++){ 
		if(pr[i].second==plane_text[j] && plane_text[j]>='a'&&plane_text[j]<='z'){ 
			plane_text[j]=most_use_lc[k]; 
			a.push_back(abs(plane_text[j]-most_use_lc[k])); 
		} 
		else if(pr[i].second==plane_text[j] && plane_text[j]>='A'&&plane_text[j]<='Z'){ 
			plane_text[j]=most_use_uc[k]; 
			a.push_back(abs(plane_text[j]-most_use_lc[k])); 
		}				 
	} 
	k++; 
} 
cout<<plane_text<<endl; 
int f=0; 
for(int j=0;j<plane_text.size();j++){ 
	if(plane_text[j]>='a'&&plane_text[j]<='z'){ 
		plane_text[j]=plane_text[j]+a[f]; 
	} 
	else if( plane_text[j]>='A'&&plane_text[j]<='Z'){ 
		plane_text[j]=plane_text[j]+a[f]; 

	}				 
	f++; 
} 
cout<<plain_text1<<endl; 
return 0;	 

} 