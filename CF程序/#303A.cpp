#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;
int main(){
    int i,j,k,m,n,t;
    int flag[105];
    while(~scanf("%d",&n)){
        memset(flag, 0, sizeof flag);
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++){
                scanf("%d",&m);
                if(m== 1)
                    flag[i]= 1;
                if(m== 2)
                    flag [j] = 1;
                if(m == 3){
                    flag [i] = 1;
                    flag [j] = 1;
                    }
                }
            k=n;
            for(i=1;i<=n;i++)
                if(flag[i]==1)
                    k--;
            printf("%d\n",k);
            for(i=1;i<=n;i++){
                if(flag[i]!=1 && k>1){
                   printf("%d ",i);
                   k--;
                }
                else if(flag[i]!=1 &&k==1)
                    printf("%d\n",i);
            }
    }
return 0;
}
