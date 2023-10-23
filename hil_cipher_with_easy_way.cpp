#include<bits/stdc++.h>
using namespace std;
int main(){

	int a[2][2]={{3,3},{2,5}};
	cout<<"plain text: "; //demo
	string p1,p;
	cin>>p1;
	cout<<endl;
	cout<<"Key matrix"<<endl<<endl;;
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	for(auto u:p1){
		p+=toupper(u);
	}
	// cout<<p<<endl;
	map<char,int>m;
	for(int i=0;i<26;i++){
		m[char(65+i)]=i;
	}
	// for(auto u:m)cout<<u.first<<" "<<u.second<<endl;
	vector<int>v,dec;
	for(int i=0;i<p.size();i++){
		v.push_back(m[p[i]]);
	}
	// for(auto u:v)cout<<u<<" ";
	// cout<<endl;
	// for(int i=0;i<2;i++){
	// 	for(int j=0;j<2;j++){
	// 		cout<<a[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	cout<<endl;
	cout<<"The encrypted text: ";
	int mul[2][2],k=0,sum=0;
	for(int i=0;i<2;i++){
		sum=0,k=0;
		for(int j=0;j<2;j++){
			sum+=a[i][j]*v[k];
			k++;
		}
		dec.push_back(((sum%26)));
		cout<<char((sum%26)+65);
	}
	for(int i=0;i<2;i++){
		sum=0,k=2;
		for(int j=0;j<2;j++){
			sum+=a[i][j]*v[k];
			k++;
		}
		dec.push_back(((sum%26)));
		cout<<char((sum%26)+65);
	}
	cout<<endl;
	cout<<"The determinant: ";

	int det=a[0][0]*a[1][1]-a[0][1]*a[1][0];

	for(int i=0;i<100;i++){
		if((i*det)%26==1){
			det=i;
			break;
		}
	}
	cout<<det<<endl;

	swap(a[0][0],a[1][1]);
	a[1][0]=-(a[1][0]);
	a[0][1]=-(a[0][1]);
	cout<<"The inverse matrix: "<<endl;;
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			a[i][j]=(a[i][j]*3);
			while(a[i][j]<0)a[i][j]+=26;
		}
	}
	// for(auto u:dec)cout<<u<<" ";
	cout<<"The Decrypted text: ";
	for(int i=0;i<2;i++){
		sum=0,k=0;
		for(int j=0;j<2;j++){
			sum+=a[i][j]*dec[k];
			k++;
		}
		cout<<char((sum%26)+65);
	}
	for(int i=0;i<2;i++){
		sum=0,k=2;
		for(int j=0;j<2;j++){
			sum+=a[i][j]*dec[k];
			k++;
		}
		cout<<char((sum%26)+65);
	}
	
	return 0;
}