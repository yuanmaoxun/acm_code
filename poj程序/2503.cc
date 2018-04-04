#include<iostream>
#include<cstring>
#include<string>
#include<map>
#include<stdio.h>
using namespace std;

int main()
{
    map<string,string> d;
    char str1[12],str2[12],str[30];
       while(gets(str))
       {
            if(strlen(str)==0)
                break;
            sscanf(str,"%s %s",str1,str2);
            d[str2]=str1;
       }
       string str3,p_out;
       while(cin>>str3)
       {
           p_out=d[string(str3)];
           if(p_out.length()==0)
           cout<<"eh"<<endl;
           else
           cout<<p_out<<endl;
       }
       return 0;
}
