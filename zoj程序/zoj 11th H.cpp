#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<string.h>
#include<math.h>
#define PI 3.1415926535898
using namespace std;
int main(){
    int i,j,k,m,n,t,a,b,c;
    int summax,summin;
    while(~scanf("%d",&t)){
        while(t--){
            cin >> a >> b >> c;
            summax=0;summin=0;
            j=0;k=0;
            for(i=1;i<=a;i++){
              summin+=300*((j++)*2+1);
            }
            for(i=1;i<=b;i++){
              summin+=100*((j++)*2+1);
            }
            for(i=1;i<=c;i++){
              summin+=50*((j++)*2+1);
            }
            for(i=1;i<=c;i++){
              summax+=50*((k++)*2+1);
            }
            for(i=1;i<=b;i++){
              summax+=100*((k++)*2+1);
            }
            for(i=1;i<=a;i++){
              summax+=300*((k++)*2+1);
            }
           cout << summin <<" "<< summax << "\n";
        }

    }
return 0;
}
