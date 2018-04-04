#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<string.h>
using namespace std;
int main() {
    int a[25],b[25];
    int i,j,k,m1,m2,n,t,tempa,tempb;
    while(~scanf("%d",&n)){
        scanf("%d",&m1);
        for(i=0;i<m1;i++)
            {scanf("%d",&a[i]);}
        scanf("%d",&m2);
        for(i=0;i<m2;i++)
            {scanf("%d",&b[i]);}
        k=1;
        while(1){
        if(a[0]<b[0]&&m1!=0&&m2!=0){
            tempa=a[0];
            tempb=b[0];
            m1--;
            m2++;
            if(m1==0){cout <<k <<" "<< "2"  <<endl;break; }
            if(m2==0){cout <<k << " "<<"1" <<endl;break; }
          for(i=0;i<m1;i++)
              a[i]=a[i+1];
          for(i=0;i<m2-1;i++){
            b[i]=b[i+1];
           }
            b[m2-2]=tempa;
            b[m2-1] = tempb;
           k++;

        }
         if(a[0]>b[0]&&m1!=0&&m2!=0){
            tempa=a[0];
            tempb=b[0];
            m1++;
            m2--;
            if(m1==0){cout <<k <<" "<< "2" <<endl;break; }
            if(m2==0){cout <<k << " "<<"1" <<endl;break; }
          for(i=0;i<m2;i++)
              b[i]=b[i+1];
          for(i=0;i<m1-1;i++){
            a[i]=a[i+1];
            }
            a[m1-2]=tempb;
            a[m1-1] = tempa;
           k++;
        }
        if(k>105)
            {cout << "-1" <<endl;break;}
    }
        }
return 0;
}
