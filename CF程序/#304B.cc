#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
    int i,j,k,m,n,t,temp;
    int a[3005],coin;
    while(~scanf("%d",&n)){
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        coin = 0;
        for(i=0;i<n-1;i++){
            if(a[i]==a[i+1]){
                    t=i;
                temp = a[i+1] + 1;
                coin++;
                for(k=i+2;k<n;k++)
                if(temp==a[k]){
                    temp++;
                    coin++;
                }
                a[i+1]=temp;
            sort(a,a+n);
            i=t-1;
           }
        }
        printf("%d\n",coin);
    }
return 0;
}
