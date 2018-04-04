#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

string sum(string s1,string s2){
     if(s1.length()<s2.length()){
          string temp=s1;
          s1=s2;
          s2=temp;
     }
     for(int i=s1.length()-1,j=s2.length ()-1;i>=0;i--,j--) {
          s1[i]=char(s1[i]+(j>=0?s2[j]-'0':0));
          if(s1[i]-'0'>=10) {
              s1[i]=char((s1[i]-'0')%10+'0');
              if(i)
                   s1[i-1]++;
              else
                   s1='1'+s1;
          }
     }
     return s1;
}


int main() {
	string s1,s2;
	int T;

	while(~scanf("%d",&T)) {
        for(int i = 1; i <= T; i++) {
            cin>>s1>>s2;
            if(i==T) {
                cout<< "Case " << i <<":\n";
                cout << s1 << " + " <<s2<<" = "<<sum(s1,s2)<<endl;
            }
            else {
                cout<<"Case "<<i<<":\n";
                cout <<s1<<" + "<<s2<<" = "<<sum(s1,s2)<<endl<<endl;
            }
        }
	}
	return 0;
}
