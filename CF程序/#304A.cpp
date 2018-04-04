#include <stdio.h>
int main(){
    long long  i,j,k,m,n,w;
    long long  sum;
    while(~scanf("%lld%lld%lld",&k,&n,&w)){
            sum=0;
        for(i=1;i<=w;i++)
            sum+=i*k;
            if(sum-n>0)
           printf("%lld\n",sum-n);
    else
        printf("0\n");
    }
return 0;
}
