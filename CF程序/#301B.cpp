#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int i,j,k,m,n,sum,b,p,x,y ,c;
    int a[10000],key[10000];
    while(~scanf("%d%d%d%d%d",&n,&k,&p,&x,&y)){
           sum=0;b=0;c=0;
        for(i=0;i<k;i++){
            cin >> a[i];
           sum+=a[i];
          if(a[i]>=y) b++;
          if(a[i]<y) c++;
        }
        if(c>=n/2+1){
            puts("-1");
            continue;
        }
        m=0;
        int tx=n/2+1-b;
        while(tx>0){
            sum += y;
            key[m++]=y;
            tx--;
        }
        tx=n-m-k;
        while(tx>0){
            sum += 1;
            key[m++]=1;
            tx--;
        }
        if(sum>x)
            puts("-1");
        else
            for(j=0;j<m;j++){
            if(j==m-1)
                cout << key[j] << "\n";
            else
                cout << key[j] << " ";
        }
    }
return 0;
}
