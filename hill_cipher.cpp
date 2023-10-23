#include <bits/stdc++.h>
using namespace std;

int main()
{      
     
     
     map<char,int>letter;
     vector<char>conv(26);
     for(int i=0;i<26;i++)
     {
        letter.insert({char('A'+i),i});
        conv[i]=char('A'+i);
     }
    // for(auto it:letter)cout<<it.first<<" "<<it.second<<endl;
     //for(auto it:conv)cout<<it<<" ";cout<<endl;
     string plaintext;
     vector<vector<int> >matrix{{3,3},{2,5}};
    
     //input plaintext 
    cin>>plaintext;
    string cipher="";
    vector<int>ans;
    
   for(int k=0;k<plaintext.size();k+=2){
    int l=k;
   for (int i = 0; i < matrix.size(); i++)
    {
        int cal=0;
        for (int j = 0; j < matrix[i].size(); j++)
        {
            // cal += (matrix[i][j]*letter[plaintext[i+j]]);
                   
             //cout<<plaintext[l+j]<<" "<<matrix[i][j]<<endl;
             cal += (matrix[i][j]*letter[toupper(plaintext[l+j])]);
        } 
         ans.push_back(cal%26);
    }
}
 
cout<<"Plaintext: "<<plaintext<<endl<<"Encryption Text: ";
for(auto it:ans)cipher+=char(conv[it]);cout<<cipher<<endl;


    int det = ((matrix[0][0]*matrix[1][1])-(matrix[0][1]*matrix[1][0]));
        cout<<"Determinant value : "<<det<<endl;
       matrix[0][1]= -matrix[0][1];
       matrix[1][0] = -matrix[1][0];
     swap(matrix[1][1],matrix[0][0]);
     cout<<"InverseMatrix--------\n";
     for(int i=0;i<matrix.size();i++)
     {
        for(int j=0;j<matrix[i].size();j++)
        {
            cout<<matrix[i][j]<< " ";
        }
        cout<<endl;
     }
     
     int rem,i;        //for remainder value^-1 mod 26 use Arithematic idea
     for( i=1;i<=26;i++)
     {
        int mat = det*i;
        if(mat%26 == 1){rem=i;break;}        
        
     }
     //cout<<rem<<endl;
      for(int i=0;i<matrix.size();i++)
     {
        for(int j=0;j<matrix[i].size();j++)
        {
            matrix[i][j]= matrix[i][j]*rem;
            if(matrix[i][j]<0)
            {
                matrix[i][j]= matrix[i][j]+26;
            }
        }
     }
     cout<<"Modify Matrix -------\n";   // for modify if value negative then replace value+26 otherwise fixed value
     for(int i=0;i<matrix.size();i++)
     {
        for(int j=0;j<matrix[i].size();j++)
        {
            cout<<matrix[i][j]<< " ";
        }
        cout<<endl;
     }

       string decipher="";
    vector<int>decans;
    
   for(int k=0;k<cipher.size();k+=2){
    int l=k;
   for (int i = 0; i < matrix.size(); i++)
    {
        int cal=0;
        for (int j = 0; j < matrix[i].size(); j++)
        {
           ;
             cal += (matrix[i][j]*letter[cipher[l+j]]);  //already uppercase output so not needed convert uppercase
        } 
         decans.push_back(cal%26);
    }
}
 
cout<<"\nEncryption Text: "<<cipher<<endl<<"Decryption Text: ";
for(auto it:decans)decipher+=char(conv[it]);cout<<decipher<<endl;
     

    return 0;}
